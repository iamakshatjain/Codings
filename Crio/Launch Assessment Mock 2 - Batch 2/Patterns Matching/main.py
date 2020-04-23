#https://www.hackerrank.com/contests/launch-assessment-mock-2-batch-2/challenges/patterns-matching

def isMatching(pattern, string):
    i = 0
    j = 0
        
    np = len(pattern)
    ns = len(string)
    
    if(ns == 0 and np!=0):
            return False

    while(i<np and j<ns):
        if(pattern[i] == string[j]):
            i+=1
            j+=1
        else:
            if(ord(string[j])>=ord('a') and ord(string[j])<=ord('z')):
                j+=1
            else:
                return False
    if(i<np):
        return False
    
    while(j<ns):
        if(ord(string[j])>=ord('a') and ord(string[j])<=ord('z')):
            j+=1
        else:
            return False
    
    return True
        

n = int(input())
words = []

for i in range(n):
    words.append(input())
    
pattern = input()

for i in words:
    if(isMatching(pattern, i)):
        print("true")
    else:
        print("false")
    
