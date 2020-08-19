/*
 This programs performs the same function as the
 assembly language program used in MASM for Part
 3 of lab 1.
 */
#include<stdio.h>
     
int main() {
    printf("MASM Hello by Anthony Chavez\n");          // Display Program Title and Name
    
    int loopNum = 0;    // Number of loops
    int num = 1;        // Number msg
        
    printf("How many times do you wish to loop: ");
    scanf("%d", &loopNum);      // Get number of loops desired
    
    while(loopNum > 0) {
        printf("Hello World  ");
        printf("%d\n", num);
        loopNum = loopNum - 1;  // Decrement loop number
        num = num + 1;          // Increment Number msg
    }
    
    return 0;
}
