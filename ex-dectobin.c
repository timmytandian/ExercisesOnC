#include <stdio.h>
/*
This program reads decimal number from user, and return the binary representation. 
*/

int main(){
    int dec;
    int remainder[32];
    int quotient, i,j;

    // read decimal number from user
    printf("insert a decimal number to convert to binary: ");
    scanf("%d",&dec);
    
    // if user input number less than equal 0, return 0
    if (dec <= 0){
        printf("0\n");
        return 0;
    }
    
    // algorithm:
    // 1. Divide the decimal number by 2, take a note of the remainder.
    // 2. Take the quotient from the division of step 1 above, and repeat the division to take the remainder
    // 3. Repeat this process until the quotient is 0.
    // 4. The last remainder we got will become the most significant digit in our binary number
    i=0;
    quotient = dec;
    while(quotient>0){
        remainder[i] = quotient%2; // take a note of the remainder, store in array
        quotient = quotient/2;
        i++;
    }
    
    // Output the array from the last element to the first element.
    // (the last remainder is the most significant bit in binary representation)
    for(j=i-1; j>=0; --j){
        printf("%d",remainder[j]);
    }
    printf("\n");
    
    return 0;
}