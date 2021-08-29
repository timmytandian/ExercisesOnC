#include "stdio.h"

/*
Write a program to read in a character, an integer, and a float, and print out the values, 
then cast to other types; so that the interaction with the user is something like the following:
    Input a single character, followed by : h
	Input an integer, followed by :  4872
	Input a float, followed by :  182.937
	The character h when cast to an int gives value ?????
	The character h when cast to a float gives value ?????
	The integer 4872 when cast to a char gives value ?
	The integer 4872 when cast to a float gives value ?????
	The float 182.937 when cast to a char gives value ?
	The float 182.937 when cast to an int gives value ?????
*/

int main()
{ /* PROGRAM TO PRINT OUT SPACE RESERVED FOR VARIABLES */
	char c,i_as_char,f_as_char;	
	int i,c_as_int,f_as_int;
	float f,c_as_float,i_as_float;
	
	printf("Input a single character:");
    scanf(" %c",&c);
    printf("\nInput an integer:");
    scanf("%d",&i);
    printf("\nInput a float:");
    scanf("%f",&f);
    
    c_as_int = c;
    c_as_float = c;
    i_as_char = i;
    i_as_float = i;
    f_as_char = f;
    f_as_int = f;
    
    printf("\n\nThe character %c when cast to an int gives value \t%d",c,c_as_int);
    printf("\n\nThe character %c when cast to a float gives value \t%f",c,c_as_float);
    printf("\n\nThe integer %d when cast to a float gives value \t%f",i,i_as_float);
    printf("\n\nThe integer %d when cast to a char gives value \t%c",i,i_as_char);
    printf("\n\nThe float %f when cast to a char gives value \t%c",f,f_as_char);
    printf("\n\nThe float %f when cast to a int gives value \t%d\n",f,f_as_int);
    
    return 0;
}