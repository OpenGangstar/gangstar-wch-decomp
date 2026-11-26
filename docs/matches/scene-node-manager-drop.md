# SceneNodeManager::drop exact match

`SceneNodeManager::drop(int, irr::scene::ISceneNode const*)` matches all 210
retail bytes at Thumb address `0x003219cd`, including relocations. The other
sections of `SceneNodeManager.cpp` are unchanged.

## Source form

The function searches a pool's active nodes backwards for the given scene
node. When it finds it, it marks the node available, stamps the release time,
swaps the node to the boundary of the active range and decrements the active
count. Details that the retail bytes require, each commented in the source:

- **Block order.** The found block comes first in the source, and the search
  is entered by `goto start`. That gives reload's block walk retail's
  register rotation, so the pool loads use `r1`.
- **Second index.** The node accesses use a second index `j` that always equals
  `i`. Reassigning it in the latch (`--i, j = k--`) makes ivopts build its
  offset IVs from `size - 2` while `i` keeps its own start value, which
  reproduces retail's preheader and loop.
