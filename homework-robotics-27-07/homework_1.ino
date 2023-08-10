char led_pin = 2;
char button_pin = 6;

void setup () {
  pinMode( led_pin, OUTPUT );
  pinMode( button_pin, INPUT );
}

void loop () {
  if ( digitalRead( button_pin ) == HIGH ) {
    blink_led();
  }
}

void blink_led () {
  digitalWrite( led_pin, HIGH );
  delay( 500 );
  digitalWrite( led_pin, LOW );
  delay( 500 );
}
