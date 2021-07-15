## Initialization of the pin

```c
pinMode(pin, INPUT/OUTPUT);
```

- INPUT: for pin that is connected to sensor
- OUTPUT: for pin that output signal

## GPIO

```c
digitalRead(pin);
digitalWrite(pin, HIGH/LOW);
```

- in function digitalRead():
  - For 5V power supply, if the voltage is >3.0V return HIGH;
  - For 3.3V power supply, if the voltage is >2.0V return HIGH;
- in function digitalRead():
  - ouput 5V if HIGH in 5V power supply
  - ouput 3.3V if HIGH in 3.3V power supply

## Task: Traffic Light Fun!

- Make trafic light with button
- Default is GREEN in color, when button is pressed, present the following sequence:

###

（GREEN → YELLOW → RED → RED + YELLOW → GREEN）

```c
#define BUTTON 8
#define LED_red 3
#define LED_green 6
#define LED_yellow 5
void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(LED_red, OUTPUT);
  pinMode(LED_green, OUTPUT);
  pinMode(LED_yellow, OUTPUT);
}

void loop()
{
  while(!digitalRead(BUTTON)){

  digitalWrite(LED_green, HIGH);
  digitalWrite(LED_yellow, LOW);
  digitalWrite(LED_red, LOW);
  }
  digitalWrite(LED_yellow, HIGH);
  digitalWrite(LED_green, LOW);
  delay(700);
  digitalWrite(LED_yellow, LOW);
  digitalWrite(LED_red, HIGH);
  delay(2000);
  digitalWrite(LED_red, HIGH);
  digitalWrite(LED_yellow, HIGH);
  digitalWrite(LED_green, LOW);
  delay(700);
  digitalWrite(LED_yellow, LOW);
  digitalWrite(LED_green, HIGH);
  digitalWrite(LED_red, LOW);
  delay(700);
}
```
