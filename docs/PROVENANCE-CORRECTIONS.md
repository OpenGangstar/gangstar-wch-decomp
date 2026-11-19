# Catalogue provenance corrections

The maintainer approved correcting provenance while retaining every function
from the original project in the catalogue. No function, source file or
assembly marker is removed by this correction.

## Complete accounting

The authoritative [function table](../config/functions.tsv) still contains all
17,703 retail function entries. Every original address, symbol, size, source
attribution, demangled name and pending/matched status is retained. The source
manifest still contains 689 entries and the symbol table still has 70,867 rows.

The original 4,661-entry game classification is fully accounted for as:

| Classification | Functions | Catalogue code bytes |
| --- | ---: | ---: |
| Corrected game target | 4,550 | 561,716 |
| FreeType entries listed below | 103 | 13,054 |
| gameswf base entries listed below | 8 | 494 |
| Original classification total | 4,661 | 575,264 |

All 111 reclassified functions remain **pending**. Classification alone
preserves every pending status. Its frozen audit baseline had 401 pending
entries: 290 game, 103 FreeType and 8 gameswf base entries. Separate verified
constructor work subsequently matches two game aliases; it does not alter any
of these 111 dependency statuses. Existing dependency assembly markers remain
at their original paths; vendor lookup preserves their status,
including the host filesystem's case rules. No source or verification-profile
input changes.

## Provenance evidence

