#include <iostream>
#include "Room.h"
#include "Light.h"
#include "DoorLock.h"
#include "Alarm.h"
#include "Section.h"
#include "Thermostat.h"
#include "OldThermostat.h"
#include "SmartThermostatIntegrator.h"
#include "Sensor.h"
#include "MacroRoutine.h"
#include "TurnOffAllLights.h"
#include "LockAllDoors.h"
#include "TurnOnAllAlarms.h"

int main() {
    // Test Room
    Room room("Living Room");
    Light light;
    DoorLock doorLock;
    Alarm alarm;

    room.addDevice(&light);
    room.addDevice(&doorLock);
    room.addDevice(&alarm);

    std::cout << room.getDeviceType() << std::endl;
    room.performAction("ToggleOn");
    room.performAction("Lock");
    room.performAction("TurnOn");

    std::cout << room.getStatus() << std::endl;

    room.removeDevice(&light);
    std::cout << room.getDeviceType() << std::endl;

    room.update("motion detected");

    // Test Light
    Light light2;
    std::cout << light2.getDeviceType() << std::endl;
    std::cout << light2.getStatus() << std::endl;
    light2.performAction("ToggleOn");
    std::cout << light2.getStatus() << std::endl;
    light2.performAction("ToggleOff");
    std::cout << light2.getStatus() << std::endl;
    light2.update("motion detected");

    // Test DoorLock
    DoorLock doorLock2;
    std::cout << doorLock2.getDeviceType() << std::endl;
    std::cout << doorLock2.getStatus() << std::endl;
    doorLock2.performAction("Lock");
    std::cout << doorLock2.getStatus() << std::endl;
    doorLock2.performAction("Unlock");
    std::cout << doorLock2.getStatus() << std::endl;
    doorLock2.update("motion detected");

    // Test Alarm
    Alarm alarm2;
    std::cout << alarm2.getDeviceType() << std::endl;
    std::cout << alarm2.getStatus() << std::endl;
    alarm2.performAction("TurnOn");
    std::cout << alarm2.getStatus() << std::endl;
    alarm2.performAction("TurnOff");
    std::cout << alarm2.getStatus() << std::endl;
    alarm2.update("motion detected");

    // Test Section
    Section section("House");
    Room room3("Living Room");
    Room room4("Bedroom");

    section.addRoom(&room3);
    section.addRoom(&room4);

    std::cout << section.getDeviceType() << std::endl;
    section.performAction("ToggleOn");
    section.performAction("Lock");
    section.performAction("TurnOn");

    std::cout << section.getStatus() << std::endl;

    section.removeRoom(&room3);
    std::cout << section.getDeviceType() << std::endl;

    section.update("motion detected");

    // Test Thermostat
    Thermostat thermostat;
    std::cout << thermostat.getDeviceType() << std::endl;
    std::cout << thermostat.getStatus() << std::endl;
    thermostat.performAction("IncreaseTemp");
    std::cout << thermostat.getStatus() << std::endl;
    thermostat.performAction("DecreaseTemp");
    std::cout << thermostat.getStatus() << std::endl;
    thermostat.update("motion detected");

    // Test SmartThermostatIntegrator
    OldThermostat oldThermostat;
    SmartThermostatIntergator smartThermostat(&oldThermostat);
    std::cout << smartThermostat.getDeviceType() << std::endl;
    std::cout << smartThermostat.getStatus() << std::endl;
    smartThermostat.setTemperature(25);
    std::cout << smartThermostat.getStatus() << std::endl;
    smartThermostat.update("motion detected");

    // Test Sensor
    Sensor sensor;
    Light light3;
    DoorLock doorLock3;
    Alarm alarm3;

    sensor.addDevice(&light3);
    sensor.addDevice(&doorLock3);
    sensor.addDevice(&alarm3);

    sensor.notifyDevices("motion detected");

    // Test MacroRoutine
    MacroRoutine macroRoutine;
    std::vector<SmartDevice*> devices;
    Light light4;
    DoorLock doorLock4;
    Alarm alarm4;
    devices.push_back(&light4);
    devices.push_back(&doorLock4);
    devices.push_back(&alarm4);

    TurnOffAllLights turnOffAllLights(devices);
    LockAllDoors lockAllDoors(devices);
    TurnOnAllAlarms turnOnAllAlarms(devices);

    macroRoutine.addProcedure(&turnOffAllLights);
    macroRoutine.addProcedure(&lockAllDoors);
    macroRoutine.addProcedure(&turnOnAllAlarms);

    macroRoutine.execute();

    return 0;
}