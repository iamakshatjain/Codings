#https://www.hackerearth.com/challenges/college/codelnm18/algorithm/8ee0f427470645f0985218817f7d6ab7/
#Not correct

import sys
#important
sys.setrecursionlimit(10**9)

def findPossibleDoors(passed, doors, n, m, door, i, c):
    if(door<0 or door>n):
        return
    elif(passed[i][door] == 1):
        print("passed")
        return
   
    passed[i][door] = 1
 
    if(i == m):
        if(door<=n and door>=0):
            doors.append(door)
        return
 
    door1 = door+c[i]
    door2 = door-c[i]

    if(door1>=0 and door1<=n and i+1<=m and passed[i+1][door1]!=1):
        findPossibleDoors(passed, doors, n, m, door1, i+1, c)
    if(door2>=0 and door2<=n and i+1<=m and passed[i+1][door2]!=1):
        findPossibleDoors(passed, doors, n, m, door2, i+1, c)
 
n,m = map(int, input().split())
b = int(input())
c = list(map(int, input().split()))
doors = []
passed = [[0]*(n+1) for i in range(m+1)]
 
ni = b
mi = 0
 
 
if(b<0 or b>n):
    print(-1)
else:
    findPossibleDoors(passed, doors, n, m, ni, mi, c)
    l = len(set(doors))
    if(l == 0):
        print(-1)
    else:
        print(l)
