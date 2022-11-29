#include "Maze.hpp"

#include <ctime>

Maze::Maze() {}

Maze::Maze(int rows, int columns, int foodAmount, int standartPlayerX, int standartPlayerY, std::vector<std::string> mazePath)
{
    this->rows = rows;
    this->columns = columns;
    this->foodAmount = foodAmount;
    this->mazePath = mazePath;

    this->standartPlayerX = standartPlayerX;
    this->standartPlayerY = standartPlayerY;
}

int Maze::getRows()
{
    return rows;
}

void Maze::setRows(int rows)
{
    this->rows = rows;
}

int Maze::getColumns()
{
    return columns;
}

void Maze::setColumns(int columns)
{
    this->columns = columns;
}

int Maze::getFoodAmount()
{
    return foodAmount;
}

void Maze::setFoodAmount(int foodAmount)
{
    this->foodAmount = foodAmount;
}

int Maze::getXFood()
{
    return this->xFood;
}

void Maze::setXFood(int xFood)
{
    this->xFood = xFood;
}

int Maze::getYFood()
{
    return this->yFood;
}

int Maze::getStandartPlayerX()
{
    return this->standartPlayerX;
}

int Maze::getStandartPlayerY()
{
    return this->standartPlayerY;
}

void Maze::setYFood(int yFood)
{
    this->yFood = yFood;
}

void Maze::setMazePath(std::vector<std::string> &mazePath)
{
    this->mazePath = mazePath;
}

void Maze::spawnFood(int xPlayer, int yPlayer)
{
    srand(time(NULL));
    std::vector<std::pair<int, int>> availablePositions;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (mazePath[i][j] == ' ' && (i != xPlayer || j != yPlayer))
                availablePositions.push_back(std::make_pair(i, j));

    int randomPosition = rand() % availablePositions.size();

    xFood = availablePositions[randomPosition].first;
    yFood = availablePositions[randomPosition].second;
}

char Maze::getMazeElement(int x, int y)
{
    return mazePath[x][y];
}