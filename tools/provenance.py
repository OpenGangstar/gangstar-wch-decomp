"""Provenance classification for the symbols in ``libsanangeles.so``.

The retail library statically links the engine and its third party
dependencies next to Gameloft's own game code.  Telling them apart is the
first thing any contributor needs, because it decides where a decompiled
function belongs:

* **engine code** (Irrlicht, gameswf) and **third party code** (Box2D, zlib,
  libpng, freetype, libjpeg, STLport, libgcc) are upstream open source.  They
  are vendored, not decompiled, and they are excluded from the matching budget.
* **game code** is Gameloft's own and is what this project decompiles.

Classification is driven by the *mangled* symbol name, whose outermost scope is
exact and needs no demangler.  The original source file name that the retail
symbol table records is used as a second, more specific signal where it is
available.
"""

from __future__ import annotations

import re
from dataclasses import dataclass

from .demangle import mangled_scope


@dataclass(frozen=True)
class Library:
    """A statically linked upstream library."""

    key: str
    title: str
    version: str
    upstream: str
    license: str
    #: Outer scopes (from the mangled name) that belong to this library.
    scopes: tuple[str, ...] = ()
    #: Regular expressions matched against plain C symbol names.
    c_patterns: tuple[str, ...] = ()
    #: Regular expressions matched against the original source file name.
    file_patterns: tuple[str, ...] = ()

    @property
    def vendored(self) -> bool:
        """Vendored code is excluded from the decompilation budget."""
        return True


@dataclass(frozen=True)
class Area:
    """A gameplay area of the game, used to organise the source tree."""

    key: str
    title: str
    description: str
    #: Regular expressions matched against the outer scope of a mangled name.
    scope_patterns: tuple[str, ...] = ()
    #: Regular expressions matched against the original source file name.
    file_patterns: tuple[str, ...] = ()


