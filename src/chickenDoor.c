// #include <stdio.h>
// #include <wiringPi.h>
// #include <time.h>


// /*
// *Config variables.
// */
// #define DLST 1 //Daylight savings time; manually update this when needed.
// float openTime = 6;//Decima number from [0,24], decimal for partial hours
// float closingTime = 20; //Decima number from [0,24], decimal for partial hours

// /*
// *Pinout declarations
// */
// #define SPEEDPIN 1
// #define DIR1 0  // GPIO 17 in WiringPi is pin 0; 
// #define DIR2 2

// /*
// *Prototypes
// */
// //Returns the number of seconds elapsed over the current day.
// long int daySeconds();
// //Set the motor controller pins to open the door.
// void open();
// //set the motor controller direction pins to close the door.
// void close();

// int main(void) {
//     // Initialize WiringPi and pin modes + outputs
//     wiringPiSetup();  // Initialize wiringPi
//     pinMode(SPEEDPIN, OUTPUT);  // Set pin as output
//     pinMode(DIR1, OUTPUT);
//     pinMode(DIR2, OUTPUT);
//     analogWrite(SPEEDPIN,255);

//     // open();
//     // for(;;){

//     // }

    

//     while(1) {
//         digitalWrite(DIR1, HIGH);  // Turn LED on
//         delay(500);  // Wait 500ms
//         digitalWrite(DIR1, LOW);  // Turn LED off
//         delay(500);  // Wait 500ms
//     }


//     // long int openSeconds = openTime*60*60;
//     // long int closingSeconds = closingTime*60*60;

//     // // for(;;){

//     //     if(daySeconds() >= openSeconds && daySeconds() <= closingSeconds){
//     // //         open();
//     //         ;
//     //     }else{
//     // //         close();
//     //         ;
//     //      }
//     // //}


//     return 0;

// }


// long int daySeconds(){
//     time_t timer;
//     struct tm y2k = {0}; //Struct holding date for Jan 1, 2000, reference point
//     long int seconds;
//     y2k.tm_hour = 0;
//     y2k.tm_min = 0;
//     y2k.tm_sec = 0;
//     y2k.tm_year = 0;
//     y2k.tm_mon = 0;
//     y2k.tm_mday = 0;
//     y2k.tm_isdst = DLST;
//     time(&timer); //get current time, same as timer = time(NULL);
//     seconds = difftime(timer,mktime(&y2k));

    
//     //Note: decimal DT cannot have % done on them, must be cast to discrete numerical 
//     //type first.
//     long int secondsToday = seconds%(24*60*60);

//     return secondsToday;
// }

// void open(){
//     digitalWrite(DIR1, HIGH);
//     digitalWrite(DIR2, LOW);
// }

// void close(){
//     digitalWrite(DIR1, LOW);
//     digitalWrite(DIR2, HIGH);
// }


// // 1.  If currentTime > openTime && currentTime < CloseTime:
// //         Open Door
// //     Else:
// //         close door


    




#include <wiringPi.h>
#include <stdio.h>

// Pin number declaration (WiringPi scheme)
#define LED_PIN 0  // GPIO 17 in WiringPi is pin 0

int main(void) {
    // Setup stuff:
    wiringPiSetup();  // Initialize wiringPi
    pinMode(LED_PIN, OUTPUT);  // Set pin as output

    while(1) {
        digitalWrite(LED_PIN, HIGH);  // Turn LED on
        delay(500);  // Wait 500ms
        digitalWrite(LED_PIN, LOW);  // Turn LED off
        delay(500);  // Wait 500ms
    }

    return 0;
}
