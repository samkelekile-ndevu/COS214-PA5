/**
 * @class Alarm
 * @brief Represents an alarm device that can be activated based on sensor events.
 *
 * The Alarm class inherits from SmartDevice and implements functionality
 * to sound an alarm when specific sensor events, such as motion detection,
 * are triggered. The alarm can be turned on or off and reports its status.
 *
 * @section methods Methods
 * - update(const std::string& sensorEvent): Responds to sensor events by sounding the alarm.
 * - performAction(const string& action): Turns the alarm on or off based on the specified action.
 * - getDeviceType(): Returns the type of the device as "Alarm".
 * - getStatus(): Returns the current status of the alarm (on or off).
 */

#ifndef ALARM_H
#define ALARM_H
#include"SmartDevice.h"
using namespace std;
#include<iostream>


class Alarm : public SmartDevice
{
    private:
    bool isOn;
    public:
    void update(const std::string& sensorEvent) override {
        if (sensorEvent == "motion detected") {
            std::cout << "Alarm is sounding due to motion detection!" << std::endl;
        }
    }
    //
    Alarm()
    {
        isOn = false;
    }

    void performAction(const string& action)override
    {
         if (action == "TurnOn") isOn = true;
        else if (action == "TurnOff") isOn = false;
    
        std::cout << "Alarm is now " << getStatus() << std::endl;
    }
    string getDeviceType()const override
    {
        return "Alarm";
    }
    string getStatus()const override
    {
        return isOn ? "on" : "off" ; //options for light
    }

};
#endif
