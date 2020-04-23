#https://www.hackerrank.com/challenges/array-splitting/problem?h_r=internal-search
#!/bin/python3
 
import os
import sys
 
#
# Complete the arraySplitting function below.
#
sys.setrecursionlimit(10**9)
 
def arraySplitting(arr, sumarr, l, r):
    if((r-l+1) == 1):
        return 0
    if((r-l+1) == 2):
        if(arr[l] == arr[r]):
            return 1
        else:
            return 0
 
    # ls = sum(arr)
    ls = sumarr[r]-(sumarr[l]-arr[l])
    rs = 0
    if(ls%2 != 0):
        return 0
 
    i = r
    count = 0
 
    while(i>=l):
        ls-=arr[i]
        rs+=arr[i]
 
        if(ls == rs):
            return max(arraySplitting(arr, sumarr, l, i-1),arraySplitting(arr, sumarr, i, r))+1
        i-=1
    return count
 
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
 
    t = int(input())
 
    for t_itr in range(t):
        arr_count = int(input())
 
        arr = list(map(int, input().rstrip().split()))
        sumarr = []
        s = 0
        for index, i in enumerate(arr):
            s+=arr[index]
            sumarr.append(s)
 
        result = arraySplitting(arr, sumarr, 0, len(arr)-1)
 
        fptr.write(str(result) + '\n')
 
    fptr.close()
