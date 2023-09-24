// defines pins numbers
const int trigPin = 8;
const int echoPin = 9;
//sensor 1
const int trigPin_1 = 7;
const int echoPin_1 = 6;
//sensor 2
const int trigPin_2 = 2;
const int echoPin_2 = 3;
//sensor 3
const int trigPin_3 = 20;
const int echoPin_3 = 21;


const int buzzer = 11;
const int ledPin = 13;

//sensor defines variables
long duration;
int distance;
int safetyDistance;

//sensor 1 defines variables
long duration_1;
int distance_1;
int safetyDistance_1;

//sensor 2 defines variables
long duration_2;
int distance_2;
int safetyDistance_2;

//sensor 3 defines variables
long duration_3;
int distance_3;
int safetyDistance_3;

void setup() {
//sensor 1
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
//sensor 2
pinMode(trigPin_1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin_1, INPUT); // Sets the echoPin as an Input
//sensor 3
pinMode(trigPin_2, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin_2, INPUT); // Sets the echoPin as an Input
//sensor 4
pinMode(trigPin_3, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin_3, INPUT); // Sets the echoPin as an Input


pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {

//////////////////////////////////////////////Sensor 1////////////////////////////////////////////////
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
//////////////////////////////////////////////Sensor 2////////////////////////////////////////////////
// Clears the trigPin
digitalWrite(trigPin_1, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin_1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration_1 = pulseIn(echoPin_1, HIGH);
// Calculating the distance
distance_1= duration_1*0.034/2;

//////////////////////////////////////////////Sensor 1////////////////////////////////////////////////
// Clears the trigPin
digitalWrite(trigPin_2, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin_2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_2, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration_2 = pulseIn(echoPin_2, HIGH);
distance_2= duration_2*0.034/2;
//////////////////////////////////////////////Sensor 1////////////////////////////////////////////////
// Clears the trigPin
digitalWrite(trigPin_3, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin_3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_3, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration_3 = pulseIn(echoPin_3, HIGH);
distance_3= duration_3*0.034/2;


safetyDistance = distance;
safetyDistance_1 = distance_1;
safetyDistance_2 = distance_2;
safetyDistance_3 = distance_3;


if (safetyDistance <= 20){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(1000);
}else if(safetyDistance_1 <= 20){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(1000);
}else if(safetyDistance_2 <= 20){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(1000);
}else if(safetyDistance_3 <= 20){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(1000);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

Serial.print("Distance_1: ");
Serial.println(distance_1);

Serial.print("Distance_2: ");
Serial.println(distance_2);

Serial.print("Distance_3: ");
Serial.println(distance_3);

}
