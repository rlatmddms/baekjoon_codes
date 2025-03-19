from collections import deque
def print_board(board):
    for i in board:
        print(i)
    print()

def solution(m, n, puddles):
    answer = 0
    board = [[0]*(m+1) for _ in range(0,n+1)]
    board2 = [[0]*(m+1) for _ in range(0,n+1)]
    for x,y in puddles:
        board[y][x] = -1
    board[1][1] = 1
    board2[1][1] = 1
    q = deque()
    q.appendleft((1,1))
    dx = [0,0,-1,1]
    dy = [-1,1,0,0]
    while q:
        x,y = q.popleft()
        for i in range(0,4):
            ax = x+dx[i]
            ay = y+dy[i]
            if ax > m or ay > n or ax < 1 or ay < 1 or board[ay][ax] != 0:
                continue
            board[ay][ax] = board[y][x] + 1
            q.append((ax,ay))
    q = deque()
    q.appendleft((1,1))
    while q:
        x,y = q.popleft()
        for i in range(0,4):
            ax = x+dx[i]
            ay = y+dy[i]
            if ax > m or ay > n or ax < 1 or ay < 1 or board[ay][ax] != board[y][x] + 1:
                continue
            if board2[ay][ax] == 0:
                q.append((ax,ay))
            board2[ay][ax] += board2[y][x]
            board2[ay][ax] % 1000000007
            
    return board2[n][m] % 1000000007