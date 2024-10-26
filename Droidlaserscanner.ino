 #include <Servo.h>

// Servo myservosm;  // create servo object to control a servo
Servo myservolg;
// twelve servo objects can be created on most boards
 
 
    int ledPin = 9;      // LED connected to digital pin 9
    int analogPin = A3;   // potentiometer connected to analog pin 3 (A3)
    int val = 0;         // variable to store the read value
    int laserPin = 7;
    int pos = 0;    // variable to store the servo position


    void setup() {
    Serial.begin(9600);
      pinMode(ledPin, OUTPUT);  // sets the pin as output
      pinMode(laserPin, OUTPUT);  // sets the pin as output

  //    myservosm.attach(2);  // attaches the servo on pin 9 to the servo object      
      myservolg.attach(3);  // attaches the servo on pin 9 to the servo object
    }

    void loop() {


  val = analogRead(analogPin);  // read the input pin
    //  analogWrite(ledPin, val / 4); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
    //  analogWrite(laserPin, 1);
      
  val = map(val, 0, 1023, 01, 100);   
  //val = 40;  


  for (pos = 0; pos <= 60; pos += 15) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservolg.write(pos);              // tell servo to go to position in variable 'pos'
//    myservosm.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
    digitalWrite(ledPin, HIGH);
    delay(val);
    digitalWrite(ledPin, LOW);
    delay(val);
    Serial.print("1-pos ");
    Serial.print(pos);
    Serial.print(" val ");
    Serial.println(val);

  }
  for (pos = 60; pos >= 0; pos -= 15) { // goes from 180 degrees to 0 degrees
    myservolg.write(pos);              // tell servo to go to position in variable 'pos'
//    myservosm.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
    digitalWrite(ledPin, HIGH);
    delay(val);
    digitalWrite(ledPin, LOW);
    delay(val);
    Serial.print("2-pos ");
    Serial.print(pos);
    Serial.print("val ");
    Serial.println(val);
  }
    }

