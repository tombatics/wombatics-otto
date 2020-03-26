/* 
 * Wombatics OTTO - Ultrasonic Test
 * https://www.wombatics.com/
 * https://www.facebook.com/wombaticsco/ 
 * https://github.com/wombatics/
*/

#define trigPin 7
#define echoPin 8
#define led     13
#define buzzer  12



void setup() 
{
  Serial.begin (9600);
  ultrasonicSetup();
  
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
}

void loop() 
{
  long distance;

  distance = ultrasonicDistance();

  Serial.print(distance);
  Serial.println(" cm");

  if( distance < 20)
  {
    digitalWrite(led, HIGH);
    tone(buzzer, 100, 10);
  }
  else
  {
    digitalWrite(led, LOW);
  }
  
  delay(100);
}

// Functions for Ultrasonic
void ultrasonicSetup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

long ultrasonicDistance()
{
  long duration, distance;

  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH, 24000);
  distance =  duration / 58;
  
  if (distance >= 400 || distance <= 0)
  {
    distance = 9999;
  }

  return distance;
}
