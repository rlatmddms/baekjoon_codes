import sys
n,m = map(int,sys.stdin.readline().strip().split())
dic = {}
for i in range(1,n+1):
    s = str(sys.stdin.readline().strip())
    dic[str(i)] = s
    dic[s] = i
for i in range(m):
    s = sys.stdin.readline().strip()
    print(dic[s])