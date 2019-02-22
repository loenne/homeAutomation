/*
 Robotics with the BOE Shield – ServoRunTimes
 Generate a servo full speed counterclockwise signal with pin 13 and 
 full speed clockwise signal with pin 12.
 */

#include <Servo.h>                           // Include servo library
 
Servo servoLeft;                             // Declare left servo signal
Servo servoRight;                            // Declare right servo signal

void setup()                                 // Built in initialization block
{ 
  pinMode(13, OUTPUT);                       // Set digital pin 13 -> output
  pinMode(12, OUTPUT);                       // Set digital pin 13 -> output
  pinMode(7, INPUT);                         // Set right whisker pin to input
  pinMode(5, INPUT);                         // Set left whisker pin to input  
  servoLeft.attach(11);                      // Attach left signal to P13 
  servoRight.attach(10);                     // Attach right signal to P12 
  Serial.begin(9600);
  Serial.println("Hello from setup()!");
  tone(3, 3000, 1000);                       // Play tone for 1 second
  delay(1000);                               // Delay to finish tone

  digitalWrite(13, HIGH);                    // Pin 13 = 5 V, LED emits light
  digitalWrite(12, HIGH);                    // Pin 13 = 5 V, LED emits light
  delay(200);                                // ..for 0.5 seconds
  digitalWrite(13, LOW);                    // Pin 13 = 5 V, LED emits light
  digitalWrite(12, LOW);                    // Pin 13 = 5 V, LED emits light

  Serial.println("Driving forward!");
  // Fast forward
//  servoLeft.writeMicroseconds(1580);         // Pin 13 clockwise
  servoLeft.writeMicroseconds(1600);         // Pin 13 clockwise
  servoRight.writeMicroseconds(1300);        // Pin 12 clockwise
  delay(4000);                               // ..for 3 seconds 
  // Reverse slow
  Serial.println("Driving backward slowly!");
  digitalWrite(12, HIGH);                    // Pin 13 = 5 V, LED emits light
  digitalWrite(13, HIGH);                    // Pin 13 = 5 V, LED emits light
  servoLeft.writeMicroseconds(1300);         // Pin 13 counterclockwise
  servoRight.writeMicroseconds(1620);        // Pin 12 counterclockwise
  delay(2000);                               // ..for 3 seconds 
  servoLeft.writeMicroseconds(1500);         // Pin 13 stay still
  servoRight.writeMicroseconds(1500);        // Pin 12 stay still
  digitalWrite(12, LOW);                    // Pin 13 = 5 V, LED emits light
  digitalWrite(13, LOW);                    // Pin 13 = 5 V, LED emits light
  delay(1000);                               // ..for 3 seconds 
  digitalWrite(12, HIGH);                    // Pin 13 = 5 V, LED emits light
  digitalWrite(13, HIGH);                    // Pin 13 = 5 V, LED emits light
  delay(1000);                               // ..for 3 seconds 
  digitalWrite(12, LOW);                    // Pin 13 = 5 V, LED emits light
  digitalWrite(13, LOW);                    // Pin 13 = 5 V, LED emits light
  delay(1000);                               // ..for 3 seconds 
  digitalWrite(12, HIGH);                    // Pin 13 = 5 V, LED emits light
  digitalWrite(13, HIGH);                    // Pin 13 = 5 V, LED emits light
  delay(1000);                               // ..for 3 seconds 
  digitalWrite(12, HIGH);                    // Pin 13 = 5 V, LED emits light
  digitalWrite(13, HIGH);                    // Pin 13 = 5 V, LED emits light
  delay(3000);                               // ..for 3 seconds 
  digitalWrite(12, LOW);                    // Pin 13 = 5 V, LED emits light
  digitalWrite(13, LOW);                    // Pin 13 = 5 V, LED emits light
  // Turn right backward
  Serial.println("Turn maximum right!");
  digitalWrite(12, HIGH);                    // Pin 13 = 5 V, LED emits light
  servoLeft.writeMicroseconds(1450);         // Pin 13 stay still
  servoRight.writeMicroseconds(1500);        // Pin 12 stay still
  delay(2000);                               // ..for 3 seconds 
  Serial.println("Turn maximum left!");
  servoLeft.writeMicroseconds(1500);         // Pin 13 stay still
  servoRight.writeMicroseconds(1550);        // Pin 12 stay still
  delay(2000);                               // ..for 3 seconds 
  digitalWrite(12, LOW);                    // Pin 13 = 5 V, LED emits light
  Serial.println("Slow forward!");
  servoLeft.writeMicroseconds(1550);         // Pin 13 stay still
  servoRight.writeMicroseconds(1450);        // Pin 12 stay still
  delay(500);                                // ..for 3 seconds 
  Serial.println("Slow backward!");
  servoLeft.writeMicroseconds(1450);         // Pin 13 stay still
  servoRight.writeMicroseconds(1550);        // Pin 12 stay still
  delay(500);                                // ..for 3 seconds 
  Serial.println("Stop!");
  servoLeft.writeMicroseconds(1500);         // Pin 13 stay still
  servoRight.writeMicroseconds(1500);        // Pin 12 stay still
  tone(3, 4000, 500);                       // Play tone for 1 second
  delay(550);                               // Delay to finish tone
  tone(3, 4000, 500);                       // Play tone for 1 second
  delay(550);                               // Delay to finish tone

  wLeftOld = 0;                              // Init. previous whisker states
  wRightOld = 1;  
  counter = 0;                               // Initialize counter to 0
} }  
 
