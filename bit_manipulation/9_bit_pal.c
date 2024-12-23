#include<stdio.h>
#include<stdlib.h>
#define SIZE 16

void bin(long n) {
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

long reverse(long a) {
    long reversed = 0;

    for (int i = 0; i < SIZE; i++) {
        int lsb = a & 1;
        reversed = reversed << 1;
        reversed = reversed | lsb;
        a = a >> 1;
    }

    return reversed;
}

int main() {
    long a;
    printf("Enter the number to check: ");
    scanf("%ld", &a);

    long reversed = reverse(a);

    printf("\nBefore reversal a = %ld, binary rep = ", a);
    bin(a);

    printf("\nAfter reversal a = %ld, binary rep = ", reversed);
    bin(reversed);

    if (reversed == a) {
        printf("\n%ld is a palindrome\n", a);
    } else {
        printf("\n%ld is not a palindrome\n", a);
    }

    return 0;
}
