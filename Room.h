/**
 * @class Room
 * @brief Represents a room that can contain multiple smart devices.
 *
 * The Room class inherits from SmartDevice and serves as a composite that can 
 * manage multiple smart devices. It allows adding and removing devices and 
 * performing actions on all contained devices.
 *
 * @section methods Methods
 * - Room(const string& rName): Constructor that initializes the room with a name.
 * - addDevice(SmartDevice* addDevice): Adds a smart device to the room.
 *   - @param addDevice Pointer to the SmartDevice to add.
 * - removeDevice(SmartDevice* device): Removes a smart device from the room.
 *   - @param device Pointer to the SmartDevice to remove.
 * - getStatus(): Returns the current status of all devices in the room.
 *   - @return A string representing the aggregated status of devices.
 * - performAction(const string& action): Performs the specified action on all devices in the room.
 *   - @param action A string representing the action to perform.
 * - getDeviceType(): Returns the type of the device as "Room".
 *   - @return A string representing the device type.
 * - update(const string& sensor): Updates the status of devices in response to a sensor event.
 *   - @param sensor A string representing the sensor event.
 */

#ifndef ROOM_H
#define ROOM_H
#include"SmartDevice.h"
#include<vector>
using namespace std;
class Room : public SmartDevice
{
    private:
    vector<SmartDevice*> devices;
    string name;
    public:
    Room(const string& rName);
    void addDevice(SmartDevice* addDevice);
    void removeDevice(SmartDevice* device);
    string getStatus()const override
    ;
    void performAction(const string& action) override;
    string getDeviceType()const override;
    void update(const string& sensor)override;


};
#endif
