#include<Servo.h>
Servo Serv;
char rxDato;

String conChar,Grados;

int velocidad=150,gServo;
int diferencia=100;

#define PwmI 5
#define PwmD 6
#define LlantaIT 8
#define LlantaID 9
#define LlantaDT 10
#define LlantaDD 11

void setup() {
Serial.begin(9600);
pinMode(LlantaIT,OUTPUT);
pinMode(LlantaID,OUTPUT);
pinMode(LlantaDT,OUTPUT);
pinMode(LlantaDD,OUTPUT);
Serv.attach(3);
Serv.write(90);

}

void loop() {
  if(Serial.available()>0){
    rxDato=Serial.read();
    //Serial.print(rxDato);
    if(rxDato=='v'){
      delay(10);
      while(Serial.available()){
        rxDato=Serial.read();
        conChar=conChar+rxDato;
      }
      velocidad=conChar.toInt();//0,100,130,240
      velocidad=map(velocidad,0,100,100,255);
      //Serial.println(conChar);
      conChar="";//v200
    }
    if(rxDato=='g'){
      delay(10);
      while(Serial.available()){
        rxDato=Serial.read();
        Grados=Grados+rxDato;
      }
      gServo=Grados.toInt();
      Serv.write(gServo);
      Grados="";
    }
  }
  //HACIA ADELANTA
  if(rxDato=='w'){
   digitalWrite(LlantaIT,LOW);
   digitalWrite(LlantaDT,LOW);
   digitalWrite(LlantaID,HIGH);
   digitalWrite(LlantaDD,HIGH);
   analogWrite(PwmI,velocidad);
   analogWrite(PwmD,velocidad);
  }
  //HACIA ATRAS
  if(rxDato=='x'){
   digitalWrite(LlantaIT,HIGH);
   digitalWrite(LlantaDT,HIGH);
   digitalWrite(LlantaID,LOW);
   digitalWrite(LlantaDD,LOW);
   analogWrite(PwmI,velocidad);
   analogWrite(PwmD,velocidad);
  }
  //HACIA LA DERECHA
  if(rxDato=='a'){
   digitalWrite(LlantaIT,HIGH);
   digitalWrite(LlantaDT,LOW);
   digitalWrite(LlantaID,LOW);
   digitalWrite(LlantaDD,HIGH);
   analogWrite(PwmI,velocidad);
   analogWrite(PwmD,velocidad); 
  }

  //HACIA LA IZQUIERDA
  if(rxDato=='d'){
   digitalWrite(LlantaIT,LOW);
   digitalWrite(LlantaDT,HIGH);
   digitalWrite(LlantaID,HIGH);
   digitalWrite(LlantaDD,LOW);
   analogWrite(PwmI,velocidad);
   analogWrite(PwmD,velocidad);
  }
  //DETIENE
  if(rxDato=='s'){
   digitalWrite(LlantaIT,LOW);
   digitalWrite(LlantaDT,LOW);
   digitalWrite(LlantaID,LOW);
   digitalWrite(LlantaDD,LOW);
   analogWrite(PwmI,0);
   analogWrite(PwmD,0);
  }
  //HACIA LA DERECHA ARRIBA
   if(rxDato=='e'){
   digitalWrite(LlantaIT,LOW);
   digitalWrite(LlantaDT,LOW);
   digitalWrite(LlantaID,HIGH);
   digitalWrite(LlantaDD,HIGH);
   analogWrite(PwmI,velocidad-diferencia);
   analogWrite(PwmD,velocidad);
  }
  //HACIA LA IZQUIERDA ADELANTE
  if(rxDato=='q'){
   digitalWrite(LlantaIT,LOW);
   digitalWrite(LlantaDT,LOW);
   digitalWrite(LlantaID,HIGH);
   digitalWrite(LlantaDD,HIGH);
   analogWrite(PwmI,velocidad);
   analogWrite(PwmD,velocidad-diferencia);
  }
  //HACIA LA IZQUIERDA ATRAS
  if(rxDato=='z'){
   digitalWrite(LlantaIT,HIGH);
   digitalWrite(LlantaDT,HIGH);
   digitalWrite(LlantaID,LOW);
   digitalWrite(LlantaDD,LOW);
   analogWrite(PwmI,velocidad);
   analogWrite(PwmD,velocidad-diferencia);
  }
  //HACIA LA DERECHA ATRAS
  if(rxDato=='c'){
   digitalWrite(LlantaIT,HIGH);
   digitalWrite(LlantaDT,HIGH);
   digitalWrite(LlantaID,LOW);
   digitalWrite(LlantaDD,LOW);
   analogWrite(PwmI,velocidad-diferencia);
   analogWrite(PwmD,velocidad);
  }
}
