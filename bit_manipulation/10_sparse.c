#include<stdio.h>
#include<stdlib.h>
#define SIZE 16

void bin(long n) {
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

int main(){
    long num;
    printf("Enter the number to check: ");
    scanf("%ld", &num);
    printf("bit representation : ");
    bin(num);
    if(((num<<1)&num)>0)
        printf("\n%ld is not a sparse",num);
    else
        printf("\n%ld is a sparse",num);

}
