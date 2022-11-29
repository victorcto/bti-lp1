#include "Game.hpp"
#include "Player.hpp"

#include <string.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

Game::Game(Interface *interface)
{
    this->interface = interface;
}

std::string Game::getFileName()
{
    return this->fileName;
}

void Game::setFileName(std::string fileName)
{
    this->fileName = fileName;
}

std::string Game::getMode()
{
    return this->mode;
}

void Game::setMode(std::string mode)
{
    this->mode = mode;
}

std::string Game::getAI()
{
    return this->ai;
}

void Game::setAI(std::string ai)
{
    this->ai = ai;
}

bool Game::getParameterError()
{
    return this->parameterError;
}

void Game::setParameterError(bool error)
{
    this->parameterError = error;
}

void Game::processArguments(int argc, char *argv[])
{
    if (argc < 5)
    {
        this->parameterError = true;
        interface->printArgumentsError();
    }
    else
    {
        for (int i = 1; i < argc; i++)
        {
            if (strcmp(argv[i], "-mode") == 0)
            {
                if (strcmp(argv[i + 1], "snaze") == 0)
                    this->setMode("snaze");
                else if (strcmp(argv[i + 1], "pacmaze") == 0)
                    this->setMode("pacmaze");
                else
                {
                    this->parameterError = true;
                    interface->printArgumentsError();
                }
            }
            else if (strcmp(argv[i], "-ia") == 0)
            {
                if (strcmp(argv[i + 1], "random") == 0)
                    this->setAI("random");
                else if (strcmp(argv[i + 1], "find") == 0)
                    this->setAI("find");
                else
                {
                    this->parameterError = true;
                    interface->printArgumentsError();
                }
            }
            else if (strcmp(argv[i], "find") != 0 && strcmp(argv[i], "random") != 0 &&
                     strcmp(argv[i], "-d") != 0 && strcmp(argv[i], "pacmaze") != 0 &&
                     strcmp(argv[i], "snaze") != 0)
                this->setFileName(argv[i]);
        }
    }
}

/**
 * @brief Função auxiliar para fazer o programa esperar por alguns milisegundos
 * @param ms a quantidade de segundos que o programa deve esperar
 */
