#include<stdio.h>
#include<stdlib.h>
#define SIZE 16

int main(){
    long num1,num2;
    printf("Enter the number : ");
    scanf("%ld %ld",&num1,&num2);
    long mask = num1 ^ num2;
    if((mask>>SIZE-1)&1)
        printf("different signs");
    else
        printf("same sign");
}
