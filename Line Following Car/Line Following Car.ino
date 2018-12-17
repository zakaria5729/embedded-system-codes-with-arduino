#define LS 2 //left IR sensor
#define RS 3 //right IR sensor
#define LM1 5 //left motor M1a
#define LM2 4 //left motor M2a
#define RM1 7 //right motor M2a
#define RM2 6 //right motor M2b

void setup() {
	pinMode(LS, INPUT);
	pinMode(RS, INPUT);
	pinMode(LM1, OUTPUT);
	pinMode(LM2, OUTPUT);
	pinMode(RM1, OUTPUT);
	pinMode(RM2, OUTPUT);
}

void loop(){
	//Move Forward on line
	if(digitalRead(LS) && digitalRead(RS)) {
	    digitalWrite(LM1, HIGH);
	    digitalWrite(LM2, LOW);
	    digitalWrite(RM1, HIGH);
	    digitalWrite(RM2, LOW);
	}
	
	//Turn left by rotationg left motors in forward and right ones in backward direction
	if(digitalRead(LS) && !(digitalRead(RS))) {
		digitalWrite(LM1, HIGH);
		digitalWrite(LM2, LOW);
		digitalWrite(RM1, LOW);
		digitalWrite(RM2, HIGH);
	}
	
	//Turn right by rotating right motors in forward and left ones in backward direction
	if(!(digitalRead(LS)) && digitalRead(RS)) {
		digitalWrite(LM1, LOW);
		digitalWrite(LM2, HIGH);
		digitalWrite(RM1, HIGH);
		digitalWrite(RM2, LOW);
	}

	//Finish line, stop both the motors
	if(!(digitalRead(LS)) && !(digitalRead(RS))) {
		digitalWrite(LM1, LOW);
		digitalWrite(LM2, LOW);
		digitalWrite(RM1, LOW);
		digitalWrite(RM2, LOW);
	}
}
