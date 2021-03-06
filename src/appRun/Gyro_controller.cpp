#include "Gyro_controller.h"
Gyro_controller::Gyro_controller()
{
  mpu.initialize();
  Serial.println("<<<<Gyro has been initialized>>>>");
  // should prompt to option to calibrate, change sensitivity
}

void Gyro_controller::changeView()
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  mouse_x = -(gz)/sensitivity_x;     //gz+15
  mouse_y = (gy- mouse_y_bias)/sensitivity_y;     //gy-100

  Serial.print("gz = ");
  Serial.print(gz);
  Serial.print(" | gy = ");
  Serial.print(gy);
  
  Serial.print("\nX = ");
  Serial.print(mouse_x);
  Serial.print(" | Y = ");
  Serial.println(mouse_y);
  
  Mouse.move(mouse_x, mouse_y,0);
}


