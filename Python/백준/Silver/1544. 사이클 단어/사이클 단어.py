import sys

input = sys.stdin.readline

set1 = set()

n = int(input())

nn = 0

for i in range(n):

    o = input().strip()

    if o not in set1:

        nn+=1

    l = len(o)

    set1.add(o)

    for j in range(l-1):

        a = ''

        a += o[1+j:l]

        a += o[0:j+1]

        set1.add(a)

        

print(nn)        

