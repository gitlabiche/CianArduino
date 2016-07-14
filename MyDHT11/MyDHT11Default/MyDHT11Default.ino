#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V  (Board: Middle pin)
//      GND: GND       (Board: Rightmost pin)
//      DATA: 2        ()
int pinDHT11 = 2;   // Digital Pin 2
SimpleDHT11 dht11;

int DHT11SampleRate = 5000;
int DHTSampleCount = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // start working...
  Serial.println("___________________________");
  Serial.print("Sample DHT11... Rate= "); Serial.print((int)DHT11SampleRate);
  Serial.print(" :: DHTSampleCount= ");
  Serial.print((int)DHTSampleCount); Serial.print(" :: \n");
  Serial.println("---------------------------");
  Serial.println("--");
  DHTSampleCount++;
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  if (dht11.read(2, &temperature, &humidity, NULL)) {
    Serial.print("Read DHT11 failed.");
    delay(DHT11SampleRate);
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)( (temperature*1.8) +32) ); Serial.print(" *Farenheit, "); 
  Serial.print((int)humidity); Serial.println(" %");
  
  // DHT11 sampling rate is 1HZ.
  delay(DHT11SampleRate);
}