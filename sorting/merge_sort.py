#merge two sorted array
def merge(arr1,mid,low,high):
    arr2=[]
    i=low
    j=mid+1 
    k=0
    while(i<mid and j<high):
        if(arr1[i]<arr1[j]):
            arr2[k]=arr1[i]     #copy element of left side sorted array to final sorted array
            i+=1
            k+=1
        else:
            arr2[k]=arr1[j]     #copy element of right side sorted array to final sorted array
            j+=1
            k+=1
    # after empty of any sorted array(left or right)
    while (i<=mid):
        arr2[k]=arr1[i]   #copy all remaining element of left side sorted array to final sorted array
        i+=1
        k+=1
    while (j<high):
        arr2[k]=arr1[j]    #copy all remaining element of right side sorted array to final sorted array
        j+=1
        k+=1

    #copy  elements of  final sorted array to orginal array
    for i in range(low,high+1):
        arr1[i]=arr2[i]

               
#recursive  merge sort
def merge_sort(arr,low,high):
    if (low<high):
        mid=(low+high)/2
        merge_sort(arr,1,mid)   # merge sort for left side of element to mid
        merge_sort(arr,mid+1,high) # merge sort for right side of element to mid
        merge(arr,low,mid,high)    

    
arr=[4,1,7,3,8,1]
merge_sort(arr,0,len(arr))
print(arr)
