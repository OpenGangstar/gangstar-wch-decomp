# Vehicle.cpp static initializer exact match

The local `__static_initialization_and_destruction_0(int, int)` of
`Vehicle.cpp` matches all 652 retail bytes at Thumb address `0x0030b311`,
including relocations. The existing `_GLOBAL__I_` wrapper calls it.

## What it initializes

In definition order:

1. `irr::scene::quake3::irrEmptyStringc`. Its fields are zeroed, it is assigned
   from the shared empty startup text through the weak `stringc::operator=`, and
   `__tcf_4` is registered with `__aeabi_atexit`.
2. `irr::ps::vHalf`, set to `{0.5f, 0.5f, 0.5f}`.
3. The ten `gameloft::ai` transition lists, each a `{table, count}` pair.
4. The four `gameloft::vehicle::gear_profiles` (`car0`, `car1`, `car2`,
   `truck1`), followed by four block copies into `profiles`.

## Source form

- **Storage.** All objects use struct-typed POD storage written by direct member
  stores. Placement new evaluates its arguments up front, which raises register
  pressure and costs 24 bytes. Struct-typed destinations give each store a
  declaration-based memory expression, so the scheduler interleaves the stores
  the way retail does.
- **Tables.** The transition tables and gear arrays stay in the retail image.
  They are hidden externs, and the linker script assigns their retail
  addresses. The AI tables need complete array types: with an incomplete extern
  array, each table address is expanded before its destination address, which
  swaps `r2` and `r3`.
- **Constant.** Retail stores `0x3ed91688`, one ulp above the nearest float to
  0.424, written as `0.42400002f`.
