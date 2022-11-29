#include "Interface.hpp"

Interface::Interface() {}

void Interface::printArgumentsError()
{
    std::cout << "Usage: ./snaze <level_file> -mode [snaze|pacmaze] -ia [random|find]\n\tonde <level_file> é um arquivo txt contendo a descrição dos níveis no formato especificado neste documento\n\t\t-mode [snaze|pacmaze] representa o modo do jogo, sendo possíveis dois valores snaze ou pacmaze\n\t\t-ia [random|find] representa o modo da ia do jogo, sendo possível: \"random\" onde a classe player apenas escolhe decisões aleatorias, possívelmente não letais para a Snake/Pacman; ou \"find\" onde a classe player decide um caminho possível para a comida.\n\t\t-d por fim o programa pode receber o argumento -d, que sinaliza à interface para exibir as decisões calculadas pela classe player. Esse argumento é opcional." << std::endl;
}

void Interface::welcomeScreen(std::string mode, int totalMaze, int totalFoodAmount)
{
    std::string trace;

    if (mode == "snaze")
        trace = "-";

    std::cout << "\n\033[1;33m";
    std::cout << trace << "--------------> Bem-vindo ao " << mode << " Game <--------------" << trace << std::endl;
    std::cout << "                copyright LP1/UFRN 2022                " << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Níveis carregados: " << totalMaze << " | Vidas: 5 | Comidas disponíveis: " << totalFoodAmount << std::endl;
    std::cout << "Passe todos os níveis para vencer o jogo. Boa sorte!!!" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << ">>> Pressione <ENTER> para iniciar o jogo!" << std::endl;
    std::cin.ignore();

    clearScreen();
}

int Interface::clearScreen()
{
#if defined _WIN32
    return system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    return system("clear");
#elif defined(__APPLE__)
    return system("clear");
#endif
}

void Interface::printScoreboard(Player *player, int mazeFoodAmount)
{
    std::string lives;

    for (int i = 0; i < player->getLives(); i++)
        lives += "♥";

    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Vidas: " << lives << " | Pontos: " << player->getScore() << " | Maças comidas: " << player->getFoodEaten() << " of " << mazeFoodAmount << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
}

void Interface::printContinueMessage()
{
    std::cout << "Você quer iniciar/continuar o jogo? (s/n)" << std::endl;
}

void Interface::printGameOverQuestion()
{
    clearScreen();
    std::cout << "0 - Recomeçar o mesmo nível" << std::endl;
    std::cout << "3 - Recomeçar do nível 1" << std::endl;
    std::cout << "2 - Sair do jogo" << std::endl;
}

void Interface::printGameOverMessage()
{
    clearScreen();
    std::cout << "O jogo terminou!" << std::endl;
}

void Interface::printMaze(Maze *maze, int xPlayer, int yPlayer)
{
    for (int i = 0; i < maze->getRows(); i++)
    {
        for (int j = 0; j < maze->getColumns(); j++)
        {
            if (i == xPlayer && j == yPlayer)
                std::cout << 'c';
            else if (i == maze->getXFood() && j == maze->getYFood())
                std::cout << 'o';
            else
                std::cout << maze->getMazeElement(i, j);
        }
        std::cout << std::endl;
    }
}

void Interface::printLevelTransition()
{

    std::cout << "0 - Recomeçar o mesmo nível" << std::endl;
    std::cout << "1 - Passar para o próximo nível" << std::endl;
    std::cout << "2 - Sair do jogo" << std::endl;
}

void Interface::printNoMoreLevelsLoadedMessage()
{
    std::cout << "Não há mais níveis para jogar, repense sua decisão." << std::endl;
}