#ifndef Player_hpp
#define Player_hpp
#include "Maze.hpp"

class Player
{
private:
    int posX;                                       // Posição horizontal do jogador.
    int posY;                                       // Posição vertical do jogador.
    int lives;                                      // Quantidades de vidas do jogador.
    int score;                                      // Pontuação do jogador.
    int foodEaten;                                  // Quantidade de comidas comida pelo jogador.
    int pathSolutionCounter;                        // Contador da solução do jogador.
    Maze *currentMaze;                              // Instância do labirinto atual do jogador.
    std::vector<std::pair<int, int>> visitedPlaces; // Posições visitadas pelo jogador.
    std::vector<int> pathSolution;                  // Conjunto de direções com a solução para a comida.

public:
    /**
     * @brief Construtor padrão da classe.
     */
    Player();

    /**
     * @brief Construtor personalizado da classe do jogador.
     * @param lives Quantidades de vidas
     * @param score Pontuação
     * @param foodEaten Quantidade de comidas comida
     * @param currentMaze Instância do labirinto
     */
    Player(int lives, int score, int foodEaten, Maze *currentMaze);

    /**
     * @brief Pega a posição horizontal do jogador.
     * @return int posição horizontal.
     */
    int getPosX();

    /**
     * @brief Define a posição horizontal do no labirinto.
     * @param x valor a ser atribuído a posição horizontal do jogador no labirinto.
     */
    void setPosX(int x);

    /**
     * @brief Pega a posição vertical do jogador.
     * @return int posição vertical.
     */
    int getPosY();

    /**
     * @brief Define a posição vertical do no labirinto.
     * @param y valor a ser atribuído a posição vertical do jogador no labirinto.
     */
    void setPosY(int y);

    /**
     * @brief Pega a quantidade de vidas do jogador.
     * @return int vidas do jogador.
     */
    int getLives();

    /**
     * @brief Define a quantidade de vidas do jogador.
     * @param lives valor a ser atribuído as vidas do jogador.
     */
    void setLives(int lives);

    /**
     * @brief Pega a pontuação do jogador
     * @return int pontuação do jogador.
     */
    int getScore();

    /**
     * @brief Pega a quantidade de comidas já comida pelo jogador
     * @return int comida comidas pelo jogador.
     */
    int getFoodEaten();

    /**
     * @brief Define a quantidade de comidas já comida pelo jogador.
     * @param foodEaten valor a ser atribuído a quantidade de comidas já comida pelo jogador.
     */
    void setFoodEaten(int foodEaten);

    /**
     * @brief Define a quantidade de comidas já comida pelo jogador.
     * @param foodEaten valor a ser atribuído a quantidade de comidas já comida pelo jogador.
     */
    void setCurrentMaze(Maze *currentMaze);

    /**
     * @brief dada a localização atual da cobra dentro do labirinto e a localização da comida,
     * ele retorna true se ele encontrou (e armazenou) uma sequência de direções que leva à comida,
     * ou false caso contrário. No caso da solução ser encontrada, este método também armazena a
     * solução internamente no objeto.
     * @param x Posição horizontal do jogador.
     * @param y Posição vertical do jogador.
     * @return true se ele encontrou (e armazenou) uma sequência de direções que leva à comida false
     * false caso contrário.
     */
    bool find_solution(int x, int y);

    /**
     * Retorna a próxima ação do jogador um mapeamento de 0-3, representando ir para esquerda, cima, direita, baixo.
     * @param mode Modo de jogo.
     * @return a próxima ação do jogador
     **/
    int next_move(std::string ai);

    /**
     * @brief Método responsável por verificar se, dada a posição do jogador, o jogador já passou pelo local.
     * @param x Atual posição horizontal do jogador.
     * @param y Atual posição vertical do jogador.
     * @return true se o jogador já passou pelo local, false se o jogador ainda não passou pelo local.
     */
    bool visitedPlace(int x, int y);

    /**
     * @brief Método responsável por verificar se o local, dada a posição do jogador, é um local válido.
     * @param x Atual posição horizontal do jogador.
     * @param y Atual posição vertical do jogador.
     * @return true se o local é válido (' '), false se o local não é válido ("#").
     */
    bool allowedMove(int x, int y);

    /**
     * @brief Método responsável por verificar se o local atual do jogador é um local válido.
     * @return true se o local é válido (' '), false se o local não é válido ("#").
     */
    bool checkCurrentPositionAllowed();

    /**
     * @brief Método responsável por resetar os status do player (posições vertical e horizontal, comidas, etc).
     */
    void resetPlayerStatus();

    /**
     * @brief Método responsável por "matar" o player numa situação de colisão.
     */
    void killPlayer();

    /**
     * @brief Método responsável por verificar se, dada a posição do jogador, o jogador encontrou a comida.
     * @param x Atual posição horizontal do jogador.
     * @param y Atual posição vertical do jogador.
     * @return true se o jogador encontrou a comida, false caso contrário.
     */
    bool foundFood(int x, int y);

    /**
     * @brief Movimenta o jogador para cima, retirando 1 da posição vertical do jogador.
     */
    void moveUp();

    /**
     * @brief Movimenta o jogador para baixo, adicionando 1 da posição vertical do jogador.
     */
    void moveDown();

    /**
     * @brief Movimenta o jogador para esquerda, retirando 1 da posição horizontal do jogador.
     */
    void moveLeft();

    /**
     * @brief Movimenta o jogador para direita, adicionando 1 da posição horizontal do jogador.
     */
    void moveRight();
};
#endif // Player_hpp