# Vehicle cleanup callbacks

The SDK string cleanup reuses the existing local string storage. The other
callbacks pass the retail AI manager, game factory, and car factory singleton
addresses to their destructors. The two factory calls use their retail weak
GOT entries. The AI manager call uses the retail Thumb symbol binding.

```text
OK  __tcf_4  0x00308015  48 bytes
OK  __tcf_3  0x00308211  28 bytes
OK  __tcf_1  0x0030b5dd  36 bytes
OK  __tcf_2  0x0030b625  36 bytes
```

The separate 652-byte gear-profile initializer differed in the placement of
stores among the AI initialization instructions. Its first candidate first
differed at offset 0x9a. The initializer and its 20-byte wrapper remain in
assembly pending verification of the complete startup path.
