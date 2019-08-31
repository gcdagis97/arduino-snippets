#include "C:\Users\USERFunctions.ino"

//first comparitor always has equals set to true, since there is no prior digit
int gt = 0;
int lt = 0;
int eq = 1;

int gt0;
int lt0;
int eq0;

int eq1;
int lt1;
int gt1;

int eq2;
int lt2;
int gt2;

int eq3;
int lt3;
int gt3;

void setup() {

  //8 inputs; four pairs of two binary values to compare
  //a0, b0
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  
  //a1, b1
  pinMode(5,INPUT);
  pinMode(6,INPUT);

  //a2, b2
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  
  //a3, b3
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  
  //3 outputs; equals, less than, greater than
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

  //Compare numbers
  Serial.begin(9600);
}

void loop() {

  //first pair of binary values
  int a0 = digitalRead(3);
  int b0 = digitalRead(7);

  //second pair of binary values
  int a1 = digitalRead(4);
  int b1 = digitalRead(8);

  //third pair of binary values
  int a2 = digitalRead(5);
  int b2 = digitalRead(9);
  
  //fourth pair of binary values
  int a3 = digitalRead(6);
  int b3 = digitalRead(10);
  
  //Print first number
  Serial.print("1st number:     ");
  Serial.print(a0);
  Serial.print(a1);
  Serial.print(a2);
  Serial.println(a3);
  
  //Print second number
  Serial.print("2nd number:     ");
  Serial.print(b0);
  Serial.print(b1);
  Serial.print(b2);
  Serial.println(b3);

  //Compare each pair of binary values
  COMPARE(a0,b0,eq,lt,gt,&eq0,&lt0,&gt0);      //Compare a0 to b0, given that gt=0, lt=0, eq=1. Outputs gt,lt,eq values for next comparitor
  COMPARE(a1,b1,eq0,lt0,gt0,&eq1,&lt1,&gt1);   //Compare a1 to b1, given gt0,lt0,eq0 from last comparitor. Outputs gt,lt,eq values for next comparitor and so on...
  COMPARE(a2,b2,eq1,lt1,gt1,&eq2,&lt2,&gt2);   //Compare a2 to b2, ""
  COMPARE(a3,b3,eq2,lt2,gt2,&eq3,&lt3,&gt3);   //Compare a3 to b3, ""

  Serial.print("Equals values: ");
  Serial.print(eq);
  Serial.print(eq0);
  Serial.print(eq1);
  Serial.print(eq2);
  Serial.println(eq3);
  
  Serial.print("G-than values: ");
  Serial.print(gt);
  Serial.print(gt0);
  Serial.print(gt1);
  Serial.print(gt2);
  Serial.println(gt3);
  
  Serial.print("L-than values: ");
  Serial.print(lt);
  Serial.print(lt0);
  Serial.print(lt1);
  Serial.print(lt2);
  Serial.println(lt3);
  Serial.println();
  
  //Write to 3 LED's
  digitalWrite(11,eq3);
  digitalWrite(12,gt3);
  digitalWrite(13,lt3);
}
