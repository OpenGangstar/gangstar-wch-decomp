# Sprite geometry and markers

The geometry helpers map flip flags to a transform and test a point
against inclusive rectangle bounds. Marker lookups scan the frame's
modules, skip nested frames, and count or emit the coordinates of
modules of marker type 5.

```text
OK  _ZN7ASprite21GetTransformFromFlagsEj  0x003496c5  30 bytes
OK  _ZNK3RctIiE14isIntersectingEii  0x003497b9  42 bytes
OK  _ZNK7ASprite15GetFrameMarkersEiPi  0x00349c95  110 bytes
OK  _ZNK7ASprite23GetNumberOfFrameMarkersEi  0x00349d05  90 bytes
```
