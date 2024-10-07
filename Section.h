/**
 * @class Section
 * @brief Represents a section that can contain multiple rooms in the smart home automation system.
 *
 * The Section class inherits from SmartDevice and serves as a composite 
 * element that manages a collection of Room objects. It provides methods 
 * to add or remove rooms and can perform actions on all rooms within 
 * the section.
 *
 * @section methods Methods
 * - addRoom(Room* room): Adds a room to the section.
 * - removeRoom(Room* room): Removes a room from the section.
 * - getStatus(): Returns the status of all rooms within the section.
 * - performAction(const string& action): Executes a specified action across all rooms.
 * - getDeviceType(): Returns the type of the device as "Section".
 * - update(const string& sensor): Updates the section based on the specified sensor event.
 */

#ifndef SECTION_H
#define SECTION_H
#include"SmartDevice.h"
#include"Room.h"
#include<string>
#include<vector>
using namespace std;
class Section : public SmartDevice
{
    private:
    vector<Room*> rooms;
    string name;
    public:
    Section(const string& sName);
    void addRoom(Room* room);
    void removeRoom(Room* room);
    string getStatus()const override;
    void performAction(const string& action)override;
    string getDeviceType()const override;
    void update(const string& sensor)override;
};
#endif
