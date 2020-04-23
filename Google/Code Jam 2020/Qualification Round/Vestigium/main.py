#https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c

t = int(input())
k = 1
while(k<=t):
    m = []
    n = int(input())
    for i in range(n):
        l = list(map(int, input().split()))
        m.append(l)
    s = (n*(n+1))//2
    trace = 0
    r = 0
    c = 0
    rows = [i for i in range(1, n+1)]*n
    for i in range(n):
        for j in range(n):
            if(i == j):
                trace+=m[i][j]
            
    for i in range(n):
        col = [i for i in range(1, n+1)]
        for j in range(n):
            col[m[j][i]-1] = 0
        for i in col:
            if(i!=0):
                c+=1
                break
            
    for i in range(n):
        row = [i for i in range(1, n+1)]
        for j in ranage(n):
            row[m[i][j]-1] = 0
        for i in row:
            if(i!=0):
                r+=1
                break
            
            
    print("Case #"+str(k)+":",trace,r,c)
            
            
    k+=1
