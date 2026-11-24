// UNMATCHED: 1220 function bytes versus 1220 native.
// This is a source fragment for the documented historical private fixture.
void ScriptManager::update(int elapsed)
{
    if (paused)
        return;

    MenuManager* menu = MenuManager::getInstance();
    if (vehicleNameAnimation->animation != -1) {
        vehicleNameTimer -= elapsed;
        if (!(vehicleNameTimer > 0 && !isInCinematic() && s_fadeIntensity <= 0)) {
            menu->setText(static_cast<MenuManager::eText>(0), -1, 0);
            vehicleNameTimer = 0;
            vehicleNameAnimation->SetAnim(-1);
        } else if (!vehicleNameAnimation->IsAnimOver()) {
            vehicleNameAnimation->Update(elapsed);
        } else if (menu->getTextId(static_cast<MenuManager::eText>(0)) == -1) {
            Vehicle* vehicle = PlayerTest::GetPlayer()->getVehicle();
            if (vehicle)
                menu->setText(static_cast<MenuManager::eText>(0),
                    *reinterpret_cast<const int*>(reinterpret_cast<const char*>(vehicle) + 424), 0);
        }
    }

    Application* app = Application::GetInstance();
    if (isInCinematic()) {
        bIsInCutscene = true;
        skipButton->update(0.0);
        if (app->GetTouchScreen()->getTouchIDInitiatedInRegion(
            reinterpret_cast<const irr::core::rect<float>&>(
                static_cast<const HudTouchRegion&>(skipButton->getTouchRegion()))) == -1)
            checkScreenPress();
    }

    if (cinematicState == 1) {
        cinematicBars->SetAnim(unknown88, 0);
        if (cinematicBars->IsAnimOver())
            setState(State2);
    } else if (cinematicState == 3) {
        cinematicBars->SetAnim(unknown84, 0);
        if (cinematicBars->IsAnimOver())
            setState(State0);
    } else if (cinematicState == 4) {
        setState(State5);
    } else if (cinematicState == 6) {
        setState(State0);
    } else if (cinematicState == 2) {
        if (cinematicBars->animation != -1 && cinematicBars->animation != unknown88)
            cinematicBars->SetAnim(unknown88, 0);
    }

    if (!cinematicBars->IsAnimOver())
        cinematicBars->Update(elapsed);

    if (!s_failure) {
        const unsigned int flags = PlayerTest::GetPlayer()->flags240;
        if (!(flags & 0x4000u))
            goto checkMissionFailure;
        if (flags & 0x2000u)
            goto checkMissionFailure;
        s_failure |= 5;
        goto failureDetectionDone;

    checkMissionFailure:
        if (mission->getState() == 6)
            s_failure |= 1;
        else if (static_cast<unsigned char>(PlayerTest::GetPlayer()->unknown424))
            s_failure |= 2;

    failureDetectionDone:

        if (s_failure) {
            ScriptManager::getInstance()->setState(State0);
            menu->popAll(false);
            mission->idle();
            Explosion::s_cameraShakeTimer = 0.0f;
            menu->setText(static_cast<MenuManager::eText>(2), -1, 0);
            menu->hideDialogArrow();
            cinematicCharacterAnimation->SetAnim(-1);
            StateMachine::getInstance()->pushState<GSFailure>();
        }
    } else {
        rewindRunningScripts();
        s_failure = 0;
    }

    if (!s_failure) {
        mission->update(elapsed);
        for (int i = 0; i < scriptCount; ++i) {
            if (scripts[i]->getState() == Script::State2)
                scripts[i]->execute(elapsed);
        }
    }

    AchievementManager* achievements = AchievementManager::s_achievementManager;
    if (achievements->hasNewCompletedAchievements() && !isInCinematic() && unknown104 <= 0) {
        const AchievementManager::Achievement* completed = achievements->popCompletedAchievement();
        MenuWidget* widget = menu->getWidgetByIndex(10);
        static_cast<Menus::Achievement*>(menu->getState(scriptUpdateAchievement))->SetAchievement(completed);
        widget->Show();
        widget->UpdateLocalization();
        SoundManager* sound = SoundManager::getInstance();
        sound->unknown140 = true;
        sound->playEx(217, 0, false, 1.0f, 0, true, 1.0f, 0);
        sound->unknown140 = false;
        unknown104 = 5000;
        menu->resetWidgetVisibility();
    }
    if (unknown104 > 0) {
        unknown104 -= elapsed;
        if (unknown104 <= 0 || isInCinematic()) {
            unknown104 = 0;
            menu->getWidgetByIndex(10)->Hide(true);
        }
    }

    if (unknown78 && menu->getDepth() <= 0 && !isInCinematic() &&
        (static_cast<Mission*>(getMission())->getState() == 0 ||
         static_cast<Mission*>(getMission())->getState() == 4) &&
        vehicleNameTimer <= 0 && !app->GetHudManager()->isAnyMessageDisplayed() &&
        !PlayerTest::GetPlayer()->flag383 && app->GetHudManager()->isWeaponVisible()) {
        MenuManager::getInstance()->setTutorialIds(0x3074, 0x3075);
        MenuManager::getInstance()->push(scriptUpdateTutorial, true);
        app->GetHudManager()->blink(6);
        PlayerTest::GetPlayer()->flag383 = true;
    }

    if (introAnimation->animation != -1 && !introAnimation->IsAnimOver())
        introAnimation->Update(elapsed);

    if (revive && revive->update(elapsed))
        SafeDelete(revive);
}
