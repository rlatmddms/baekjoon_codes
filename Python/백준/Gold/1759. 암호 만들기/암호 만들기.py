import sys
from itertools import combinations as com
n,m = map(int,sys.stdin.readline().strip().split())
a = sys.stdin.readline().strip().split()
a.sort()
cnt = 0
lst = []
for i in com(a,n):
    o = list(i)
    aeiou = 0
    other = 0
    for i in o:
        if i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u':
            aeiou += 1
        else :
            other += 1
    if aeiou >= 1 and other >= 2:
        o.sort()
        lst.append(o)
lst.sort()
for i in lst:
    for j in i:
        print(j,end='')
    print()