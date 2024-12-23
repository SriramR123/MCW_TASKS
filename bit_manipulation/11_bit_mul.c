#include<stdio.h>
#include<stdlib.h>
#define SIZE 16

int main(){
    long a, b;
    printf("Enter a and b :");
    scanf("%ld %ld", &a, &b);
    long result = 0;

    while (b != 0) {
        if (b & 1) {
            result += a;
        }
        a <<= 1;
        b >>= 1;
    }

    printf("Product is %ld", a, b, result);
}
