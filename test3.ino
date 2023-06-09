#include<SoftwareSerial.h>

int IN1Pin = 2;
int IN2Pin = 4;
int IN3Pin = 8;
int IN4Pin = 10;

// 5번핀은 모터의 힘을 설정해주는 핀
int EN1Pin = 3;
int EN2Pin = 5;
int EN3Pin = 9;
int EN4Pin = 11;



// switch
int sw1 = 14;


// pir
int pir1 = 6;
int pir2 = 7;
int pir3 = 12;
int pir4 = 13;

bool detected = false; // pir


void setup() {

  pinMode(IN1Pin, OUTPUT);
  pinMode(IN2Pin, OUTPUT); 
  pinMode(IN3Pin, OUTPUT);
  pinMode(IN4Pin, OUTPUT);
  
  pinMode(sw1, INPUT);
  
  
  pinMode(pir1,INPUT);
  pinMode(pir2,INPUT);
  pinMode(pir3,INPUT);
  pinMode(pir4,INPUT);


  Serial.begin(9600);
  
}


void loop() {

 int pirCount = 0;

  if(digitalRead(pir1) == HIGH){
   delay(1000);
    //Serial.println("a");
    pirCount++;
  }
  if(digitalRead(pir2) == HIGH){
   delay(1000);
   //Serial.println("b");
    pirCount++;
  }
  if(digitalRead(pir3) == HIGH){
   delay(1000);
   //Serial.println("c");
   pirCount++;
    
  }
  if(digitalRead(pir4) == HIGH){
   delay(1000);
   //Serial.println("d");
   pirCount++;
  }
   Serial.println(pirCount);
   delay(1000);

if(pirCount >= 3 && !detected){
    Serial.println("detected!");
    delay(5000);
    detected = true;
    stop();
    
    pirCount = 0;
    detected = false;

}else{
    Serial.println("no detected! ");
    }


if(Serial.available()>-2){
  
  char data = Serial.read();
  //Serial.println(data);
  delay(500);
        
  if(digitalRead(sw1)==LOW && data == 'a'){       
  go(); 
  }else{
  
  digitalWrite(IN1Pin, HIGH);
  analogWrite(EN1Pin, 0); 
        
  digitalWrite(IN2Pin, HIGH);
  analogWrite(EN2Pin, 0); 

  digitalWrite(IN3Pin, HIGH);
  analogWrite(EN3Pin, 0); 

  digitalWrite(IN4Pin, HIGH);
  analogWrite(EN4Pin, 0);
    }
  }
}



void go(){
  
 digitalWrite(IN1Pin, HIGH); 
 analogWrite(EN1Pin, 200); 
 
 digitalWrite(IN2Pin, LOW); 
 analogWrite(EN2Pin, 200);  

 digitalWrite(IN3Pin, HIGH);
 analogWrite(EN3Pin,200); 
       
 digitalWrite(IN4Pin, LOW);
 analogWrite(EN4Pin, 200); 
 }

void stop(){
  
 digitalWrite(IN1Pin, HIGH);
 analogWrite(EN1Pin, 0); 
        
 digitalWrite(IN2Pin, HIGH);
 analogWrite(EN2Pin, 0); 

 digitalWrite(IN3Pin, HIGH);
 analogWrite(EN3Pin, 0); 

 digitalWrite(IN4Pin, HIGH);
 analogWrite(EN4Pin, 0); 

    /*int pirCount = 0;
    while(pirCount<3){
      pirCount = 0;
      if(digitalRead(pir1) == HIGH){
            pirCount++;
        }
        if(digitalRead(pir2) == HIGH){
            pirCount++;
        }
        if(digitalRead(pir3) == HIGH){
            pirCount++;
        }
        if(digitalRead(pir4) == HIGH){
            pirCount++;
        }
        delay(500);
       
    }*/
    
    

}