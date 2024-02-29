def insertion_sort(mylist):
    n=len(mylist)
    #loop for iteration or pass
    for i in range(1,n): #1 to n-1
        key=mylist[i]
        j=i-1

        #finding position for insertion in sorted array
        while(j>=0 and mylist[j]>key):# key is smaller than element at pos j
            mylist[j+1]=mylist[j]   #so shifting element at j to j+1, now j is vacant
            j=j-1
        mylist[j+1]=key   #inserting key element at position j+1 as element at j is lesser than key 
    return mylist


arr=[0,4,3,6,1,9,2]
print(insertion_sort(arr))

#  -1      0    1   2   3   4   5
#          12,| 54, 65, 07, 23, 09 --> i=1, key=54, j=0
#          12,| 54, 65, 07, 23, 09 --> 1st pass done (i=1)!

#         12, 54,| 65, 07, 23, 09 --> i=2, key=65, j=1
#          12, 54,| 65, 07, 23, 09 --> 2nd pass done (i=2)!

#          12, 54, 65,| 07, 23, 09 --> i=3, key=7, j=2
#          12, 54, 65,| 65, 23, 09 --> i=3, key=7, j=1
#          12, 54, 54,| 65, 23, 09 --> i=3, key=7, j=0
#          12, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1
#          07, 12, 54,| 65, 23, 09 --> i=3, key=7, j=-1--> 3rd pass done (i=3)!

#     Fast forwarding and 4th and 5th pass will give:
#          07, 12, 54, 65,| 23, 09 --> i=4, key=23, j=3
#          07, 12, 23, 54,| 65, 09 --> After the 4th pass

#          07, 12, 23, 54, 65,| 09 --> i=5, key=09, j=4
#          07, 09, 12, 23, 54, 65| --> After the 5th pass 

