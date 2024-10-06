
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