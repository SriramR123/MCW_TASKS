#include<stdio.h>
#include<stdlib.h>
#define SIZE 16

void bin(long n)
{
    for(int i=SIZE-1;i>=0;i--){
        printf("%d",(n>>i)&1);

    }
}
void leading(long num){
  int count=0,max=0;
  for(int i=SIZE-1;i>=0;i--){
    if(!((1<<i)&num))
        count++;
    else{
        if(SIZE/2<=count){
           max=count;
           break;
        }else if(max<count){
            max=count;
        }
    }
  }
  printf("\nThe number of leading zeros : %d",count);
}

void trail(long num){
    int count=0;
    for(int i=0;i<SIZE;i++){
    if(!((1<<i)& num))
        count++;
    else{
        break;
    }
  }
  printf("\nThe number of trailing zeros : %d",count);

}

int main(){
    long num;
    printf("Enter the number to check : ");
    scanf("%ld",&num);
    printf("bit representation : ");
    bin(num);
    leading(num);
    trail(num);

}

