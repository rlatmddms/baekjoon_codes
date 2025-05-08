def is_perfect(p):
    s = 0
    for i in p:
        s += (-1 if i == ')' else 1)
        if s < 0:
            return False
    if s == 0:
        return True
def is_balance(p):
    s = 0
    for i in p:
        s += (-1 if i == ')' else 1)
    if s == 0:
        return True
    return False

def reverse(c):
    if c == '(':
        return ')'
    else:
        return '('

def jagyu(p):
    if p == "":
        return ""
    for i in range(len(p)):
        if is_balance(p[:i+1]):
            u = p[:i+1]
            v = p[i+1:]
            break
    if is_perfect(u):
        return u + jagyu(v)
    return "(" + jagyu(v) + ")" + ''.join([')' if c == '(' else '(' for c in u[1:-1]])

def solution(p):
    answer = ''
    alen = 0
    plen = len(p)
    if is_perfect(p):
        return p

    return jagyu(p)
    