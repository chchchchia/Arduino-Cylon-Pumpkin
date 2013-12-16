

#define PIN_COUNT 12
#define UPDATE_DURATION 15

int pins[PIN_COUNT] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
int states[PIN_COUNT];
int current_pin = 0;
int dir = 1;
int update_count = 0;

void setup() {
  pinMode(0,OUTPUT);
  for ( int i = 0; i < PIN_COUNT; i++ ) {
    pinMode(pins[i], OUTPUT);
    states[i] = 0;
  }
}

void updatePins() {
  digitalWrite(0,LOW);
  for ( int i = 0; i < PIN_COUNT; i++ ) {
    digitalWrite(pins[i], states[i]);
  }
  delay(6);
}

void decay() {
  for ( int i = 0; i < PIN_COUNT; i++ ) {
    states[i] = LOW;
  }
}

void loop() {
  decay();
 // states[current_pin] = 255 * update_count / UPDATE_DURATION;
  states[current_pin] = HIGH;
  updatePins();
  
  update_count++;
  if ( update_count > UPDATE_DURATION ) {
    update_count = 0;
    current_pin += dir;
    if ( current_pin == 0 ) {
      dir = 1;
      digitalWrite(0,HIGH);
      delay(50);
    }
    else if ( current_pin == (PIN_COUNT-1) ) {
      dir = -1;
      digitalWrite(0,HIGH);
      delay(50);
    }
  }
}
