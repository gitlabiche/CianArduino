int blinkCount;

void setup() {
  // put your setup code here, to run once:

  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);

  Serial.begin(115200);  
  blinkCount = 0;

}

void loop() {
  // put your main code here, to run repeatedly:

  BlinkAtRate(3000);
  
  BlinkAtRate(1000);
  BlinkAtRate(2000);


}

void BlinkAtRate( int blinkRate)
{

  blinkCount += 1;
  Serial.print("BlinkAtRate=");
  Serial.print(blinkRate);
  Serial.print("blinkCount=");
  Serial.print(blinkCount);
  Serial.print("\n");

  digitalWrite(13, HIGH);
  delay(blinkRate);
  digitalWrite(13, LOW);
  delay(blinkRate);

}

