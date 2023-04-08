#include <Servo.h>

Servo servo_z_axis;
Servo servo_x_axis;
Servo servo_y_axis;
Servo servo_clamp;

int x_axis_degree = 90;
int y_axis_degree = 90;
int z_axis_degree = 85;
int clamp_degree = 90;


#define left_joystick_x A0
#define left_joystick_y A1
#define right_joystick_x A2
#define right_joystick_y A3


void setup() {
  Serial.begin(9600);
  
  servo_z_axis.attach(3);
  servo_clamp.attach(5);
  servo_x_axis.attach(6);
  servo_y_axis.attach(9);
}

void loop() {
  int left_joystick_x_value = analogRead(left_joystick_x);
  int left_joystick_y_value = analogRead(left_joystick_y);
  int right_joystick_x_value = analogRead(right_joystick_x);
  int right_joystick_y_value = analogRead(right_joystick_y);

  if(left_joystick_x_value < 340) y_axis_degree -=7;
  else if(left_joystick_x_value > 680) y_axis_degree +=7;

  if(left_joystick_y_value < 340) clamp_degree -=5;
  else if(left_joystick_y_value > 680) clamp_degree +=5;

  if(right_joystick_x_value < 340) x_axis_degree -=7;
  else if(right_joystick_x_value > 680) x_axis_degree +=7;

  if(right_joystick_y_value < 340) z_axis_degree -=7;
  else if(right_joystick_y_value > 680) z_axis_degree +=7;

  
  z_axis_degree = min(145, max(15, z_axis_degree));
  x_axis_degree = min(175, max(40, x_axis_degree));
  y_axis_degree = min(150, max(5, y_axis_degree));
  clamp_degree = min(90, max(75, clamp_degree));

  Serial.print("x_axis_degree : ");
  Serial.print(x_axis_degree);
  Serial.print(", y_axis_degree : ");
  Serial.print(y_axis_degree);
  Serial.print(", z_axis_degree 4 : ");
  Serial.print(z_axis_degree);
  Serial.print(", clamp_degree : ");
  Serial.println(clamp_degree);
  
  servo_clamp.write(clamp_degree);  
  servo_x_axis.write(x_axis_degree);
  servo_y_axis.write(y_axis_degree);
  servo_z_axis.write(z_axis_degree);
}
