/*
 This programs performs the same function as the
 assembly language program used in DEBUG for Lab 1 Part 2.
*/

#include <stdio.h>

int main() {
    int mem1[3] = {20, 50, 0};        // Memory Addresses 0204, 0205, 0206
    char mem2[1][40] = {"Water Filling Program by Anthony Chavez"};  // Memory Addresses 0210 ...
    
    printf("%s\n", mem2[0]);          // Display Program Title and Name
    
    int DL, BL, CL;                   // Registers DL, BL, CL
    
    asm ("movl $0x20,%dl");
    asm ("mov1 $0x248,%bl");
    asm ("mov1 $0x05,%cl");

    printf("Memory 0204 is: %d\n", mem1[0]);
    printf("Memory 0205 is: %d\n", mem1[1]);
    printf("Memory 0206 is: %d\n", mem1[2]);
    printf("Value of DL register: %d\n", DL);
    printf("Value in BL register: %d\n", BL);
    printf("Value in CL register: %d\n", CL);
    
    BL = BL - CL;       // SUB BL,CL ; Subtract Irrigation Amount from Current Water Level
    
    printf("Value in BL register: %d\n", BL);
    
    while(BL < 0) {                  // JGE 011D ; Tank Filled?
        mem1[2] = mem1[2] + 1;       // INC BYTE PTR [0206] ; Increment number of times tank is filled by 1
        printf("Count incremented\n");
        BL = BL + DL;                // ADD BL,DL ; Fill Tank using Filling Rate
        printf("Value in BL register: %d\n", BL);
    }
    
    mem1[0] = BL;                     // MOV [0204],BL ; Store Current Water Level
    printf("Value in Memory 0200: %d\n", mem1[0]);
    
    printf("Counter: %d\n", mem1[2]);  // Display Times Tank Filled Count


    return 0;
}