/**
 * @class SmartDevice
 * @brief Abstract base class representing a smart device.
 *
 * This class serves as the interface for all smart devices in the smart home
 * automation system. It allows for composite device management and command
 * execution. All smart devices must implement this interface to provide
 * uniform functionality.
 *
 * @section methods Methods
 * - getStatus(): Returns the current status of the device.
 * - performAction(const string& action): Executes a specified action on the device.
 * - getDeviceType(): Returns the type of the device (e.g., "Light", "Thermostat").
 * - update(const string& event): Updates the device based on the specified event.
 */

#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class SmartDevice
{
    public:
    virtual string getStatus() const = 0;
    virtual void performAction(const string& action) = 0;
    virtual string getDeviceType() const = 0;
    virtual ~SmartDevice() = default;
    //observer patter 
    virtual void update(const string& event) = 0;


};
#endif