#: The libraries that are statically linked into the retail shared object.
LIBRARIES: tuple[Library, ...] = (
    Library(
        key="irrlicht",
        title="Irrlicht Engine",
        version="1.4.2",
        upstream="https://github.com/irrlicht/irrlicht",
        license="zlib (engine), MIT (SDL build)",
        scopes=("irr",),
        # The retail build stripped the ``STT_FILE`` symbols of the Irrlicht
        # objects, so they inherit the name of the object that precedes them.
        file_patterns=(r"^lib1funcs\.asm$",),
    ),
    Library(
        key="gameswf",
        title="gameswf",
        version="1.0",
        upstream="https://github.com/kennethshackleton/gameswf",
        license="zlib",
        scopes=("gameswf",),
        file_patterns=(r"^gameswf_", r"^as_", r"^tu_", r"^http_helper",),
    ),
    Library(
        key="box2d",
        title="Box2D",
        version="2.0.2",
        upstream="https://github.com/erincatto/box2d",
        license="zlib",
        scopes=("b2",),
        file_patterns=(r"^b2[A-Z]",),
    ),
    Library(
        key="stlport",
        title="STLport",
        version="5.x (Android NDK)",
        upstream="https://github.com/android/platform_external_stlport",
        license="permissive (BSD-like)",
        scopes=("std", "std::allocator", "stlp_priv", "__gnu_cxx", "__cxxabiv1"),
    ),
    Library(
        key="libgcc",
        title="GCC ARM support routines",
        version="4.2.1 (libgcc)",
        upstream="https://gcc.gnu.org/onlinedocs/gcc-4.2.1/gcc/ARM-Options.html",
        license="GPL-3 with GCC Runtime Library Exception",
        c_patterns=(
            r"^__aeabi_",
            r"^__gnu_",
            r"^__div",
            r"^__udiv",
            r"^__mod",
            r"^__umod",
            r"^__mul",
            r"^__float",
            r"^__fix",
            r"^__extend",
            r"^__enable_exceptions",
            r"^__cxa_",
            r"^_Unwind_",
            r"^__register_frame",
            r"^__deregister_frame",
            r"^__sync_",
            r"^__atomic_",
        ),
    ),
    Library(
        key="libpng",
        title="libpng",
        version="1.2.x",
        upstream="http://www.libpng.org/pub/png/libpng.html",
        license="PNG Reference Library License",
        c_patterns=(r"^png_", r"^pnglib_"),
        file_patterns=(r"^png[A-Za-z0-9_]*\.c$",),
    ),
    Library(
        key="freetype",
        title="FreeType",
        version="2.x",
        upstream="https://freetype.org",
        license="FTL / GPL-2",
        c_patterns=(r"^ft_", r"^FT_", r"^TT_", r"^_ft_", r"^tt_", r"^FTC_", r"^ftc_"),
        file_patterns=(
            r"^(af|autofit|bdf|bdfparse|cff|cffparse|cid|cidparse|psaux|psbase|"
            r"pshinter|pshutil|pcf|pfr|pfrparse|raster|sfnt|smooth|truetype|"
            r"ttcmap|ttgload|ttinterp|ttload|ttobjs|ttpost|ttsbit|ttmtx|"
            r"type1|type1cid|type42|winfnt|gxvalid|gxload|otvalid|otload|"
            r"ftbase|ftbbox|ftcache|ftcalc|ftcid|ftdebug|ftgload|ftglyph|ftinit|ftkern|"
            r"ftlcd|ftmm|ftoutln|ftpfr|fts|ftstream|fttrigon|gzip)\.c$",
        ),
    ),
    Library(
        key="libjpeg",
        title="libjpeg",
        version="6b",
        upstream="https://www.ijg.org",
        license="IJG",
        c_patterns=(r"^jpeg_", r"^jinit_", r"^jcopy_", r"^jdiv_", r"^jround_up"),
        file_patterns=(r"^j[a-z0-9]+\.c$",),
    ),
    Library(
        key="zlib",
        title="zlib",
        version="1.2.x",
        upstream="https://zlib.net",
        license="zlib",
        c_patterns=(
            r"^deflate",
            r"^inflate",
            r"^compress",
            r"^uncompress",
            r"^adler32",
            r"^crc32",
            r"^zlib",
            r"^get_crc_table",
            r"^gf2_",
            r"^putShort",
            r"^longest_match",
            r"^fill_window",
            r"^flush_pending",
            r"^syncsearch",
            r"^updatewindow",
            r"^init_block",
            r"^_tr_",
            r"^pqdownheap",
            r"^scan_tree",
            r"^send_tree",
            r"^bi_",
            r"^zcfree",
            r"^zcalloc",
            r"^keymatch",
            r"^read_stdin",
            r"^write_stdout",
            r"^gz(open|read|write|close|gets|putc|getc|seek|tell|rewind|flush|eof|error|direct)",
            r"^zError",
            r"^zlibVersion",
            r"^zlibCompileFlags",
        ),
        file_patterns=(
            r"^(adler32|compress|crc32|deflate|infback|inffast|inflate|inftrees|"
            r"trees|uncompr|zutil|gzclose|gzlib|gzread|gzwrite)\.c$",
        ),
    ),
)

#: Libraries whose code is *not* part of the decompilation budget.
VENDORED_KEYS = frozenset(lib.key for lib in LIBRARIES)

