void setup() {
 Serial.begin( 9600 );
}

void loop() {
  String input;
  Serial.print( "Introduce la cadena de instrucciones: " );
  // the instruction are in the form of "MotorD=100,MotorI=100,Tiempo=1000;MotorD=200,MotorI=200,Tiempo=2000"
  while( !Serial.available() );
  input = Serial.readString();
  String instructions[ 50 ];
  int quantity = 0;
  separate_by_character( input, instructions, quantity, ';' );
  for ( int i = 0; i < quantity; i++ ) {
    int instruction_values[ 3 ] = { 0, 0, 0 };
    get_instruction_values( instructions[ i ], instruction_values );
    execute_instructions( instruction_values );
  }
}

void execute_instructions ( int * instruction_values ) {
  int motorD = abs( instruction_values[ 0 ] );
  int motorI = abs( instruction_values[ 1 ] );
  int tiempo = instruction_values[ 2 ];
  
  if ( instruction_values[ 0 ] < 0 ) {
    analogWrite( 3, motorD );
    analogWrite( 5, 0 );
  } else {
    analogWrite( 3, 0 );
    analogWrite( 5, motorD );
  }
  if ( instruction_values[ 1 ] < 0 ) {
    analogWrite( 6, motorI );
    analogWrite( 9, 0 );
  } else {
    analogWrite( 6, 0 );
    analogWrite( 9, motorI );
  }
  delay( tiempo );
}


void get_instruction_values ( String instruction, int * instruction_values ) {
  // the instruction are in the form of "MotorD=100,MotorI=100,Tiempo=1000"
  String separated_instruction[ 3 ];
  int quantity = 0;
  separate_by_character( instruction, separated_instruction, quantity, ',' );
  int instruction_index = 0;
  for ( int i = 0; i < quantity; i++ ) {
    String aux = separated_instruction[ i ];
    String aux2 = aux.substring( aux.indexOf( '=' ) + 1 );
    if ( aux.indexOf( 'D' ) != -1 )
      instruction_index = 0;
    else if ( aux.indexOf( 'I' ) != -1 )
      instruction_index = 1;
    else if ( aux.indexOf( 'T' ) != -1 ) {
      instruction_index = 2;
    }
    instruction_values[ instruction_index ] = aux2.toInt();
  }
}


void separate_by_character ( String original_text, String * separated_text, int &quantity, char character ) {
  int primer_indice = 0;
  String text = original_text;
  while ( text.indexOf( character ) != -1 ) {
    String aux = text.substring( 0, text.indexOf( character ) );
    separated_text[ quantity ] = aux;
    text = text.substring( text.indexOf( character ) + 1 );
    quantity++;
  }
  if ( text.length() > 0 ) {
    separated_text[ quantity ] = text;
    quantity++;
  }
}

