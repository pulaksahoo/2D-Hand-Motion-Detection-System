#include <Keyboard.h>
const int ldrPin0 = A0;
const int ldrPin1 = A1;
const int ldrPin2 = A2;
const int ldrPin3 = A3;
int ldrPin;
long count=0;
int thvalue0;
int thvalue1;
int thvalue2;
int thvalue3;
int ldrstatus0;
int ldrstatus1;
int ldrstatus2;
int ldrstatus3;

void setup() {
  // put your setup code here, to run once:
//  pinMode(ldrPin0, INPUT);
//  pinMode(ldrPin1, INPUT);
//  pinMode(ldrPin2, INPUT);
//  pinMode(ldrPin3, INPUT);
 Keyboard.begin();

}

void loop() {
delay(1000);

if(thvalue0==0 && analogRead(ldrPin0)!=0){
ldrPin=ldrPin0;
thvalue0=threshold();
Serial.println("thvalue0");
Serial.println(thvalue0);

}
if(thvalue1==0 && analogRead(ldrPin1)!=0){
  ldrPin=ldrPin1;
  thvalue1=threshold();
  Serial.println("thvalue1");
  Serial.println(thvalue1);
}
if(thvalue2==0 && analogRead(ldrPin2)!=0){
  ldrPin=ldrPin2;
  thvalue2=threshold();
  Serial.println("thvalue2");
  Serial.println(thvalue2);
}
if(thvalue3==0 && analogRead(ldrPin3)!=0){
  ldrPin=ldrPin3;
  thvalue3=threshold();
  Serial.println("thvalue3");
  Serial.println(thvalue3);
}
ldrstatus0 = analogRead(ldrPin0);
ldrstatus1 = analogRead(ldrPin1);
ldrstatus2 = analogRead(ldrPin2);
ldrstatus3 = analogRead(ldrPin3);

//Serial.println("ldr0");
//Serial.println(ldrstatus0);
//Serial.println("ldr1");
//Serial.println(ldrstatus1);
//Serial.println(ldrstatus0);
int running=0;
if(ldrstatus0>(thvalue0+100) && running!=1){
  Serial.println("ldr0 ldr1");
  Serial.println(ldrstatus0);
  Serial.println(thvalue0);
  running=ldr_function_detected_right_to_left();

}
if(ldrstatus1>(thvalue1+100) && running!=1){
  Serial.println("ldr1 ldr0");
  Serial.println(ldrstatus1);
  Serial.println(thvalue1);
  running=ldr_function_detectedleft_to_right();

}
if(ldrstatus2>(thvalue2+100) && running!=1){
  Serial.println("ldr2 ldr3");
  Serial.println(ldrstatus2);
  Serial.println(thvalue2);
  running=ldr_function_detected_down_to_up();

}
if(ldrstatus3>(thvalue3+100) && running!=1){
  Serial.println("ldr3 ldr2");
  Serial.println(ldrstatus3);
  Serial.println(thvalue3);
  running=ldr_function_detected_up_to_down();

}
running=0;
}

int threshold(){
  int ldrStatus = analogRead(ldrPin);
  long ldrsum = 0;
  int var = 0;
while(var < 100){
  ldrStatus = analogRead(ldrPin);
//  Serial.println(ldrStatus);
  ldrsum=ldrsum+ldrStatus;
//  Serial.println(ldrsum);
  // do something repetitive 200 times
  var++;
}
Serial.println(int(ldrsum/100));
return int(ldrsum/100);
}
int ldr_function_detected_right_to_left(){
  int counter=0;
  while(analogRead(ldrPin1)<(thvalue1+100) && counter<10000){
    Serial.println(counter);
 counter++;
  }
  if(counter<10000 && counter>50){
    
//  delay(1000);
Serial.println(counter);
Keyboard.press(KEY_LEFT_ARROW );
Keyboard.releaseAll();
  Serial.println("right to left");
  
  }
  return 1;
}
int ldr_function_detectedleft_to_right(){
  int counter=0;
  while(analogRead(ldrPin0)<(thvalue0+100) && counter<10000){
    
    Serial.println(counter);
  counter++;
  }
  if(counter<10000 && counter>50){
   Serial.println(counter);
   Keyboard.press(KEY_RIGHT_ARROW );
   Keyboard.releaseAll();
  Serial.println("left to right");
  }
  return 1;
}
int ldr_function_detected_down_to_up(){
  
  int counter=0;
  while(analogRead(ldrPin3)<(thvalue3+100) && counter<10000){
    Serial.println(counter);
 counter++;
  }
  if(counter<10000 && counter>50){
    
//  delay(1000);
Serial.println(counter);
Keyboard.press(KEY_UP_ARROW );
   Keyboard.releaseAll();
  Serial.println("down to up");
  
  }
  return 1;
}
int ldr_function_detected_up_to_down(){
  int counter=0;
  while(analogRead(ldrPin2)<(thvalue2+100) && counter<10000){
    Serial.println(counter);
 counter++;
  }
  if(counter<10000 && counter>50){
    
//  delay(1000);
Serial.println(counter);
Keyboard.press(KEY_DOWN_ARROW );
   Keyboard.releaseAll();
  Serial.println("up to down");
  
  }
  return 1;
}

