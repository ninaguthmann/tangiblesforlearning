#include <Servo.h>

const int speakerPin = 8;
const int speakerPin2 = 7;
const int ledPin = 2;
const int servoPin = 9;

Servo myservo;

int pos = 0;
//int posHit = 45;

int length = 24; // the number of notes
char notes[] = "ffdbbeeeggaBaaaedfffeefe"; // a space represents a rest
int beats[] = { 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 1, 1, 1, 1, 1 };
int tempo = 100;

void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    digitalWrite(speakerPin2, HIGH);
    digitalWrite(ledPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    digitalWrite(speakerPin2, LOW);
    digitalWrite(ledPin, LOW);
    delayMicroseconds(tone);

    Serial.println(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = {'B','a', 'g', 'f', 'e', 'd', 'b' };
  int tones[] = { 506, 568, 601, 675, 758, 851, 1012 };

  // play the tone corresponding to the note name
  for (int i = 0; i < 7; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);

      //Serial.println(tones[i]);
    }
  }
}

void setup() {

  Serial.begin(9600);
  
  pinMode(speakerPin, OUTPUT);
  pinMode(speakerPin2, OUTPUT);
  pinMode(ledPin, OUTPUT);

  myservo.attach(servoPin);
}

void loop() {
  
  for (int i = 0; i < length; i++) {

    if (i == 0){
      for (pos = 0; pos <= 45; pos += 1) {
       myservo.write(pos);
      }
    } else if(i == 2){
      for (pos = 45; pos >= 0; pos -= 1) {
       myservo.write(pos);
      }
    } else if(i == 12){
      for (pos = 0; pos <= 45; pos += 1) {
      myservo.write(pos);
      }
    } else if(i == 14){
      for (pos = 45; pos >= 0; pos -= 1) {
      myservo.write(pos);
      }
    }

    //if notes[i] == 0, servo hits, notes[i] == 2, go back to initial position
    //note[i] == 12, servo hits, notes[i] == 14, go back to initial position

    playNote(notes[i], beats[i] * tempo);
    
    // pause between notes
    
    Serial.print(notes[i]);
    Serial.print(" | ");
    Serial.println(beats[i]);
    
    delay(tempo);
  }
  
}
