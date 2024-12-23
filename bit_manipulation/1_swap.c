#include<stdio.h>
#include<stdlib.h>

int main(){
    int a=5,b=7;
    printf("Before swapping a = %d b = %d\n",a,b);
    a= a^b;
    b=a^b;
    a=a^b;
    printf("After swapping a = %d b = %d",a,b);

}
