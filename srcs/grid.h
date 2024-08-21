#pragma once 
#include <raylib.h>
#include <vector>
class Grid
{
public:
    Grid();
    void Initialize();
    void Draw();
    char grid[20][10];
    
private:
    int nRows;
    int nColumns;
    int cellSize;
};