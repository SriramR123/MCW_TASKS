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
    printf("Enter the number : ");
    scanf("%ld",&num);
    int pos=0;
    printf("Binary rep of %ld : ",num);
    bin(num);
     for(int i=SIZE-1;i>=0;i--){
       if(num & (1<<i)){
         pos = i;
         break;
       }
}
    num |= ((1<<pos+1)-1);
    num+=1;
    printf("\nThe next power of 2 is : %ld",num);
    printf("\nbinary rep : ");
    bin(num);

}
