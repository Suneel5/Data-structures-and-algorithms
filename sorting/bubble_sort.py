def bubble_sort(numlist):
    #smaller elements shifts to left side
    for i in range(len(numlist)):
        for j in range(i,len(numlist)):
            if numlist[i]>numlist[j]:
                extra=numlist[j]
                numlist[j]=numlist[i]
                numlist[i]=extra
    return numlist
    
def bubble_sort_adaptable(numlist):
    #larger element shifted to right side
    n = len(numlist)
    for i in range(n): #loof for iteraiton/pass
        # Flag to track if any swaps were made in this iteration
        swapped = False
        
        # Perform the bubble sort for this iteration
        for j in range(n - i - 1): #iteration for comparision or swap 
            if numlist[j] > numlist[j + 1]:  
                # Swap the elements
                numlist[j], numlist[j + 1] = numlist[j + 1], numlist[j]
                swapped = True
        
        # If no swaps were made in this iteration, the list is already sorted
        if not swapped:
            break
    
    return numlist
numlist= [0,4,3,6,1,9,2]
# numlist=[1,2,3,4,5,6]

# print(bubble_sort(numlist))
print(bubble_sort_adaptable(numlist))

