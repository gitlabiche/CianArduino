const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {
  // Start off with the LED off.
  Serial.begin(115200);
  setColourRgb(0,0,0);
}

void loop() {
  unsigned int rgbColour[3];
  int byteIn;

// setColourRgb(255, 0, 0);
// delay(5000);
// setColourRgb(0,255, 0);
// delay(5000);
// setColourRgb(0, 0, 255);
// delay(5000);


  // Start off with red.
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  

  Serial.println("___________________________");
  Serial.println("___________________________");
  Serial.println("___________________________");

  Serial.println("before the for() loop....:: RGB LED color");
  // Choose the colours to increment and decrement.
  for (int decColour = 0; decColour < 3; decColour += 1) {
/*
        // send data only when you receive data:
        byteIn = 0;
        Serial.println("Enter a key to cycle the RGB LED color");

        while( byteIn == 0)
        {
          if (Serial.available() > 0) {
                // read the incoming byte:
                byteIn = Serial.read();

                // say what you got:
                Serial.print("I received: ");
                Serial.println(byteIn, DEC);
          }
        }
        
*/
    int incColour = decColour == 2 ? 0 : decColour + 1;

    // cross-fade the two colours.
    for(int i = 0; i < 255; i += 1) {
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      
      setColourRgb(rgbColour[0], rgbColour[1], rgbColour[2]);
      delay(5);
    }
  }
}

void setColourRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
 }