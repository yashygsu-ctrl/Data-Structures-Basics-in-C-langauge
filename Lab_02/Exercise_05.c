#include<stdio.h>
#include<stdlib.h>

int main(){
     int i;
    char*str = (char*)malloc(50*sizeof(char));
    printf("Enter a string :\n");
    scanf("%49s",str);
    printf("The entered string is %s\n",str);
    return 0;
    
}