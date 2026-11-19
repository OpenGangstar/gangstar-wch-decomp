# MenuState::Hide()

The 104-byte Thumb function at `0x002e8655` matches the retail library exactly.
It caches the menu animation setting, conditionally hides visible auto-hide
widgets when depth equals one, then resets depth to zero.

The implementation reuses the existing typed
`MenuManager::getWidgetByIndex(int) const` rather than the provisional raw views
in the historical candidates. The getter also occurs in already matched code.
The old 104-byte candidate differed by two bytes expressing an equivalent signed
comparison. Reusing the authentic interface reproduces the original comparison
without register constraints, branch hints, compiler flags or output editing.
No existing function body or header changes.

```text
OK  _ZN9MenuState4HideEv  0x002e8655  104 bytes
OK SECTION .menu_state_hide  0x002e8654  104 bytes
OK SECTION .menu_anims_enabled  0x002e3f84  12 bytes
```

Function SHA-256:
`bd261775ebc6c4499dcdac11ec76e3806e66b6062d1fd6c9367159c53e531279`.
The owning profile keeps all 232 previous functions and 87 previous
section/region checks. Its complete dependency build passes 929 comparisons:
610 functions, 314 sections and five regions. The object adds only the new
104-byte function section; every old allocated section remains byte-identical.
No helpers, data, vtables or masked compiled definitions are introduced.

The actual compiled `MenuManager::areAnimsEnabled` dependency is retained at
`0x002e3f84` and explicitly checked as a 12-byte function and section. Initial
private setup rejected conflicting retail imports, then exposed this discarded
callee. The final setup retains its real definition and the already retained
`IsVisible` definition; it does not substitute absolute imports. The source
remained unchanged throughout these setup corrections.

The final combined current-root verification passes all 190 profiles and
10,539 comparisons: 5,266 functions, 5,092 sections and 181 regions.
All previously configured comparisons are retained. The matched-function
catalogue is regenerated only after this successful gate. These sources remain
incomplete overall and receive no additional Fully Linked credit.
