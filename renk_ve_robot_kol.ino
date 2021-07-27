#include<Servo.h>
#define s0 8 //Bağladığımız pinlere göre tanımlamalarımızı yapıyoruz
#define s1 9
#define s2 10
#define s3 11
#define sensorOut 12

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;

int aci1;
int aci2;
int aci3;
int aci4;

int K, Y, M = 0; //3 ana renk için değişken tanımlıyoruz

void setup() {

  motor1.attach(3); 
  motor2.attach(4);
  motor3.attach(5);
  motor4.attach(2);

  pinMode(s0, OUTPUT);//S0, S1, S2 ve S3 pinlerini OUTPUT olarak tanımlıyoruz
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(sensorOut, INPUT);//OUT pinini INPUT olarak tanımlıyoruz

  digitalWrite(s1,LOW);  //Frekans ölçeğimizi %20 olarak tanımlıyoruz
  digitalWrite(s0,HIGH);  
  Serial.begin(9600);

}

void loop() {
  

  digitalWrite(s2, LOW); //Kırmızıyı filtrelemek için
  digitalWrite(s3, LOW);
  K = pulseIn(sensorOut, LOW);//OUT pini üzerindeki LOW süresini okur
  Serial.print("Kırmızı= ");
  Serial.print(K); //Kırmızı için aldığımız değeri serial monitöre yazdır
  Serial.print("  ");
  delay(50);//50 milisaniye bekle
 
  digitalWrite(s2, HIGH); //Yeşili filtrelemek için
  digitalWrite(s3, HIGH);
  Y = pulseIn(sensorOut, LOW); //OUT pini üzerindeki LOW süresini okur
  Serial.print("Yeşil= ");
  Serial.print(Y); //Yeşil için aldığımız değeri serial monitöre yazdır
  Serial.print("   ");
  delay(50);//50 milisaniye bekle
 
  digitalWrite(s2, LOW); //Maviyi filtrelemek için
  digitalWrite(s3, HIGH);
  M = pulseIn(sensorOut, LOW);//OUT pini üzerindeki LOW süresini okur
  Serial.print("Mavi= ");
  Serial.print(M);//Mavi için aldığımız değeri serial monitöre yazdır
  Serial.println();
  delay(50);//50 milisaniye bekle

if(K<60 && M<70 && Y<60)
{
Serial.print("Renk=Beyaz");
delay(1000);
}
else if(Y<150 && Y<M && Y<K)
{
  Serial.print("Renk=Yeşil ");
  motor1.write(0);
  delay(2000);
  motor2.write(120);
  delay(2000);
  motor3.write(110);
  delay(2000);
  motor4.write(120);
  delay(2000);
  
  motor4.write(180);
  delay(2000);
  motor1.write(120);
  delay(2000);
  motor3.write(120);
  delay(2000);
  motor1.write(0);
  delay(2000);
  motor3.write(130);
  delay(2000);
  motor4.write(0);
  delay(2000);
  motor1.write(100);
  delay(2000);
    delay(1000);
}
else if(M<80 && M<Y && M<K)
{
  Serial.print("Renk=Mavi ");
  motor1.write(0);
  delay(2000);
  motor2.write(120);
  delay(2000);
  motor3.write(110);
  delay(2000);
  motor4.write(120);
  delay(2000);
  
  motor4.write(180);
  delay(2000);
  motor1.write(120);
  delay(2000);
  motor3.write(120);
  delay(2000);
  motor1.write(0);
  delay(2000);
  motor3.write(130);
  delay(2000);
  motor4.write(40);
  delay(2000);
  motor1.write(100);
  delay(2000);
    delay(1000);
}
  else if(K<90 && K<Y && K<M)
  {
    Serial.print("Renk=Kırmızı ");
  motor1.write(0);
  delay(2000);
  motor2.write(120);
  delay(2000);
  motor3.write(110);
  delay(2000);
  motor4.write(120);
  delay(2000);
  
  motor4.write(180);
  delay(2000);
  motor1.write(120);
  delay(2000);
  motor3.write(120);
  delay(2000);
  motor1.write(0);
  delay(2000);
  motor3.write(130);
  delay(2000);
  motor4.write(75);
  delay(2000);
  motor1.write(100);
  delay(2000);
    delay(1000);
  }
else
{
  Serial.println();
  delay(1000);
}




  
}
