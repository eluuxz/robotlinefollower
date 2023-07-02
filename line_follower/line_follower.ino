#include <Arduino.h>
#include <TB6612_ESP32.h>

#define s1 16
#define s2 17
#define s3 18
#define s4 19
#define s5 21
#define s6 22
#define s7 23
#define s8 25
#define ir 26

#define AIN1 13
#define BIN1 4
#define AIN2 27
#define BIN2 2
#define PWMA 14
#define PWMB 15
#define STBY 33

byte data[8];

const int offsetA = 1;
const int offsetB = 1;

Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY,5000 ,8,1 );
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY,5000 ,8,2 );

void setup() {
  Serial.begin(9600);
  pinMode(ir, OUTPUT);
  digitalWrite(ir, HIGH);

  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  pinMode(s3,INPUT);
  pinMode(s4,INPUT);
  pinMode(s5,INPUT);
  pinMode(s6,INPUT);
  pinMode(s7,INPUT);
  pinMode(s8,INPUT);

}

void loop() {
//AMBIL DATA SENSOR
data[0] = digitalRead(s1);
data[1] = digitalRead(s2);
data[2] = digitalRead(s3);
data[3] = digitalRead(s4);
data[4] = digitalRead(s5);
data[5] = digitalRead(s6);
data[6] = digitalRead(s7);
data[7] = digitalRead(s8);

//TAMPILKAN DATA SENSOR
for(int a=0;a<8;a++){
 Serial.print(data[a]); 
}
Serial.println();

//SELEKSI DATA SENSOR
if(data[0]== 0 && data[1]== 0 && data[2]== 0 && data[3]== 1 && data[4]== 1 && data[5]== 0 && data[6]== 0 && data[7]==0){
 motor2.drive(230); motor1.drive(230);
delay(1);
}
else if(data[0]== 0 && data[1]== 0 && data[2]== 0 && data[3]== 0 && data[4]== 1 && data[5]== 1 && data[6]== 0 && data[7]==0){
  motor2.drive(60);motor1.drive(100);
  delay(1);
}
else if(data[0]== 0 && data[1]== 0 && data[2]== 0 && data[3]== 0 && data[4]== 0 && data[5]== 1 && data[6]== 1 && data[7]==0){
  motor2.drive(0);motor1.drive(100);
  delay(1);
}
else if(data[0]== 0 && data[1]== 0 && data[2]== 0 && data[3]== 0 && data[4]== 0 && data[5]== 0 && data[6]== 1 && data[7]==1){
  motor2.drive(0);motor1.drive(130);
  delay(1);
}
else if(data[0]== 0 && data[1]== 0 && data[2]== 0 && data[3]== 0 && data[4]== 0 && data[5]== 0 && data[6]== 0 && data[7]==1){
  motor2.drive(0);motor1.drive(150);
  delay(1);
}
else if(data[0]== 0 && data[1]== 0 && data[2]== 1 && data[3]== 1 && data[4]== 0 && data[5]== 0 && data[6]== 0 && data[7]==0){
  motor2.drive(100);motor1.drive(60);
  delay(1);
}
else if(data[0]== 0 && data[1]== 1 && data[2]== 1 && data[3]== 0 && data[4]== 0 && data[5]== 0 && data[6]== 0 && data[7]==0){
  motor2.drive(100);motor1.drive(0);
  delay(1);
}
else if(data[0]== 1 && data[1]== 1 && data[2]== 0 && data[3]== 0 && data[4]== 0 && data[5]== 0 && data[6]== 0 && data[7]==0){
  motor2.drive(130);motor1.drive(0);
  delay(1);
}
else if(data[0]== 1 && data[1]== 0 && data[2]== 0 && data[3]== 0 && data[4]== 0 && data[5]== 0 && data[6]== 0 && data[7]==0){
  motor2.drive(150);motor1.drive(0);
  delay(1);
}

}
