#include "C:\Users\USER\Desktop\Functions.ino"

//Program implements a 4-BIT adder with carry in and carry out bits.

void setup() {

    //Inputs correspond to user entered bits
    //"A's", switches 5, 6, 7, 8
    pinMode(2,INPUT);
    pinMode(3,INPUT);
    pinMode(4,INPUT);
    pinMode(5,INPUT);

    //"B's", switches 1, 2, 3, 4
    pinMode(A0,INPUT);
    pinMode(A1,INPUT);
    pinMode(A2,INPUT);
    pinMode(A3,INPUT);

    //Carryout bits
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
}

void loop() {
    //"A's", bits increasing in signifigance
    int a = digitalRead(2);
    int b = digitalRead(3);
    int c = digitalRead(4);
    int d = digitalRead(5);
  
    //"B's", bits increasing in signifigance
    int e = digitalRead(A0);
    int f = digitalRead(A1);
    int g = digitalRead(A2);
    int h = digitalRead(A3);

    int carry_out,out1,out2,out3,out4;

    FOURBIT_ADD(a,b,c,d,e,f,g,h,&carry_out,&out1,&out2,&out3,&out4);

    //Output to five LEDs
    digitalWrite(8,carry_out);
    digitalWrite(9,out1);
    digitalWrite(10,out2);
    digitalWrite(11,out3);
    digitalWrite(12,out4);
}