#include<vector>
#include"Light.h"
using namespace std;
Light::Light()
{
    //light initially off
    isOn = false;

}
void Light::performAction(const string& action)
{
    //hard coded commands basically
     if (action == "ToggleOn") isOn = true;
        else if (action == "ToggleOff") isOn = false;
        else if (action == "Toggle") isOn = !isOn;
        std::cout << "Light is now " << getStatus() << std::endl;
}
string Light::getDeviceType()const
{
    return "Light";
}
string Light::getStatus()const
{
    return isOn ? "on" : "off" ; //options for light
}
void Light::update(const string& sensorEvent)
{
    if (sensorEvent == "motion detected") {
            std::cout << "Light is turning on due to motion detection by the sensor." << std::endl;
        }
}

