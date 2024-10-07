#include"DoorLock.h"
using namespace std;
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
     if (action == "Lock") {isLocked = true;std::cout << "Door has been " << getStatus() << std::endl;}
        else if (action == "Unlock") 
        {isLocked = false;
         std::cout << "Door has been " << getStatus() << std::endl;
        }
        
}
string DoorLock::getDeviceType()const
{
    return "DoorLock";
}
void DoorLock::update(const string& sensorEvent)
{
    if(sensorEvent == "motion detected")
    {
        cout <<"Motion detected with the door sensors.\n";
    }
}
