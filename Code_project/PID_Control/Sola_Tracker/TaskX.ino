void Task1(void *pvParameter)
{
  while (1)
  {
    if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE)
    {
      currentTime = millis();
      dt = (currentTime - previousTime) * 0.001;
      previousTime = currentTime;
      valueLDR1 = analogRead(LDR2);
      valueLDR2 = analogRead(LDR3) + 500;
      xSemaphoreGive(xMutex);
    }
    vTaskDelay(50);

  }
}

void Task2(void *pvParameter)
{
  while (1)
  {
    if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE)
    {
      Error = valueLDR1 - valueLDR2;
      d_Error = (Error - p_Error) / dt;
      p_Error = Error;
      i_Error += Error * dt;
      ut = Kp * Error + Ki * i_Error + Kd * d_Error;
//      Serial.print("X :  ");
//      Serial.print(valueLDR1);
//      Serial.print(" ");
//      Serial.print(valueLDR2);
      //                Serial.print(" ");
      //        Serial.print(Error);
      //        Serial.print(" ");

      Errorut1 = map(ut, Min, Max, 3, -3);
      servovlue1 += Errorut1;
      if (servovlue1 < 0)
        servovlue1 = 0;
      else if (servovlue1 > 180)
        servovlue1 = 180;

      myservo.write(servovlue1);
//      Serial.print(Errorut1);
//      Serial.print(" ");
//      Serial.print(servovlue1);
//      Serial.print("x: ");
      
      xSemaphoreGive(xMutex);
    }
    vTaskDelay(50);
  }
}