#: The gameplay areas of Gangstar: West Coast Hustle.
#:
#: The patterns match the outermost scope of the mangled name, which is the
#: class a method belongs to, or the name of a free function.
GAME_AREAS: tuple[Area, ...] = (
    Area(
        key="ai",
        title="AI and character behaviour",
        description=(
            "NPC and police behaviour, the behaviour model, state machines and the "
            "player test harness."
        ),
        scope_patterns=(
            r"^NPC",
            r"^CopController",
            r"^CopVehicleController",
            r"^Civ(Agressive|Passive)Controller",
            r"^GuardController",
            r"^VehicleController",
            r"^RadioStationController",
            r"^PlayerTest",
            r"^StateMachine",
            r"^StateBase",
            r"^AIManager",
            r"^gameloft2ai",
            r"^PBehaviorModel",
            r"^PDomain",
            r"^PSManager",
        ),
        file_patterns=(
            r"^NPC",
            r"^CopController",
            r"^CopVehicleController",
            r"^Civ(Agressive|Passive)Controller",
            r"^GuardController",
            r"^VehicleController",
            r"^RadioStationController",
            r"^PlayerTest",
            r"^StateMachine",
            r"^PBehaviorModel",
            r"^PDomain",
            r"^PSManager",
        ),
    ),
    Area(
        key="characters",
        title="Characters",
        description="The character model, its animation and its physical attributes.",
        scope_patterns=(
            r"^Character",
            r"^AnimObject",
            r"^PhysicAttributes",
            r"^Transformation",
            r"^RenderObject",
            r"^Particle",
            r"^ParticleSystem",
            r"^ParticleContext",
        ),
        file_patterns=(
            r"^Character\.",
            r"^AnimObject\.",
            r"^PhysicAttributes\.",
            r"^Transformation\.",
            r"^RenderObject\.",
            r"^Particle\.",
        ),
    ),
    Area(
        key="vehicles",
        title="Vehicles",
        description="Vehicles, their sounds, their wheels and their cameras.",
        scope_patterns=(r"^Vehicle", r"^CarSounds", r"^Wheel", r"^Taxi", r"^Civ"),
        file_patterns=(r"^Vehicle", r"^CarSounds\.", r"^Wheel\.", r"^Taxi"),
    ),
    Area(
        key="combat",
        title="Combat and weapons",
        description="Weapons, projectiles, damage feedback and their managers.",
        scope_patterns=(
            r"^Weapon",
            r"^BulletTraceManager",
            r"^Rocket",
            r"^Explosion",
            r"^Ammo",
            r"^ArmorBar",
            r"^HealthBar",
            r"^HitWarning",
        ),
        file_patterns=(
            r"^Weapon",
            r"^BulletTraceManager\.",
            r"^Rocket\.",
            r"^Explosion\.",
            r"^Ammo\.",
        ),
    ),
    Area(
        key="missions",
        title="Missions",
        description="Main and side missions, checkpoints, rewards and the wanted level.",
        scope_patterns=(
            r"^Mission",
            r"^SideMission",
            r"^Checkpoint",
            r"^WantedLevelManager",
            r"^WantedMeter",
            r"^Revive",
            r"^Reward",
        ),
        file_patterns=(
            r"^Mission",
            r"^SideMission",
            r"^Checkpoint\.",
            r"^WantedLevelManager\.",
            r"^WantedMeter\.",
            r"^Reward\.",
            r"^AmbulanceSideMission\.",
            r"^DeliverySideMission\.",
        ),
    ),
    Area(
        key="scripting",
        title="Scripting",
        description="The scripting runtime, the script manager and the event system.",
        scope_patterns=(r"^Script", r"^EventManager", r"^Event$"),
        file_patterns=(r"^Script", r"^EventManager\."),
    ),
    Area(
        key="world",
        title="World and level",
        description="Level objects, spawn points, scene nodes, paths and streaming.",
        scope_patterns=(
            r"^LevelObject",
            r"^SpawnPoint",
            r"^GameObject",
            r"^SceneNodeManager",
            r"^Trail",
            r"^World",
            r"^Map$",
            r"^Path",
            r"^OctTreeAABB",
            r"^MeshCollision",
            r"^ResStream",
            r"^DataReloaderManager",
        ),
        file_patterns=(
            r"^LevelObject\.",
            r"^SpawnPoint\.",
            r"^GameObject",
            r"^SceneNodeManager\.",
            r"^Trail",
            r"^World",
            r"^Path\.",
            r"^OctTree",
        ),
    ),
    Area(
        key="rendering",
        title="Rendering",
        description="Render effects, billboards, sky boxes, LOD and sprites.",
        scope_patterns=(
            r"^RenderFX",
            r"^GS3DStuff",
            r"^render_handler_irrlicht",
            r"^CustomBillboard",
            r"^CustomSkyBox",
            r"^LODSceneNode",
            r"^RetroEffect",
            r"^S3DVertexComponentArrays",
            r"^ASprite",
            r"^AMTC",
        ),
        file_patterns=(
            r"^Custom(Billboard|SkyBox)",
            r"^LODSceneNode\.",
            r"^GS3DStuff\.",
            r"^RetroEffect\.",
            r"^ASprite",
            r"^PVRTDecompress\.",
            r"^ParticleSystem\.",
        ),
    ),
    Area(
        key="ui",
        title="Menus and user interface",
        description="The menu system, its widgets and the individual game menus.",
        scope_patterns=(
            r"^Menus",
            r"^Widgets",
            r"^MenuManager",
            r"^MenuFX",
            r"^MenuWidget",
            r"^MenuState",
            r"^GS[A-Za-z0-9_]*Menu",
            r"^Shop",
            r"^Cash",
            r"^Preferences",
            r"^AnimatedButton",
            r"^SlideControl",
            r"^SwipeButton",
            r"^ToggleButton",
            r"^VirtualButton",
            r"^Background",
            r"^Message",
            r"^GSUpsell",
            r"^GSBlockingTutorial",
        ),
        file_patterns=(
            r"^Menu",
            r"^GS.*Menu\.",
            r"^Menus",
            r"^Widgets",
            r"^Shop\.",
            r"^Cash\.",
            r"^Preferences\.",
            r"^SlideControl\.",
        ),
    ),
    Area(
        key="hud",
        title="HUD",
        description="Heads up display elements, the minimap, gauges and markers.",
        scope_patterns=(
            r"^CHudManager",
            r"^C(Driving|Walking|Camera|Sniper)Hud",
            r"^HudElement",
            r"^MiniMap",
            r"^SpyGauge",
            r"^Gauge",
            r"^CarBar",
            r"^TargetMarker",
        ),
        file_patterns=(
            r"^CHudManager\.",
            r"^C(Driving|Walking|Camera|Sniper)Hud\.",
            r"^HudElement\.",
            r"^MiniMap\.",
            r"^SpyGauge\.",
            r"^Gauge\.",
            r"^CarBar\.",
            r"^TargetMarker\.",
            r"^HealthBar\.",
            r"^ArmorBar\.",
        ),
    ),
    Area(
        key="input",
        title="Input",
        description="Touch screen, accelerometer and analogue stick handling.",
        scope_patterns=(r"^TouchScreen", r"^AnalogStick", r"^Accelerometer"),
        file_patterns=(
            r"^TouchScreen",
            r"^AnalogStick\.",
            r"^Accelerometer",
            r"^C(OnFoot|Driving)ControlHandler\.",
            r"^SniperControlHandler\.",
            r"^CControlManager\.",
        ),
    ),
    Area(
        key="audio",
        title="Audio",
        description="The sound manager, the decoders, streaming and the radio.",
        scope_patterns=(
            r"^Sound",
            r"^CSound",
            r"^StaticSound",
            r"^StreamingSound",
            r"^Adpcm",
            r"^Radio",
        ),
        file_patterns=(
            r"^Sound",
            r"^CSound",
            r"^StaticSound\.",
            r"^StreamingSound\.",
            r"^Adpcm",
        ),
    ),
    Area(
        key="persistence",
        title="Persistence and file IO",
        description="Save games, preferences, file systems and data streams.",
        scope_patterns=(
            r"^SaveGame",
            r"^Persistence",
            r"^FileManager",
            r"^FileSystem",
            r"^FileStream",
            r"^DataStream",
            r"^BufferStream",
            r"^Stream",
            r"^StringManager",
            r"^Checksum",
        ),
        file_patterns=(
            r"^SaveGame\.",
            r"^Persistence\.",
            r"^File(Manager|System|Stream)\.",
            r"^DataStream\.",
            r"^BufferStream\.",
            r"^Stream",
            r"^StringManager\.",
        ),
    ),
    Area(
        key="app",
        title="Application shell",
        description="The application object, the loading screen and the screen fades.",
        scope_patterns=(
            r"^Application",
            r"^GSLoading",
            r"^GSFade",
            r"^GSGameloftLogo",
            r"^GSIGP",
            r"^GSM",
            r"^GSSplash",
            r"^GSSideMissionMenu",
            r"^GSFailure",
            r"^Win32",
            r"^IPhone",
            r"^Irrlicht",
            r"^app-android",
        ),
        file_patterns=(
            r"^Application\.",
            r"^GSLoading\.",
            r"^GSFade\.",
            r"^GSGameloftLogo\.",
            r"^GSM",
            r"^GSSplash\.",
            r"^GSFailure\.",
            r"^app-android\.",
            r"^jni_",
            r"^IPhone\.",
            r"^MediaPlayerIPhone\.",
            r"^Irrlicht",
        ),
    ),
    Area(
        key="meta",
        title="Meta systems",
        description="Achievements, items, races, factions and other progression systems.",
        scope_patterns=(r"^Achievement", r"^Item", r"^Race", r"^Factions"),
        file_patterns=(r"^Achievements\.", r"^Item\.", r"^Race\.", r"^Factions\."),
    ),
    Area(
        key="core",
        title="Core utilities",
        description="Shared helpers, containers, threading, cameras and logging.",
        scope_patterns=(
            r"^Structs",
            r"^Utils",
            r"^Memory",
            r"^Logs",
            r"^Debug_Log",
            r"^Lock",
            r"^Thread",
            r"^UnitHeap",
            r"^Perfs",
            r"^Float",
            r"^Camera",
            r"^SceneCamera",
            r"^FPSCamera",
            r"^FollowCamera",
            r"^FreeLookCamera",
            r"^LockCamera",
            r"^CControlManager",
            r"^SafeDelete",
        ),
        file_patterns=(
            r"^Structs\.",
            r"^Memory\.",
            r"^Logs\.",
            r"^logger\.",
            r"^utility\.",
            r"^Debug_Log\.",
            r"^Lock\.",
            r"^Thread\.",
            r"^Perfs\.",
            r"^Float\.",
            r"^Camera",
            r"^SceneCamera\.",
            r"^FPSCamera\.",
            r"^FollowCamera\.",
            r"^FreeLookCamera\.",
            r"^LockCamera\.",
        ),
    ),
)

