//NanoFull step mode
//512 >> 360 degrees     1.4 step/degree
//Motor 1 Left-Right
int M1A = 10; int M1B = 11; int M1C = 12; int M1D = 13;
//Motor 2 Up-Down
//Motor 3 Eyelids
int M3A = 2; int M3B = 3; int M3C = 4; int M3D = 5;
#define RELAY_IN1 8 //Red
#define RELAY_IN2 7 //Blue

int t=2;
void setup() 
{ 
  Serial.begin(9600);
  pinMode(13, OUTPUT);
 pinMode(M1A, OUTPUT);   pinMode(M1B, OUTPUT);   pinMode(M1C, OUTPUT);   pinMode(M1D, OUTPUT);  
  pinMode(M3A, OUTPUT);   pinMode(M3B, OUTPUT);   pinMode(M3C, OUTPUT);   pinMode(M3D, OUTPUT);
   pinMode(RELAY_IN1, OUTPUT);
    pinMode(RELAY_IN2, OUTPUT);  
} 
 void loop() 
{ 
digitalWrite(RELAY_IN2, LOW);
  digitalWrite(RELAY_IN1, LOW);
for(int x=0; x<120;x++){
digitalWrite(M3A, LOW); digitalWrite(M3B, LOW); digitalWrite(M3C, HIGH); digitalWrite(M3D, HIGH); delay(t);
digitalWrite(M3A, LOW); digitalWrite(M3B, HIGH); digitalWrite(M3C, HIGH); digitalWrite(M3D, LOW); delay(t);
digitalWrite(M3A, HIGH); digitalWrite(M3B, HIGH); digitalWrite(M3C, LOW); digitalWrite(M3D, LOW); delay(t);
digitalWrite(M3A, HIGH); digitalWrite(M3B, LOW); digitalWrite(M3C, LOW); digitalWrite(M3D, HIGH); delay(t);}

//Motor 3 CW
  for(int x=0; x<120;x++){
digitalWrite(M3A, HIGH); digitalWrite(M3B, LOW); digitalWrite(M3C, LOW); digitalWrite(M3D, HIGH); delay(t);
digitalWrite(M3A, HIGH); digitalWrite(M3B,HIGH); digitalWrite(M3C, LOW); digitalWrite(M3D, LOW); delay(t);
digitalWrite(M3A, LOW); digitalWrite(M3B, HIGH); digitalWrite(M3C, HIGH); digitalWrite(M3D, LOW); delay(t);
digitalWrite(M3A, LOW); digitalWrite(M3B, LOW); digitalWrite(M3C, HIGH); digitalWrite(M3D, HIGH); delay(t);}


for(int x=0; x<120;x++){
digitalWrite(M3A, LOW); digitalWrite(M3B, LOW); digitalWrite(M3C, HIGH); digitalWrite(M3D, HIGH); delay(t);
digitalWrite(M3A, LOW); digitalWrite(M3B, HIGH); digitalWrite(M3C, HIGH); digitalWrite(M3D, LOW); delay(t);
digitalWrite(M3A, HIGH); digitalWrite(M3B, HIGH); digitalWrite(M3C, LOW); digitalWrite(M3D, LOW); delay(t);
digitalWrite(M3A, HIGH); digitalWrite(M3B, LOW); digitalWrite(M3C, LOW); digitalWrite(M3D, HIGH); delay(t);}

//Motor 3 CW
  for(int x=0; x<120;x++){
digitalWrite(M3A, HIGH); digitalWrite(M3B, LOW); digitalWrite(M3C, LOW); digitalWrite(M3D, HIGH); delay(t);
digitalWrite(M3A, HIGH); digitalWrite(M3B,HIGH); digitalWrite(M3C, LOW); digitalWrite(M3D, LOW); delay(t);
digitalWrite(M3A, LOW); digitalWrite(M3B, HIGH); digitalWrite(M3C, HIGH); digitalWrite(M3D, LOW); delay(t);
digitalWrite(M3A, LOW); digitalWrite(M3B, LOW); digitalWrite(M3C, HIGH); digitalWrite(M3D, HIGH); delay(t);
  }

delay(2000);

digitalWrite(RELAY_IN1, HIGH);
digitalWrite(RELAY_IN2, LOW);
  

for(int x=0; x<70;x++){
digitalWrite(M1A, HIGH); digitalWrite(M1B, LOW); digitalWrite(M1C, LOW); digitalWrite(M1D, HIGH); delay(t);
digitalWrite(M1A, HIGH); digitalWrite(M1B, HIGH); digitalWrite(M1C, LOW); digitalWrite(M1D, LOW); delay(t);
digitalWrite(M1A, LOW); digitalWrite(M1B, HIGH); digitalWrite(M1C, HIGH); digitalWrite(M1D, LOW); delay(t);
digitalWrite(M1A, LOW); digitalWrite(M1B, LOW); digitalWrite(M1C, HIGH); digitalWrite(M1D, HIGH); delay(t);}
//Motor 1 CCW
for(int x=0; x<140;x++){
digitalWrite(M1A, LOW); digitalWrite(M1B, LOW); digitalWrite(M1C, HIGH); digitalWrite(M1D, HIGH); delay(t);
digitalWrite(M1A, LOW); digitalWrite(M1B, HIGH); digitalWrite(M1C, HIGH); digitalWrite(M1D, LOW); delay(t);
digitalWrite(M1A, HIGH); digitalWrite(M1B,HIGH); digitalWrite(M1C, LOW); digitalWrite(M1D, LOW); delay(t);
digitalWrite(M1A, HIGH); digitalWrite(M1B, LOW); digitalWrite(M1C,LOW); digitalWrite(M1D, HIGH); delay(t);} 
 //Motor 1 CW 
for(int x=0; x<70;x++){
digitalWrite(M1A, HIGH); digitalWrite(M1B, LOW); digitalWrite(M1C, LOW); digitalWrite(M1D, HIGH); delay(t);
digitalWrite(M1A, HIGH); digitalWrite(M1B, HIGH); digitalWrite(M1C, LOW); digitalWrite(M1D, LOW); delay(t);
digitalWrite(M1A, LOW); digitalWrite(M1B, HIGH); digitalWrite(M1C, HIGH); digitalWrite(M1D, LOW); delay(t);
digitalWrite(M1A, LOW); digitalWrite(M1B, LOW); digitalWrite(M1C, HIGH); digitalWrite(M1D, HIGH); delay(t);}


delay(2000);


          for(int x=0; x<120;x++){
digitalWrite(M3A, LOW); digitalWrite(M3B, LOW); digitalWrite(M3C, HIGH); digitalWrite(M3D, HIGH); delay(t);
digitalWrite(M3A, LOW); digitalWrite(M3B, HIGH); digitalWrite(M3C, HIGH); digitalWrite(M3D, LOW); delay(t);
digitalWrite(M3A, HIGH); digitalWrite(M3B, HIGH); digitalWrite(M3C, LOW); digitalWrite(M3D, LOW); delay(t);
digitalWrite(M3A, HIGH); digitalWrite(M3B, LOW); digitalWrite(M3C, LOW); digitalWrite(M3D, HIGH); delay(t);}
digitalWrite(RELAY_IN1, LOW);
  digitalWrite(RELAY_IN2, HIGH);


delay(3000);
  for(int x=0; x<120;x++){
digitalWrite(M3A, HIGH); digitalWrite(M3B, LOW); digitalWrite(M3C, LOW); digitalWrite(M3D, HIGH); delay(t);
digitalWrite(M3A, HIGH); digitalWrite(M3B,HIGH); digitalWrite(M3C, LOW); digitalWrite(M3D, LOW); delay(t);
digitalWrite(M3A, LOW); digitalWrite(M3B, HIGH); digitalWrite(M3C, HIGH); digitalWrite(M3D, LOW); delay(t);
digitalWrite(M3A, LOW); digitalWrite(M3B, LOW); digitalWrite(M3C, HIGH); digitalWrite(M3D, HIGH); delay(t);




    }




for(int x=0; x<80;x++){
digitalWrite(M3A, LOW); digitalWrite(M3B, LOW); digitalWrite(M3C, HIGH); digitalWrite(M3D, HIGH); delay(t);
digitalWrite(M3A, LOW); digitalWrite(M3B, HIGH); digitalWrite(M3C, HIGH); digitalWrite(M3D, LOW); delay(t);
digitalWrite(M3A, HIGH); digitalWrite(M3B, HIGH); digitalWrite(M3C, LOW); digitalWrite(M3D, LOW); delay(t);
digitalWrite(M3A, HIGH); digitalWrite(M3B, LOW); digitalWrite(M3C, LOW); digitalWrite(M3D, HIGH); delay(t);}

//Motor 3 CW
  for(int x=0; x<80;x++){
digitalWrite(M3A, HIGH); digitalWrite(M3B, LOW); digitalWrite(M3C, LOW); digitalWrite(M3D, HIGH); delay(t);
digitalWrite(M3A, HIGH); digitalWrite(M3B,HIGH); digitalWrite(M3C, LOW); digitalWrite(M3D, LOW); delay(t);
digitalWrite(M3A, LOW); digitalWrite(M3B, HIGH); digitalWrite(M3C, HIGH); digitalWrite(M3D, LOW); delay(t);
digitalWrite(M3A, LOW); digitalWrite(M3B, LOW); digitalWrite(M3C, HIGH); digitalWrite(M3D, HIGH); delay(t);}





    
 
    
}
