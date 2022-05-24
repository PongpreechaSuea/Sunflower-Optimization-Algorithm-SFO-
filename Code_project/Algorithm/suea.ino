#include <ESP32Servo.h>
Servo myservo, myservoy;
//Pin motor
int servoPin = 17;
int servoPiny = 16;
int sensor_PIN[4] = {A0, A3, A6, A7};

//ค่าตำแหน่งขององศามอเตอร์
int pos_x = 0;
int pos_y = 0;

//ค่าที่ใช่เล่น
int sensor_LDR[4] = {0, 0, 0, 0};
int si_value[4] = {0, 0, 0, 0};
int di_value[4] = {0, 0, 0, 0};
int X_value[4] = {0, 0, 0, 0};
int MaxVal = 0;
int MinVal = 0;
int rad = 0;
int P = 1;
int N = 4;
int y_Update = 0;
int x_Update = 0;

//ค่าที่ใช้ในการแปลง LUX
float LDR = 0;
float Volt = 0;
float Lux = 0;

void setup() {
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

int MaxValue(int sensor_LDR[] , int length) {
  int Max = 0;
  for (int i = 0; i < length ; i++) {
    if (sensor_LDR[i] > Max ) {
      Max = int(sensor_LDR[i]);
    }
  }
  return Max;
}

int MinValue(int sensor_LDR[] , int length) {
  int Min = 10000;
  for (int i = 0; i < length ; i++) {
    if (sensor_LDR[i] < Min ) {
      Min = int(sensor_LDR[i]);
    }
  }
  return Min;
}

int radian(int MaxVal , int MinVal , int N) {
  int d_max = (abs((MaxVal * 1000 / 57296) + (MinVal * 1000 / 57296)) / (2 * N) );
  int rads = (d_max % 180) * 1000 / 57296;
  return rads;
}

int Count(int si_value[] , int length) {
  int count = 0;
  for (int i = 0; i < length ; i++) {
    if (si_value[i] == 0 ) {
      count += 1;
    }
  }
  return count;
}

void loop() {
  for (int i = 0; i < N ; i++) { //sizeof(sensor_LDR)
   if (i != 2)
   {
    LDR = analogRead(sensor_PIN[i]);
    Volt = (3.3 / 4096) * (LDR);
    Lux = 42.0 * pow(Volt, 3.15);
    sensor_LDR[i] = int(Lux);
   }
   else
   {
    LDR = analogRead(sensor_PIN[i]);
    Volt = (3.3 / 4096) * (LDR+500);
    Lux = 42.0 * pow(Volt, 3.15);
    sensor_LDR[i] = int(Lux);
   }
  }
  MaxVal = MaxValue( sensor_LDR , N );
  MinVal = MaxValue( sensor_LDR , N );
  rad = radian( MaxVal, MinVal, N);

  for (int i = 0; i < N ; i++) {
    if (MaxVal == sensor_LDR[i]) {
      si_value[i] = int(0);
    }
    else {
      int si = ( MaxVal - sensor_LDR[i] / abs(MaxVal - sensor_LDR[i]) ) ;
      si_value[i] = int(si);
    }
    int di = ( rad * (P * ((sensor_LDR[i] + sensor_LDR[i - 1]) * abs(sensor_LDR[i] + sensor_LDR[i - 1])))) % 180;
    di_value[i] = int(di);
    int X = sensor_LDR[i] + di_value[i] * si_value[i];
    X_value[i] = int(X) % 180;
  }
  int num = Count(si_value, N);
  if ((num > 2 && si_value[1] == 0) || si_value[1] == 0) {
    x_Update = ((abs(X_value[1] - X_value[2]) / 4) * (-1));
  }
  else {
    x_Update = ((abs(X_value[1] - X_value[2]) / 4));
  }

  if ((num > 2 && si_value[3] == 0) || si_value[3] == 0) {
    y_Update = ((abs(X_value[0] - X_value[3]) / 4) * (-1));
  }
  else {
    y_Update = ((abs(X_value[0] - X_value[3]) / 4));
  }
//  if (si_value[1] == 0 || si_value[3] == 0 || (num > 2 && ( si_value[1] == 0 || si_value[3] == 0)) || (num < 2 && ( si_value[1] == 0 || si_value[3] == 0))) {
//    y_Update = ((abs(X_value[0] - X_value[3]) / 4) * (-1));
//    x_Update = ((abs(X_value[1] - X_value[2]) / 4) * (-1));
//  }
//  else {
//    y_Update = ((abs(X_value[0] - X_value[3]) / 4));
//    x_Update = ((abs(X_value[1] - X_value[2]) / 4));
//  }
  pos_x = pos_x+map(x_Update,-43,43,-2,2);
  pos_y = pos_y+map(y_Update,-43,43,-2,2);
//  pos_x = pos_x+x_Update;
//  pos_y = pos_y+y_Update;
  if(pos_x>180)
  {
    pos_x = 180;
  }
  else if(pos_x<0)
  {
    pos_x = 0;
  }

  if(pos_y>180)
  {
    pos_y = 180;
  }
  else if(pos_y<0)
  {
    pos_y = 0;
  }
  myservo.write(pos_x);
  myservoy.write(pos_y);
  Serial.print(x_Update);
  Serial.print(" ");
  Serial.print(pos_x);
  Serial.print(y_Update);
  Serial.print(" ");
  Serial.println(pos_y);
  Serial.println("=============================");
//  delay(10);
}
