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