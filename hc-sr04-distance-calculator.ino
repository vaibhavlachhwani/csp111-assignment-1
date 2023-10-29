int trigger = 5;
int echo = 6;
long deltaTime;
float distance;
float speedSound = 0.000343;         //speed of sound in air (meters per microseconds)

void setup() {
  Serial.begin(9600);
  
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trigger, LOW);       //to ensure clean trigger signal
  delayMicroseconds(2);

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  deltaTime = pulseIn(echo, HIGH);

  distance = (deltaTime * speedSound) / 2;

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.print(" meters");
  Serial.print("\n");
  Serial.println("______________________________________");

  delay(1000);
}
