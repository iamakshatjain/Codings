t = int(input())
while(t > 0):
    x, y, l, r = map(int, input().split())
    print(x|y)
    t-=1