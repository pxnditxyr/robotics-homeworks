char counter = 0;
char led_pines[ 4 ] = { 2, 3, 4, 5 };
char button_pin = 6;

void setup () {
  for ( int i = 0; i < 4; i ++ ) {
    pinMode ( led_pines[ i ], OUTPUT );
  }
  pinMode ( button_pin, INPUT );
}

void loop () {
  bool bin [ 4 ];
  bool button_state = digitalRead( button_pin );
  int_to_bin ( bin, counter );

  if ( button_state ) {
    counter++;
    if ( counter > 15 )
      counter = 0;
  }

  for ( int i = 0; i < 4; i++ )
    digitalWrite ( led_pines[ i ], bin[ i ] );
}

void int_to_bin ( bool * bin, int number ) {
  for ( int i = 0; i < 4; i++ ) {
    bin [ i ] = number % 2;
    number /= 2;
  }
}
