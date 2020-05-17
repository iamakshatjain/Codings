T = int(input())
t = 0
while(t<T):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    count = 0
    i = 0
    while(i < n):
        val = arr[i]
        if(val == k):
            while(val!=0 and i<n):
                if(val!=arr[i]):
                    break
                i+=1
                val-=1
            if(val == 0):
                count+=1
        else:
            i+=1
    print("Case #{}: {}".format(t+1, count))

    t+=1