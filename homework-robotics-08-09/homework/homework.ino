#include <LiquidCrystal.h>
#define COLS 16
#define ROWS 2

LiquidCrystal lcd( 6, 7, 2, 3, 4, 5 );

void setup() {
  lcd.begin( COLS, ROWS );
  Serial.begin( 9600 );
  reset_lcd();
  print_message_in_lcd( "Seleccione una opcion del Serial" );
}

void loop() {
  int n = 0;
  int j = 0;
  int size = 32;
  int serie[ size ];

  print_menu();
  int option = get_number();

  switch ( option ) {
    case 1:
      print_alert( "Ingrese la cantidad: " );
      n = get_number();
      serie_1( serie, n );
      print_array_in_serial( serie, n );
      print_serie_in_lcd( serie, n, option );
      break;
    case 2:
      print_alert( "Ingrese la cantidad: " );
      n = get_number();
      serie_2( serie, n );
      print_array_in_serial( serie, n );
      print_serie_in_lcd( serie, n, option );
      break;
    case 3:
      print_alert( "Ingrese la cantidad: " );
      n = get_number();
      serie_3( serie, n );
      print_array_in_serial( serie, n );
      print_serie_in_lcd( serie, n, option );
      break;
    case 4:
      print_alert( "Ingrese la cantidad: " );
      n = get_number();
      serie_4( serie, n );
      print_array_in_serial( serie, n );
      print_serie_in_lcd( serie, n, option );
      break;
    case 5:
      print_alert( "Ingrese la cantidad: " );
      n = get_number();
      print_alert( "Ingrese J: " );
      j = get_number();
      serie_5( serie, n, j );
      print_array_in_serial( serie, n );
      print_serie_in_lcd( serie, n, option );
      break;
    case 6:
      print_alert( "Ingrese la cantidad: " );
      n = get_number();
      serie_6( serie, n );
      print_array_in_serial( serie, n );
      print_serie_in_lcd( serie, n, option );
      break;
    case 7:
      print_alert( "Ingrese la cantidad: " );
      n = get_number();
      serie_7( serie, n );
      print_array_in_serial( serie, n );
      print_serie_in_lcd( serie, n, option );
      break;
    case 8:
      print_alert( "Ingrese la cantidad: " );
      n = get_number();
      serie_8( serie, n );
      print_array_in_serial( serie, n );
      print_serie_in_lcd( serie, n, option );
      break;
    case 9:
      print_alert( "Ingrese la cantidad: " );
      n = get_number();
      serie_9( serie, n );
      print_array_in_serial( serie, n );
      print_serie_in_lcd( serie, n, option );
      break;
    default:
      break;
  }
  delay( 300 );
}

void reset_lcd () {
  lcd.home();
  lcd.cursor();
  lcd.clear();
  lcd.setCursor( 0, 0 );
}

void print_menu () {
  Serial.println( "--------------------------------------------------" );
  Serial.println( "Seleccione una opcion del Serial" );
  Serial.println( "1. Serie 1 '1, 2, 3, 3, 2, 1, 1, 2, 3, 3, 2, 1, 1, 2, 3, ..., n'" );
  Serial.println( "2. Serie 2 '0, 0, 0, 0, 0, 0, 0, 1, 1, 1, ..., n'" );
  Serial.println( "3. Serie 3 '0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, ..., n'" );
  Serial.println( "4. Serie 4 '0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, ..., n'" );
  Serial.println( "5. Serie 5 '1, 2, 1, 4, 5, 2, 7, 8, 3, 10, 11, ..., n'" );
  Serial.println( "6. Serie 6 '1, 2, 3, 4, 5, 6, 7, 7, 6, 5, 4, ..., n'" );
  Serial.println( "7. Serie 7 '1, 2, 9, 4, 5, 36, 7, 8, 81, 10, 11, ..., n'" );
  Serial.println( "8. Serie 8 '0, 1, 1, 2, 1, 3, 2, 4, 3, 5, ..., n'" );
  Serial.println( "9. Serie 9 '0, 1, 1, 4, 3, 5, 64, 13, 21, 1156, ..., n'" );
  Serial.println( "--------------------------------------------------" );
}

void serie_1 ( int * serie, int quantity ) {
  int counter = 0;
  while ( quantity > 0 ) {
    int number = 1;
    while ( number <= 3 && quantity > 0 ) {
      serie[ counter ] = number;
      counter++;
      number++;
      quantity--;
    }
    if ( quantity == 0 )
      break;
    number = 3;
    while ( number >= 1 && quantity > 0 ) {
      serie[ counter ] = number;
      counter++;
      number--;
      quantity--;
    }
  }
}

void serie_2 ( int * serie, int quantity ) {
  int counter = 0;
  int middle = quantity / 2;
  middle = quantity % 2 == 0 ? middle : middle + 1;

  for ( int i = 0; i < middle; i++ )
    serie[ i ] = 0;

  for ( int i = middle; i < quantity; i++ )
    serie[ i ] = 1;
}

void serie_3 ( int * serie, int quantity ) {
  int i = 0;
  int numbers_quantity = 1;
  while ( quantity > 0 ) {
    int counter = 0;
    while ( counter < numbers_quantity && quantity > 0 ) {
      serie[ i ] = 0;
      quantity--;
      counter++;
      i++;
    }
    if ( quantity == 0 )
      break;
    counter = 0;
    while ( counter < numbers_quantity && quantity > 0 ) {
      serie[ i ] = 1;
      quantity--;
      counter++;
      i++;
    }
    numbers_quantity++;
  }
}

