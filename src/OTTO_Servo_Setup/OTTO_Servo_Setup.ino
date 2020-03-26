/* 
 * Wombatics OTTO - Ultrasonic Test
 * https://www.wombatics.com/
 * https://www.facebook.com/wombaticsco/ 
 * https://github.com/wombatics/
*/

#include <Servo.h> 
#include <Oscillator.h>


/*
                 --------------- 
                |     O   O     |
                |---------------|
RIGHT LEG 4==>  |               | <== LEFT LEG 3
                 --------------- 
                    ||     ||
RIGHT FOOT 6==>   -----   ------  <== LEFT FOOT 5
                 |-----   ------|
*/

#define PIN_LEFT_LEG   3   
#define PIN_RIGHT_LEG  4  
#define PIN_LEFT_FOOT  5  
#define PIN_RIGHT_FOOT 6 

#define N_SERVOS 4 // There are four servos 
Oscillator servo[N_SERVOS];

void setup()
{
  servo[0].attach(PIN_LEFT_LEG); 
  servo[1].attach(PIN_RIGHT_LEG); 
  servo[2].attach(PIN_LEFT_FOOT); 
  servo[3].attach(PIN_RIGHT_FOOT); 

  //Test 45 degree
  servo[0].SetPosition(45);
  servo[1].SetPosition(45);
  servo[2].SetPosition(45);
  servo[3].SetPosition(45);
  delay(1000);

  //Test 90 degree
  servo[0].SetPosition(90);
  servo[1].SetPosition(90);
  servo[2].SetPosition(90);
  servo[3].SetPosition(90);
  delay(1000);  

  //Test 135 degree
  servo[0].SetPosition(135);
  servo[1].SetPosition(135);
  servo[2].SetPosition(135);
  servo[3].SetPosition(135);
  delay(1000);  

  // Set Final position to 90 degree for assembly
  servo[0].SetPosition(90);
  servo[1].SetPosition(90);
  servo[2].SetPosition(90);
  servo[3].SetPosition(90);
  
  delay(1000);
  
}

void loop() 
{

 
}  
