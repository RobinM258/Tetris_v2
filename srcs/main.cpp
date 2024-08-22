#include "Tetris.hpp"

int main(void)
{
    Grid grid;
    grid.Initialize();
    grid.Newpieces();
    grid.Gravity();
    grid.Draw();
    return 0;
}