from pathlib import Path
import contextlib,hashlib,json,os,re,subprocess,sys,time
P=Path(__file__).resolve().parent;R=Path(os.environ['REPO_ROOT']).resolve();H=Path(os.environ['TRAIL_OUTPUT']).resolve();assert H!=R and R not in H.parents;H.mkdir(parents=True,exist_ok=False);sys.path.insert(0,str(R))
from tools import build,check
from tools.elf import ElfFile
from tools.retail_got import write_harness
from tools.thumb_bindings import write_bindings
BASE_LIB_SHA256 = 'b322b642d365a34c48e140234b7ef4efd965d1e81acd2b95d9034e2f4386ea8a'
retail_path = Path(os.environ['RETAIL_LIBRARY']).resolve()
actual_base_sha256 = hashlib.sha256(retail_path.read_bytes()).hexdigest()
assert actual_base_sha256 == BASE_LIB_SHA256, 'Retail SHA256 mismatch: ' + actual_base_sha256
(H/'retail-identity.json').write_text(json.dumps(dict(expected=BASE_LIB_SHA256, actual=actual_base_sha256),indent=2)+'\n')
base=Path(os.environ['GAME_TOOLS_ROOT']);m=json.loads((R/'config/matches/sdk-startup-trail.json').read_text());profile='sdk-startup-trail';sdk=base/m['toolchain'];obj=H/f'{profile}.o';import shutil;shutil.copytree(R/'src/game',H/'src');shutil.copy2(P/'Trail.cpp',H/'src/world/Trail.cpp');shutil.copy2(P/'SceneNode.h',H/'src/core/SceneNode.h');env={**os.environ,'PATH':str(base/'toolchain/cygwin32/bin')+os.pathsep+os.environ['PATH']};primary=[[str(sdk/'libexec/gcc/arm-eabi/4.2.1/cc1plus.exe'),'-quiet',*m['compiler_flags'],(H/'src/world/Trail.cpp').as_posix(),'-o',(H/f'{profile}.s').as_posix()],[str(sdk/'bin/arm-eabi-as.exe'),*m['assembler_flags'],'-o',obj.as_posix(),(H/f'{profile}.s').as_posix()]];(H/'primary-commands.json').write_text(json.dumps(primary,indent=2));[subprocess.run(c,cwd=R,env=env,check=True) for c in primary]
assert not (H/f'{profile}.elf').exists();target_hash=hashlib.sha256(obj.read_bytes()).hexdigest();compiled=ElfFile.load(str(obj));retail=ElfFile.load(os.environ['RETAIL_LIBRARY'])
definitions=set(s.name for unit in (compiled,) for s in unit.symbols if s.st_shndx not in (0,0xfff1));allthumb=[]
for s in compiled.symbols:
 if s.st_shndx!=0 or not s.name or s.name in definitions:continue
 if any(t.name==s.name and t.is_func and t.st_shndx not in (0,0xfff1) and t.st_value&1 for t in retail.symbols):allthumb.append(s.name)
extnames=sorted(set(n for n in m['external_thumb_functions']+allthumb if n not in definitions))
hs,bindings=write_harness(retail,compiled,H,());ext=write_bindings(retail,(compiled,),extnames,H)
script=(P/'Trail-complete-context.ld').read_text().replace('INCLUDE retail-symbols.ld','INCLUDE '+json.dumps(bindings.as_posix()));ld=H/'Trail.ld';ld.write_text(script);commands=[];env={**os.environ,'PATH':str(base/'toolchain/cygwin32/bin')+os.pathsep+os.environ['PATH']}
def call(tool,*args):
 cmd=[str(sdk/tool),*[p.as_posix() if isinstance(p,Path) else str(p) for p in args]];commands.append(cmd);(H/'link-commands.json').write_text(json.dumps(commands,indent=2)+'\n');subprocess.run(cmd,cwd=R,env=env,check=True,stdout=sys.stdout,stderr=sys.stderr)
with (H/'link-comparison.log').open('w') as out,contextlib.redirect_stdout(out),contextlib.redirect_stderr(out):
 call('libexec/gcc/arm-eabi/4.2.1/cc1plus.exe','-quiet','-O0','-fpic','-fno-exceptions','-fno-rtti','-fno-unwind-tables','-fno-asynchronous-unwind-tables','-mthumb','-march=armv5te',hs,'-o',H/'retail-got.s')
 call('bin/arm-eabi-as.exe',*m['assembler_flags'],'-o',H/'retail-got.o',H/'retail-got.s');call('bin/arm-eabi-as.exe',*m['assembler_flags'],'-o',H/'external-thumb.o',ext)
 image=H/f'{profile}.elf';call('bin/arm-eabi-ld.exe','-T',ld,'-Map',H/'image.map','-o',image,H/'retail-got.o',obj,H/'external-thumb.o');e=ElfFile.load(str(image));targets=[]
 for n,sec in [('_ZN5Trail6UpdateEv','.trail_update'),('_ZN5Trail10BuildPointEib','.trail_build'),('_ZN5Trail19CreateMeshSceneNodeEv','.trail_mesh')]:
  status=check.check_function(retail,e,n);section=build.check_section(retail,e,sec);s=check.find_symbol(e,n);a=check.find_symbol(retail,n);x=check.symbol_bytes(e,s);y=check.symbol_bytes(retail,a);targets.append(dict(name=n,status=status,section_exact=section,address=hex(s.st_value),size=len(x),native_size=len(y),linked_sha256=hashlib.sha256(x).hexdigest(),differing_offsets=[hex(i) for i in range(max(len(x),len(y))) if x[i:i+1]!=y[i:i+1]]))
 assert [t['status'] for t in targets] == [1,1,1], 'Expected all three pending methods to remain NONMATCHING'
 assert [t['size'] for t in targets] == [320,760,500]
 assert [t['native_size'] for t in targets] == [324,812,500]
 assert [t['address'] for t in targets] == ['0x3485f1','0x348735','0x348cfd']
 assert targets[2]['differing_offsets'] == ['0x46','0x47','0x48','0x49']
 assert targets[2]['linked_sha256'] == '9440c3fd19bec7e47ff2c81c23367ecd245c37fdbadae38411461e4e429493f0'
 nf=ns=0
 for mf in [m]:
  for entry in mf['functions']:
   n,a,c=build.function_selector(entry);assert check.check_function(retail,e,n,address=a,compiled_func=c)==0;nf+=1
  for entry in mf['sections']:
   assert build.check_section(retail,e,entry if isinstance(entry,str) else entry['name'],0 if isinstance(entry,str) else entry['offset']);ns+=1
 assert nf == 16 and ns == 6, 'Expected all original 16 function and 6 support selections'
 assert build.check_section(retail,e,'.rodata.g_trailTexOffsetY')
 r=dict(targets=targets,old_functions_exact=nf,old_regions_exact=ns,strict_link=True,primary_game_frontends=1,failed_primary_frontends=0,additional_game_compiles=0,generated_reference_harness_compiles=1,pending_actual_compiled=True);(H/'linked-result.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r))
assert hashlib.sha256(obj.read_bytes()).hexdigest()==target_hash
assert build.check_section(retail,e,'.rodata.g_trailTexOffsetY')
print(json.dumps({k:v for k,v in r.items() if k!='targets'}));print([(x['name'],x['status'],len(x['differing_offsets'])) for x in targets])
