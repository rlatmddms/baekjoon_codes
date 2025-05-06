def is_prime(n):
    if n == 2: return True
    if n < 2:
        return False
    if n % 2 == 0:
        return False
    for i in range(3, round(n**0.5+0.5), 2):
        if n % i == 0:
            return False
    return True;

def solution(n, k):
    answer = 0
    s = ""
    while n != 0:
        s += str(n%k)
        n //= k
    s = s[::-1]
    nlst = s.split('0')
    lst = [int(i) for i in nlst if i != ""]
    prime = set()
    for i in lst:
        if i in prime or is_prime(i):
            prime.add(i)
            answer += 1
    return answer