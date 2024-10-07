/**
 * @class Thermostat
 * @brief Represents a thermostat device that can control temperature.
 *
 * The Thermostat class inherits from SmartDevice and provides functionality
 * to set and get the current temperature. It can respond to specific commands
 * to adjust the temperature or report its status.
 *
 * @section methods Methods
 * - Thermostat(): Constructor that initializes the thermostat with a default temperature.
 * - getStatus(): Returns the current status of the thermostat, including the temperature.
 *   - @return A string representing the current temperature.
 * - performAction(const string& action): Adjusts the temperature based on the specified action.
 *   - @param action A string representing the action to perform (e.g., "setTemperature").
 * - getDeviceType(): Returns the type of the device as "Thermostat".
 *   - @return A string representing the device type.
 * - update(const string& event): Updates the thermostat based on specific events (e.g., temperature changes).
 *   - @param event A string representing the event that triggers the update.
 */

#ifndef THERMOSTAT_H
#define THERMOSTAT_H
#include"SmartDevice.h"
#include<iostream>
#include<vector>
using namespace std;
class Thermostat : public SmartDevice
{
    private:
    int temperature;
    public:
    Thermostat();
    string getStatus()const override;
    void performAction(const string& action) override;
    string getDeviceType()const override;
    void update(const string& event)override;


};
#endif
