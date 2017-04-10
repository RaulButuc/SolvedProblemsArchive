#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define pb(x) push_back(x)

typedef enum {
    UP = 0,
    DOWN
} VMove;

typedef enum {
    LEFT = 0,
    RIGHT
} HMove;

typedef struct {
    char val;
    int posX;
    int posY;
} cell;

auto printVDir(int dir) -> void {
    if (dir == UP)
        std::cout << "UP\n";
    else if (dir == DOWN)
        std::cout << "DOWN\n";
}

auto printHDir(int dir) -> void {
    if (dir == LEFT)
        std::cout << "LEFT\n";
    else if (dir == RIGHT)
        std::cout << "RIGHT\n";
}

auto nextMove(int n, std::vector<cell> grid) -> void {
    int vMoveTimes,hMoveTimes;
    VMove vMove;
    HMove hMove;
    cell m;
    cell p;
    
    for (cell x : grid) {
        if (x.val == 'm')
            m = x;
        else if (x.val == 'p')
            p = x;
    }
        
    vMoveTimes = std::abs(m.posX - p.posX);
    if (m.posX < p.posX) {
        vMove = DOWN;
    } else if (m.posX > p.posX) {
        vMove = UP;
    }
    
    hMoveTimes = std::abs(m.posY - p.posY);
    if (m.posY < p.posY) {
        hMove = RIGHT;
    } else if (m.posY > p.posY) {
        hMove = LEFT;
    }
    
    if (hMoveTimes == 0)
        printVDir(vMove);
    else if (vMoveTimes == 0)
        printHDir(hMove);
    else if (vMoveTimes == hMoveTimes)
        printVDir(vMove);
    else if (vMoveTimes > hMoveTimes)
        printHDir(hMove);
    else if (vMoveTimes < hMoveTimes)
        printVDir(vMove);        
}

auto main(void) -> int {
    std::vector<cell> grid = {};
    
    int m; std::cin >> m;
    int r; std::cin >> r;
    int c; std::cin >> c;
    
    for (int i = 0; i < m * m; ++i) {
        cell x;
        char c; std::cin >> c;
        
        if (c == 'm' || c == 'p' || c == '-') {
            x.val = c;
            x.posX = i / m;
            x.posY = i % m;
            
            grid.pb(x);
        } else
            continue;
    }

    nextMove(m, grid);

    return 0;
}
