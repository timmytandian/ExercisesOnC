#include "stdio.h"
/*
Write a program to read three ints and to print them in ascending order.

*/

void swap (int* x, int* y);

int main()
{
	int a,b,c;
	int *max,*mid,*min;

    // Read 3 integers
    printf("Input integer 1:");
    scanf("%d",&a);
    printf("Input integer 2:");
    scanf("%d",&b);
    printf("Input integer 3:");
    scanf("%d",&c);
    
    // Initial default condition
    max = &a; mid = &b; min = &c;

    // Sort those integers
    if(*max<*mid){
        swap(max, mid);
    }
    if(*max<*min){
        swap(max,min);
        swap(min,mid);
    }
    if(*mid<*min){
        swap(min,mid);
    }
    
    printf("\nIntegers after sorted ascending: %d, %d, %d",*min,*mid,*max);
    
    return 0;
}

void swap (int* x, int* y){
    int temp;
    
    temp = *x;
    *x = *y;
    *y = temp;
}