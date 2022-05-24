#include <ESP32Servo.h> 
Servo myservo,myservoy;
int servoPin = 17; 
int servoPiny = 16; 
double P = 25; //25
double I = 8;  //8
double D = 1; //1
double Max = 84017.39; //72375
double Min = -95756.30; //-72375
double Max_y = 83364.40; //72375
double Min_y = -89044.80; //-72375
void Task1(void *pvParameter);
void Task2(void *pvParameter);
void Task3(void *pvParameter);
void Task4(void *pvParameter);
SemaphoreHandle_t  xMutex;

#define LDR1 A0 ///y
#define LDR2 A3 ///x
#define LDR3 A6 ///x
#define LDR4 A7 ///y
/////////////////x/////////////////////////////
unsigned long currentTime, previousTime;
double dt = 0;
double Error = 0;
double d_Error = 0;
double p_Error = 0;
double i_Error = 0;
double ut =0;
double Kp = P; //25
double Ki = I;  //8
double Kd = D;  //1
int valueLDR1 = 0;
int valueLDR2 = 0;
int servovlue1 = 90;
int Errorut1 = 0;
/////////////////y/////////////////////////////
unsigned long currentTime_y, previousTime_y;
double dt_y = 0;
double Error_y = 0;
double d_Error_y = 0;
double p_Error_y = 0;
double i_Error_y = 0;
double ut_y =0;
double Kp_y = P;
double Ki_y = I;
double Kd_y = D;
int valueLDR3 = 0;
int valueLDR4 = 0;
int Errorut2 = 0;
int servovlue2 = 90;
void setup() {
  // put your setup code here, to run once:
  xMutex = xSemaphoreCreateMutex();
  Serial.begin(115200);
  myservo.setPeriodHertz(50);
  myservo.attach(servoPin, 500, 2400); 
  myservoy.setPeriodHertz(50);
  myservoy.attach(servoPiny, 500, 2400); 
  xTaskCreatePinnedToCore(Task1, "Task1", 1024, NULL, 50, NULL, 0);
  xTaskCreatePinnedToCore(Task2, "Task2", 1024, NULL, 10, NULL, 0);
  xTaskCreatePinnedToCore(Task3, "Task3", 1024, NULL, 5, NULL, 0);
  xTaskCreatePinnedToCore(Task4, "Task4", 1024, NULL, 0, NULL, 0);
//  myservo.write(servovlue1);
//  myservoy.write(servovlue2);
  currentTime = millis();
  previousTime = currentTime;
  currentTime_y = millis();
  previousTime_y = currentTime_y;
}

void loop() {
//   put your main code here, to run repeatedly:
//  Serial.print(analogRead(LDR1));
//  Serial.print(" ");
//  Serial.print(analogRead(LDR2));
//  Serial.print(" ");
//  Serial.print(analogRead(LDR3));
//  Serial.print(" ");
//  Serial.println(analogRead(LDR4));
}
