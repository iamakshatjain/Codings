def isRound(n):
    if(n == 0):
        return False

    if(n>=1 and n<=9):
        return True
    elif(n%10 == 0):
        return True
    else:
        return False


t = int(input())
while(t>0):
    n = int(input())
    res = []
    power = 1
    while(n > 0):
        dig = n%10
        if(isRound(dig*power)):
            res.append(dig*power)
        power*=10
        n//=10
    print(len(res))
    print(*res)

    t-=1