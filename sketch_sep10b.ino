#include <math.h>
#include "DHT.h"
const int pinTempSensor = 24;     // Grove - Temperature Sensor connect to A5  

DHT dht(pinTempSensor, DHT22);            /* temperature&humidity sensor object */

void setup()  
{  
  Serial.begin(9600);  
  dht.begin();                         /* initialize temperature humidity sensor */
  pinMode(40, OUTPUT);  
}  
void loop()  
{  
  float temperature = dht.readTemperature(true);   
  Serial.print("temperature = ");  
  Serial.println(temperature);  
  if (temperature > 83) // Sound the alarm if the temp is too high!  
    {  
      for(int i = 0; i < 10; i++ )   
      {  
        digitalWrite(40, HIGH);  
        delay(10);  
        digitalWrite(40, LOW);  
        delay(10);  
      }  
    }  
  delay(100);  
}   
