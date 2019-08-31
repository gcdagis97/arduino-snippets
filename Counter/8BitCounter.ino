#include "C:\Users\USER\Functions.ino"

  //first counter
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

  //second counter
  int P1=0;
  int P2=0;
  int P3=0;
  int P4=0;
  int PM=0;
  int P0_NOT=1;
  int P1_NOT=1;
  int P2_NOT=1;
  int P3_NOT=1;
  int P4_NOT=1;
  int PM1=0;
  int PM2=0;
  int PM3=0;
  int PM_NOT=1;
  int PM1_NOT=1;
  int PM2_NOT=1;
  int PM3_NOT=1;

  int out1;
  int out2;
  int out3;
  int out4;
  int out1_New;
  int out2_New;
  int out3_New;
  int out4_New;
  int out5_New;
  int out6_New;
  int out7_New;
  int out8_New;

  int c_out;
  int c_out2;

void setup(){

  //output to 8 LEDS
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
  
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

/*
  P1=0;
  P2=0;
  P3=0;
  P4=0;
  PM=0;
  P0_NOT=1;
  P1_NOT=1;
  P2_NOT=1;
  P3_NOT=1;
  P4_NOT=1;
  PM1=0;
  PM2=0;
  PM3=0;
  PM_NOT=1;
  PM1_NOT=1;
  PM2_NOT=1;
  PM3_NOT=1;
  */
  
  out1=0;
  out2=0;
  out3=0;
  out4=0;

  out1_New = 0;
  out2_New = 0;
  out3_New = 0;
  out4_New = 0;
  out5_New = 0;
  out6_New = 0;
  out7_New = 0;
  out8_New = 0;

  c_out = 0;
  c_out2 = 0;
}

void loop(){

  int clk = digitalRead(A0);
  
  //When out4=1 (16 and above), the second four bit count activates
  FOURBIT_COUNT(clk,&out1_New,&out2_New,&out3_New,&out4_New,&c_out,&out1,&out2,&out3,&out4,&QM,&QM_NOT,&QM1,&QM1_NOT,&QM2,&QM2_NOT,&QM3,&QM3_NOT,&Q0_NOT,&Q1_NOT,&Q2_NOT,&Q3_NOT,&Q4_NOT);
  FOURBIT_COUNT(INV(out4_New),&out5_New,&out6_New,&out7_New,&out8_New,&c_out2,&P1,&P2,&P3,&P4,&PM,&PM_NOT,&PM1,&PM1_NOT,&PM2,&PM2_NOT,&PM3,&PM3_NOT,&P0_NOT,&P1_NOT,&P2_NOT,&P3_NOT,&P4_NOT);
  
  //output to 8 LED's
  digitalWrite(9,out8_New);
  digitalWrite(8,out7_New);
  digitalWrite(7,out6_New);
  digitalWrite(6,out5_New);
  digitalWrite(5,out4_New);
  digitalWrite(4,out3_New);
  digitalWrite(3,out2_New);
  digitalWrite(2,out1_New);
}
