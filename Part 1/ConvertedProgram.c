/*
 This programs performs the same function as the
 assembly language program used in DEBUG.
 */
#include<stdio.h>
     
int main() {
    int mem[2] = {120, 250};    // Memory Addresses 0200 and 0202

    int D = 120,                // Register DX ; MOV DX,##
        A = mem[0],             // Register AX ; MOV AX,[##]
        B = mem[1];             // Register BX ; MOV BX,[##]

    printf("Memory 0200 is: %d\n", mem[0]);
    printf("Memory 0202 is: %d\n", mem[1]);
    printf("Value of DX register: %d\n", D);
    printf("Value in AX register: %d\n", A);
    printf("Value in BX register: %d\n", B);
    
    A = A - B;                  // SUB AX,BX
    
    printf("Value in AX register: %d\n", A);
    
    while(A < 0) {              // JGE 0114
        A = A + D;              // ADD AX,DX
        printf("Value in AX register: %d\n", A);
    }
    
    mem[0] = A;                 // MOV [0200],AX
    
    printf("Value in Memory 0200: %d\n", mem[0]);
       
    return 0;                   // INT 20
}
