#ifndef Maze_hpp
#define Maze_hpp

#include <iostream>
#include <vector>

class Maze
{
private:
    int rows;                          // Quantidade de linhas do labirinto.
    int columns;                       // Quantidade de colunas do labirinto.
    int foodAmount;                    // Quantidade de vezes que as comidas serão geradas no labirinto.
    int xFood;                         // Posição horizontal da comida no labirinto.
    int yFood;                         // Posição vertical da comida no labirinto.
    int standartPlayerX;               // Posição horizontal padrão do jogador no labirinto.
    int standartPlayerY;               // Posição vertical padrão do jogador no labirinto.
    std::vector<std::string> mazePath; // Caminho do labirinto.

public:
    /**
     * @brief Construtor padrão da classe labirinto
     */
    Maze();

    /**
     * @brief Construtor personalizado da classe labirinto
     * @param rows Quantidade de linhas
     * @param columns Quantidade de colunas
     * @param foodAmount Quantidade de vezes que as comidas serão geradas
     * @param mazePath Caminho
     */
    Maze(int rows, int columns, int foodAmount, int standartPlayerX, int standartPlayerY, std::vector<std::string> mazePath);

    /**
     * @brief Pega a quantidade de linhas do labirinto.
     * @return int quantidade de linhas
     */
    int getRows();

    /**
     * @brief Define a quantidade de linhas do labirinto.
     * @param rows valor a ser atribuído da quantidade de linhas do labirinto.
     */
    void setRows(int rows);

    /**
     * @brief Pega a quantidade de colunas do labirinto.
     * @return int quantidade de colunas
     */
    int getColumns();

    /**
     * @brief Define a quantidade de colunas do labirinto.
     * @param columns valor a ser atribuído da quantidade de colunas do labirinto.
     */
    void setColumns(int columns);

    /**
     * @brief Pega a quantidade de vezes que as comidas serão geradas no labirinto.
     * @return int quantidade de de vezes que as comidas serão geradas.
     */
    int getFoodAmount();

    /**
     * @brief Define a quantidade de vezes que as comidas serão geradas no labirinto.
     * @param foodAmount valor a ser atribuído a quantidade de vezes que as comidas serão geradas no labirinto.
     */
    void setFoodAmount(int foodAmount);

    /**
     * @brief Pega a posição horizontal da comida no labirinto.
     * @return int a posição horizontal da comida.
     */
    int getXFood();

    /**
     * @brief Pega a posição padrão horizontal do player no labirinto.
     * @return int a posição horizontal do player.
     */
    int getStandartPlayerX();

    /**
     * @brief Pega a posição padrão vertical do player no labirinto.
     * @return int a posição vertical do player.
     */
    int getStandartPlayerY();

    /**
     * @brief Define a posição horizontal da comida no labirinto.
     * @param xFood valor a ser atribuído a posição horizontal da comida no labirinto.
     */
    void setXFood(int xFood);

    /**
     * @brief Pega a posição vertical da comida no labirinto.
     * @return int a posição vertical da comida.
     */
    int getYFood();

    /**
     * @brief Define a posição vertical da comida no labirinto.
     * @param yFood valor a ser atribuído a posição vertical da comida no labirinto.
     */
    void setYFood(int yFood);

    /**
     * @brief Define o caminho do labirinto.
     * @param mazePath valor a ser atribuído ao caminho do labirinto.
     */
    void setMazePath(std::vector<std::string> &mazePath);

    /**
     * @brief Método responsável por inserir em uma posição aleatória a comida no labirinto.
     * @param xPlayer posição horizontal do player.
     * @param yPlayer posição vertical do player.
     */
    void spawnFood(int xPlayer, int yPlayer);

    /**
     * @brief Método responsável por fornecer um fragmento gráfico do labirinto dados linha e coluna.
     * @param x linha do fragmento gráfico
     * @param y coluna do fragmento gráfico
     * @return char elemento gráfico da posição correspondente.
     */
    char getMazeElement(int x, int y);
};

#endif