const int buttonStart = 12;
const int speakerPin = 13;

const int buttonC = 5;
const int buttonD = 6;
const int buttonE = 7;
const int buttonF = 8;
const int buttonG = 9;
const int buttonA = 10;
const int buttonB = 11;

const int ledPin = 4;

int randomNote;

int length = 7; // the number of notes
char notes[] = "cdefgab "; // a space represents a rest
int tempo = 300;

int buttonStartState = 0;
int speakerPinState = 0;

int buttonCState = 0;
int buttonDState = 0;
int buttonEState = 0;
int buttonFState = 0;
int buttonGState = 0;
int buttonAState = 0;
int buttonBState = 0;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 7; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

void setup() {
  
  Serial.begin(9600);
  
  pinMode(speakerPin, OUTPUT);
  pinMode(buttonStart, INPUT);
  
  pinMode(buttonC, INPUT);
  pinMode(buttonD, INPUT);
  pinMode(buttonE, INPUT);
  pinMode(buttonF, INPUT);
  pinMode(buttonG, INPUT);
  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);

  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  buttonStartState = digitalRead(buttonStart);
  speakerPinState = digitalRead(speakerPin);

  buttonCState = digitalRead(buttonC);
  buttonDState = digitalRead(buttonD);
  buttonEState = digitalRead(buttonE);
  buttonFState = digitalRead(buttonF);
  buttonGState = digitalRead(buttonG);
  buttonAState = digitalRead(buttonA);
  buttonBState = digitalRead(buttonB);

//  Serial.print(buttonCState);
//  Serial.print(buttonDState);
//  Serial.print(buttonEState);
//  Serial.print(buttonFState);
//  Serial.print(buttonGState);
//  Serial.print(buttonAState);
//  Serial.println(buttonBState);

  //play scale
  if (buttonStartState == HIGH){

    randomNote = random(0,6);
    digitalWrite(speakerPin, HIGH);
    
    for (int i = 0; i < length; i++) {
      if (notes[i] == ' ') {
        delay(2 * tempo); // rest
      } else {
        playNote(notes[i], 2 * tempo);
      }
      // pause between notes
      delay(tempo / 2);
    }

    //play random note
    delay(tempo / 2);
    playNote(notes[randomNote], 2 * tempo);
  }

   //play C
  if(buttonCState == HIGH){
    digitalWrite(speakerPin, HIGH);
    //delay(1000);
    playNote(notes[0], 2 * tempo);
  }

  //play D
  if(buttonDState == HIGH){
    digitalWrite(speakerPin, HIGH);
    //delay(1000);
    playNote(notes[1], 2 * tempo); 
  }

  //play E
  if(buttonEState == HIGH){
    digitalWrite(speakerPin, HIGH);
    //delay(1000);
    playNote(notes[2], 2 * tempo);
    }

  //play F
    if(buttonFState == HIGH){
    digitalWrite(speakerPin, HIGH);
    //delay(1000);
    playNote(notes[3], 2 * tempo);
    }  

   //play G
  if(buttonGState == HIGH){
    digitalWrite(speakerPin, HIGH);
    //delay(1000);
    playNote(notes[4], 2 * tempo);
    }

   //play A
  if(buttonAState == HIGH){
    digitalWrite(speakerPin, HIGH);
    //delay(1000);
    playNote(notes[5], 2 * tempo);
    }

  //play B
  if(buttonBState == HIGH){
    digitalWrite(speakerPin, HIGH);
    //delay(1000);
    playNote(notes[6], 2 * tempo);
    }

  //make ledPin turns on when right note is clicked
  if (buttonCState == HIGH && notes[0] == notes[randomNote]) {
     digitalWrite(ledPin, HIGH);
     delay(1000);
     } else {
     digitalWrite(ledPin, LOW);
     } 

  if (buttonDState == HIGH && notes[1] == notes[randomNote]) {
     digitalWrite(ledPin, HIGH);
     delay(1000);
     } else {
     digitalWrite(ledPin, LOW);
     } 
     
  if (buttonEState == HIGH && notes[2] == notes[randomNote]) {
     digitalWrite(ledPin, HIGH);
     delay(1000);
     } else {
     digitalWrite(ledPin, LOW);
     } 

  if (buttonFState == HIGH && notes[3] == notes[randomNote]) {
     digitalWrite(ledPin, HIGH);
     delay(1000);
     } else {
     digitalWrite(ledPin, LOW);
     } 

  if (buttonGState == HIGH && notes[4] == notes[randomNote]) {
     digitalWrite(ledPin, HIGH);
     delay(1000);
     } else {
     digitalWrite(ledPin, LOW);
     } 
     
  if (buttonAState == HIGH && notes[5] == notes[randomNote]) {
     digitalWrite(ledPin, HIGH);
     delay(1000);
     } else {
     digitalWrite(ledPin, LOW);
     } 

   if (buttonBState == HIGH && notes[6] == notes[randomNote]) {
     digitalWrite(ledPin, HIGH);
     delay(1000);
     } else {
     digitalWrite(ledPin, LOW);
     } 

     Serial.println(notes[randomNote]);
}
