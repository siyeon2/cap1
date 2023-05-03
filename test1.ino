// 3번과 4번 핀은 모터 제어에 관한 핀
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
int sw2 = 15;


// rip
int pir1 = 6;
int pir2 = 7;
int pir3 = 12;
int pir4 = 13;

void setup() {

  pinMode(IN1Pin, OUTPUT);
  pinMode(IN2Pin, OUTPUT); 
  pinMode(IN3Pin, OUTPUT);
  pinMode(IN4Pin, OUTPUT);
  
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  
  pinMode(pir1,INPUT);
  pinMode(pir2,INPUT);
  pinMode(pir3,INPUT);
  pinMode(pir4,INPUT);


  Serial.begin(9600);
  
}

void loop() {

  if(digitalRead(pir1)==HIGH){
   
    stop();
    Serial.println("yes");
  }
  else{
    Serial.println("no");
  }
 /* int pirCount = 0;

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

  if(pirCount >= 3){
    stop();
    Serial.println("Motion detected!");
  }*/


  if(digitalRead(sw1)==HIGH)    // 스위치 눌리면
    {
      go();
      delay(50);
      stop();
      
    }
 
  if(digitalRead(sw2)==HIGH)
    { 
      stop();
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
/*while(digitalRead(pir1) == HIGH || digitalRead(pir2) == HIGH || digitalRead(pir3) == HIGH || digitalRead(pir4) == HIGH)*/
        while(digitalRead(pir1)==HIGH){
        }

    }
  