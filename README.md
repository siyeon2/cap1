# Capstone design 1
</br>
</br>

>_3월 / ?_
</br>
Raspberry Pi 4B Configuration Bullseye 32bits

Find Dataset - roboflow('helmet', 'head', 'person')


***


>_3월 / ?_
</br>
Data Learning with Colab : Eboch 50 -> 100

best.pt -> raspberry pi (usb) : error pytorch


***


>_3월 / ?_
</br>
Raspberry Pi 4B Configuration Bullseye 64bits

Install pytorch(1.11.0) , torchvision(0.12.?)

error : None 'shape' ? , 1/1 ... open 0 


***


>_3월 / ?_ 
</br>
Change from pi camera to webcam ,  Change the line of the pi camera

speed problem : imgsz=(640, 640) -> imgsz=(160, 160) & default=[160]

***


>_4월 / ?_
</br>

# Raspberry pi and Arduino Uart Communication

Recognize specific objects('helmet')

helmet : Serial Moniter = 49


***


>_5월 / 03_
</br>

# Update Arduino Code

PIR * 4

Moter

Switch

***

>_5월 / 08_
</br>

# Arduino Error

Error : avrdude: ser_open can t open device com3

-> Change to new Arduino : com5

</br>

# PIR sensor * 4 

-> Sensing distance adjustment complete


***

>_5월 / 15_
</br>

# Arduino_PIR ERROR

    void stop(){
        digitalWrite(IN1Pin, HIGH);
        analogWrite(EN1Pin, 0); 
        
        digitalWrite(IN2Pin, HIGH);
        analogWrite(EN2Pin, 0); 

        digitalWrite(IN3Pin, HIGH);
        analogWrite(EN3Pin, 0); 

        digitalWrite(IN4Pin, HIGH);
        analogWrite(EN4Pin, 0); 
        while(digitalRead(pir1) == HIGH || digitalRead(pir2) == HIGH || digitalRead(pir3) == HIGH || digitalRead(pir4) == HIGH){}
     }
 
stop() 함수에서 pir 센서의 상태를 확인하는 부분에서 무한 루프를 돌게 된다.
이는 pir 센서가 감지되었을 때 모터를 정지시키고, pir 센서가 더 이상 감지되지 않을 때까지 기다리기 위함임. 그러나 pir 센서가 하나라도 계속해서 감지되는 경우, 무한 루프를 돌게 되어 프로그램이 멈추게 된다.

</br>

# Update

    void stop(){
      digitalWrite(IN1Pin, HIGH);
      analogWrite(EN1Pin, 0); 
        
      digitalWrite(IN2Pin, HIGH);
      analogWrite(EN2Pin, 0); 

      digitalWrite(IN3Pin, HIGH);
      analogWrite(EN3Pin, 0); 

     digitalWrite(IN4Pin, HIGH);
     analogWrite(EN4Pin, 0); 

    
      int pirCount = 0;
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
          delay(100);
        }
      }

stop 함수에서 pir 센서 3개가 감지된 상태에서 모터를 정지시키기 전에, while문을 사용하여 pir 센서가 모두 감지되지 않을 때까지 대기한다. 
3개 이상의 pir 센서가 감지될 때까지 while 문으로 대기하다가, 3개 이상이 감지되면 정지가 되도록 구현한다.



***



>_5월 / 16_
</br>

# Original Code

    if(pirCount >= 3){
        digitalWrite(IN1Pin, HIGH);
        analogWrite(EN1Pin, 0); 
        
        digitalWrite(IN2Pin, HIGH);
        analogWrite(EN2Pin, 0); 

        digitalWrite(IN3Pin, HIGH);
        analogWrite(EN3Pin, 0); 

        digitalWrite(IN4Pin, HIGH);
        analogWrite(EN4Pin, 0); 
    Serial.println("detected!");
    pirCount = 0;
    }else{
    Serial.println("no detected! ");
    }


# Code update_1

    if(pirCount >= 3 && !detected){
        Serial.println("detected!");
        detected = true;
        delay(10000);
    
     pirCount = 0;
     detected = false;

    }else{
     Serial.println("no detected! ");
     }
pirCount>=3 < ... > stop(); 대신 delay 넣기

# Code Update_2

    bool detected = false;
    < ... >
    if(pirCount >= 3 && !detected){
        Serial.println("detected!");
        detected = true;
        delay(10000);
    
     pirCount = 0;

    }else{
     Serial.println("no detected! ");
     }
한 번 인식된 pir 센서는 pirCount 값이 누적되지 않게 재인식 방지

# Code Update_3

    < ... >
    pirCount = 0;
    detected = false;
    < ... >
   pir 센서 3개 이상이 감지되면 정지되지만 일회성 문제로 코드 수정
