t = int(input())
while(t>0):
    # n is always odd
    n = int(input())
    s = 0
    tot = 0
    if(n == 1):
        print(0)
    else:
        n-=2
        while(n > 0):
            tot+=4*(n+1)
            s+=tot
            n-=2
        print(s)
    t-=1