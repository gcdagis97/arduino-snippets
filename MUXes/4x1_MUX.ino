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

int MUX(int A, int B, int S) {
    int outAND1 = AND(A,S);
    int outAND2 = AND(B,INVERT(S));
    int outputOR = OR(outAND1, outAND2);
    return (outputOR);
}

void setup() {
    pinMode(3, INPUT); //Input A
    pinMode(4, INPUT); //Input B
    pinMode(5, INPUT); //Input C
    pinMode(6, INPUT); //Input D
    pinMode(7, INPUT); //Switch 1
    pinMode(8, INPUT); //Switch 2
    pinMode(9, OUTPUT); //Output  
}  

void loop() {
	int w = digitalRead(3);
	int x = digitalRead(4);
	int y = digitalRead(5);
	int z = digitalRead(6);
	int s1 = digitalRead(7);
	int s2 = digitalRead(8);

	int output1 = MUX(w, x, s1); 
	int output2 = MUX(y, z, s1);
	int output3 = MUX(output1, output2, s2);
	
	digitalWrite(9, output3);
}
