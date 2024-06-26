#include <stdio.h>
#include <wiringPi.h>
#include <time.h>

/*
*Config variables.
*/
#define DLST 1 //Daylight savings time; manually update this when needed.
const float openTime = 6;//Decimal number from [0,24], decimal for partial hours
const float closingTime = 21; //Decima number from [0,24], decimal for partial hours

/*
*Pinout declarations
*/
#define SPEEDPIN 7 //ENA on L298N
#define DIR1 0  // GPIO 17 in WiringPi is pin 0; IN1 on L298N
#define DIR2 2 //IN2 on L298N

/*
*Prototypes
*/
//Returns the number of seconds elapsed over the current day.
long int daySeconds();
//Set the motor controller pins to open the door.
void openDoor();
//set the motor controller direction pins to close the door.
void closeDoor();
//resets any voltages on direction pins for motor controller.
void resetDirectionPins();
//Delays10ms
void delay10();

int main(void) {
    // Initialize WiringPi and pin modes + outputs
    wiringPiSetup();  // Initialize wiringPi
    pinMode(SPEEDPIN, OUTPUT);  // Set pin as output
    pinMode(DIR1, OUTPUT);
    pinMode(DIR2, OUTPUT);
    digitalWrite(SPEEDPIN,HIGH); //no analog write; digital write HIGH to set motor speed to max.
    resetDirectionPins();//Stupid bug, you have to initialize direction pin values to low.

    long int openSeconds = openTime*60*60;
    long int closingSeconds = closingTime*60*60;

    //Infinite control loop
    
    for(;;){
        long int doorActivationTime = 30;
	long int seconds = daySeconds();
	float hours = ((float)seconds)/(60*60);
	printf("Hours: %9.6f\n", hours);

        //TODO: put this if statement in a timer that makes sure door is open/closed (make it like 5 mins long)
        if((daySeconds() >= openSeconds) && (daySeconds() <= closingSeconds)){
            time_t startTime = time(NULL);
            //while((time(NULL) - startTime) < doorActivationTime){
                openDoor();
		printf("Door opening\n");
		delay10();
            //}
        }else{
            time_t startTime = time(NULL);
            //while((time(NULL) - startTime) < doorActivationTime){
                closeDoor();
		printf("Door closing\n");
		delay10();
            //}
            
         }
				
        resetDirectionPins();
	delay(10);
    }

    return 0;
}


long int daySeconds(){
    time_t timer;
    struct tm y2k = {0}; //Struct holding date for Jan 1, 2000, reference point
    long int seconds;
    y2k.tm_hour = 0;
    y2k.tm_min = 0;
    y2k.tm_sec = 0;
    y2k.tm_year = 0;
    y2k.tm_mon = 0;
    y2k.tm_mday = 0;
    y2k.tm_isdst = DLST;
    time(&timer); //get current time, same as timer = time(NULL);
    seconds = difftime(timer,mktime(&y2k));

    
    //Note: decimal DT cannot have % done on them, must be cast to discrete numerical 
    //type first.
    long int secondsToday = seconds%(24*60*60);

    return secondsToday;
}

void openDoor(){
    digitalWrite(DIR1, LOW);
    digitalWrite(DIR2, HIGH);
}

void closeDoor(){
    digitalWrite(DIR1, HIGH);
    digitalWrite(DIR2, LOW);
}

void resetDirectionPins(){
    digitalWrite(DIR1, LOW);
    digitalWrite(DIR2, LOW);
}

void delay10(){
	long int secondsNow = time(NULL);
	while((time(NULL) - secondsNow)<10 ){
		;
	}
	printf("Delayed 10 seconds\n");
	return;
}
    







//TODO: I found the fuking bug. setup calls a function called open(), 
//and I implicitly overrided the open() function.
