def selection_sort(arr):
    n=len(arr)
    #loop iteration or pass
    for i in range(n):
        indexofmin=i
        #loop for finding min element from remaining unsorted list
        for j in range(i+1,n):
            if arr[j]<arr[indexofmin]:
                indexofmin=j

        arr[i],arr[indexofmin]=arr[indexofmin],arr[i]  #swap element at i and min element so min element is in i

    return arr

arr=[3,8,4,1,9,5,0]
sorted_arr=selection_sort(arr)
print(sorted_arr)

