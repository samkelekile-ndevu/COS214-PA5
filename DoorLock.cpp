#include"DoorLock.h"
DoorLock::DoorLock()
{
    isLocked = false;

}
string DoorLock::getStatus()const
{
    return isLocked ? "locked" : "unlocked";
}
void DoorLock::performAction(const string& action)
{
     if (action == "Lock") {isLocked = true;std::cout << "Door is now " << getStatus() << std::endl;}
        else if (action == "Unlock") {isLocked = false;std::cout << "Door is now " << getStatus() << std::endl;}
        
}
string DoorLock::getDeviceType()const
{
    return "DoorLock";
}
void DoorLock::update(const string& sensorEvent)
{
    if(sensorEvent == "motion detected")
    {
        cout <<"Motion detected involving door.\n";
    }
}