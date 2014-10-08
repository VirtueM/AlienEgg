//Haunted Space Station Exhibit - October 6, 2014
//By Monica Virtue

//Using a combination of code provided during:
//Creation & Computation - October 2, 2014
//Example 2 for Rube Goldberg Machines
//Prof Kate Hartman
//With additional LED Heartbeat code
//by Tyler Murphy (May 23, 2014)
//http://www.youtube.com/watch?v=cSBZobNh6Ms

#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 

int sensorPin = 0;  // analog pin used to connect the sensor
int sensorValue;    // variable to read the value from the analog pin 
int threshold = 700; // change this to your desire threshold
int position1 = 0; //change this to your starting position for the servo
int position2 = 50; //change this to your ending position for the servo

int led = 3; //Define pin 3 to be the LED

void setup() 
{ 
  myservo.attach(13);  // attaches the servo on pin 13 to the servo object 
  myservo.write(position1); // turn the servo to the starting position

  pinMode(led, OUTPUT);
}

int brightness = 5; //The initial brightness of the LED 

void loop(){ 
  sensorValue = analogRead(sensorPin); // reads the value of the sensor (value between 0 and 1023) 
  if(sensorValue > threshold){ // if the sensor value is above the threshold
    myservo.write(position2);    // move the servo to position 2 
  }
  else{
    myservo.write(position1); // leave the servo at position 1
  }
  delay(5);               // waits for the servo to get there 
      
  fade(100, 1, 1);
  fade(30, 1, 1.5);
  fade(255, 1, 1);
  fade(30, 1, 2);
  fade(15, 1, 4);
  fade(10, 1, 8);
  fade(8, 1, 20);
  fade(7, 1, 40);
  fade(6, 1, 80);
  fade(5, 1, 160);
  delay(600);
  
}

//Define the function to linearly ramp brightness up or down
//Starts with 'void' because there's no output

void fade(int fadeTo, int fadeSpeed, float delayTime) {
  if (fadeTo > brightness) {
    while (brightness < fadeTo) {
      analogWrite(led, brightness);
      brightness+=fadeSpeed;
      delay(delayTime);
    }
  } else {
    while (brightness > fadeTo) {
      analogWrite(led, brightness);
      brightness-=fadeSpeed;
      delay(delayTime);
    }
  }  
}
