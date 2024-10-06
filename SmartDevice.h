#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//BASE CLASS INTERFACE FOR COMPOSITE + COMMAND
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