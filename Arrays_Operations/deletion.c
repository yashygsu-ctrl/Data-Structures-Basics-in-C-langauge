/* 🔹 3. Deletion in Array
👉 Concept:

Choose position

Shift elements to left

Reduce size

👉 Code: */
#include<stdio.h>
int main(){
    int arr[10]={10,20,30,40,50};
    int pos =2;
    int n=5,i;
    for ( i = pos; i <= n; i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
    for(int i =0; i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
    
}