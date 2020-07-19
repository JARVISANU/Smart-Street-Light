int const trigPin = 4;
int const echoPin = 7;
int const LED = 9;
int const LDR = A0;
int const LED2 = 10;
void setup()
{
pinMode(trigPin, OUTPUT); // trig pin will have pulses output
pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
pinMode(LED,OUTPUT);


}
void loop()
{
  int value=digitalRead(LDR);
  if(value==HIGH)
  {
    int duration, distance;
  digitalWrite(trigPin, HIGH);
delay(1);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
// if distance less than 0.5 meter and more than 0 (0 or less means over range)
if (distance <= 100 && distance >= 0)
{
// Glow
digitalWrite(LED, HIGH);
delay(1000);
digitalWrite(LED2,HIGH);
} else {
// Glow dim
analogWrite(LED,20);
delay(1000);
analogWrite(LED2,20);
}
  }
 else
 {
  digitalWrite(LED, LOW);
  delay(1000);
  digitalWrite(LED2, LOW);
 }
delay(60);
}