FreeType's official historical sources identify
[`ftcache.c`](https://github.com/freetype/freetype/blob/VER-2-3-7/src/cache/ftcache.c)
as a cache compilation wrapper and
[`type1cid.c`](https://github.com/freetype/freetype/blob/VER-2-3-7/src/cid/type1cid.c)
as the CID driver wrapper. All 95 retail names occur in their included source
files. The historical tag establishes provenance, not the exact retail version
or a new byte match. The missing exact filenames and `FTC_`/`ftc_` prefixes
previously made every function in both objects fall through to game/core;
majority inference could not recover from unanimous incorrect initial votes.

The classifier adds those two exact filenames and anchored prefixes. It does
not classify arbitrary `cid_`, `parse_` or similar game names as FreeType.

## Historical FreeType cache/CID reporting effect

| Measure | Before correction | After correction |
| --- | ---: | ---: |
| Matched function entries | 4,260 | 4,260 |
| Matched code bytes | 342,294 | 342,294 |
| Fully linked code bytes | 111,046 | 111,046 |
| Matched / fuzzy percentage | 59.50% | 60.77% |
| Fully linked percentage | 19.30% | 19.71% |
| Complete / total report units | 124 / 208 | 124 / 206 |

**Zero matched bytes and zero fully linked bytes are added.** The percentage
change comes only from correcting the denominator. All 206 retained report
units are unchanged; the two excluded units contain only pending FreeType
entries. ByteMatch continues to report game progress, while the full catalogue
and the following table retain the dependency accounting.

Historical match notes and CI reports retain their original classification
basis. This correction does not revise their recorded native comparison output.

## Every reclassified FreeType function

All entries below remain in the full function table with origin `freetype`,
area `-` and status `pending`; their original classification was `game/core`.

| Native address | Symbol | Bytes | Source file | Status |
| --- | --- | ---: | --- | --- |
| `0x00364bf5` | `FTC_MruNode_Prepend` | 28 | `ftcache.c` | pending |
| `0x00364c11` | `FTC_MruNode_Up` | 32 | `ftcache.c` | pending |
| `0x00364c31` | `FTC_MruNode_Remove` | 32 | `ftcache.c` | pending |
| `0x00364c51` | `FTC_MruList_Init` | 30 | `ftcache.c` | pending |
| `0x00364c71` | `ftc_size_node_compare_faceid` | 18 | `ftcache.c` | pending |
| `0x00364c85` | `ftc_face_node_compare` | 18 | `ftcache.c` | pending |
| `0x00364c99` | `FTC_Node_Unref` | 22 | `ftcache.c` | pending |
| `0x00364cb1` | `ftc_node_mru_unlink` | 24 | `ftcache.c` | pending |
| `0x00364cc9` | `ftc_cmap_node_weight` | 4 | `ftcache.c` | pending |
| `0x00364ccd` | `ftc_cmap_node_compare` | 40 | `ftcache.c` | pending |
| `0x00364cf5` | `ftc_cmap_node_remove_faceid` | 18 | `ftcache.c` | pending |
| `0x00364d09` | `FTC_GNode_Init` | 12 | `ftcache.c` | pending |
| `0x00364d15` | `ftc_gnode_compare` | 36 | `ftcache.c` | pending |
| `0x00364d39` | `FTC_GNode_Compare` | 14 | `ftcache.c` | pending |
| `0x00364d49` | `ftc_inode_weight` | 72 | `ftcache.c` | pending |
| `0x00364d91` | `ftc_snode_weight` | 56 | `ftcache.c` | pending |
| `0x00364dc9` | `ftc_basic_family_compare` | 106 | `ftcache.c` | pending |
| `0x00364e35` | `ftc_basic_family_init` | 34 | `ftcache.c` | pending |
| `0x00364e59` | `ftc_image_type_from_old_desc` | 76 | `ftcache.c` | pending |
| `0x00364ea5` | `ftc_cmap_node_free` | 18 | `ftcache.c` | pending |
| `0x00364eb9` | `FTC_MruList_Remove` | 42 | `ftcache.c` | pending |
| `0x00364ee5` | `FTC_GNode_UnselectFamily` | 40 | `ftcache.c` | pending |
| `0x00364f0d` | `ftc_basic_gnode_compare_faceid` | 26 | `ftcache.c` | pending |
| `0x00364f29` | `FTC_GNode_Done` | 16 | `ftcache.c` | pending |
| `0x00364f39` | `ftc_snode_free` | 64 | `ftcache.c` | pending |
| `0x00364f79` | `FTC_MruList_RemoveSelection` | 98 | `ftcache.c` | pending |
| `0x00364fdd` | `FTC_MruList_Reset` | 24 | `ftcache.c` | pending |
| `0x00364ff5` | `FTC_Manager_Reset` | 24 | `ftcache.c` | pending |
| `0x0036500d` | `FTC_MruList_Done` | 12 | `ftcache.c` | pending |
| `0x00365019` | `FTC_Manager_Done` | 102 | `ftcache.c` | pending |
| `0x00365081` | `ftc_cmap_node_new` | 78 | `ftcache.c` | pending |
| `0x003650d1` | `FTC_Manager_RegisterCache` | 162 | `ftcache.c` | pending |
| `0x00365175` | `FTC_GCache_New` | 12 | `ftcache.c` | pending |
| `0x00365181` | `FTC_SBitCache_New` | 28 | `ftcache.c` | pending |
| `0x0036519d` | `FTC_SBit_Cache_New` | 12 | `ftcache.c` | pending |
| `0x003651a9` | `FTC_ImageCache_New` | 28 | `ftcache.c` | pending |
| `0x003651c5` | `FTC_Image_Cache_New` | 12 | `ftcache.c` | pending |
| `0x003651d1` | `FTC_CMapCache_New` | 28 | `ftcache.c` | pending |
| `0x003651ed` | `FTC_Manager_New` | 176 | `ftcache.c` | pending |
| `0x0036529d` | `FTC_MruList_New` | 214 | `ftcache.c` | pending |
| `0x00365375` | `FTC_Manager_LookupFace` | 122 | `ftcache.c` | pending |
| `0x003653f1` | `ftc_basic_family_get_count` | 32 | `ftcache.c` | pending |
| `0x00365411` | `FTC_Manager_Lookup_Face` | 12 | `ftcache.c` | pending |
| `0x0036541d` | `FTC_Manager_LookupSize` | 124 | `ftcache.c` | pending |
| `0x00365499` | `FTC_Manager_Lookup_Size` | 70 | `ftcache.c` | pending |
| `0x003654e1` | `ftc_snode_load` | 352 | `ftcache.c` | pending |
| `0x00365641` | `ftc_snode_new` | 142 | `ftcache.c` | pending |
| `0x003656d1` | `ftc_basic_family_load_bitmap` | 56 | `ftcache.c` | pending |
| `0x00365709` | `ftc_inode_free` | 40 | `ftcache.c` | pending |
| `0x00365731` | `ftc_inode_new` | 102 | `ftcache.c` | pending |
| `0x00365799` | `ftc_basic_family_load_glyph` | 92 | `ftcache.c` | pending |
| `0x003657f5` | `ftc_cache_init` | 42 | `ftcache.c` | pending |
| `0x00365821` | `ftc_gcache_init` | 42 | `ftcache.c` | pending |
| `0x0036584d` | `ftc_cache_resize` | 254 | `ftcache.c` | pending |
| `0x0036594d` | `FTC_Manager_RemoveFaceID` | 218 | `ftcache.c` | pending |
| `0x00365a29` | `ftc_cache_done` | 162 | `ftcache.c` | pending |
| `0x00365acd` | `ftc_gcache_done` | 18 | `ftcache.c` | pending |
| `0x00365ae1` | `ftc_node_destroy` | 118 | `ftcache.c` | pending |
| `0x00365b59` | `FTC_Manager_FlushN` | 92 | `ftcache.c` | pending |
| `0x00365bb5` | `ftc_snode_compare` | 182 | `ftcache.c` | pending |
| `0x00365c6d` | `FTC_SNode_Compare` | 12 | `ftcache.c` | pending |
| `0x00365c79` | `FTC_Cache_NewNode` | 308 | `ftcache.c` | pending |
| `0x00365dad` | `FTC_SBitCache_LookupScaler` | 472 | `ftcache.c` | pending |
| `0x00365f85` | `FTC_SBitCache_Lookup` | 480 | `ftcache.c` | pending |
| `0x00366165` | `FTC_SBit_Cache_Lookup` | 46 | `ftcache.c` | pending |
| `0x00366195` | `FTC_ImageCache_LookupScaler` | 460 | `ftcache.c` | pending |
| `0x00366361` | `FTC_ImageCache_Lookup` | 464 | `ftcache.c` | pending |
| `0x00366531` | `FTC_Image_Cache_Lookup` | 46 | `ftcache.c` | pending |
| `0x00366561` | `ftc_face_node_done` | 52 | `ftcache.c` | pending |
| `0x00366595` | `ftc_face_node_init` | 48 | `ftcache.c` | pending |
| `0x003665c5` | `ftc_size_node_done` | 18 | `ftcache.c` | pending |
| `0x003665d9` | `ftc_size_node_compare` | 98 | `ftcache.c` | pending |
| `0x0036663d` | `ftc_scaler_lookup_size` | 110 | `ftcache.c` | pending |
| `0x003666ad` | `ftc_size_node_reset` | 46 | `ftcache.c` | pending |
| `0x003666dd` | `ftc_size_node_init` | 34 | `ftcache.c` | pending |
| `0x00366701` | `FTC_CMapCache_Lookup` | 428 | `ftcache.c` | pending |
| `0x00386969` | `cid_get_offset` | 56 | `type1cid.c` | pending |
| `0x003869a1` | `cid_slot_done` | 10 | `type1cid.c` | pending |
| `0x003869ad` | `cid_driver_init` | 4 | `type1cid.c` | pending |
| `0x003869b1` | `cid_driver_done` | 2 | `type1cid.c` | pending |
| `0x003869b5` | `cid_get_postscript_name` | 22 | `type1cid.c` | pending |
| `0x003869cd` | `cid_ps_get_font_info` | 20 | `type1cid.c` | pending |
| `0x003869e1` | `cid_get_ros` | 38 | `type1cid.c` | pending |
| `0x00386a09` | `cid_size_get_globals_funcs` | 56 | `type1cid.c` | pending |
| `0x00386a41` | `cid_size_request` | 44 | `type1cid.c` | pending |
| `0x00386a6d` | `cid_size_init` | 58 | `type1cid.c` | pending |
| `0x00386aa9` | `cid_size_done` | 32 | `type1cid.c` | pending |
| `0x00386ac9` | `cid_slot_init` | 60 | `type1cid.c` | pending |
| `0x00386b05` | `cid_load_glyph` | 424 | `type1cid.c` | pending |
| `0x00386cad` | `cid_slot_load_glyph` | 644 | `type1cid.c` | pending |
| `0x00386f31` | `cid_face_done` | 264 | `type1cid.c` | pending |
| `0x00387039` | `parse_font_matrix` | 176 | `type1cid.c` | pending |
| `0x003870e9` | `cid_face_init` | 2658 | `type1cid.c` | pending |
| `0x00387b4d` | `parse_fd_array` | 116 | `type1cid.c` | pending |
| `0x00387bc1` | `cid_get_interface` | 28 | `type1cid.c` | pending |


## gameswf base utility correction

The subsequent eight-entry correction recognizes two actual gameswf base
translation units, rather than treating a generic filename as proof.
The pinned historical source at commit
`b29f4cc842244eb8e1daf3b7c4d8ce2693c04853` contains all six retail logger
names and signatures in
[`base/logger.cpp`](https://github.com/weihuoya/gameswf/blob/b29f4cc842244eb8e1daf3b7c4d8ce2693c04853/tu-testbed/base/logger.cpp),
with their callback type independently declared in
[`logger.h`](https://github.com/weihuoya/gameswf/blob/b29f4cc842244eb8e1daf3b7c4d8ce2693c04853/tu-testbed/base/logger.h).
The same source identifies both the local `reverse_scan` helper and
`file_util::get_extension` in
[`base/file_util.cpp`](https://github.com/weihuoya/gameswf/blob/b29f4cc842244eb8e1daf3b7c4d8ce2693c04853/tu-testbed/base/file_util.cpp).
These files retain their original public-domain notices. This identifies
source provenance, not an exact retail revision or a new byte match.

Only the exact `logger.cpp` and `file_util.cpp` source filenames are added to
classification. Unsourced generic logger functions and `reverse_scan` remain
unchanged. `PVRTDecompress.cpp` is not part of this correction.

| Measure | Before gameswf correction | After gameswf correction |
| --- | ---: | ---: |
| Game functions / code bytes | 4,566 / 563,270 | 4,558 / 562,776 |
| Matched function entries | 4,260 | 4,260 |
| Matched code bytes | 342,294 | 342,294 |
| Fully linked code bytes | 111,046 | 111,046 |
| Matched / fuzzy percentage | 60.77% | 60.82% |
| Fully linked percentage | 19.71% | 19.73% |
| Complete / total report units | 124 / 206 | 124 / 204 |

Zero matched or fully linked bytes are added. All 204 retained report units
remain unchanged. The two excluded units contain only these pending gameswf
entries. All original function identities and pending/matched statuses remain
in the full catalogue. At that stage, the original 4,661-entry classification
was exactly 4,558 game + 95 FreeType + 8 gameswf entries. The earlier reporting table
above records the historical FreeType-only correction, not the latest totals.

### Every reclassified gameswf base function

Each row changes only origin `game` to `gameswf` and area `core` to `-`.
Addresses, symbols, sizes, source attribution and status remain unchanged.

| Native address | Symbol | Bytes | Source file | Before origin / area / status | After origin / area / status |
| --- | --- | ---: | --- | --- | --- |
| `0x0039110d` | `_Z12reverse_scanPKcS0_c` | 34 | `file_util.cpp` | game / core / pending | gameswf / - / pending |
| `0x00391131` | `_ZN9file_util13get_extensionEPKc` | 52 | `file_util.cpp` | game / core / pending | gameswf / - / pending |
| `0x0039324d` | `_ZN6logger21register_log_callbackEPFvNS_8log_typeEPKcE` | 20 | `logger.cpp` | game / core / pending | gameswf / - / pending |
| `0x00393261` | `_ZN6logger25set_standard_log_handlersEv` | 28 | `logger.cpp` | game / core / pending | gameswf / - / pending |
| `0x0039327d` | `_ZN6logger5errorEPKcz` | 100 | `logger.cpp` | game / core / pending | gameswf / - / pending |
| `0x003932e1` | `_ZN6logger3msgEPKcz` | 100 | `logger.cpp` | game / core / pending | gameswf / - / pending |
| `0x00393345` | `_ZN6logger4vmsgEPKcz` | 116 | `logger.cpp` | game / core / pending | gameswf / - / pending |
| `0x003933b9` | `_ZN6logger15standard_loggerENS_8log_typeEPKc` | 44 | `logger.cpp` | game / core / pending | gameswf / - / pending |


## FreeType PSNames module correction

FreeType's pinned official
[`src/psnames/psmodule.c`](https://github.com/freetype/freetype/blob/VER-2-3-7/src/psnames/psmodule.c)
defines all eight pending functions below. Its included
[`pstables.h`](https://github.com/freetype/freetype/blob/VER-2-3-7/src/psnames/pstables.h)
defines the existing `ft_get_adobe_glyph_index` helper. Official
[`rules.mk`](https://github.com/freetype/freetype/blob/VER-2-3-7/src/psnames/rules.mk)
selects `psmodule.c` for both single-object and multi-object PSNames builds.
This identifies the source family, not the exact retail FreeType version.

The existing `ft_` rule correctly identifies the 280-byte helper, but the
other eight symbols previously produced game votes. Their majority prevented
object inference from recognizing the rest. Only the exact `psmodule.c`
filename is added; generic `ps_` and comparator names remain unchanged.

All nine entries remain in the catalogue. The already classified 280-byte
helper at `0x0037525d` retains origin `freetype`, area `-`, status `matched`,
and every other field unchanged. Its existing catalogue status adds no new
vendor verification or byte credit. Only eight pending entries change origin.
The source manifest already identified this file as FreeType from its first
function, so its 689 rows and the current 182 game-file count do not change.

| Measure | Before PSNames correction | After PSNames correction |
| --- | ---: | ---: |
| Game functions / code bytes | 4,558 / 562,776 | 4,550 / 561,716 |
| Matched function entries | 4,260 | 4,260 |
| Matched code bytes | 342,294 | 342,294 |
| Fully linked code bytes | 111,046 | 111,046 |
| Matched / fuzzy percentage | 60.82% | 60.94% |
| Fully linked percentage | 19.73% | 19.77% |
| Complete / total report units | 124 / 204 | 124 / 203 |

Zero matched or linked bytes are added. All 203 retained report units are
unchanged; the excluded PSNames game fragment contained only pending entries.
The earlier reporting tables record their respective historical corrections.
The original target remains fully accounted for: 4,550 game + 103 FreeType +
8 gameswf = 4,661 functions, and 561,716 + 13,054 + 494 = 575,264 bytes.
No function identity, status, source byte, match profile or assembly marker
is removed or changed. `PVRTDecompress.cpp` remains outside these corrections.

### Every reclassified PSNames function

Each row changes only origin and area. Status and all identity fields remain.

| Native address | Symbol | Bytes | Source file | Before origin / area / status | After origin / area / status |
| --- | --- | ---: | --- | --- | --- |
| `0x00375375` | `ps_unicode_value` | 224 | `psmodule.c` | game / core / pending | freetype / - / pending |
| `0x00375455` | `compare_uni_maps` | 32 | `psmodule.c` | game / core / pending | freetype / - / pending |
| `0x00375475` | `ps_unicodes_char_index` | 96 | `psmodule.c` | game / core / pending | freetype / - / pending |
| `0x003754d5` | `ps_unicodes_char_next` | 148 | `psmodule.c` | game / core / pending | freetype / - / pending |
| `0x00375569` | `ps_get_macintosh_name` | 48 | `psmodule.c` | game / core / pending | freetype / - / pending |
| `0x00375599` | `ps_get_standard_strings` | 48 | `psmodule.c` | game / core / pending | freetype / - / pending |
| `0x003755c9` | `ps_unicodes_init` | 436 | `psmodule.c` | game / core / pending | freetype / - / pending |
| `0x0037577d` | `psnames_get_service` | 28 | `psmodule.c` | game / core / pending | freetype / - / pending |

## Current report after separate constructor matching

The independently verified [Application constructor](matches/application-constructor.md)
adds two genuine matched alias entries for one physical 148-byte body. That
separate source change adds 296 catalogue matched bytes; these provenance
corrections add none. The combined current report is:

```text
ByteMatch: 4262/4550 functions; 342590/561716 bytes (60.99%); Fully Linked 111046/561716 bytes (19.77%, 124/203 units); Fuzzy Matched 60.99%
```

The sixteen additional dependency corrections preserve all 17,703 identities
and every status from the post-constructor baseline. All 203 retained report
units are identical to that baseline. The three removed game-report fragments
contain only pending vendor functions. All 1,321 source, assembly, match-profile,
linker and nonmatching input hashes remain unchanged by classification. The
existing 280-byte FreeType helper in psmodule.c is unchanged and receives no
new match credit.
