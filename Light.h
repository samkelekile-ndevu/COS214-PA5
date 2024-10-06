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