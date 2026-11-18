# Splash-state cleanup

GSSplash::dtor is the StateBase lifecycle callback, separate from the C++
destructor. It clears touch input, resets text slots 14, 13, and 1 in that
order, then pops the menu with true. Each operation preserves its original
singleton lookup. The reconstruction reuses the existing Application,
TouchScreenBase and MenuManager interfaces and the existing C-linkage symbol
for MenuManager::pop. No shared header or object layout changes are needed.

The integrated command `python tools/build.py state-hooks-gssplash` exited 0;
all existing functions, state-table sections, and GOT comparisons passed.

```text
OK  _ZN8GSSplash4dtorEPK12StateMachine  0x002e3791  70 bytes
```

The state constructor clears touch input, shows text, pushes Splash, records the
unsigned timer word at offset 4, and sets the original splash flag. The update
callback preserves sound initialization, video completion, blinking text, touch
rectangle handling, music stop, and the existing weak main-menu transition.
Caching the touch interface before constructing the local rectangle preserves
the original evaluation order. All three lifecycle callbacks compare together;
existing C++ constructors, destructors, vtable, and startup data remain exact.

```text
OK  _ZN8GSSplash4ctorEPK12StateMachine  0x002e37d9  88 bytes
OK  _ZN8GSSplash6updateEP12StateMachine  0x002e3831  212 bytes
OK SECTION .splash_name  0x00418710  8 bytes
```

The final `python tools/build.py --all` run exited 0 with 9,662 retail comparisons.
