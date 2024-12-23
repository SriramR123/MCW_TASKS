#include<stdio.h>
#include<stdlib.h>
#define SIZE 8

void bin(long n)
{
    for(int i=SIZE-1;i>=0;i--){
        printf("%d",(n>>i)&1);

    }
   // if (n > 1)
     //   bin(n / 2);
  //  printf("%d", n % 2);
}
int main(){
   int a = 59;
   int reversed = 0;
   printf("\nBefore reversal a = %d, binary rep = ",a);
   bin(a);
   for(int i=0;i<SIZE;i++){
     int lsb = a & 1;
     reversed = reversed << 1;
     reversed = reversed | lsb;
     a = a>>1;
   }
   printf("\nAfter reversal a = %d, binary rep = ",reversed);
   bin(reversed);

}
