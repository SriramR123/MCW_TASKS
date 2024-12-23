#include<stdio.h>
#include<stdlib.h>
#define SIZE 16

int main(){
    long num;
    printf("Enter the number : ");
    scanf("%ld",&num);
    long mask = num >> 31;
    num = (num ^ mask)-mask;
    printf("The abs is %ld",num);

}
