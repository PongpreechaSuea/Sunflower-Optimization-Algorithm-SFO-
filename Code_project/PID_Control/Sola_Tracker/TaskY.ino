void Task3(void *pvParameter)
{
  while (1)
  {
    if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE)
    {
      currentTime_y = millis();
      dt_y = (currentTime_y - previousTime_y) * 0.001;
      previousTime_y = currentTime_y;
      valueLDR3 = analogRead(LDR1);
      valueLDR4 = analogRead(LDR4);
      xSemaphoreGive(xMutex);
    }
    vTaskDelay(50);

  }
}

void Task4(void *pvParameter)
{
  while (1)
  {
    if (xSemaphoreTake(xMutex, portMAX_DELAY) == pdTRUE)
    {
      Error_y = valueLDR3 - valueLDR4;
      d_Error_y = (Error_y - p_Error_y) / dt_y;
      p_Error_y = Error_y;
      i_Error_y += Error_y * dt_y;
      ut_y = Kp_y * Error_y + Ki_y * i_Error_y + Kd_y * d_Error_y;
      //      Serial.print("Y :  ");
      //      Serial.print(valueLDR3);
      //      Serial.print(" ");
      //      Serial.print(valueLDR4);
      //      Serial.print(" ");
      //        Serial.print(Error_y);
      //        Serial.print(" ");

      Errorut2 = map(ut_y, Min_y, Max_y, -3, 3);
      servovlue2 += Errorut2;
      if (servovlue2 < 0)
        servovlue2 = 0;
      else if (servovlue2 > 180)
        servovlue2 = 180;

      myservoy.write(servovlue2);/
      //      Serial.print(Errorut2);
      //      Serial.print(" ");
      //      Serial.print(servovlue2);
      Serial.print("Servo_X:");
      Serial.print(servovlue1);
      Serial.print(',');
      Serial.print("Servo_Y:");
      Serial.print(servovlue2);
      Serial.print(',');
      Serial.print("UT:");
      Serial.print(ut);
      Serial.print(',');
      Serial.print("UT_y:");
      Serial.print(ut_y);
      Serial.println();
      xSemaphoreGive(xMutex);
    }
    vTaskDelay(50);
  }
}
