#https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9

def findOrder(arr):
    Y = [None]*len(arr)
    sc = arr[0][0]
    ec = arr[0][1]
    Y[arr[0][2]] = 'C'
    sj = -1
    ej = -1
    for i in range(1, len(arr)):
        s = arr[i][0]
        e = arr[i][1]
        n = arr[i][2]
        print(s,e,n)
        if(s>=sc and s<ec):
            if(s>=sj and s<ej):
                return None
            else:
                sj = s
                ej = e
                Y[n] = 'J'
        else:
            sc = s
            ec = e
            Y[n] = 'C'
    return Y
        

t = int(input())
k=1
while(k<=t):
    n = int(input())
    act = []
    for i in range(n):
        s,e = map(int, input().split())
        act.append([s,e,i])
    act = sorted(act, key= lambda x:x[0])
    Y = "IMPOSSIBLE"
    Y1 = findOrder(act)
    if(Y1 is not None):
        Y2 = ""
        for i in Y1:
            Y2+=i
        print("Case #"+str(k)+":",str(Y2))
    else:
        print("Case #"+str(k)+":",str(Y))

    k+=1
