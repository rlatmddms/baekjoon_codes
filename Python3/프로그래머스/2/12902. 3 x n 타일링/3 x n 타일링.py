import sys
sys.setrecursionlimit(100000)


dp = [0]*50001
dp[0] = 1
dp[2] = 3
def f(n):
    if dp[n] == 0:
        dp[n] = (f(n-2) * 4 - f(n-4))%1000000007
    return dp[n]
    

def solution(n):
    return f(n)