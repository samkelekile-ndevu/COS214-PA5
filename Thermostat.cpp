#include"Thermostat.h"
Thermostat::Thermostat()
{
    temperature = 22; //base temp
}
string Thermostat::getStatus()const
{
    return "Temperature is: " + std::to_string(temperature) + "°C";

}
void Thermostat::performAction(const string& action)
{
    if (action == "IncreaseTemp") {temperature += 1;  std::cout << getStatus() << std::endl;}
        else if (action == "DecreaseTemp") {temperature -= 1;  std::cout << getStatus() << std::endl;}
       

}
string Thermostat::getDeviceType()const 
{
    return "Thermostat. ";
}
void Thermostat::update(const string& sensorEvent)
    {
        if (sensorEvent == "motion detected") {
            std::cout << "SmartThermostat has detected motion." << std::endl;
        }

    }
