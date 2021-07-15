## Data types of C++

Here are some basic data types of C++

```c
int x = 8;
float pi = 3.14159265359;
char input = 'c'; //character
bool signal = true;
char arr[5] = "HKUST"; //string
int data_set[3] = {136,387,390}; //int array
```

## Variable types

- **local variable:** is a variable that is only accessible within a specific part of a program.

- **global variable:** is a variable that accessible throughout the program.

## if statements

```c
if([circumstances1]){
    //code
}else if([circumstances2]){
    //code
}else{
    //code
}

```

## loop

For loop is usually for sth that you want it run fixed time.

###

While loop is usually for sth that u want to run under a specific circumstances.

```c
for(int i = 0, i < 5, i++){
}

while([circumstances]){
}
```

## define

```c
#define haha 1
#define a b
#define pressure_sensor A0
```

Good to use in Arduino when dealing with the pin. Name it with meaningful name.

## Function

```c
DataType name_of_function(int data){
	return data;
}
```

## Arduino Structure

```c
void setup() {
    // only run once
}

void loop() {
    // run repeatedly
}
```

## Serial

Usually use it when we need to debug or print out sensor reading.

```c
Serial.begin(Baudrate);
Serial.print(variable);
Serial.println(variable);
```

- .print dnt have a line space
- .println will auto enter one line

## Delay

```c
delay(100); // in ms
```
