import sys
input = sys.stdin.readline

def solution(phone_book):
    phone_book.sort()
    ck = set()
    for i in phone_book:
        l = len(i)
        for j in range(1,l+1):
            if i[:j] in ck:
                return False
        ck.add(i)
    
    return True

t = int(input())
for k in range(t):
    n = int(input())
    phone = []
    for j in range(n):
        o = input().strip()
        phone.append(o)
    
    phone.sort()
    if solution(phone):
        print("YES")
    else:
        print("NO")