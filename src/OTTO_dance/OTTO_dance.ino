/* 
 * Wombatics OTTO - Moonwalk Dance
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


void loop()
{
 
  Otto.moonwalker(10);

  delay(3000);
}

/*        
    //-- Predetermined Motion Functions
    void jump(float steps=1, int T = 2000);

    void walk(float steps=4, int T=1000, int dir = FORWARD);
    void turn(float steps=4, int T=2000, int dir = LEFT);
    void bend (int steps=1, int T=1400, int dir=LEFT);
    void shakeLeg (int steps=1, int T = 2000, int dir=RIGHT);

    void updown(float steps=1, int T=1000, int h = 20);
    void swing(float steps=1, int T=1000, int h=20);
    void tiptoeSwing(float steps=1, int T=900, int h=20);
    void jitter(float steps=1, int T=500, int h=20);
    void ascendingTurn(float steps=1, int T=900, int h=20);

    void moonwalker(float steps=1, int T=900, int h=20, int dir=LEFT);
    void crusaito(float steps=1, int T=900, int h=20, int dir=FORWARD);
    void flapping(float steps=1, int T=1000, int h=20, int dir=FORWARD);
 */
