int INVERT(int w) {
    int output = !w;
    return output;
}

int AND(int w, int x) {
    int output = w && x;
    return output;
}

int OR(int w, int x) {
    int output = w || x;
    return output;
}

int XOR(int A, int B) {
    int outAND1 = AND(A,INVERT(B));
    int outAND2 = AND(INVERT(A),B);
    int outputOR = OR(outAND1, outAND2);
    return (outputOR);
}

int ADD(int A, int B, int C, int* carryout, int* sumout) {
    //carry out bit
    int AND1 = AND(A,B);
    int AND2 = AND(A,C);
    int AND3 = AND(B,C);
    int OR1 = OR(AND1, AND2);
    int OR2 = OR(OR1, AND3);
    *carryout = (OR2);
  
    //sum  bit
    int XOR1 = XOR(A,C);
    int XOR2 = XOR(XOR1, B);
    *sumout = (XOR2);
}


void setup() {
    pinMode(3, INPUT); //Input A
    pinMode(4, INPUT); //Input B
    pinMode(5, INPUT); //Cin
    pinMode(9, OUTPUT); //Output
    pinMode(10, OUTPUT); //Carry Out
}  

void loop() {
	int w = digitalRead(3); //Input A
	int x = digitalRead(4); //Input B
	int y = digitalRead(5); //Carry In

	int Output = ADD(w, x, y, &carryout, &sumout);
	int CarryOut = ADD(w, x, y, &carryout, &sumout);

	//Write output to pin 9
	digitalWrite(9, Output); //Output

	//Write carryout to pin 10
	digitalWrite(10, CarryOut); //CarryOut
}
