
int delay_value = 1000;

char led_pin = 2;
char button_pin = 3;

void setup () {
  pinMode( led_pin, OUTPUT );
  pinMode( button_pin, INPUT );
}

void loop () {
  bool button_state = digitalRead( button_pin );
  if ( button_state ) {
    delay_value -= 100;
    if ( delay_value < 100 )
      delay_value = 1000;
  }

  digitalWrite( led_pin, HIGH );
  delay( delay_value );
  digitalWrite( led_pin, LOW );
  delay( delay_value );
}
