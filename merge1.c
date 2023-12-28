#include<stdio.h>
void merge(int arr[],int lb,int mid,int ub){
    int i=lb;
    int j=mid+1;
    int k=lb;
    int b[k];
    while(i<=mid && j<=ub){
        if(arr[i]<=arr[j]){
            b[k]=arr[i];
            i++;
        }
        else{
            b[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            b[k]=arr[j];
            j++;
            k++;
        }}
    else{
            while(i<=mid){
                b[k]=arr[i];
                i++;
                k++;
            }
        }
        
    for(k=lb;k<=ub;k++){
        arr[k]=b[k];
    }
}
void mergesort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)%2;
        mergesort(arr,lb,mid);
        mergesort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
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
printf("Enter the no.of elements:");
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    printf("Enter the data %d:",i+1);
    scanf("%d ",&arr[i]);
}
mergesort(arr,0,n-1);
printf("\nTHE SORTED ARRAY IS:");
print(arr,n);
return 0;
}