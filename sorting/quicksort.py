
def partition(arr,low,high):
    i=low+1
    j=high
    pivot=arr[low]
    while(i<=j):
        #find element greater than pivot
        while(arr[i]<=pivot):
            i+=1
        
        #find element lesser than piviot
        while(arr[j]>pivot):
            j-=1

       #swap that greater than and lesser than pivot element
        if(i<j):
            arr[i],arr[j]=arr[j],arr[i]

    arr[low],arr[j]=arr[j],arr[low] #placing piviot element in its position of sorted array
    return j   # j is the index of piviot element in sorted array


def quicksort(arr,low,high):
    n=len(arr)
    
    if(low<high):
        parititionIndex=partition(arr,low,high)  #gives index of pivot element in sorted array

        quicksort(arr,low,parititionIndex-1)   # sorting the sub-array of elements less than the pivot(left sub array)
        quicksort(arr,parititionIndex+1,high)  # sorting the sub-array of elements greater than the pivot(right sub array)
    return arr

# arr=[5,81,55,74,0,4,60,74,5,2,9]
arr=[1,2,3,4,5,6,7,8]
sorted_arr=quicksort(arr,low=0,high=len(arr)-1)
print(sorted_arr)