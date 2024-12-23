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
    int pos;
    printf("Enter the bit position toggle : ");
    scanf("%d",&pos);
    long a = 15447;
    printf("\nBits before toggled         :");
    bin(a);
    long toggled = a ^ (1<<pos);
    printf("\nBits after toggled at %d bit :",pos);
    bin(toggled);

}
