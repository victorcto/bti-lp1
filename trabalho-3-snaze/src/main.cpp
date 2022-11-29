#include "Interface.hpp"
#include "Game.hpp"

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    Interface *interface = new Interface();
    Game *gameManager = new Game(interface);
    gameManager->processArguments(argc, argv);

    if (!gameManager->getParameterError())
        gameManager->loop();

    delete interface;
    delete gameManager;
    return 0;
}