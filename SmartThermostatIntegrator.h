/**
 * @class SmartThermostatIntegrator
 * @brief Adapter class that integrates an old thermostat with the new smart thermostat interface.
 *
 * This class adapts the interface of the OldThermostat to the SmartDevice interface,
 * allowing it to be used within the smart home automation system. It provides methods
 * to set and get the temperature, along with the required interface methods from
 * SmartDevice.
 *
 * @section methods Methods
 * - setTemperature(int temp): Adapts the method to set temperature to the old interface.
 * - getTemperature(): Adapts the method to get temperature from the old interface.
 * - getStatus(): Returns the current status of the thermostat, including the current temperature.
 * - performAction(const string& action): Executes specified actions on the thermostat.
 * - getDeviceType(): Returns the type of the device as "Thermostat".
 * - update(const string& sensorEvent): Responds to sensor events by updating the thermostat state.
 */

#ifndef ADAPTER_H
#define ADAPTER_H
using namespace std;
#include"SmartDevice.h"
#include<iostream>
#include"OldThermostat.h"
class SmartThermostatIntergator : public Thermostat
{
    private:
    OldThermostat* adaptee ;
    public:

    SmartThermostatIntergator(OldThermostat* legacyThermostat) : adaptee(legacyThermostat) {}
     void setTemperature(int temp) {
        std::cout << "SmartThermostatIntegrator: Adapting setTemperature(to old interface ).\n";
        adaptee->oldSetTemp(temp);  // Adapts to the old interface
    }

    int getTemperature() {
        std::cout << "SmartThermostatIntegrator: Adapting getTemperature(old interface).\n";
        return adaptee->oldGetTemp();  // Adapts to the old interface
    }

    // Implementing the SmartDevice's abstract methods
    std::string getStatus()const  override {
        return "Thermostat: Current temperature is " + std::to_string(adaptee->oldGetTemp()) + " degrees.";
    }

    void performAction(const string& action) override {
        std::cout << "Thermostat is being adjusted by SmartThermostatIntegrator.\n";
        /*if (action == "IncreaseTemp") {temperature += 1;  std::cout << getStatus() << std::endl;}
        else if (action == "DecreaseTemp") {temperature -= 1;  std::cout << getStatus() << std::endl;}*/
       
    }

    std::string getDeviceType()const override {
        return "Thermostat";
    }
 void update(const string& sensorEvent)override
    {
        if (sensorEvent == "motion detected") {
            std::cout << "SmartThermostat has detected motion." << std::endl;
        }

    }


};
#endif
