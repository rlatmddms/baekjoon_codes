import sys
from collections import deque
input = sys.stdin.readline

n,m = map(int,input().split())
s2 = input().strip()
A,C,G,T = map(int,input().split())

ACTG = {
    'A':0,
    'C':0,
    'T':0,
    'G':0
}
check = deque()
cnt = 0
for i in range(0,m):
    check.append(s2[i])
    ACTG[s2[i]] += 1
    
if ACTG['A'] >= A and ACTG['C'] >= C and ACTG['G'] >= G and ACTG['T'] >= T:
    cnt+=1

for i in range(m,n):
    check.append(s2[i])
    ACTG[s2[i]] += 1
    ACTG[check.popleft()] -= 1
    
    if ACTG['A'] >= A and ACTG['C'] >= C and ACTG['G'] >= G and ACTG['T'] >= T:
        cnt+=1
print(cnt)