t = int(input())
while(t>0):
    n = int(input())
    c = list(map(int, input().split()))

    i = 1
    j = n-1

    a = c[0]
    b = 0

    ap = c[0]
    bp = 0

    chance = 1
    while(i <= j):
        # bob
        if(i<=j):
            bp = 0
            while(i<=j and bp<=ap):
                bp+=c[j]
                b+=c[j]
                j-=1
            chance+=1

        # alice
        if(i<=j):
            ap = 0
            while(i<=j and ap<=bp):
                ap+=c[i]
                a+=c[i]
                i+=1
            chance+=1

    print(str(chance)+' '+str(a)+' '+str(b))


    t-=1