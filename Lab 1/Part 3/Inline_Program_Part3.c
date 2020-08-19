/*
 This programs performs the same function as the
 assembly language program used in MASM for Part
 3 of lab 1.
 */
#include<stdio.h>

int increment(int a);
int decrement(int a);

int main() {
    printf("MASM Hello by Anthony Chavez\n");          // Display Program Title and Name
    
    int loopNum = 0;    // Number of loops
    int num = 1;        // Number msg
        
    printf("How many times do you wish to loop: ");
    scanf("%d", &loopNum);      // Get number of loops desired
    
    while(loopNum > 0) {
        printf("Hello World  ");
        printf("%d\n", num);
        loopNum = decrement(loopNum);   // Decrement loop number
        num = increment(num);   // Increment Number msg
    }
    
    return 0;
}

int increment(int a) {
    int c;
    
    __asm(
           "mov %1, %%eax;"
           "inc %%eax;"
           "mov %%eax, %0;"
           :"=r"(c)
           :"r"(a)
           :"%eax"
           );
           return c;
}

int decrement(int a) {
  int c;

  __asm(
        "mov %1, %%eax;"
        "dec %%eax;"
        "mov %%eax, %0;"
        :"=r"(c)
        :"r"(a)
        :"%eax"
        );
        return c;
}