void loop()                                  // Main loop auto-repeats
{                                            // Empty, nothing needs repeating
  byte wLeft = digitalRead(5);               // Copy left result to wLeft  
  byte wRight = digitalRead(7);              // Copy right result to wRight
  byte wait = 1;

  if (wait == 1) 
  {
    Serial.println("Wait for contact !!");  
    wait = 0;
  } 

  if((wLeft == 0) && (wRight == 0))              // If left whisker contact
  {
    Serial.println("Contact detected !!");  
    wait = 2;
  } 
 
  if (wait == 2) 
  {
    startReacting();
  } 
} 
  
void startReacting()
{
  byte wLeft = digitalRead(5);               // Copy left result to wLeft  
  byte wRight = digitalRead(7);              // Copy right result to wRight

  // Corner Escape

  if(wLeft != wRight)                        // One whisker pressed?
  {                                          // Alternate from last time?
    if ((wLeft != wLeftOld) && (wRight != wRightOld))  
    {                                       
      counter++;                             // Increase count by one
      wLeftOld = wLeft;                      // Record current for next rep
      wRightOld = wRight;
 
      if(counter == 4)                       // Stuck in a corner?
      {
        wLeft = 0;                           // Set up for U-turn
        wRight = 0;
        counter = 0;                         // Clear alternate corner count
      }
    }  
    else                                     // Not alternate from last time
    {
      counter = 0;                           // Clear alternate corner count
    }
  }
 
  if((wLeft == 0)&&(wRight == 0))              // If left whisker contact
  {
    Serial.println("LEFT and RIGHT contact");
    digitalWrite(12, HIGH);    // Left LED on
    digitalWrite(13, HIGH);     // Left LED off
    backward(1000);                          // Back up 1 second
    turnLeft(800);                           // Turn left about 120 degrees
  } 
  else if (wRight == 0)             // If right whisker contact
  {
    Serial.println("Right contact");
    digitalWrite(12, HIGH);    // Left LED on
    backward(1000);                          // Back up 1 second
    turnLeft(400);                           // Turn left about 60 degrees
  } 
  else if(wLeft == 0)              // If left whisker contact
  {
    Serial.println("Left contact");
    digitalWrite(13, HIGH);     // Left LED on
    backward(1000);                          // Back up 1 second
    turnRight(400);                          // Turn right about 60 degrees
  } 
  else                                       // Otherwise, no whisker contact
  {
    digitalWrite(12, LOW);     // Left LED on
    digitalWrite(13, LOW);     // Left LED on
    forward(20);                             // Forward 1/50 of a second
  }

  delay(50);                                 // Pause for 50 ms
}

void forward(int time)                       // Forward function
{
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(time);                               // Maneuver for time ms
}

void turnLeft(int time)                      // Left turn function
{
  servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
  servoRight.writeMicroseconds(1300);        // Right wheel clockwise
  delay(time);                               // Maneuver for time ms
}

void turnRight(int time)                     // Right turn function
{
  servoLeft.writeMicroseconds(1700);         // Left wheel counterclockwise
  servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
  delay(time);                               // Maneuver for time ms
}

void backward(int time)                      // Backward function
{
  servoLeft.writeMicroseconds(1300);         // Left wheel clockwise
  servoRight.writeMicroseconds(1700);        // Right wheel counterclockwise
  delay(time);                               // Maneuver for time ms
}


