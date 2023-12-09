#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(&arr[i],&arr[min]);
        }
    }
}
void print(int arr[],int n){
    printf("[");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("]");
}
int main(){
int n;
printf("Enter the no.of elements:");
scanf("%d",&n);
int arr[n];
for(int i=0; i<n;i++){
    printf("Enter the data of %d:",i+1);
    scanf("%d",&arr[i]);
}
print(arr,n);
selectionsort(arr,n);
printf("\nSorted array is:\n");
print(arr,n);
    return 0;
}