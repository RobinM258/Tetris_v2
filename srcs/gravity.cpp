#include "grid.hpp"

void Grid::TimeSleep(void)
{
    sleep(1);
}
int Grid::CanMooveDown(void)
{
    int nb = 0;
        for(int row=0; row<nRows; row++)
        {
            for(int column=0; column<nColumns; column++)
            {
                if (grid[row][column] == 11 || grid[row][column] == 12 || grid[row][column] == 13
                || grid[row][column] == 14 || grid[row][column] == 15 || grid[row][column] == 16
                || grid[row][column] == 17)
                {
                    if (grid[row + 1][column] == 0 || grid[row + 1][column] > 10)
                        nb++;
                }
            }
        }
    if (nb == 4)
        return 0;
    return 1;
}

void Grid::AllStatic(void)
{
    int nb = 0;
    for(int row=0; row<nRows; row++)
        {
            for(int column=0; column<nColumns; column++)
            {
                if (grid[row][column] == 11 || grid[row][column] == 12 || grid[row][column] == 13
                || grid[row][column] == 14 || grid[row][column] == 15 || grid[row][column] == 16
                || grid[row][column] == 17)
                {
                    if (nb++ < 4)
                        grid[row][column] = grid[row][column] - 10;
                }
            }
        }
        auto i = _next_tetraminos.begin();
        SetPiece(*i);
}
void Grid::Gravity(void)
{
    int Gon = 0;
    int nb = 0;
        for(int row=nRows; row>=0; row--)
        {
            for(int column=nColumns; column>=0; column--)
            {
                if (grid[row][column] == 11 || grid[row][column] == 12 || grid[row][column] == 13
                || grid[row][column] == 14 || grid[row][column] == 15 || grid[row][column] == 16
                || grid[row][column] == 17)
                {
                    if (CanMooveDown() == 0 || Gon == 1)
                    {
                        Gon = 1;
                        nb = grid[row][column];
                        grid[row][column] = 0; 
                        grid[row + 1][column] = nb;
                    }
                    else
                        AllStatic();
                }
            }
        }
}