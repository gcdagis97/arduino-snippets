#include "C:\Users\USER\Functions.ino"

  int Q0;
  int Q1; 
  int Q2; 
  int Q3; 
  int Q4;
  int Q0_NOT; 
  int Q1_NOT; 
  int Q2_NOT; 
  int Q3_NOT; 
  int Q4_NOT;

  int QM;
  int QM1;
  int QM2;
  int QM3;
  int QM_NOT;
  int QM1_NOT;
  int QM2_NOT;
  int QM3_NOT;

  int out1; 
  int out2; 
  int out3; 
  int out4;
  int out1_New; 
  int out2_New; 
  int out3_New; 
  int out4_New; 
  
  int carry_out;

void setup(){
  
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  //Serial.begin(9000);
  
  Q0=0; 
  Q1=0; 
  Q2=0; 
  Q3=0; 
  Q4=0; 
  Q0_NOT = 1;
  Q1_NOT = 1; 
  Q2_NOT = 1; 
  Q3_NOT = 1; 
  Q4_NOT = 1;
  
  QM = 0;
  QM1 = 0;
  QM2 = 0;
  QM3 = 0;
  QM_NOT = 1;
  QM1_NOT = 1;
  QM2_NOT = 1;
  QM3_NOT = 1;

  out1=0; 
  out2=0; 
  out3=0; 
  out4=0;
  out1_New = 0; 
  out2_New = 0; 
  out3_New = 0;
  out4_New = 0;
  
  carry_out = 0;
}

void loop(){
  int clk = digitalRead(A0);

  //start at 1,0,0,0 and add it to the new outputs
  FOURBIT_ADD(1,0,0,0,out4_New,out3_New,out2_New,out1_New,&carry_out,&out4,&out3,&out2,&out1);

  //if A1(reset) is on, all values go back to 0
  if(digitalRead(A5) == HIGH){
     out1_New = 0;
     out2_New = 0;
     out3_New = 0;
     out4_New = 0; 
  }
  else{}

  FOURBIT_REG(clk,out4,out3,out2,out1,&QM,&QM_NOT,&QM1,&QM1_NOT,&QM2,&QM2_NOT,&QM3,&QM3_NOT,&out4_New,&Q1_NOT,&out3_New,&Q2_NOT,&out2_New,&Q3_NOT,&out1_New,&Q4_NOT);

  digitalWrite(2,out4_New);
  digitalWrite(3,out3_New);
  digitalWrite(4,out2_New);
  digitalWrite(5,out1_New);

  /*
  Serial.println("Outputs: ");
  Serial.println(out4_New);
  Serial.println(out3_New);
  Serial.println(out2_New);
  Serial.println(out1_New);
  delay(500);
  */
}
