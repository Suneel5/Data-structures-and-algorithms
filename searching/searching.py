
def binary_search(nums ,e):
    l=0
    u=len(nums)-1
    found=False

    while l<=u:
        mid = int((l + u) / 2)
        if e==nums[mid]:
            globals()['pos']=mid
            return True
        if e>nums[mid]:
            l=mid+1
        elif e<nums[mid]:
            u=mid-1


    return False
result=binary_search([5,7,59,77,87,98,100,799,989,1000],87)

if result:
    print(f"Found at {pos+1}")
else:
    print("Not found")