#include <iostream>
#include <string>
using namespace std;

union SensorData {
    int intData;
    float floatData;
    char charData;
};

struct Sensor {
    string sensorType;
    SensorData data;
};

int main() {
    Sensor temperatureSensor;
    temperatureSensor.sensorType = "Temperature";
    temperatureSensor.data.floatData = 25.5;  // Store temperature as float

    Sensor pressureSensor;
    pressureSensor.sensorType = "Pressure";
    pressureSensor.data.intData = 1013;  // Store pressure as integer

    Sensor statusSensor;
    statusSensor.sensorType = "Status";
    statusSensor.data.charData = 'A';  // Store status as character code

    cout << "Temperature: " << temperatureSensor.data.floatData << "°C" << endl;
    cout << "Pressure: " << pressureSensor.data.intData << " hPa" << endl;
    cout << "Status: " << statusSensor.data.charData << endl;

    return 0;
}
