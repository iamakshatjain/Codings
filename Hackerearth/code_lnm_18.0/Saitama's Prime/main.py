#https://www.hackerearth.com/challenges/college/codelnm18/algorithm/c303652fff3c42e79fe5ecd9eb5bc8b0/

import math

def isPrime(x):
    if(x == 2 or x == 3):
        return True

    for i in range(2, x):    
        if(i*i > x):
            break
        if(x%i == 0):
            return False
    return True

def isSaitamaPrime(x):
    if(x < 3):
        return False
    m = int(math.log2(x)+1)+1
    for i in range(2,m):
        n = (2**i)-1
        if(x%n == 0):
            if(isPrime(n)):
                return True
    return False


t = int(input())
while(t):
    x = int(input())
    if(isSaitamaPrime(x)):
        print("YES")
    else:
        print("NO")

    t-=1
