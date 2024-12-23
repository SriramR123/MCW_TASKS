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
  int count=0,max=0;
  printf("Enter the number to check : ");
  scanf("%ld",&num);
  for(int i=SIZE-1;i>=0;i--){
    if(!((1<<i)&num))
        count++;
    else{
        break;
    }
  }
  printf("bit representation : ");
  bin(num);
  printf("\nThe number of leading zeros : %d",count);
}
