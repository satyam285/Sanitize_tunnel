//Sanitize Tunnel Code with Single sensor and relay
//Dev by Satyam Verma
// defines pins numbers
const int trigPin = 3;
const int echoPin = 2;
const int relay = 4;
// defines variables
long duration;
int distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(relay,OUTPUT);
pinMode(13,OUTPUT);
digitalWrite(13, HIGH);
digitalWrite(relay,HIGH);
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
if (distance<100){
 digitalWrite(relay,LOW);
 delay(5000);
 digitalWrite(relay,HIGH);
}
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
delay(20);
}
