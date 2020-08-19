#include <stdio.h>   //Used for printf() statements
#include <wiringPi.h> // Include WiringPi library!

// Pin number declaraction. We're using the Broadcom chip pin numbers.
const int ledPin1 = 22;		// Regular LED - Broadcom pin 22, Pi pin 15
const int ledPin2 = 23;		// Regular LED - Broadcom pin 23, Pi pin 16
const int ledPin3 = 24;		// Regular LED - Broadcom pin 24, Pi pin 18

int main (void) 
{
    // Setup stuff:
    wiringPiSetupGpio(); // Initialize wiringPi -- using Broadcom pin numbers

    pinMode(ledPin1, OUTPUT);	// Set regular LED as output, Green
    pinMode(ledPin2, OUTPUT);	// Set regular LED as output, Yellow
    pinMode(ledPin3, OUTPUT);	// Set regular LED as output, Red

    int answr = 0;

    printf("Welcome to LedLights!\n");

    printf("Please pick an option:\n");
    printf("Option 1\n");
    printf("Option 2\n");
    scanf("\n%d",&answr);

    if (answr == 1) {
	digitalWrite(ledPin1, HIGH);
	delay (500);
	digitalWrite(ledPin1, LOW);
	delay (500);
	digitalWrite(ledPin1, HIGH);
	delay (500);
	digitalWrite(ledPin1, LOW);
	delay (500);
			
	digitalWrite(ledPin2, HIGH);
	delay (500);
	digitalWrite(ledPin2, LOW);
	delay (500);
	digitalWrite(ledPin2, HIGH);
	delay (500);
	digitalWrite(ledPin2, LOW);
	delay (500);
	    
	digitalWrite(ledPin3, HIGH);
	delay (500);
	digitalWrite(ledPin3, LOW);
	delay (500);
	digitalWrite(ledPin3, HIGH);
	delay (500);
	digitalWrite(ledPin3, LOW);
	delay (500);
    }
    else if (answr == 2) {
	    for(int i = 0; i < 20; ++i) {
	        if(i < 10 && i % 2 != 0) {
		        digitalWrite(ledPin2, HIGH);
		        delay (150);
		        digitalWrite(ledPin2, LOW);
	        }
	        else if(i % 2 == 0) {
		        digitalWrite(ledPin1, HIGH);
		        delay(150);
		        digitalWrite(ledPin1, LOW);
	        }
	        else {
		        digitalWrite(ledPin3, HIGH);
		        delay(150);
		        digitalWrite(ledPin3, LOW);
	        }
	    }
    }
    
    
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    
    printf("Bye Bye.\n");

    return 0;
}
