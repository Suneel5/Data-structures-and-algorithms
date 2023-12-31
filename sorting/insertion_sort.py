def insertion_sort(mylist):

    n=len(mylist)
    for i in range(n):
        key=mylist[i]  # element to moved
        # 11 52 65 | 7 70 3 
        j=i-1
        while(j>=0 and mylist[j]>key):
            mylist[j+1] = mylist[j]
            j=j-1
        mylist[j+1]=key
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

