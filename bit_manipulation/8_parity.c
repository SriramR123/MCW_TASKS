#include<stdio.h>
#include<stdlib.h>
#define SIZE 16

void bin(long n)
{
    for(int i=SIZE-1;i>=0;i--){
        printf("%d",(n>>i)&1);

    }
}

int main(){
  long num;
  int count;
  printf("Enter the number to check : ");
  scanf("%ld",&num);
  for(int i=SIZE-1;i>=0;i--){
    if((1<<i)&num)
        count++;
  }
  printf("bit representation : ");
  bin(num);
  if(count%2==0)
     printf("\n%ld is even-parity",num);
  else
     printf("%ld is odd-parity",num);
}

