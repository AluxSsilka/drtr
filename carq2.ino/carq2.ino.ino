int motorRight1 = 4;       // Правый мотор.
int motorRight2 = 5;


int motorLeft1 = 6;        // Левый мотор.
int motorLeft2 = 7;

int led = 9;        //led
int buzz = 8;        //buzz

int control;               // Управление двигателями.
int motorSpeed;            // Управление скоростью.

void setup() {
  
  pinMode (motorRight1, OUTPUT);
  pinMode (motorRight2, OUTPUT);
  

  pinMode (motorLeft1, OUTPUT);
  pinMode (motorLeft2, OUTPUT);

  pinMode (buzz, OUTPUT);
  pinMode (led, OUTPUT);

  motorSpeed = 250;
  Serial.begin (9600);
}

void loop()
{
  if (Serial.available() > 0) {
    control = Serial.read();

    /*********************** Скорость ***********************/
    if (control == '1') {     // Скорость 1.
      motorSpeed = 120;
    }
    if (control == '2') {     // Скорость 2
      motorSpeed = 170;
    }
    if (control == '3') {     // Скорость 3.
      motorSpeed = 250;
    }

    /*********************** Направление ***********************/
    if (control == 'S') {      // Ехать вперёд.
  rightWheelForward ();
  leftWheelForward ();
    }

    if (control == 'W') {      // Ехать назад.
   digitalWrite (motorRight1, HIGH);
  digitalWrite (motorRight2, LOW);
digitalWrite (motorLeft1, HIGH);
  digitalWrite (motorLeft2, LOW);  
    }

    if (control == 'E') {      // Повернуть направо вперёд.
  rightWheelBack ();
   leftWheelForward ();   
    }

    if (control == 'Q') {      // Повернуть налево вперёд.
   rightWheelForward ();
   leftWheelBack ();   
    }

    if (control == 'P') {      // Остановиться.
      rightWheelStop ();
      leftWheelStop ();
      erroff ();
    }
  if (control == 'Z') {      //oraaaaat
      erron();
    }
  
  }
}

/*********************** Функции колёс ***********************/
void rightWheelForward () {               // Правое колесо вперёд.
  digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, HIGH);

}

void leftWheelForward () {                // Левое колесо вперёд.
  digitalWrite (motorLeft1, LOW);
  digitalWrite (motorLeft2, HIGH);

}

void rightWheelBack () {                  // Правое колесо назад.
  digitalWrite (motorRight1, HIGH);
  digitalWrite (motorRight2, LOW);

}

void leftWheelBack () {                   // Левое колесо назад.
  digitalWrite (motorLeft1, HIGH);
  digitalWrite (motorLeft2, LOW);

}

void rightWheelStop () {                  // Правое колесо остановить.
  digitalWrite (motorRight1, LOW);
  digitalWrite (motorRight2, LOW);

}

void leftWheelStop () {                   // Левое колесо остановить.
  digitalWrite (motorLeft1, LOW);
  digitalWrite (motorLeft2, LOW);

}





/**********error*********/
void erron () {                  //ay blyat huston y nas problemu
  digitalWrite (9, HIGH);
  tone (8,3000);
  delay(500);
  noTone(8);
  digitalWrite (9, LOW);
  delay (500);
  digitalWrite (led, HIGH);
  tone (8,3000);
  delay(500);
  noTone(8);
  digitalWrite (led, LOW);
  delay (500);
  digitalWrite (led, HIGH);
  tone (8,3000);
  delay(500);
  noTone(8);
  digitalWrite (led, LOW);
  delay (500);
  digitalWrite (led, HIGH);
  tone (8,3000);
  delay(500);
  noTone(8);
  digitalWrite (led, LOW);
  delay (500);
  digitalWrite (led, HIGH);
  tone (8,3000);
  delay(500);
  noTone(8);
  digitalWrite (led, LOW);
  delay (500);
  digitalWrite (led, HIGH);
  tone (8,3000);
  delay(500);
  noTone(8);
  digitalWrite (led, LOW);
  delay (500);
}

void erroff () {                   //vse zbs
  noTone(8);
  digitalWrite (led, LOW);
}
