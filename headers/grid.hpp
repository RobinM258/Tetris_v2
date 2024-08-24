#pragma once 
#include "Tetris.hpp"

class Grid
{
public:
    Grid();
    void Initialize();
    void Draw();
    char grid[20][10];
    void Load_Texture();
    void Exit();
    void Newpieces();
    int ValueTriple(int);
    int SetPiece(int nb);
    void Gravity(void);
    int CanMooveDown(void);
    int CanMooveLeft(void);
    int CanMooveRight(void);
    void TimeSleep(void);
    void AllStatic(void);
    void KeyHooks(void);
    void MooveRight(void);
    void MooveLeft(void);
    void RefreshScreen(void);
    void loose(void);
    void MooveDown(void);

    
private:
    int nRows;
    int nColumns;
    int cellSize;
    int _time;
    std::vector<int> _next_tetraminos;
    Texture2D Tetrotexture_1;
    Texture2D Tetrotexture_2;
    Texture2D Tetrotexture_3;
    Texture2D Tetrotexture_4;
    Texture2D Tetrotexture_5;
    Texture2D Tetrotexture_6;
    Texture2D Tetrotexture_7;
};