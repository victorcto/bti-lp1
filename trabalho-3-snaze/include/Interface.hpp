#ifndef Interface_hpp
#define Interface_hpp

#include "Player.hpp"
#include "Maze.hpp"

#include <iostream>
#include <vector>

class Interface
{
public:
    /**
     * @brief Construtor padrão da classe.
     */
    Interface();

    /**
     * @brief Caso ocorra algum erro ou falta de argumentos ao executar o programa
     * este método é chamado para informar como ao usuário como usar deve-se executar.
     */
    void printArgumentsError();

    /**
     * @brief Tela de boas vindas do jogo
     * @param mode indica o modo do jogo
     */
    void welcomeScreen(std::string mode, int totalMaze, int totalFoodAmount);

    /**
     * @brief função auxiliar para limpar o terminal
     */
    int clearScreen();

    /**
     * @brief Imprime o quadro de pontos com informações ligadas ao player.
     * @param player referência para o player que será usado para imprimir o quadro.
     */
    void printScoreboard(Player *player, int mazeFoodAmount);

    /**
     * @brief Imprime mensagem ao usuário perguntando se deseja continuar ou não.
     */
    void printContinueMessage();

    /**
     * @brief Imprime mensagem ao usuário informando que o jogo foi encerrado.
     */
    void printGameOverMessage();

    /**
     * @brief Imprime mensagem ao usuário perguntando sua decisão acerca do game over.
     */
    void printGameOverQuestion();

    /**
     * @brief Imprime o labirinto do jogo
     * @param maze Instância da classe Maze responsável pelo labirinto do jogo.
     * @param xPlayer Posição horizontal do jogador.
     * @param yPlayer Posição vertical do jogador.
     */
    void printMaze(Maze *maze, int xPlayer, int yPlayer);

    /**
     * @brief Exibe menu de transição de nível.
     */
    void printLevelTransition();

    /**
     * @brief Exibe mensagem informando que não há mais níveis disponíveis a serem jogados.
     */
    void printNoMoreLevelsLoadedMessage();
};

#endif