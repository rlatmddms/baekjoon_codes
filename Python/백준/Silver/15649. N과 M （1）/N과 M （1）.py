from itertools import permutations as per

a,b = map(int,input().split())
A = []
for i in range(1,a+1):
    A.append(str(i))
for i in per(A,b):
    for j in i:
        print(j,end = ' ')
    print() 