#include<stdio.h>
void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
    int temp=arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>temp ){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=temp;
    }
}
void print(int arr[],int n){
    printf("[");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("]");
}
int main(){
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("enter the data %d:",i+1);
        scanf("%d ",&arr[i]);
    }
   print(arr,n);

   insertionsort(arr,n);
   printf("\nTHE SORTED ARRAY IS:\n");
   print(arr,n);

   return 0;
}