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