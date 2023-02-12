#include <LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12);

//time variables
int seconds = 3;
int minutes = 2;
int secOnesPlace = 0;
int secTensPlace = 0;
int minOnesPlace = 0;
int minTensPlace = 0;

//buttons variables
int button1 = 2;
int button2 = 1;
int val;

//Bit construction of LCD numbers
byte blockR[8] = {
  0b00111,
  0b01111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

byte blockL[8] = {
  0b11100,
  0b11110,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

byte blockU[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte blockD[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111,
  0b11111
};

byte bottomBlockR[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b01111,
  0b00111
};

byte bottomBlockL[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11110,
  0b11100
};

byte block[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

byte blockUD[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111
};


//Creating individual numbers 
void setChars() {
  lcd.createChar(0, blockR);
  lcd.createChar(1, blockL);
  lcd.createChar(2, blockU);
  lcd.createChar(3, blockD);
  lcd.createChar(4, bottomBlockR);
  lcd.createChar(5, bottomBlockL);
  lcd.createChar(6, block);
  lcd.createChar(7, blockUD);
}

void createZero(int x)  {
  lcd.setCursor(x, 0);
  lcd.write(byte(0));
  lcd.write(byte(2));
  lcd.write(byte(1));
  lcd.setCursor(x, 1);
  lcd.write(byte(4));
  lcd.write(byte(3));
  lcd.write(byte(5));
}

void createOne(int x) {
  lcd.setCursor(x, 0);
  lcd.write(byte(2));
  lcd.write(byte(1));
  lcd.setCursor(x, 1);
  lcd.write(byte(3));
  lcd.write(byte(6));
  lcd.write(byte(3));
}

void createTwo(int x) {
  lcd.setCursor(x, 0);
  lcd.write(byte(7));
  lcd.write(byte(7));
  lcd.write(byte(1));
  lcd.setCursor(x, 1);
  lcd.write(byte(4));
  lcd.write(byte(3));
  lcd.write(byte(3));
}

void createThree(int x) {
  lcd.setCursor(x, 0);
  lcd.write(byte(7));
  lcd.write(byte(7));
  lcd.write(byte(1));
  lcd.setCursor(x, 1);
  lcd.write(byte(3));
  lcd.write(byte(3));
  lcd.write(byte(5));
}

void createFour(int x) {
  lcd.setCursor(x, 0);
  lcd.write(byte(4));
  lcd.write(byte(3));
  lcd.write(byte(6));
  lcd.setCursor(x+2, 1);
  lcd.write(byte(6));
}

void createFive(int x) {
  lcd.setCursor(x, 0);
  lcd.write(byte(4));
  lcd.write(byte(7));
  lcd.write(byte(7));
  lcd.setCursor(x, 1);
  lcd.write(byte(3));
  lcd.write(byte(3));
  lcd.write(byte(5));
}

void createSix(int x) {
  lcd.setCursor(x, 0);
  lcd.write(byte(0));
  lcd.write(byte(7));
  lcd.write(byte(7));
  lcd.setCursor(x, 1);
  lcd.write(byte(4));
  lcd.write(byte(3));
  lcd.write(byte(5));
}

void createSeven(int x) {
  lcd.setCursor(x, 0);
  lcd.write(byte(2));
  lcd.write(byte(2));
  lcd.write(byte(1));
  lcd.setCursor(x+2, 1);
  lcd.write(byte(6));
}

void createEight(int x) {
  lcd.setCursor(x, 0);
  lcd.write(byte(0));
  lcd.write(byte(7));
  lcd.write(byte(1));
  lcd.setCursor(x, 1);
  lcd.write(byte(4));
  lcd.write(byte(3));
  lcd.write(byte(5));
}

void createNine(int x) {
  lcd.setCursor(x, 0);
  lcd.write(byte(0));
  lcd.write(byte(7));
  lcd.write(byte(1));
  lcd.setCursor(x+2, 1);
  lcd.write(byte(6));
}

void displayNumber(int n, int x)  {
  if(n <= 0)  {
    createZero(x);
  } else if(n <= 1) {
    createOne(x);
  } else if(n <= 2)  {
    createTwo(x);    
  } else if(n <= 3)  {
    createThree(x);
  } else if(n <= 4)  {
    createFour(x);
  } else if(n <= 5)  {
    createFive(x);
  } else if(n <= 6)  {
    createSix(x);
  } else if(n <= 7)  {
    createSeven(x);
  } else if(n <= 8)  {
    createEight(x);
  } else {
    createNine(x);
  }
}

void setup() {
  lcd.begin(16, 2);
  setChars();
  pinMode(button1, INPUT);
  digitalWrite(button1, HIGH);
  pinMode(button2, INPUT);
  digitalWrite(button2, HIGH);
}

void loop() {
  lcd.clear();
  val = digitalRead(button1);
  if(val == LOW)  {
    minutes++;
    seconds++;
  }
  val = digitalRead(button2);
  if(val == LOW)  {
    seconds = seconds + 11;
  }
  lcd.setCursor(7, 0);
  lcd.write(byte(3));
  lcd.setCursor(7, 1);
  lcd.write(byte(3));
  seconds--;
  secOnesPlace  = seconds%10;
  secTensPlace = seconds/10;
  minOnesPlace  = minutes%10;
  minTensPlace = minutes/10;
  if(seconds != 0)  {
    displayNumber(secOnesPlace, 12);
    displayNumber(secTensPlace, 8);
    displayNumber(minOnesPlace, 4);
    displayNumber(minTensPlace, 0);
    delay(1000);
    if (seconds > 60) {
      lcd.clear();
      seconds = seconds%10;
      minutes++;
      displayNumber(secOnesPlace, 12);
      displayNumber(secTensPlace, 8);
      displayNumber(minOnesPlace, 4);
      displayNumber(minTensPlace, 0);
    }    
  }
  else  {
    createZero(8);
    createZero(12);
    displayNumber(minOnesPlace, 4);
    displayNumber(minTensPlace, 0);
    delay(1000);
    lcd.clear();
    lcd.setCursor(7, 0);
    lcd.write(byte(3));
    lcd.setCursor(7, 1);
    lcd.write(byte(3));
    minutes--;
    minOnesPlace  = minutes%10;
    minTensPlace = minutes/10;
    displayNumber(minOnesPlace, 4);
    displayNumber(minTensPlace, 0);
    seconds = 60;
    secOnesPlace  = seconds%10;
    secTensPlace = seconds/10;
    displayNumber(secOnesPlace, 12);
    displayNumber(secTensPlace, 8);
  }
}
