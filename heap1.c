#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void maxheapify(int arr[],int n,int i){
    int largest=i;
    int left=(2*i)+1;
    int right=(2*i)+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        maxheapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        maxheapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        maxheapify(arr,i,0);
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
    printf("Enter the numbers of elements:");
    scanf("%d",&n);
    int arr[10];
    for(int i=0;i<n;i++){
        printf("Enter the data %d:",i+1);
        scanf("%d",&arr[i]);
    }
    heapsort(arr,n);
    printf("The sorted array is:");
    print(arr,n);
    return 0;
}