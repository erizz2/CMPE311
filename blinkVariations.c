//LED pin numbers
const int LED2 = 2;
const int LED4 = 4;


//LED initial activation times
unsigned long int previousTimeLED2 = millis();
unsigned long int previousTimeLED4 = millis();


//LED delay times
long delayLED2 = 500;
long delayLED4 = 250;


//LED initial states
int statLED2 = LOW;
int statLED4 = LOW;


int selectedLED = 0;


void setup() {
  //Pin modes and begin serial buffer
  Serial.begin(9600);
  pinMode(LED2, OUTPUT);
  pinMode(LED4, OUTPUT);
}


void loop() {


  if (Serial.available() > 0) {


    if (selectedLED == 0) {
      Serial.println("Which pin to blink (2 or 4)? ");
      String input;
      input = Serial.readStringUntil('\n');
      input.trim();
      selectedLED = input.toInt();
    }


    if (selectedLED == 2 || selectedLED == 4) {
      Serial.println("What interval to blink (ms)? ");
      String inputDelay = Serial.readStringUntil('\n');
      inputDelay.trim();
      if (selectedLED == 2) {
        delayLED2 = inputDelay.toInt();
      } else {
        delayLED4 = inputDelay.toInt();
      }
    }
  }


  //update current time
  unsigned long int currentTime = millis();
 
  if (currentTime - previousTimeLED2 > delayLED2) {
    //set last time LED2 was activated
    previousTimeLED2 = currentTime;


    if (statLED2 == HIGH) {
      statLED2 = LOW;
    } else {
      statLED2 = HIGH;
    }


    digitalWrite(LED2, statLED2);
  }


  if (currentTime - previousTimeLED4 > delayLED4) {
    //set last time LED4 was activated
    previousTimeLED4 = currentTime;


    if (statLED4 == HIGH) {
      statLED4 = LOW;
    } else {
      statLED4 = HIGH;
    }


    digitalWrite(LED4, statLED4);
  }
}
