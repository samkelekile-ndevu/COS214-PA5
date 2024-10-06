#include"Room.h"
#include<vector>
#include<algorithm>
using namespace std;
Room::Room(const string& rName) : name(rName)
{
   
}
void Room::addDevice(SmartDevice* device)
{
    devices.push_back(device);
}
void Room::removeDevice(SmartDevice* device)
{
   // devices.erase(remove(devices.begin(), devices.end(),device),devices.end() );
   //  devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
   auto it = std::find(devices.begin(), devices.end(), device);
    if (it != devices.end()) {
        devices.erase(it); // Use the iterator to erase the element
        std::cout << "Device removed successfully from room.\n";
    } else {
        std::cout << "Device not found in the room.\n";
    }
}
string Room::getStatus()const
{
    std::string status = "Room: " + name + "\n";
        for (const auto& device : devices) {
            status += device->getDeviceType() + " is " + device->getStatus() + "\n";
        }
        return status;
}
void Room::performAction(const string& action)
{
    for (auto& device : devices) {
            device->performAction(action);
        }
}
string Room::getDeviceType()const 
{
    string status = "ROOM TYPE FOR "+ name+ " THAT HAS: ";
   for (const auto& device : devices) {
            status += device->getDeviceType()+".\n" ;
            
        }
        return status +"\n";
}
void Room::update(const string& sensorEvent)
    {
        if (sensorEvent == "motion detected") {
            std::cout << " motion detected in the Room." << std::endl;
        }

    }