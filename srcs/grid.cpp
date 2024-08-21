#include "grid.h"
#include <iostream>
#include <raylib.h>
#include "macro.hpp"

//std::cout << "test" << nRows << std::endl;
void Grid::Initialize()
{
    for(int row=0; row<nRows; row++)
    {
        for(int column=0; column<nColumns; column++)
        {
            grid[row][column] = 0;
        }
    }
}

Grid::Grid()
{
    nRows = 20;
    nColumns = 10;
    cellSize = DIM_SCREEN_Y / 24;
    Initialize();
}

void Grid::Draw()
{
    const int screenWidth = DIM_SCREEN_X;
    const int screenHeight = DIM_SCREEN_Y;

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - image loading");
    Image image = LoadImage("imgs/wall.png");     // Loaded in CPU memory (RAM)
    Texture2D texture = LoadTextureFromImage(image);          // Image converted to texture, GPU memory (VRAM)
    UnloadImage(image);
    SetTargetFPS(60);
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for(int row=0; row<nRows; row++)
        {
            for(int column=0; column<nColumns;column++)
            {
            // int cellValue = grid[row][column];
            int test = MIDLE_X;
                DrawTextureEx(texture, (Vector2){(float)column * (float)cellSize+1 + (float)test - cellSize * 5, (float)row * (float)cellSize+1}, 0.0f, 0.62f, WHITE); // drawtexture scale en fonction
               // DrawRectangle(column * cellSize+1, row * cellSize+1, cellSize-1, cellSize-1, DARKGRAY);
            }
        } 
        EndDrawing();
    }
    UnloadTexture(texture);
    CloseWindow();
}

