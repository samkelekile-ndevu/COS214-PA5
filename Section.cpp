#include"Section.h"
#include<iostream>
#include<algorithm>
using namespace std;
Section::Section(const string& sName) : name(sName)
{

}
void Section::addRoom(Room* room)
{
    rooms.push_back(room);
}
void Section::removeRoom(Room* room)
{
     //rooms.erase(std::remove(rooms.begin(), rooms.end(), room), rooms.end());
     auto it = std::find(rooms.begin(), rooms.end(), room);
    if (it != rooms.end()) {
        rooms.erase(it); // Use the iterator to erase the element
        std::cout << "Room removed successfully from section.\n";
    } else {
        std::cout << "Room not found in the section.\n";
    }
}
string Section::getStatus()const
{
    string status = "Section: " + name + ".\n";
     for (const auto& room : rooms) {
            status += room->getStatus() + "\n";
        }
        return status;
}
void Section::performAction(const string& action)
{
    cout <<"Performing action for section: \n";
     for (auto& room : rooms) {
            room->performAction(action);
        }
}
string Section::getDeviceType()const 
{ string stat = "DEvice type for Section " + name + "\n"   ;
    for (auto& room : rooms) {
            stat += room->getDeviceType();
        }
        return stat;
}
void Section::update(const string& sensorEvent)
    {
        if (sensorEvent == "motion detected") {
            std::cout << "motion detected in Section." << std::endl;
        }

    }
