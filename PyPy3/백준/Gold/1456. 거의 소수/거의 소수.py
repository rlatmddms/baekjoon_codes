a,b = map(int, input().split())

for i in range(1, 10000002):
    if i*i > b:
        b_sqrt = i
        break

is_prime = [True] * b_sqrt
is_prime[0] = False
is_prime[1] = False
cnt = 0
for i in range(2,b_sqrt):
    if is_prime[i]:
        tmp = i*i
        while b >= tmp:
            if a <= tmp:
                cnt+=1
            tmp *= i
        for j in range(i+i,b_sqrt,i):
            is_prime[j] = False

print(cnt)  