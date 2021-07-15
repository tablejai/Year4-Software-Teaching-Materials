// Constants.
const int ANALOG_IN = A0;
const int ANALOG_OUT = 6;
const int ANALOG_IN_MAX = 1024;
const int ANALOG_OUT_MAX = 256;

const int SERVO_MIN = 60;
const int SERVO_MAX = 255;

// Helper print functions.
template <class T>
void println(T x) {
  Serial.println(x);
}

template <class T, class ...Ts>
void println(T x, Ts... xs) {
  Serial.print(x);
  Serial.print(" ");
  println(xs...);
}

void setup() {
  pinMode(ANALOG_OUT, OUTPUT); // Init pwm output.
  Serial.begin(115200); // Init serial for debugging.
}

void loop() {
  int joy = analogRead(ANALOG_IN); // Get analog input.
  int out = map(joy, 0, ANALOG_IN_MAX, SERVO_MIN, SERVO_MAX);
  analogWrite(ANALOG_OUT, out); // Write pwm output.
  println(joy, out);

  delay(50);
}
