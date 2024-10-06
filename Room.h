#ifndef ROOM_H
#define ROOM_H
#include"SmartDevice.h"
#include<vector>
using namespace std;
class Room : public SmartDevice
{
    private:
    vector<SmartDevice*> devices;
    string name;
    public:
    Room(const string& rName);
    void addDevice(SmartDevice* addDevice);
    void removeDevice(SmartDevice* device);
    string getStatus()const override
    ;
    void performAction(const string& action) override;
    string getDeviceType()const override;
    void update(const string& sensor)override;


};
#endif