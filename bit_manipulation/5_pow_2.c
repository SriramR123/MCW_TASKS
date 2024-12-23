#include<stdio.h>
#include<stdlib.h>

int main(){
  int number;
  printf("Enter the number : ");
  scanf("%d",&number);
  if(!((number-1)&number))
    printf("%d is a power of 2",number);
  else
    printf("%d is not a power of 2",number);
}
