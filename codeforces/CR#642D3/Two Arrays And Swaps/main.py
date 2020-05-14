t = int(input())
while(t>0):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort()
    b.sort()
    i = 0
    j = n-1
    while(i<n and j>=0 and k > 0):
        if(a[i] < b[j]):
            a[i] = b[j]
            i+=1
            j-=1
            k-=1
        else:
            break

    print(sum(a))

    t-=1