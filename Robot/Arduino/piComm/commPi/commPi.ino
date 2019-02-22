//piTalk.ino
// Reads digital inputs.

byte onState[3] = {0,0,0};

void setup() {
  Serial.begin(9600);  
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);

  pinMode(13, OUTPUT);                       // Set digital pin 13 -> output
  pinMode(12, OUTPUT);                       // Set digital pin 13 -> output
  pinMode(7, INPUT);                         // Set right whisker pin to input
  pinMode(5, INPUT);                         // Set left whisker pin to input  
  Serial.println("Hello from setup()!");
}

//Serial.println(inputString); 

void loop() {

//  for (int=5; i<<8; i+=2) {

    if (digitalRead(5) == HIGH) {

      if (onState[0] == 0) {
//        Serial.println("left touched ");
        Serial.write(5);
        digitalWrite(12, HIGH);
        onState[0] = 1;
      }
    } else {
      onState[0] = 0;
      digitalWrite(12, LOW);
    }

    if (digitalRead(7) == HIGH) {

      if (onState[1] == 0) {
//        Serial.println("right touched ");
        Serial.write(7);
        digitalWrite(13, HIGH);
        onState[1] = 1;
      }
    } else {
      onState[1] = 0;
      digitalWrite(13, LOW);
    }
//  }
  delay(20);
}
