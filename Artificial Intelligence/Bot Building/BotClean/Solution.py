#!/usr/bin/python

def manhattan_dist(x1, y1, x2, y2):
    return (abs(x1 - x2) + abs(y1 - y2), x2, y2)

def next_move(x, y, board, dirty):
    dist = [manhattan_dist(x, y, d[0], d[1]) for d in dirty]
    dist.sort()
    dx = dist[0][1]
    dy = dist[0][2]
    if x == dx and y == dy:
        print "CLEAN"
    elif x < dx:
        print "DOWN"
    elif x > dx:
        print "UP"
    elif y < dy:
        print "RIGHT"
    elif y > dy:
        print "LEFT"
    
if __name__ == "__main__":
    pos = [int(i) for i in raw_input().strip().split()]
    board = [[j for j in raw_input().strip()] for i in range(5)]
    dirty = [(i, j) for i in range(5) for j in range(5) if board[i][j] == 'd']
    next_move(pos[0], pos[1], board, dirty)
