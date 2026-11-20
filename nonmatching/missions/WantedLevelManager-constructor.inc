WantedLevelManager::WantedLevelManager()
{
    unknown40 = 10000.0;
    unknown48 = 5000.0;
    unknown56 = 0.0;
    unknown64 = 0.0;
    unknown76 = false;
    unknown77 = false;
    unknown78 = false;
    locked = false;
    unknown8 = 0;
    lockedLevel = 0;
    savedLevel = 0;
    savedLockedLevel = 0;
    savedUnknown16 = 0;
    savedUnknown20 = 0;
    unknown72 = 0;

    EventManager* events = Application::GetInstance()->GetEventManager();
    events->attach(22, this);
    events->attach(16, this);
    events->attach(19, this);
}
