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
	pinMode(7, INPUT); //Switch 1
	pinMode(9, OUTPUT); //Output
}  

void loop() {
	int w = digitalRead(3);
	int x = digitalRead(4);
	int s1 = digitalRead(7);

	int output = MUX(w, x, s1); 
	digitalWrite(9, output);
}
