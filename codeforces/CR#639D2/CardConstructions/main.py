import math

t = int(input())
while(t > 0):
    n = int(input())
    count = 0
    while(n>=2):
        h = (-1+math.sqrt(1 + 24*n))//6
        n-=(((3*h + 1)*h)//2)
        count+=1
    print(count)
    t-=1