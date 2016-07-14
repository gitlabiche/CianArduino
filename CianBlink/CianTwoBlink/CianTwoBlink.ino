// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// CREATE a variable to store how long the Blink on+off cycle will be
//  hint make the blinkCycle an Integer (int)
//-------------------------------------------
int blinkCycle = 2000;


void makeItBlink( int blinkRate )
{    
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(blinkRate / 2);              // wait for a second

  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(blinkRate / 2);              // wait for a second
}

// the loop function runs over and over again forever
void loop() {
  makeItBlink( blinkCycle / 8);
  makeItBlink( blinkCycle / 4);
  makeItBlink( blinkCycle / 2);
  makeItBlink( blinkCycle );
}