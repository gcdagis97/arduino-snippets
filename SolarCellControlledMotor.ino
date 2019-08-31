// Control bipolar DC motor using solar cell

void setup() {

    //input from solar cell = A5
    pinMode(3,OUTPUT);
    Serial.begin(9600);
}

void loop() {
  
    int SolarVal = analogRead(A5);
    Serial.print("Solar Value is: "); //uncovered ~80, covered ~10 - ~50
    Serial.println(SolarVal);

    //Turn motor on if cell is covered
    if(SolarVal <= 50) {
		digitalWrite(3,HIGH);
		Serial.println("SC is covered - motor should be on");
		Serial.println();
    }

	//Turn off motor if cell is uncovered
	else if(SolarVal >= 80) {
		digitalWrite(3,LOW);
		Serial.println("SC is uncovered - motor should be off");
		Serial.println();
    }
}
