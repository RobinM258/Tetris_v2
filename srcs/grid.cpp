#include "Tetris.hpp"

void Grid::Initialize()
{
    for(int row=0; row<nRows; row++)
    {
        for(int column=0; column<nColumns; column++)
        {
            grid[row][column] = 0;
        }
    }
    grid[2][3] = 1; // test
    grid[2][4] = 2; // test
    grid[2][5] = 3; // test
    grid[2][6] = 4; // test
    grid[2][7] = 5; // test
    grid[2][8] = 6; // test
    grid[2][9] = 7; // test
}

Grid::Grid()
{
    nRows = 20;
    nColumns = 10;
    cellSize = DIM_SCREEN_Y / 24;
    Initialize();
}
void Grid::Load_Texture()
{
    Image image = LoadImage("imgs/wall.png");   
    Image image2 = LoadImage("imgs/wall2.png");
    Image image3 = LoadImage("imgs/wall3.png");
    Image image4 = LoadImage("imgs/wall4.png");
    Image image5 = LoadImage("imgs/wall5.png");
    Image image6 = LoadImage("imgs/wall6.png");
    Image image7 = LoadImage("imgs/wall7.png");
 
    this->Tetrotexture_1 = LoadTextureFromImage(image);
    this->Tetrotexture_2 = LoadTextureFromImage(image2);
    this->Tetrotexture_3 = LoadTextureFromImage(image3);
    this->Tetrotexture_4 = LoadTextureFromImage(image4);
    this->Tetrotexture_5 = LoadTextureFromImage(image5);
    this->Tetrotexture_6 = LoadTextureFromImage(image6);
    this->Tetrotexture_7 = LoadTextureFromImage(image7);
}
void Grid::Exit()
{
    UnloadTexture(this->Tetrotexture_1);
    UnloadTexture(this->Tetrotexture_2);
    UnloadTexture(this->Tetrotexture_3);
    UnloadTexture(this->Tetrotexture_4);
    UnloadTexture(this->Tetrotexture_5);
    UnloadTexture(this->Tetrotexture_6);
    UnloadTexture(this->Tetrotexture_7);
    CloseWindow();
}

void Grid::Draw()
{
    const int screenWidth = DIM_SCREEN_X;
    const int screenHeight = DIM_SCREEN_Y;

    InitWindow(screenWidth, screenHeight, "Tetris");
    Load_Texture();
    SetTargetFPS(60);
    while (!WindowShouldClose())  
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for(int row=0; row<nRows; row++)
        {
            for(int column=0; column<nColumns;column++)
            {
            int test = MIDLE_X;
            DrawRectangle(column * cellSize+1 + (float)test - cellSize * 5, row * cellSize+1, cellSize-1, cellSize-1, DARKGRAY);
            if (grid[row][column] == 1)
                DrawTextureEx(this->Tetrotexture_1, (Vector2){(float)column * (float)cellSize+1 + 
                (float)test - cellSize * 5, (float)row * (float)cellSize+1}, 0.0f, 0.31f, WHITE);
            else if (grid[row][column] == 2)
                DrawTextureEx(this->Tetrotexture_2, (Vector2){(float)column * (float)cellSize+1 + 
                (float)test - cellSize * 5, (float)row * (float)cellSize+1}, 0.0f, 0.31f, WHITE);
            else if (grid[row][column] == 3)
                DrawTextureEx(this->Tetrotexture_3, (Vector2){(float)column * (float)cellSize+1 + 
                (float)test - cellSize * 5, (float)row * (float)cellSize+1}, 0.0f, 0.31f, WHITE);
            else if (grid[row][column] == 4)
                DrawTextureEx(this->Tetrotexture_4, (Vector2){(float)column * (float)cellSize+1 + 
                (float)test - cellSize * 5, (float)row * (float)cellSize+1}, 0.0f, 0.31f, WHITE);
            else if (grid[row][column] == 5)
                DrawTextureEx(this->Tetrotexture_5, (Vector2){(float)column * (float)cellSize+1 + 
                (float)test - cellSize * 5, (float)row * (float)cellSize+1}, 0.0f, 0.31f, WHITE);
            else if (grid[row][column] == 6)
                DrawTextureEx(this->Tetrotexture_6, (Vector2){(float)column * (float)cellSize+1 + 
                (float)test - cellSize * 5, (float)row * (float)cellSize+1}, 0.0f, 0.31f, WHITE);
            else if (grid[row][column] == 7)
                DrawTextureEx(this->Tetrotexture_7, (Vector2){(float)column * (float)cellSize+1 + 
                (float)test - cellSize * 5, (float)row * (float)cellSize+1}, 0.0f, 0.31f, WHITE);

            }
        } 
        EndDrawing();
    }
    Exit();
}

