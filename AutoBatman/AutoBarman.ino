#include <Servo.h> 

Servo servo;  
int pinsLED[]{3, 5, 6, 7};
int pinsOutput[]{2, 3, 5, 6, 7, 8};
int pinsInput[]{4, 10};
boolean pressed = true; 
int countStack = 1; 

void setup() { 
  for(int i = 0; i < 6; i++)
  {
    pinMode(pinsOutput[i], OUTPUT);
  } 
  for(int i = 0; i < 2; i++)
  {
    pinMode(pinsInput[i], INPUT_PULLUP);
  } 
  servo.attach(9); 
} 

void loop() { 
digitalWrite(2, HIGH); 
int statusCountButton = !digitalRead(10); 

if (statusCountButton && !pressed) 
{ 
count++; 
digitalWrite(pinsLED[count - 2], HIGH); 

if(count > 5){ 
countStack = 1; 
for(int i = 0; i < 4; i++) 
digitalWrite(pinsLED[i], LOW); 
}; 

Pressed = true; 
} 

if (!statusCountButton && pressed) 
{ 
pressed = false; 
} 
int buttonStart = digitalRead(4); 

if (buttonStart == LOW) 
{ 
for(int i = 30; i<=(30*countStack); i+=30){
servo.write(i); 
delay(1500); 
Pour(); 
} 

servo.write(30); 
countStack = 1; 

for(int i = 0; i < 4; i++) 
digitalWrite(pinsLED[i], LOW); 

} 
} 
void Pour(){ 
digitalWrite(8, HIGH); 
delay(800); 
digitalWrite(8, LOW); 
delay(4000); 
} 
