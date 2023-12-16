#include<stdio.h>
void swap(int *a ,int *b){
    int temp=*a;
    *a=*b;
    *b=*a;
}
int partition(int arr[],int lb,int ub){
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if (start<end){
            swap(&arr[start],&arr[end]);
        }
 
    }
    swap(&arr[lb],&arr[end]);
    return end;
}
void quicksort(int arr[],int lb,int ub){
    if(lb<ub){
        int loc=partition(arr,lb,ub);
        quicksort(arr,lb,loc-1);
        quicksort(arr,loc+1,ub);
    }
    return ;
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
    printf("Enter the numbers of elements:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the data %d:",i+1);
        scanf("%d",&arr[i]);
    }
  printf("THE ARRAY IS:");
  print(arr,n);

  quicksort(arr,0,n-1);
  printf("\nThe sorted array is:");
  print(arr,n);
  return 0;
}