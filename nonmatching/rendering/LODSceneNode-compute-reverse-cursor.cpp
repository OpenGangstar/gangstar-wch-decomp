// UNMATCHED: 302 function / 304 input bytes; native requires 306 / 308.
// Historical full-TU method fragment; no native-address link or matching credit.
void LODSceneNode::computeLODLevel()
{
    const irr::core::vector3d<float> cameraPosition = sceneManager->getActiveCamera()->getPosition();
    const float distanceSquared = cameraPosition.getDistanceFromSQ(levels[0].sceneNode->getAbsolutePosition());
    if (distanceSquared > maxDistanceSquared) {
        if (lodLevel != -1) {
            levels[lodLevel].sceneNode->setVisible(false);
            lodLevel = -1;
        }
        return;
    }

    int index = levels.size() - 1;
    if (index < 0)
        return;
    for (SLODLevel* cursor = &levels[index];; --cursor, --index) {
        if (distanceSquared > cursor->distanceSquared) {
            if (lodLevel != index) {
                if (lodLevel != -1)
                    levels[lodLevel].sceneNode->setVisible(false);
                lodLevel = index;
                levels[lodLevel].sceneNode->setVisible(true);
            }
            return;
        }
        if (index == 0)
            return;
    }
}
