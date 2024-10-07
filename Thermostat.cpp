#include"Thermostat.h"
using namespace std;
Thermostat::Thermostat()
{
    temperature = 24; //base temp
}
string Thermostat::getStatus()const
{
    return "Temperature reading: " + std::to_string(temperature) + "°C";

}
void Thermostat::performAction(const string& action)
{
    if (action == "IncreaseTemp") 
    {temperature += 1;
     std::cout << getStatus() << std::endl;
    }else if (action == "DecreaseTemp") {temperature -= 1;  std::cout << getStatus() << std::endl;}
       

}
string Thermostat::getDeviceType()const 
{
    return "Thermostat";
}
void Thermostat::update(const string& sensorEvent)
    {
        if (sensorEvent == "motion detected") {
            std::cout << "Thermostat has detected motion. using sensors << std::endl;
        }

    }
