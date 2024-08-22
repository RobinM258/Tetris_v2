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
    //grid[10][4] = 2;
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
int Grid::ValueTriple(int nb)
{
    int triple = 0;
    for (auto i = _next_tetraminos.begin(); i != _next_tetraminos.end(); ++i)
    {
        if (nb == *i)
            triple++;
    }
    if (triple >= 3)
        return 1;
    return 0;
}

void Grid::Newpieces()
{
    int nb;
    std:: default_random_engine  re(time(0));
    while (_next_tetraminos.size() < 6)
    {
        std::uniform_int_distribution<int> value{ 1, 7 };
        nb = (int)value(re);
        if (ValueTriple(nb) == 0)
            _next_tetraminos.push_back(nb);
    }
    _next_tetraminos.erase(_next_tetraminos.begin());
    // for (auto i = _next_tetraminos.begin(); i != _next_tetraminos.end(); ++i)
    //     std::cout << *i << std::endl;
}

int Grid::SetPiece(int nb)
{
    Newpieces();
    // piece verte
    if (nb == 1 && grid[0][4] == 0 && grid[1][4] == 0 && grid[1][5] == 0 && grid[2][5] == 0)
    {
        grid[0][4] = 11;
        grid[1][4] = 11;
        grid[1][5] = 11;
        grid[2][5] = 11;
    }
    // bleu foncée
    else if (nb == 2 && grid[0][4] == 0 && grid[1][4] == 0 && grid[2][4] == 0 && grid[2][5] == 0)
    {
        grid[0][4] = 12;
        grid[1][4] = 12;
        grid[2][4] = 12;
        grid[2][5] = 12;
    }
    // piece jaune
    else if (nb == 3 && grid[0][4] == 0 && grid[0][5] == 0 && grid[1][4] == 0 && grid[1][5] == 0)
    {
        grid[0][4] = 13;
        grid[0][5] = 13;
        grid[1][4] = 13;
        grid[1][5] = 13;
    }
    // piece violette
    else if (nb == 4 && grid[0][3] == 0 && grid[0][4] == 0 && grid[0][5] == 0 && grid[1][4] == 0)
    {
        grid[0][3] = 14;
        grid[0][4] = 14;
        grid[0][5] = 14;
        grid[1][4] = 14;
    }
    // piece orange
    else if (nb == 5 && grid[0][5] == 0 && grid[1][5] == 0 && grid[2][5] == 0 && grid[2][4] == 0)
    {
        grid[0][5] = 15;
        grid[1][5] = 15;
        grid[2][5] = 15;
        grid[2][4] = 15;
    }
    // piece bleu claire
    else if (nb == 6 && grid[0][4] == 0 && grid[1][4] == 0 && grid[2][4] == 0 && grid[3][4] == 0)
    {
        grid[0][4] = 16;
        grid[1][4] = 16;
        grid[2][4] = 16;
        grid[3][4] = 16;
    }
    // piece rouge
    else if (nb == 7 && grid[0][5] == 0 && grid[1][4] == 0 && grid[1][5] == 0 && grid[2][4] == 0)
    {
        grid[0][5] = 17;
        grid[1][4] = 17;
        grid[1][5] = 17;
        grid[2][4] = 17;
    }
    else
        return 1;
    return 0;
}
void Grid::Draw()
{
    const int screenWidth = DIM_SCREEN_X;
    const int screenHeight = DIM_SCREEN_Y;
    auto i = _next_tetraminos.begin();
    SetPiece(*i);

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
            if (grid[row][column] == 1 || grid[row][column] == 11)
                DrawTextureEx(this->Tetrotexture_1, (Vector2){(float)column * (float)cellSize+1 + 
                (float)test - cellSize * 5, (float)row * (float)cellSize+1}, 0.0f, 0.31f, WHITE);
            else if (grid[row][column] == 2 || grid[row][column] == 12)
                DrawTextureEx(this->Tetrotexture_2, (Vector2){(float)column * (float)cellSize+1 + 
                (float)test - cellSize * 5, (float)row * (float)cellSize+1}, 0.0f, 0.31f, WHITE);
            else if (grid[row][column] == 3 || grid[row][column] == 13)
                DrawTextureEx(this->Tetrotexture_3, (Vector2){(float)column * (float)cellSize+1 + 
                (float)test - cellSize * 5, (float)row * (float)cellSize+1}, 0.0f, 0.31f, WHITE);
            else if (grid[row][column] == 4 || grid[row][column] == 14)
                DrawTextureEx(this->Tetrotexture_4, (Vector2){(float)column * (float)cellSize+1 + 
                (float)test - cellSize * 5, (float)row * (float)cellSize+1}, 0.0f, 0.31f, WHITE);
            else if (grid[row][column] == 5 || grid[row][column] == 15)
                DrawTextureEx(this->Tetrotexture_5, (Vector2){(float)column * (float)cellSize+1 + 
                (float)test - cellSize * 5, (float)row * (float)cellSize+1}, 0.0f, 0.31f, WHITE);
            else if (grid[row][column] == 6 || grid[row][column] == 16)
                DrawTextureEx(this->Tetrotexture_6, (Vector2){(float)column * (float)cellSize+1 + 
                (float)test - cellSize * 5, (float)row * (float)cellSize+1}, 0.0f, 0.31f, WHITE);
            else if (grid[row][column] == 7 || grid[row][column] == 17)
                DrawTextureEx(this->Tetrotexture_7, (Vector2){(float)column * (float)cellSize+1 + 
                (float)test - cellSize * 5, (float)row * (float)cellSize+1}, 0.0f, 0.31f, WHITE);

            }
        }
        TimeSleep();
        Gravity();
        EndDrawing();
        
    }
    Exit();
}

