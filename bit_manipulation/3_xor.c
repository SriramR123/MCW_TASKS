#include<stdio.h>
#include<stdlib.h>

int main(){
    int a = 13,b=9;
    printf("xor of a = %d, b = %d is %d",a,b,((~a)&b)|((~b)&a));
}

