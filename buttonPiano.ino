//Array of Pins for Buttons
int buttonPins[7] = {
  13, 12, 11, 10, 9, 8, 7
  };
//Array for the Notes (Do-re-mi-fa-sol-la-si)
int notes[7] = {
  262, 294, 330, 349, 392, 440, 494
  };

//switchstate (Pressed of not) of the buttons
int switchstate = LOW; //By default not pressed
const int buzzerPin =  2;

void setup() {
  //Beginning Serial Connection
  Serial.begin(9600);
  //Setting up input (buttons)
  for (int i = 0; i < 7; i++){
    pinMode(buttonPins[i], INPUT);
  }
  //Setting up output (buzzer)
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pitch = 0;
  //loops through notes and buttonPins array
  for (int i = 0; i < 7; i++){
    switchstate = digitalRead(buttonPins[i]); //Checks if button is pressed or not
    //If button is pressed will play corresponding note
    if (switchstate == HIGH){
      tone(buzzerPin, notes[i]);
      delay(200);
      noTone(buzzerPin);
      Serial.println(switchstate);
    }
  }
}
