const five = require( 'johnny-five' );
const board = new five.Board();

const minDistance = 30;

board.on( 'ready', function() {
  const rightMotor = new five.Motor({
    pins: {
      pwm: 11,
      dir: 1,
      cdir: 2
    }
  });
  const motorLeft = new five.Motor({
    pins: {
      pwm: 10,
      dir: 3,
      cdir: 4
    }
  });

  const directionCommands = {
    forward: () => {
      rightMotor.forward( 255 );
      motorLeft.forward( 255 );
      board.wait( 300, motor.stop );
    },
    backward: () => {
      rightMotor.reverse( 255 );
      motorLeft.reverse( 255 );
      board.wait( 300, motor.stop );
    },
    left90deg: () => {
      rightMotor.forward( 255 );
      motorLeft.reverse( 255 );
      board.wait( 1000, motor.stop );
    },
    right90deg: () => {
      rightMotor.reverse( 255 );
      motorLeft.forward( 255 );
      board.wait( 1000, motor.stop );
    },
    stop: () => {
      rightMotor.stop();
      motorLeft.stop();
      board.wait( 300, motor.stop );
    },
    middleTurn: () => {
      rightMotor.forward( 255 );
      motorLeft.forward( 255 );
      board.wait( 2000, motor.stop );
    }
  };

  const proximity = new five.Proximity({
    controller: 'HCSR04',
    pin: 7
  });

  proximity.on( 'data', function() {
    console.log(this.cm + 'cm', this.in + 'in');
  } );

  proximity.on( 'change', function() {
    // TODO: use commands
    if ( this.cm < minDistance ) {
      console.log( 'Object detected' );
      console.log( 'Stopping' );
      console.log( 'Turning right' );
      directionCommands.right90deg();
      if ( this.cm < minDistance ) {
        console.log( 'Object detected' );
        console.log( 'Stopping' );
        console.log( 'Turning backward' );
        directionCommands.middleTurn();
        if ( this.cm < minDistance ) {
          console.log( 'Object detected' );
          console.log( 'Stopping' );
          console.log( 'Turning left' );
          directionCommands.left90deg();
        }
      }
    } 
    console.log( 'No object detected' );
    console.log( 'Moving forward' );
    directionCommands.forward();
  } );
} );
