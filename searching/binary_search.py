
def binary_search(arr ,e):
    l=0
    u=len(arr)-1
    found=False

    while l<=u:
        mid = int((l + u) / 2)
        if e==arr[mid]:
            globals()['pos']=mid    #position of target elemet is pos=mid  
            return True
        if e>arr[mid]:    #element is in right half
            l=mid+1
        elif e<arr[mid]:  #element is in left half
            u=mid-1       
    return False
result=binary_search([5,7,59,77,87,98,100,799,989,1000],87)

if result:
    print(f"Found at {pos+1}")
else:
    print("Not found")