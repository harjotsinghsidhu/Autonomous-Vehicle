/*Change of Directions - forward, left, backwards, right
*/

#define M1 9
#define in1 4
#define in2 5
#define M2 10
#define in3 6
#define in4 7

int motorspeed1 = 0;
int motorspeed2 = 0;


void setup() {

 pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);


}

void loop() {

forward();
delay(5000);
backward();
delay(5000);
left();
delay(5000);
right();
delay(5000);



// Motor 1 goes forward
/*
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);

motorspeed1=255;
motorspeed2=255;

delay(1500);

digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);

motorspeed1=255;
motorspeed2=255;

delay
analogWrite(M1, motorspeed1);
analogWrite(M2, motorspeed2);

*/
}


void forward() {
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);

motorspeed1=255;
motorspeed2=255;

analogWrite(M1, motorspeed1);
analogWrite(M2, motorspeed2);

delay(2500);

digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);

}

void left() {
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);

motorspeed1=255;
motorspeed2=0;

analogWrite(M1, motorspeed1);
analogWrite(M2, motorspeed2);

delay(1500);

digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);

}

void backward() {
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);

motorspeed1=255;
motorspeed2=255;

analogWrite(M1, motorspeed1);
analogWrite(M2, motorspeed2);

delay(2500);

digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);

}

void right() {
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);

motorspeed1=0;
motorspeed2=255;

analogWrite(M1, motorspeed1);
analogWrite(M2, motorspeed2);

delay(1500);

digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);


}