void wait(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void Game::playNextLevel()
{
    int mazeCounterAux = mazeCounter + 1;
    if (mazeCounterAux < allMazes.size())
    {
        mazeCounter++;
        currentMaze = allMazes[mazeCounter];
        ateAllFood = false;
        player->setFoodEaten(0);
        player->setCurrentMaze(currentMaze);
        currentMaze->spawnFood(player->getPosX(), player->getPosY());

        state = WAITING_IA;
    }
    else
    {
        interface->clearScreen();
        interface->printNoMoreLevelsLoadedMessage();
        wait(1500);
        interface->printLevelTransition();
    }
}

void Game::replayCurrentLevel()
{
    if (gameOver)
        player->setLives(5);

    ateAllFood = false;
    gameOver = false;

    player->setFoodEaten(0);
    player->setCurrentMaze(currentMaze);
    currentMaze->spawnFood(player->getPosX(), player->getPosY());
    state = WAITING_IA;
}

void Game::restartGameLevels()
{
    mazeCounter = 0;
    currentMaze = allMazes[mazeCounter];

    ateAllFood = false;
    gameOver = false;

    player->setFoodEaten(0);
    player->setLives(5);
    player->setCurrentMaze(currentMaze);
    currentMaze->spawnFood(player->getPosX(), player->getPosY());
    state = WAITING_IA;
}

/**
 * @brief Função auxilixar para dividir uma string em partes de acordo com um delimitador.
 * @param s String a qual vai ser dividida.
 * @param delimiter Delimitador usado para dividir a string.
 * @return vector<string> vector de string contendo as partes divididas.
 */
std::vector<std::string> split(std::string s, std::string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

void Game::initialize_game()
{
    int columnPlayer = 0, rowPlayer = 0, rows = 0, columns = 0, foodAmount = 0, lineCount = 0;
    std::string line;
    std::vector<std::string> path;
    std::ifstream levelFile(fileName);

    if (levelFile.is_open())
    {
        while (getline(levelFile, line))
        {
            if (lineCount == 0)
            {
                auto lineSplit = split(line, " ");

                rows = std::stoi(lineSplit[0]);
                columns = std::stoi(lineSplit[1]);
                foodAmount = std::stoi(lineSplit[2]);
                this->totalFoodAmount += foodAmount;
            }
            else
            {
                for (int i = 0; i < line.size(); i++)
                {
                    if (line[i] == 'V')
                    {
                        columnPlayer = i;
                        rowPlayer = lineCount - 1;
                        line[i] = ' ';
                    }
                }

                path.push_back(line);
            }

            lineCount++;

            if (lineCount > rows)
            {
                Maze *maze = new Maze(rows, columns, foodAmount, rowPlayer, columnPlayer, path);
                this->allMazes.push_back(maze);
                lineCount = 0;
                path.clear();
            }
        }
    }

    state = WAITING_USER;
    currentMaze = allMazes[mazeCounter];
    player = new Player(5, 0, 0, currentMaze);

    currentMaze->spawnFood(player->getPosX(), player->getPosY());
}

void Game::process_actions()
{
    switch (state)
    {
    case WAITING_USER:
        std::cin >> std::ws >> choice;
        break;
    case WAITING_IA:
        action = player->next_move(ai);
        break;
    default:
        break;
    }
}

void Game::update()
{
    switch (state)
    {
    case RUNNING:
        if (player->getFoodEaten() == currentMaze->getFoodAmount())
        {
            player->resetPlayerStatus();
            ateAllFood = true;
            state = WAITING_USER;
            break;
        }

        if (player->getLives() == 0)
        {
            gameOver = true;
            state = WAITING_USER;
            break;
        }

        if (!player->checkCurrentPositionAllowed())
        {
            player->killPlayer();
            replayCurrentLevel();
            break;
        }

        if (action == 0)
            player->moveUp();
        else if (action == 1)
            player->moveDown();
        else if (action == 2)
            player->moveRight();
        else if (action == 3)
            player->moveLeft();
        else if (action == 4)
        {
            int foodEaten = player->getFoodEaten();
            foodEaten++;
            player->setFoodEaten(foodEaten);
            currentMaze->spawnFood(player->getPosX(), player->getPosY());
        }

        if (state == RUNNING)
            state = WAITING_IA;
        break;
    case WAITING_USER:
        if (choice == "n")
            state = GAME_OVER;
        else if (choice == "s")
        {
            player->setFoodEaten(0);
            player->setCurrentMaze(currentMaze);
            currentMaze->spawnFood(player->getPosX(), player->getPosY());
            state = RUNNING;
        }
        else if (choice == "0")
            replayCurrentLevel();
        else if (choice == "1")
            playNextLevel();
        else if (choice == "2")
            state = GAME_OVER;
        else if (choice == "3")
            restartGameLevels();
        break;
    case WAITING_IA:
        state = RUNNING;
        break;
    default:
        break;
    }
}

void Game::render()
{
    switch (state)
    {
    case RUNNING:
        interface->clearScreen();
        interface->printScoreboard(player, currentMaze->getFoodAmount());
        interface->printMaze(currentMaze, player->getPosX(), player->getPosY());
        break;
    case WAITING_USER:
        if (ateAllFood)
        {
            interface->clearScreen();
            if (mazeCounter == allMazes.size() - 1)
                game_over();
            else
                interface->printLevelTransition();
            state = WAITING_USER;
        }
        else if (gameOver)
            game_over();
        else
            interface->printContinueMessage();
        break;
    case GAME_OVER:
        interface->printGameOverMessage();
        break;
    }
}

void Game::game_over()
{
    interface->printGameOverQuestion();
}

void Game::loop()
{
    initialize_game();
    interface->welcomeScreen(mode, allMazes.size(), totalFoodAmount);
    render();
    while (state != GAME_OVER)
    {
        process_actions();
        update();
        render();
        wait(100);
    }
}