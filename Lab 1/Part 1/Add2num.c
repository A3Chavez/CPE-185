/*
 This programs asks the user to input two 
 whole numbers, adds them together and 
 outputs the sum.
 */
#include<stdio.h>
     
int main() {
    int a, b, c;
    
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    
    c = a + b;
       
    printf("Sum of the numbers = %d\n", c);
       
    return 0;
}