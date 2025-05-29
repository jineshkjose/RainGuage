

#define MODE_UART

#include "DFRobot_RainfallSensor.h"

DFRobot_RainfallSensor_UART Sensor(&Serial1);

void setup(void)
{
  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8N1, 16, 17);  // Use GPIO16, GPIO17 for UART  connected to physical serial pin RX2 TX2 

  delay(1000);
  while(!Sensor.begin()){
    Serial.println("Sensor init err!!!");
    delay(1000);
  }

  Serial.print("vid:\t");
  Serial.println(Sensor.vid, HEX);
  Serial.print("pid:\t");
  Serial.println(Sensor.pid, HEX);
  Serial.print("Version:\t");
  Serial.println(Sensor.getFirmwareVersion());
}

void loop()
{
  Serial.print("Sensor WorkingTime:\t");
  Serial.print(Sensor.getSensorWorkingTime());
  Serial.println(" H");

  Serial.print("Rainfall:\t");
  Serial.println(Sensor.getRainfall());

  Serial.print("1 Hour Rainfall:\t");
  Serial.print(Sensor.getRainfall(1));
  Serial.println(" mm");

  Serial.print("rainfall raw:\t");
  Serial.println(Sensor.getRawData());

  delay(1000);
}
