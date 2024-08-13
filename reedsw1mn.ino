#include <arduino-timer.h>

const int reedSwitchPin = 2; // Pin where the Reed switch is connected
int reedState = 0;           // Variable to store the state of the Reed switch
int lastReedState = 0;       // Variable to store the last state of the Reed switch
int count = 0;               // Variable to count the number of times the Reed switch is closed

auto timer = timer_create_default(); // create a timer with default settings

bool toggle_led(void *) {
  
   Serial.println(count); // Print the count to the serial monitor
   count = 0;
  return true; // repeat? true
}



void setup() {
  pinMode(reedSwitchPin, INPUT); // Set the Reed switch pin as input
  Serial.begin(9600);            // Start serial communication

  timer.every(60000, toggle_led);
}

void loop() {

   timer.tick(); // tick the timer
  reedState = digitalRead(reedSwitchPin); // Read the state of the Reed switch

  // Check if the Reed switch is closed
  if (reedState == HIGH && lastReedState == LOW) {
    count++; // Increment the count
    //Serial.print("Reed switch closed. Count: ");
   
  }

  lastReedState = reedState; // Update the last Reed state

  delay(50); // Add a small delay to debounce the Reed switch
}










