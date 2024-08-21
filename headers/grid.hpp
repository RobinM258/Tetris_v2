#pragma once 
#include "Tetris.hpp"
#include <raylib.h>
class Grid
{
public:
    Grid();
    void Initialize();
    void Draw();
    char grid[20][10];
    void Load_Texture();
    void Exit();
    
private:
    int nRows;
    int nColumns;
    int cellSize;
    Texture2D Tetrotexture_1;
    Texture2D Tetrotexture_2;
    Texture2D Tetrotexture_3;
    Texture2D Tetrotexture_4;
    Texture2D Tetrotexture_5;
    Texture2D Tetrotexture_6;
    Texture2D Tetrotexture_7;
};