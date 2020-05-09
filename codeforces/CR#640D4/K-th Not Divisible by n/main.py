t = int(input())
while(t>0):
    n, k = map(int, input().split())
    batches = k//(n-1)
    mods = k%(n-1)

    # calculate after batches number
    ans = (n-1) + ((batches-1)*n)

    # if mods non zero add one and then add add mod
    if(mods > 0):
        ans+=1
        ans+=mods

    print(ans)
    t-=1