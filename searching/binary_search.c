#include<stdio.h>
#include<conio.h>
int binary_search(int arr [],int size,int num){
    int low,mid,high;
    low=0;
    high=size-1;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==num) {
            return mid;
        }

        if(num>arr[mid]){   /* req element is  in right sub array*/
            low=mid+1;
        }
        else 
        {
            high=mid-1;
        }
    }
    return -1;
}

int main()
{
    int index,num,size;
    int arr[]={1,2,3,4,5};
    size=sizeof(arr)/sizeof(arr[0]);
    num=4;
    index=binary_search(arr,size,num); 
    printf("Given no %d is found at  position %d ",num,index);

}