#include<iostream>

#include"Room.h"
#include"Section.h"
#include"Light.h"
#include"DoorLock.h"
#include"SmartDevice.h"
#include"Thermostat.h"
#include"OldThermostat.h"
#include"SmartThermostatIntegrator.h"
#include"Command.h"
#include"MacroRoutine.h"
#include"LockAllDoors.h"
#include"TurnOffAllLights.h"
#include"Sensor.h"
#include"Alarm.h"
#include"TurnOnAllAlarms.h"
using namespace std;
void Comp1()
{
      // Create individual devices
    Light* livingRoomLight = new Light();
    DoorLock* mainDoorLock = new DoorLock();
    Thermostat* livingRoomThermostat = new Thermostat();
    
    // Create a room and add devices to it
    Room* livingRoom = new Room("Living Room");
    livingRoom->addDevice(livingRoomLight);
    livingRoom->addDevice(mainDoorLock);
    livingRoom->addDevice(livingRoomThermostat);
    
    // Create a section and add rooms to it
    Section* downstairs = new Section("Downstairs");
    downstairs->addRoom(livingRoom);

    // Perform actions and display statuses
    cout <<"STATUS BEOFRE ACTION PROMPTS.\n";
    std::cout << downstairs->getStatus() << std::endl;
    
    downstairs->performAction("ToggleOn"); // Toggle all lights in the section on
    downstairs->performAction("Lock"); // Lock all door locks in the section
    downstairs->performAction("IncreaseTemp"); // Increase the temperature for thermostats
    
    std::cout << "\nAfter actions:\n";
    std::cout << downstairs->getStatus() << std::endl;
    
    // Cleanup
    delete livingRoomLight;
    delete mainDoorLock;
    delete livingRoomThermostat;
    delete livingRoom;
    delete downstairs;
    

}
void comp2()
{
     // Create an old legacy thermostat
    OldThermostat* legacyThermostat = new OldThermostat();

    // Create an adapter to make the old thermostat compatible with the smart system
    //SmartThermostatIntegrator* smartThermostat = new SmartThermostatIntegrator(legacyThermostat);
    SmartThermostatIntergator* smartThermostat = new SmartThermostatIntergator(legacyThermostat);

    // Using the smart home interface with the legacy thermostat
    smartThermostat->setTemperature(25);
    std::cout << smartThermostat->getTemperature() << " degrees.\n";

    // Perform actions defined in the smart device interface
    cout <<"GET STATUS OF CURRENT SMARTDEVICE.\n";
    std::cout << smartThermostat->getStatus() << "\n";

    // Clean up
    delete smartThermostat;
    delete legacyThermostat;

}
void comp3()
{
      // Create some devices
    SmartDevice* light1 = new Light();
    SmartDevice* light2 = new Light();
    SmartDevice* door1 = new DoorLock();
    SmartDevice* door2 = new DoorLock();
    SmartDevice* alarm1 = new Alarm();

    // Put devices in a vector
    std::vector<SmartDevice*> devices = {light1, light2, door1, door2,alarm1};

    // Create individual commands
    Command* turnOffLights = new TurnOffAllLights(devices);
    Command* lockAllDoors = new LockAllDoors(devices);
    Command* allalarms = new TurnOnAllAlarms(devices);

    // Create a macro routine for "Goodnight"
    MacroRoutine goodnightRoutine;
    goodnightRoutine.addProcedure(turnOffLights);
    goodnightRoutine.addProcedure(lockAllDoors);
    goodnightRoutine.addProcedure(allalarms);

    // Execute the macro routine (turns off lights and locks doors)
    cout <<"IMPLEMENTING GOODNIGHT ROUTINE.\n";
    goodnightRoutine.execute();

    // Clean up memory
    delete turnOffLights;
    delete lockAllDoors;
    delete light1;
    delete light2;
    delete door1;
    delete door2;
    delete alarm1;
}
void comp4()
{
    // Create some devices
    SmartDevice* light1 = new Light();
    SmartDevice* alarm1 = new Alarm();
    SmartDevice* door = new DoorLock();


    // Create a motion sensor
    Sensor motionSensor;

    // Register devices with the motion sensor
    motionSensor.addDevice(light1);
    motionSensor.addDevice(alarm1);
    motionSensor.addDevice(door);

    // Motion detected, notify all devices
    motionSensor.notifyDevices("motion detected");

    // Clean up memory
    delete light1;
    delete alarm1;
    delete door;

    
}
int main()
{
    //Comp1();
    //comp2();
   // comp3();
   comp4();

}
