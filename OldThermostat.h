#ifndef OLDTHERMOSTAT_H
#define OLDTHERMOSTAT_H
using namespace std;
#include<iostream>
//LEGACY DEVICE
#include"Thermostat.h"

class OldThermostat{
    private:
    int temperature = 22;
    public:
    void oldSetTemp(int temp)
    {
        std::cout << "Legacy thermostat: Setting temperature to " << temp << " degrees.\n";
        this->temperature = temp;
        
    }
    int oldGetTemp()
    {
         std::cout << "Legacy thermostat: Current temperature is " << temperature << " degrees.\n";
        return temperature;
    }
    

};
#endif