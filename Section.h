#ifndef SECTION_H
#define SECTION_H
#include"SmartDevice.h"
#include"Room.h"
#include<string>
#include<vector>
using namespace std;
class Section : public SmartDevice
{
    private:
    vector<Room*> rooms;
    string name;
    public:
    Section(const string& sName);
    void addRoom(Room* room);
    void removeRoom(Room* room);
    string getStatus()const override;
    void performAction(const string& action)override;
    string getDeviceType()const override;
    void update(const string& sensor)override;
};
#endif