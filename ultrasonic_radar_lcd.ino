// CHANNEL NAME = E4elecTronic
// subscribe 
// for any help- WP(9334053907)
// conneoction of wire
/* 
                       CONNECTION OF WIRE                      
                                             
          buzzer(+ve)--------12
          buzzer(-ve)--------GND
          led(+ve)-----------13
          led(-ve)-----------GND
          I2C SCL------------A5
          I2C SDA------------A4
          I2C VCC------------5v
          I2C gnd------------GND
          ULTRASONIC trig----9
          ULTRASONIC echo----10
          ULTRASONIC vcc-----Vin
          ULTRASONIC gnd----GND
          SERVO yellow------8
          SERVO red---------3.3v
          SERVO brown-------GND
           */

#include <Servo.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;
Servo myServo; 
void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(2,0);
  lcd.print("WELCOME TO");
  lcd.setCursor(6,1);
  lcd.print("JGP");
  delay(3000);
  lcd.clear();

  lcd.setCursor(5,0);
  lcd.print("BATCH");
  lcd.setCursor(3,1);
  lcd.print("2021-2024");
  delay(3000);
  lcd.clear();

  lcd.setCursor(3,0);
  lcd.print("DEPARTMENT");
  lcd.setCursor(4,1);
  lcd.print("#DECE#");
  delay(3000);
  lcd.clear();

  lcd.setCursor(4,0);
  lcd.print("MADE BY");
  lcd.setCursor(1,1);
  lcd.print("MANAB,NABADEEP");
  delay(3000);
  lcd.clear();


  lcd.setCursor(0,0);
  lcd.print("SUSHANTA,RANAJIT");
  lcd.setCursor(2,1);
  lcd.print("JOYPROKASH");
  delay(3000);
  lcd.clear();


  lcd.setCursor(3,0);
  lcd.print("DEBASISH");
  lcd.setCursor(0,1);
  lcd.print("");
  delay(3000);
  lcd.clear();


  lcd.setCursor(3,0);
  lcd.print("WE MEASURE");
  lcd.setCursor(1,1);
  lcd.print("DISTANCE&ANGLE");
  delay(3000);
  lcd.clear();

  lcd.setCursor(5,0);
  lcd.print("TOPIC");
  lcd.setCursor(2,1);
  lcd.print("ULTRASONIC");
  delay(3000);
  lcd.clear();

  lcd.setCursor(4,0);
  lcd.print("SENSOR");
  lcd.setCursor(5,1);
  lcd.print("WITH");
  delay(3000);
  lcd.clear();


  lcd.setCursor(3,0);
  lcd.print("MEASURED");
  lcd.setCursor(0,1);
  lcd.print("DISTANCE&MEASURE");
  delay(3000);
  lcd.clear();

  lcd.setCursor(5,0);
  lcd.print("START");
  lcd.setCursor(0,1);
  lcd.print("");
  delay(3000);
  lcd.clear();




  pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 
    pinMode(13, OUTPUT); 
  Serial.begin(9600);
  myServo.attach(8); }
void loop() {
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(7);
  distance = calculateDistance();
  Serial.print("angle: ");
  lcd.setCursor(0,0);
  lcd.print("ANGLE:"); 
  lcd.setCursor(7,0);
  lcd.print(i);
  lcd.setCursor(0,1);
  lcd.print("DISTANCE: ");
  lcd.setCursor(9,1);
  lcd.print(distance);
  delay(80);
  lcd.clear();
  Serial.print(i); 
  Serial.print("    distance: ");
  Serial.println(distance);
  if(distance <30){ tone(12,25);  tone(13,25); i--; }
  else{noTone(12); ;}
  }
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(7);
  distance = calculateDistance();
  Serial.print("angle: ");
  Serial.print(i);
  lcd.setCursor(0,0);
  lcd.print("ANGLE:"); 
  lcd.setCursor(7,0);
  lcd.print(i);
  lcd.setCursor(0,1);
  lcd.print("DISTANCE: ");
  lcd.setCursor(9,1);
  lcd.print(distance);
  delay(40);
  lcd.clear();
  Serial.print("   distance: ");
  Serial.println(distance);
  if(distance <30){ tone(12,25); tone(13,25); i++; }
  else{noTone(12); ;}
  
  }
}

int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}