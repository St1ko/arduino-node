//RGB Light
int redPin = 7;
int greenPin = 6;
int bluePin = 5;

//Pins Sensor 1
const int trigPin1 = 10;
const int echoPin1 = 9;

//Pins Sensor 2
const int trigPin2 = 3;
const int echoPin2 = 4;

double duration1;
double distance1;

double duration2;
double distance2;

int people = 0;

int delaytime = 20;
double doorWidth = 60;

boolean in = true;

double time1;
double time2;

void setup() {
  Serial.begin(9600); // starts the serial communication

  pinMode(trigPin1, OUTPUT); // sets the trigPin1 as an Output
  pinMode(echoPin1, INPUT); // sets the echoPin1 as an Input

  pinMode(trigPin2, OUTPUT); // sets the trigPin2 as an Output
  pinMode(echoPin2, INPUT); // sets the echoPin2 as an Input
  //Set up light
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

}

//Check Sensor 1
void Sensor1() {
  digitalWrite(trigPin1, LOW);   // clears the trigPin1
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);    // sets the trigPin1 on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  duration1 = pulseIn(echoPin1, HIGH);  // reads the echoPin1, returns the sound wave travel time in microseconds
  distance1 = duration1 * 0.034 / 2;    // calculating the distance

  if (distance1 < doorWidth) {
    time1 = millis();

  }
}


//Check Sensor 2
void Sensor2() {
  digitalWrite(trigPin2, LOW);   // clears the trigPin2
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);    // sets the trigPin2 on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  duration2 = pulseIn(echoPin2, HIGH);  // reads the echoPin2, returns the sound wave travel time in microseconds
  distance2 = duration2 * 0.034 / 2;    // calculating the distance

  if (distance2 < doorWidth) {
    time2 = millis();
  }
}

//Mensen tellen
void CountPeople() {

  if (in == true) {
    if (((time1 - time2) < 0)) {
      people = people + 1;
      in = false;
      setColor(255, 0, 0);
    }
  }
  if (in == false) {
    if (((time1 - time2) > 0)) {
      people = people - 1;
      in = true;
      setColor(0, 255, 0);
    }
  }
}
//Functie kleur
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
void DisplayPeople() {
  //  Serial.print("People count: ");
  Serial.println(people);
}

void loop() {
  Sensor1();
  Sensor2();
  CountPeople();
  DisplayPeople();
  SendData();
}
