# TLE
import heapq
t = int(input())
while(t>0):
    n = int(input())
    res = [0]*n
    nzeros = n
    h = []
    heapq.heappush(h, -1*n)
    mp = {}
    mp[n] = [[0, n-1]]
    i = 1
    while(nzeros>0):
        ele = heapq.heappop(h)
        limits = min(mp[-1*ele], key=lambda x:x[0])
        # limits = mp[-1*ele][limits_i]
        mp[-1*ele].remove(limits)

        r = limits[1]
        l = limits[0]
        val = r-l+1
        mid = None
        if(val%2 == 0):
            mid = (l+r-1)//2
            res[mid] = i
            i+=1
            nzeros-=1
        else:
            mid = (l+r)//2
            res[mid] = i
            i+=1
            nzeros-=1

        if(mid-1>=l):
            heapq.heappush(h, -1*(mid-l))
            if (mid-l) in mp:
                mp[(mid-l)].append([l, mid-1])
            else:
                mp[(mid-l)] = [[l, mid-1]]
        if(mid+1<=r):
            heapq.heappush(h, -1*(r-mid))
            if (r-mid) in mp:
                mp[r-mid].append([mid+1, r])
            else:
                mp[r-mid] = [[mid+1, r]]


    print(*res)

    t-=1