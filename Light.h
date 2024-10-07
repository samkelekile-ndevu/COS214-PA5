/**
 * @class Light
 * @brief Represents a smart light device that can be turned on or off.
 *
 * The Light class inherits from SmartDevice and provides functionality
 * to manage the state of a light. It can be controlled to turn on or off
 * and can respond to sensor events.
 *
 * @section methods Methods
 * - Light(): Default constructor that initializes the light.
 * - performAction(const string& action): Performs the specified action on the light.
 *   - @param action A string representing the action to perform ("TurnOn" or "TurnOff").
 * - getDeviceType(): Returns the type of the device as "Light".
 *   - @return A string representing the device type.
 * - getStatus(): Returns the current status of the light (on or off).
 *   - @return A string representing the current status ("on" or "off").
 * - update(const string& sensorEvent): Updates the light based on a sensor event.
 *   - @param sensorEvent A string representing the event from the sensor.
 */

#ifndef LIGHT_H
#define LIGHT_H
#include<string>
#include<iostream>
using namespace std;
#include"SmartDevice.h"
class Light : public SmartDevice
{
    private:
    bool isOn;
    public:
    Light();
    void performAction(const string& action ) override;
    string getDeviceType()const override;
    string getStatus()const override;
    void update(const string& sensorEvent) override;


};
#endif
