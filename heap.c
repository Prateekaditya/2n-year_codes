#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void maxHeapify(int arr[],int n,int i){
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
        maxHeapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){
    //Building Max Heap
    for(int i=n/2-1;i>=0;i--){
        maxHeapify(arr,n,i);
    }
    //Deleting
    for(int i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);
        maxHeapify(arr,i,0);
    }
}

void printArray(int arr[],int n){
    printf("[");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("]");
}
int main(){
    int n;
    printf("Enter the number of Element: ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the data %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    heapSort(arr,n);

    printf("Sorted Array is: ");
    printArray(arr,n);

    return 0;
}