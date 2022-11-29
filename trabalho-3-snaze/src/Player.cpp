#include "Player.hpp"

#include <iostream>

using namespace std;

Player::Player() {}

Player::Player(int lives, int score, int foodEaten, Maze *currentMaze)
{
    this->lives = lives;
    this->score = score;
    this->foodEaten = foodEaten;
    this->currentMaze = currentMaze;

    this->posX = currentMaze->getStandartPlayerX();
    this->posY = currentMaze->getStandartPlayerY();
}

int Player::getLives()
{
    return this->lives;
}

void Player::setLives(int lives)
{
    this->lives = lives;
}

int Player::getScore()
{
    return this->score;
}

int Player::getFoodEaten()
{
    return this->foodEaten;
}

void Player::setFoodEaten(int foodEaten)
{
    this->foodEaten = foodEaten;
}

int Player::getPosX()
{
    return this->posX;
}

void Player::setPosX(int x)
{
    posX = x;
}

void Player::setCurrentMaze(Maze *currentMaze)
{
    this->currentMaze = currentMaze;
}

int Player::getPosY()
{
    return this->posY;
}

void Player::setPosY(int y)
{
    posY = y;
}

bool Player::visitedPlace(int x, int y)
{
    std::pair<int, int> coord = std::make_pair(x, y);

    for (auto visitedCoor : this->visitedPlaces)
        if (visitedCoor == coord)
            return true;

    return false;
}

void Player::resetPlayerStatus()
{
    this->foodEaten = 0;
    this->posX = this->currentMaze->getStandartPlayerX();
    this->posY = this->currentMaze->getStandartPlayerY();
}

void Player::killPlayer()
{
    this->lives--;
    this->score = 0;
    resetPlayerStatus();
}

bool Player::checkCurrentPositionAllowed()
{
    if (this->currentMaze->getMazeElement(this->posX, this->posY) != '#')
        return true;
    else
        return false;
}

bool Player::allowedMove(int x, int y)
{
    if (this->currentMaze->getMazeElement(x, y) != '#')
        return true;
    else
        return false;
}

bool Player::foundFood(int x, int y)
{
    if (currentMaze->getXFood() == x && currentMaze->getYFood() == y)
        return true;
    else
        return false;
}

bool Player::find_solution(int x, int y)
{
    this->visitedPlaces.push_back(std::make_pair(x, y));

    if (foundFood(x, y))
        return true;
    else
    {
        if (allowedMove(x + 1, y) && !visitedPlace(x + 1, y))
            if (find_solution(x + 1, y))
                return true;

        if (allowedMove(x - 1, y) && !visitedPlace(x - 1, y))
            if (find_solution(x - 1, y))
                return true;

        if (allowedMove(x, y + 1) && !visitedPlace(x, y + 1))
            if (find_solution(x, y + 1))
                return true;

        if (allowedMove(x, y - 1) && !visitedPlace(x, y - 1))
            if (find_solution(x, y - 1))
                return true;
    }

    return false;
}

int Player::next_move(std::string ai)
{
    int nextAction = 0;
    if (ai == "find")
    {
        if (this->find_solution(this->posX, this->posY))
        {
            // pendente implementação da IA Find.
        }
    }
    else
    {
        if (foundFood(posX, posY))
        {
            nextAction = 4;
            this->score += 1000;
        }
        else
        {
            srand(time(NULL));

            std::vector<int> possibleMoves;

            if (allowedMove(posX - 1, posY)) // up
                possibleMoves.push_back(0);

            if (allowedMove(posX + 1, posY)) // down
                possibleMoves.push_back(1);

            if (allowedMove(posX, posY + 1)) // right
                possibleMoves.push_back(2);

            if (allowedMove(posX, posY - 1)) // left
                possibleMoves.push_back(3);

            if (possibleMoves.size() > 0)
            {
                int randomPosition = rand() % possibleMoves.size();
                nextAction = possibleMoves[randomPosition];
            }
            else
                nextAction = rand() % 4;
        }
    }

    this->score += 1;

    return nextAction;
}

void Player::moveUp()
{
    this->posX--;
    if (this->posX < 0)
        this->posX = 0;
}

void Player::moveDown()
{
    this->posX++;

    int limit = this->currentMaze->getRows();
    if (this->posX >= limit)
        this->posX = limit - 1;
}

void Player::moveLeft()
{
    this->posY--;
    if (this->posY < 0)
        this->posY = 0;
}

void Player::moveRight()
{
    this->posY++;

    int limit = this->currentMaze->getColumns();
    if (this->posY >= limit)
        this->posY = limit - 1;
}