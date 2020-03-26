/* 
 * Wombatics OTTO - Avoid Obstacles
 * https://www.wombatics.com/
 * https://www.facebook.com/wombaticsco/ 
 * https://github.com/wombatics/
*/

#include <Servo.h> 
#include <Oscillator.h>
#include <US.h>
#include <Otto.h>

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

#define PIN_TRIGGER 7
#define PIN_ECHO    8
#define PIN_LED     13
#define PIN_BUZZER  12

#define TRIM_LEFT_LEG   0 
#define TRIM_RIGHT_LEG  0
#define TRIM_LEFT_FOOT  0
#define TRIM_RIGHT_FOOT 0

Otto Otto;  //This is Otto!

void setup()
{
  Serial.begin(9600);
  
  //Set the servo pins
  Otto.init(PIN_LEFT_LEG,PIN_RIGHT_LEG,PIN_LEFT_FOOT,PIN_RIGHT_FOOT,true, A6, PIN_BUZZER, PIN_TRIGGER, PIN_ECHO);
  Otto.setTrims(TRIM_LEFT_LEG,TRIM_RIGHT_LEG, TRIM_LEFT_FOOT, TRIM_RIGHT_FOOT);
  Otto.home();
  delay(2000);
 
}

///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop() 
{
  bool obstacleDetected = false;
  
  obstacleDetected = obstacleDetector(); 
  
  if(obstacleDetected)
  { 
        Otto.sing(S_surprise); 
        Otto.walk(10,1000,BACKWARD); 
        delay(1000);
        Otto.sing(S_happy);
        Otto.turn(10,1000,RIGHT);                
        delay(2000); 
          
   }        
   else
   { 
          Otto.walk(1,1000,FORWARD);  
    }          
 }  

///////////////////////////////////////////////////////////////////
//-- Function to read distance sensor 
bool obstacleDetector()
{
   int distance = Otto.getDistance();
   
   Serial.println(distance);
   
   if(distance<15)
   {
      return true;
   }
   else
   {
      return false;
   }

}
