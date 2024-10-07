/**
 * @class Sensor
 * @brief Represents a sensor that detects events and notifies registered smart devices.
 *
 * The Sensor class allows for the addition and removal of smart devices to be notified
 * when an event occurs. It can trigger notifications to all registered devices in response
 * to detected events.
 *
 * @section methods Methods
 * - addDevice(SmartDevice* device): Adds a smart device to the sensor's notification list.
 *   - @param device Pointer to the SmartDevice to add.
 * - removeDevice(SmartDevice* device): Removes a smart device from the sensor's notification list.
 *   - @param device Pointer to the SmartDevice to remove.
 * - notifyDevices(const std::string& event): Notifies all registered devices about a specific event.
 *   - @param event A string representing the event that has been detected.
 */

#ifndef SENSOR_H
#define SENSOR_H
#include"SmartDevice.h"
#include<vector>
#include<algorithm>
class Sensor
{
    private:
    vector<SmartDevice*> devices;

    public: 
    void addDevice(SmartDevice* device) {
        devices.push_back(device);
    }

    void removeDevice(SmartDevice* device) {
        devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
    }

    // Trigger the notification when a sensor detects something
    void notifyDevices(const std::string& event) {
        for (SmartDevice* device : devices) {
            device->update(event);  // Notify each device about the event
        }
    }

};
#endif
