#include <ESP32Servo.h>
Servo myservo, myservoy;
int servoPin = 17;
int servoPiny = 16;
int pos_x = 0;
int pos_y = 0;


#define LDR1 A0 ///y
#define LDR2 A3 ///x
#define LDR3 A6 ///x
#define LDR4 A7 ///y
float LDR_sersor(String Name, int LDR_Pin)
{
  float LDR = 0;
  float Volt = 0.0;
  float Lux = 0;
  if (Name != "3") {
    float LDR = analogRead(LDR_Pin);
    float Volt = (3.3 / 4096) * LDR;
    float Lux = 42.0 * pow(Volt, 3.15);
    //    Serial.print("Lux ");
    //    Serial.print(Name);
    //    Serial.print(" :");
    //    Serial.println(Lux);
    return Lux;
  }
  else
  {
    float LDR = analogRead(LDR_Pin);
    float Volt = (3.3 / 4096) * (LDR + 300);
    float Lux = 42.0 * pow(Volt, 3.15);
    //    Serial.print("Lux ");
    //    Serial.print(Name);
    //    Serial.print(" :");
    //    Serial.println(Lux);
    return Lux;
  }
}
void setup()
{

  Serial.begin(9600);
  myservo.setPeriodHertz(50);
  myservo.attach(servoPin, 500, 2400);
  myservoy.setPeriodHertz(50);
  myservoy.attach(servoPiny, 500, 2400);
  pos_x = 90;
  pos_y = 120;
  myservo.write(pos_x);
  myservoy.write(pos_y);
}

void loop()
{
  float Lux_1 = LDR_sersor("1", LDR1);
  float Lux_2 = LDR_sersor("2", LDR2);
  float Lux_3 = LDR_sersor("3", LDR3);
  float Lux_4 = LDR_sersor("4", LDR4);
  if (abs(Lux_1 - Lux_4) > 100 || abs(Lux_2 - Lux_3) > 100 )
  {
    if (Lux_1 > Lux_2 && Lux_1 > Lux_3 && Lux_1 > Lux_4)
    {
      pos_y += map(Lux_1-Lux_4,-1800,1800,0,3);
      if (pos_y > 180)
      {
        pos_y = 180;
      }
      myservoy.write(pos_y);
    }
    else if (Lux_2 > Lux_1 && Lux_2 > Lux_3 && Lux_2 > Lux_4)
    {
      pos_x -= map(Lux_2-Lux_3,-1800,1800,0,3);
      if (pos_x < 0)
      {
        pos_x = 0;
      }
      myservo.write(pos_x);
    }
    else if (Lux_3 > Lux_1 && Lux_3 > Lux_2 && Lux_3 > Lux_4)
    {
      pos_x += map(Lux_3-Lux_2,-1800,1800,0,3);
      if (pos_x > 180)
      {
        pos_x = 180;
      }
      myservo.write(pos_x);
    }
    else if (Lux_4 > Lux_1 && Lux_4 > Lux_2 && Lux_4 > Lux_3)
    {
      pos_y -= map(Lux_4-Lux_1,-1800,1800,0,3);
      if (pos_y < 0)
      {
        pos_y = 0;
      }
      myservoy.write(pos_y);

    }
  }

  //  Serial.print("pos_X :");
  //  Serial.println(pos_x);
  //  Serial.print("pos_Y :");
  //  Serial.println(pos_y);
  //  Serial.println("=============================");
  delay(50);

}
