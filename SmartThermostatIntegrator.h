//ADAPTER
#ifndef ADAPTER_H
#define ADAPTER_H
using namespace std;
#include"SmartDevice.h"
#include<iostream>
#include"OldThermostat.h"
class SmartThermostatIntergator : public SmartDevice
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