void serie_4 ( int * serie, int quantity ) {
  int i = 0;
  int numbers_quantity_0 = 1;
  int numbers_quantity_1 = 2;
  while ( quantity > 0 ) {
    int counter = 0;
    while ( counter < numbers_quantity_0 && quantity > 0 ) {
      serie[ i ] = 0;
      quantity--;
      counter++;
      i++;
    }
    if ( quantity == 0 )
      break;
    counter = 0;
    while ( counter < numbers_quantity_1 && quantity > 0 ) {
      serie[ i ] = 1;
      quantity--;
      counter++;
      i++;
    }
    numbers_quantity_0++;
    numbers_quantity_1++;
  }
}

void serie_5 ( int * serie, int quantity, int j ) {
  int i = 0;
  int counter_1 = 1;
  int counter_2 = 1;
  while ( quantity > 0 ) {
    int counter = 0;
    while ( counter < j - 1 && quantity > 0 ) {
      serie[ i ] = counter_1;
      counter_1++;
      Serial.println( "counter_1: " + String( counter_1 ) );
      Serial.println( "counter_2: " + String( counter_2 ) );
      quantity--;
      i++;
      counter++;
    }
    if ( quantity == 0 )
      break;
    serie[ i ] = counter_2;
    counter_2++;
    counter_1++;
    i++;
    quantity--;
  }
}

void serie_6 ( int * serie, int quantity ) {
  int i = 0;
  int middle = quantity / 2;
  middle = quantity % 2 == 0 ? middle : middle + 1;
  bool is_even = quantity % 2 == 0;
  int counter = 1;
  while ( i < middle ) {
    serie[ i ] = counter;
    counter++;
    i++;
    quantity--;
  }
  if ( is_even ) {
    serie[ i ] = counter - 1;
    i++;
    quantity--;
  }
  counter -= 2;
  while ( quantity > 0 ) {
    serie[ i ] = counter;
    counter--;
    i++;
    quantity--;
  }
}

void serie_7 ( int * serie, int quantity ) {
  int i = 0;
  int counter = 1;
  while ( i < quantity ) {
    serie[ i ] = counter;
    if ( counter % 3 == 0 )
      serie[ i ] *= counter;
    i++;
    counter++;
  }
}

void serie_8 ( int * serie, int quantity ) {
  int counter = 2;
  serie[ 0 ] = 0;
  if ( quantity == 1 )
    return;
  serie[ 1 ] = 1;
  if ( quantity == 2 )
    return;
  serie[ 2 ] = 1;
  if ( quantity == 3 )
    return;

  int middle = quantity / 2;
  int fibonacci[ middle ];
  fibonacci[ 0 ] = 0;
  fibonacci[ 1 ] = 1;

  for ( int i = 2; i < middle; i++ ) {
    fibonacci[ i ] = fibonacci[ i - 1 ] + fibonacci[ i - 2 ];
  }

  int j = 2;
  for ( int i = 3; i < quantity; i++ ) {
    if ( i % 2 == 0 ) {
      serie[ i ] = fibonacci[ j ];
      j++;
    }
    else {
      serie[ i ] = counter;
      counter++;
    }
  }
}

void serie_9 ( int * serie, int quantity ) {
  int i = 0;
  int fibonacci[ quantity ];
  fibonacci[ 0 ] = 0;
  if ( quantity == 1 )
    return;
  fibonacci[ 1 ] = 1;
  if ( quantity == 2 )
    return;
  for ( int i = 2; i < quantity; i++ ) {
    fibonacci[ i ] = fibonacci[ i - 1 ] + fibonacci[ i - 2 ];
  }
  for ( int i = 0; i < quantity; i++ ) {
    serie[ i ] = fibonacci[ i ];
    if ( i % 3 == 0 )
      serie[ i ] *= serie[ i ];
  }
}

void print_serie_in_lcd ( int * serie, int size, int number_serie ) {
  char message[ 32 ] = "";
  message[ 0 ] = 'S';
  message[ 1 ] = number_serie + 48;
  message[ 2 ] = ':';

  for ( int i = 0; i < size; i++ ) {
    char cadena[ 3 ];
    snprintf( cadena, sizeof( cadena ), "%d", serie[ i ] );
    strcat( message, cadena );
    strcat( message, "," );
  }
  print_message_in_lcd( message );
}

void print_message_in_lcd ( char * message ) {
  reset_lcd();
  int i = 0;
  while ( i < 16 ) {
    lcd.print( message[ i ] );
    if ( message[ i ] == '-' || message[ i ] == 0 || message[ i ] == 45 )
      break;
    i++;
    delay( 50 );
  }
  lcd.setCursor( 0, 1 );
  while ( i < 32 ) {
    if ( message[ i ] == '-' || message[ i ] == 0 || message[ i ] == 45 )
      break;
    lcd.print( message[ i ] );
    i++;
    delay( 50 );
  }
}

void print_array_in_serial ( int * array, int size ) {
  for ( int i = 0; i < size; i++ ) {
    Serial.print( array[ i ] );
    Serial.print( ", " );
  }
  Serial.println();
}

void print_alert ( char * message ) {
  Serial.println( message );
  print_message_in_lcd( message );
}

int get_number () {
  while ( !Serial.available() );
  return Serial.readString().toInt();
}

