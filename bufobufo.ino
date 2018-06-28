#include <Thread.h>
#include <ThreadController.h>
#define input A0
int ledMax = 0;
int sorteio = 4;
unsigned long currentMillis = 0;
long previousMillis  =     0;   
long timeModoEspera  =    5000; 

Thread threadMain;
Thread threadEspera;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(3,INPUT);

for(int i=4;i<14;i++){
      pinMode(i,OUTPUT);
      
  }
}
int leitura = 0;
void loop() {
  // put your main code here, to run repeatedly:
  //currentMillis = millis();

 /*if (currentMillis - previousMillis >= timeModoEspera ) {   
        modoEspera();  
 }*/

if(digitalRead(3)){
  modoEspera();
  
 }{
  
leitura = analogRead(input);
leitura = map(leitura,0,1023,0,1000)*2;


if(leitura > 50){
  Serial.println(leitura);
  if(leitura > 10 && leitura <= 100){
    ledMax = 4;
  }else if(leitura > 100 && leitura <= 200){
    ledMax = 5;
  }else if(leitura > 200 && leitura <= 300){
    ledMax = 6;
  }else if(leitura > 300 && leitura <= 400){
    ledMax = 7;
  }else if(leitura > 400 && leitura <= 500){
    ledMax = 8;
  }else if(leitura > 500 && leitura <= 600){
    ledMax = 9;
  }else if(leitura > 600 && leitura <= 700){
    ledMax = 10;
  }else if(leitura > 700 && leitura <= 800){
    ledMax = 11;
  }else if(leitura > 800 && leitura <= 900){
    ledMax = 12;
  }else if(leitura > 900 ){
    ledMax = 13;
  }
  
  for(int i=4;i <= ledMax;i++){
      digitalWrite(i,HIGH);
      delay(100000/leitura);
  }
  for(int i=ledMax;i >= 4;i--){
      digitalWrite(i,LOW);
      delay(100000/leitura);
  }
  if(ledMax == 11 || ledMax == 12 || ledMax == 13){
     ganhou();
     }

  }
  

 }
}



void ganhou(){
  for(int k=1;k <= 10;k++){
        for(int i=4;i <= ledMax;i++){
          digitalWrite(i,HIGH);      
        }
        delay(500/k);
        for(int i=4;i <= ledMax;i++){
          digitalWrite(i,LOW);      
        }
        delay(500/k);
     }
     for(int k=1;k <= 10;k++){
             for(int i=4;i <= ledMax;i++){
                 digitalWrite(i,HIGH);
                  delay(10);
            }
            for(int i=ledMax;i >= 4;i--){
                digitalWrite(i,LOW);
                delay(10);
            }    
     
     }
  
  }

  void modoEspera(){
      ledMax = 13;
      ganhou();
       for(int i=4;i <= ledMax-2;i++){                
                 digitalWrite(i,HIGH);
                 delay(50);
                 digitalWrite(i+2,HIGH);
                 delay(50);
                 digitalWrite(i,LOW);
                 delay(50);
                 digitalWrite(i+2,LOW);
                 delay(50);
            }

         for(int i=ledMax;i >= 4+2;i--){                
                 digitalWrite(i,HIGH);
                 delay(50);
                 digitalWrite(i-2,HIGH);
                 delay(50);
                 digitalWrite(i,LOW);
                 delay(50);
                 digitalWrite(i-2,LOW);
                 delay(50);
            }    
       for(int k=1;k <= 10; k++){
            for(int i=4;i <= ledMax-2;i++){
                 sorteio = 4 + ( rand() % ledMax );
                 digitalWrite(sorteio,HIGH);
                 delay(5);
                 digitalWrite(sorteio,HIGH);
                 delay(5);
                 digitalWrite(sorteio,LOW);
                 delay(5);
                 digitalWrite(sorteio,LOW);
                 delay(5);
            }
       }

         for(int i=4;i <= ledMax-4;i++){                
                 digitalWrite(i,HIGH);
                 delay(50);
                 digitalWrite(i+2,HIGH);
                 delay(50);
                 digitalWrite(i+4,HIGH);
                 delay(50);
                 digitalWrite(i,LOW);
                 delay(50);
                 digitalWrite(i+2,LOW);
                 delay(50);
                 digitalWrite(i+4,LOW);
                 delay(50);
            } 
      
      for(int i=ledMax;i >= 4+4;i--){                
                 digitalWrite(i,HIGH);
                 delay(50);
                 digitalWrite(i-2,HIGH);
                 delay(50);
                 digitalWrite(i-4,HIGH);
                 delay(50);
                 digitalWrite(i,LOW);
                 delay(50);
                 digitalWrite(i-2,LOW);
                 delay(50);
                 digitalWrite(i-4,LOW);
                 delay(50);
            } 



       
       for(int i=4;i <= ledMax;i++){
            digitalWrite(i,LOW);
       }
       
      ledMax = 0;
    }
