/**
 * @class OldThermostat
 * @brief Represents a legacy thermostat device with basic functionality.
 *
 * This class simulates a legacy thermostat that can set and get the temperature.
 * It provides an interface to interact with older systems, allowing integration
 * with the smart home automation framework via the adapter pattern.
 *
 * @section methods Methods
 * - oldSetTemp(int temp): Sets the temperature on the legacy thermostat.
 * - oldGetTemp(): Retrieves the current temperature from the legacy thermostat.
 */

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
