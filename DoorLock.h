/**
 * @class DoorLock
 * @brief Represents a smart door lock that can be locked or unlocked.
 *
 * The DoorLock class inherits from SmartDevice and provides functionality
 * to manage the locking state of a door. It can be controlled to lock or
 * unlock and can respond to sensor events.
 *
 * @section methods Methods
 * - DoorLock(): Default constructor that initializes the door lock.
 * - getStatus(): Returns the current status of the door lock (locked or unlocked).
 *   - @return A string representing the current status ("locked" or "unlocked").
 * - performAction(const string& action): Performs the specified action on the door lock.
 *   - @param action A string representing the action to perform ("Lock" or "Unlock").
 * - getDeviceType(): Returns the type of the device as "DoorLock".
 *   - @return A string representing the device type.
 * - update(const string& sensorEvent): Updates the door lock based on a sensor event.
 *   - @param sensorEvent A string representing the event from the sensor.
 */

#ifndef DOORLOCK_H
#define DOORLOCK_H
#include"SmartDevice.h"
#include<vector>
#include<iostream>
using namespace std;

class DoorLock : public SmartDevice
{
    private:
    bool isLocked;
    public:
    DoorLock();
    string getStatus()const override;
    void performAction(const string& action) override;
    string getDeviceType()const override;
    void update(const string& sensorEvent)override;
    


};
#endif
