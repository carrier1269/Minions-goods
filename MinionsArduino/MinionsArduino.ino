#include<SoftwareSerial.h>
SoftwareSerial BLE (2,3);
String a="";
int b;

#define led1 6
#define led2 9
#define led3 10
#define led4 11

void setup() {
  Serial.begin(9600);
  BLE.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
}

void loop() {
  
 if(BLE.available())
  {
   a=BLE.readStringUntil('c'); 
   b=a.toInt();
   light();
   Serial.println(b);
  }
}

void light()
{
  analogWrite(led1,b);
  analogWrite(led2,b);
  analogWrite(led3,b);
  analogWrite(led4,b);
}
