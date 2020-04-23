#https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f

t = int(input())
k = 1
while(k<=t):
    s = input()
    n = len(s)

    # Converting to int array
    arr = []
    for i in s:
        arr.append(int(i))

    # Storing positions of all numbers
    position = {}
    for i in range(0,n):
        num = int(s[i])
        if(position.get(num, -1) == -1):
            position[num] = [i]
        else:
            position[num].append(i)


    # Getting distinct elements in asc sort order
    distinct = [i for i in position.keys()]
    distinct.sort()

    # Determining the position of the brackets
    prev = [0]*n
    after = [0]*n
    bCount = [0]*n

    for num in distinct:
        if (num <= 0):
            continue
        indices = position[num]
        prevPos = -1
        nextPos = -1
        for index in indices:
            diff = arr[index] - bCount[index]

            if (index >= prevPos and index <= nextPos):
                continue
            prevPos = index
            nextPos = index + 1
            while (prevPos >= 0 and arr[prevPos] >= arr[index]):
                bCount[prevPos] += diff
                prevPos-=1
            
            prevPos+=1
            prev[prevPos] += diff
            while (nextPos < n and arr[nextPos] >= arr[index]):
                bCount[nextPos] += diff
                nextPos+=1
            
            nextPos-=1
            after[nextPos] += diff

    # Generating the final result string
    result = ""
    for i in range(0,n):
        if (prev[i] > 0):
            for j in range(0, prev[i]):
                result+='('
        result+=s[i]
        if (after[i] > 0):
            for j in range(0, after[i]):
                result+=')'

    print("Case #" + str(k) + ":", result)
    k+=1