#: The area used when nothing more specific applies.
DEFAULT_AREA = "core"


@dataclass
class Classification:
    """The result of classifying a single symbol."""

    #: ``"game"`` or the key of a vendored library.
    origin: str
    #: The gameplay area for game code, ``None`` for vendored code.
    area: str | None
    #: The outer scope taken from the mangled name.
    scope: str | None
    #: Whether the symbol belongs to a nested (member) name.
    nested: bool
    #: The original source file the symbol was compiled from.
    source_file: str | None = None


def _library_for(scope: str | None, plain_name: str, source_file: str | None) -> Library | None:
    for lib in LIBRARIES:
        if scope is not None and scope in lib.scopes:
            return lib
    for lib in LIBRARIES:
        for pattern in lib.c_patterns:
            if re.search(pattern, plain_name):
                return lib
    if source_file:
        for lib in LIBRARIES:
            for pattern in lib.file_patterns:
                if re.search(pattern, source_file):
                    return lib
    return None


def area_for_file(source_file: str | None) -> str | None:
    """The gameplay area an original source file belongs to."""
    if not source_file:
        return None
    for area in GAME_AREAS:
        for pattern in area.file_patterns:
            if re.search(pattern, source_file):
                return area.key
    return None


def _area_for_scope(scope: str | None) -> str | None:
    if scope is None:
        return None
    for area in GAME_AREAS:
        for pattern in area.scope_patterns:
            if re.search(pattern, scope):
                return area.key
    return None


def classify(name: str, source_file: str | None = None) -> Classification:
    """Classify a symbol by its name and the source file it came from.

    Vendored libraries win over gameplay areas: a symbol in namespace ``irr``
    is engine code even though it might look game related.
    """
    scope, nested = mangled_scope(name)
    library = _library_for(scope, name, source_file)
    if library is not None:
        return Classification(
            origin=library.key,
            area=None,
            scope=scope,
            nested=nested,
            source_file=source_file,
        )
    area = area_for_file(source_file) or _area_for_scope(scope) or DEFAULT_AREA
    return Classification(
        origin="game",
        area=area,
        scope=scope,
        nested=nested,
        source_file=source_file,
    )


def area_title(key: str) -> str:
    for area in GAME_AREAS:
        if area.key == key:
            return area.title
    return key


def library(key: str) -> Library | None:
    for lib in LIBRARIES:
        if lib.key == key:
            return lib
    return None
