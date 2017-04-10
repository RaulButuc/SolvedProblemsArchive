#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

#define UP   -1
#define DOWN  1
#define LEFT -1
#define RIGHT 1

#define pb(x) push_back(x)

typedef struct {
    char val;
    int posX;
    int posY;
} cell;

auto displayPathtoPrincess(int n, std::vector<cell> grid) -> void {
    int vMove, vMoveTimes, hMove, hMoveTimes;
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
    
    for (int i = 0; i < vMoveTimes; ++i) {
        if (vMove == UP)
            std::cout << "UP\n";
        else if (vMove == DOWN)
            std::cout << "DOWN\n";
    }
    
    for (int i = 0; i < hMoveTimes; ++i) {
        if (hMove == LEFT)
            std::cout << "LEFT\n";
        else if (hMove == RIGHT)
            std::cout << "RIGHT\n";
    }
}

auto main(void) -> int {
    std::vector<cell> grid = {};
    
    int m; std::cin >> m;
    
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

    displayPathtoPrincess(m, grid);

    return 0;
}
