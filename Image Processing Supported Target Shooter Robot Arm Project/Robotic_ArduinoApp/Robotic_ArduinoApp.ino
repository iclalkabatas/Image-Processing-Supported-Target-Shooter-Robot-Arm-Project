#include <Servo.h>

//Define Servo Motors
Servo M1;
Servo M2;

//Define Pins
int M1_pin = 2;
int M2_pin = 3;
int lazerPin = 13;

//Define Th Values and Serial Com
int Th1, Th2, tmp;


void setup() {
  
  //Serial Ports
  Serial.begin(9600);
  pinMode(lazerPin,OUTPUT);

  //Motor Start Angles
  M1.attach(M1_pin);
  M2.attach(M2_pin);

  //Lazer Pin
  pinMode(lazerPin, OUTPUT);
  digitalWrite(lazerPin, HIGH);

}


void loop() {

  if(Serial.available()>=2)
  {
    Th1 = Serial.read();
    Th2 = Serial.read();

    //Remove any extra worng reading
    while(Serial.available()) tmp = Serial.read();    
    
    // Run the robotic arm here. For testing, we will 
        //M1 Rotation
        M1.write(Th1);

        //M2 Rotation
        M2.write(Th2);

  }
}
