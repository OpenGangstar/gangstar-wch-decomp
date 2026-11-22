void PlayerTest::switchContext(eContext next,bool save)
{
    int previous=contextWord;
    if(previous==next)return;
    ScriptManager* scripts=ScriptManager::getInstance();
    scripts->freezeRunningScripts(0,context);
    contextWord=next;
    ScriptManager::getInstance()->unlockFrozenScripts();
    Application* app=Application::GetInstance();
    irr::core::vector3d<float> position;
    irr::core::quaternion rotation;
    if(sceneNode) {
        position=sceneNode->getPosition();
        rotation=sceneNode->getRotation();
    }
    WantedLevelManager::getInstance()->resetWantedLevel();
    const int nodeIndex=contextWord;
    Character* character=this;
    PlayerContextStorageView& savedContexts=*reinterpret_cast<PlayerContextStorageView*>(inactiveContextNodes);
    if(savedContexts.nodes[contextWord]) {
        sceneNode=savedContexts.nodes[contextWord];
        *reinterpret_cast<Character::AnimationInfo*>(&unknown164Pointer)=savedContexts.animations[contextWord];
    } else {
        const char* filename=0;
        if(contextWord==Context0)filename=retail_player_context_text::normal;
        else if(contextWord==Context1)filename=retail_player_context_text::jail;
        sceneNode=irr::collada::CColladaDatabase::constructScene(filename,&irr::collada::CColladaDatabase::DefaultFactory);
        savedContexts.nodes[nodeIndex]=sceneNode;
        Character::AnimationInfo& animation=*reinterpret_cast<Character::AnimationInfo*>(&unknown164Pointer);
        character->bindAnimation(retail_player_context_text::bip,animation,0);
        savedContexts.animations[contextWord]=animation;
        GS3DStuff::SetMaterialFlag(sceneNode,irr::video::MaterialFlag16,true);
        GS3DStuff::SetMaterialFlag(sceneNode,irr::video::MaterialFlag2,true);
        GS3DStuff::SetMaterialFlag(sceneNode,irr::video::MaterialFlag4,true);
        GS3DStuff::SetMaterialFiltering(sceneNode,false,true);
        GS3DStuff::SetColor(sceneNode,irr::video::SColor(255,63,63,63),GS3DStuff::Color3);
        GS3DStuff::SetColor(sceneNode,irr::video::SColor(255,255,255,255),GS3DStuff::Color0);
        GS3DStuff::SetColor(sceneNode,irr::video::SColor(255,255,255,255),GS3DStuff::Color1);
        GS3DStuff::SetColor(sceneNode,irr::video::SColor(255,229,229,229),GS3DStuff::Color2);
        GS3DStuff::SetCulling(sceneNode,static_cast<irr::scene::E_CULLING_TYPE>(2));
        GS3DStuff::CleanNode(sceneNode);
        irr::IrrlichtDevice* device=app->GetDevice();
        device->getVideoDriver();
        device->getSceneManager()->getRootSceneNode()->addChild(sceneNode);
    }
    sceneNode->setRotation(rotation);
    sceneNode->setPosition(position);
    if(collisionBody->data) ::operator delete(collisionBody->data);
    collisionBody->data=new Box2DUserInfo(character,GS3DStuff::FindAMesh(sceneNode));
    irr::core::vector3d<float> direction=character->GetFront();
    facing.x=direction.X;facing.y=direction.Y;facing.z=direction.Z;
    character->setAnimation(165,1.0f,false,false,false);
    character->resetCollisions();
    app->GetHudManager()->switchWeapon(0);
    app->GetHudManager()->showCash(contextWord==Context0);
    irr::video::ITexture* sky=contextWord==Context1?0:GS3DStuff::getSkyBoxTexture();
    if(sky!=GS3DStuff::getSkyBox()->getMaterial(0).layers[0].texture) {
        GS3DStuff::setSkyColor(contextWord==Context1);
        GS3DStuff::getSkyBox()->setMaterialTexture(0,sky);
        GS3DStuff::getSkyBox()->notifyMaterialChanged();
    }
    Map::getInstance()->setMap(static_cast<Map::eMapType>(contextWord==Context1));
    app->GetHudManager()->retroEffect(contextWord==Context1);
    if(save && previous!=AnyContext) {
        SaveGame game;
        game.SampleAndSave(SaveGame::GetDefaultFilename());
    }
}
