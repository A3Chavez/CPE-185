#include <stdio.h>   //Used for printf() statements
#include <wiringPi.h> // Include WiringPi library!

// Pin number declaraction. We're using the Broadcom chip pin numbers.
const int ledPin = 17; // Regular LED - Broadcom pin 23, P1 pin 16
const int buttonPin = 27; // Active-low button - Broadcom pin 17, P1 pin 11

int main (void) 
{
    // Setup stuff:
    wiringPiSetupGpio(); // Initialize wiringPi -- using Broadcom pin numbers

    pinMode(ledPin, OUTPUT);   // Set regular LED as output
    pinMode(buttonPin, INPUT);  // Set button as INPUT

    printf("C GPIO program running! Press CTRL+C to quit.\n");

    while(1)
    {
        if(digitalRead(buttonPin))
            digitalWrite(ledPin, HIGH);
        else
            digitalWrite(ledPin, LOW);
    }

    return 0;
}
