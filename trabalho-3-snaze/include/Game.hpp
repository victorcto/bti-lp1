#ifndef Game_hpp
#define Game_hpp

#include "Interface.hpp"
#include "Maze.hpp"
#include "Player.hpp"

#include <iostream>
#include <vector>

class Game
{
public:
    /**
     * @brief Descreve os possíveis estados do jogo.
     **/
    enum GameStates
    {
        RUNNING,      // Quando o jogo está executando o estado é RUNNING
        GAME_OVER,    // Quando o jogo deve terminar o estado é GAME_OVER
        WAITING_USER, // Quando o jogo deve esperar por uma entrada do usuário o estado é WAITING_USER
        WAITING_IA    // Usualmente o jogo está esperando por comandos da IA, neste caso o estado é WAITING_IA
    };

private:
    Interface *interface;        // Instância da classe Interface responsável pela interface textual do jogo.
    bool parameterError = false; // Verificação de erros no recebimento de parâmetros.

    std::string fileName; // Arquivo com os níveis do jogo.
    std::string mode;     // Modo do jogo (Snaze | Pacmaze).
    std::string ai;       // Inteligência artificial do jogo (Find | Random).

    std::vector<Maze *> allMazes; // Vector contendo o todos os labirintos do jogo.
    Maze *currentMaze;            // Vector contendo o labirinto atual, pode ser interpretado como uma matriz
    int totalFoodAmount;          // Quantidade total de comida nos labirintos.

    int mazeCounter = 0; // Número do labirinto atual.
    std::string choice;  // Usado na função process_actions para guardar a escolha do usuário.
    GameStates state;    // Guarda o estado do jogo.
    Player *player;      // Instancia da classe Player responsável pela IA do jogo.
    int action = -1;     // Representa a ação escolhida pela IA.
    bool ateAllFood;     // todas as comidas do fase foram comidas.
    bool gameOver;       // Indica se o jogo deve terminar.

public:
    /**
     * @brief Construtor padrão da classe do jogo.
     */
    Game();

    /**
     * @brief Construtor personalizado da clsse do jogo.
     * @param interface referência da classe Interface.
     */
    Game(Interface *interface);

    /**
     * @brief Pega o nome do arquivo - mapa.
     * @return std::string nome do arquivo - mapa.
     */
    std::string getFileName();

    /**
     * @brief Define o nome do arquivo.
     * @param fileName valor a ser atribuído ao nome do arquivo.
     */
    void setFileName(std::string fileName);

    /**
     * @brief Pega o modo do jogo.
     * @return std::string modo do jogo.
     */
    std::string getMode();

    /**
     * @brief Define o modo do jogo.
     * @param mode valor a ser atribuído ao modo do jogo.
     */
    void setMode(std::string mode);

    /**
     * @brief Pega qual a ia responsável pelo jogo.
     * @return std::string ia do jogo.
     */
    std::string getAI();

    /**
     * @brief Define a ia do jogo.
     * @param ai valor a ser atribuído a ia do jogo.
     */
    void setAI(std::string ai);

    /**
     * @brief Pega se houve error ao executar o programa.
     * @return true se não apresenta erros ao executar o programa, false se apresenta
     * erros ao executar o programa.
     */
    bool getParameterError();

    /**
     * @brief Define se houve error ou não ao executar o programa.
     * @param error valor a ser atribuído a error na interface.
     */
    void setParameterError(bool error);

    /**
     * @brief Manipula atributos da classe game para fazer com que o jogo passe a simulação para o próximo
     * nível carregado do arquivo.
     */
    void playNextLevel();

    /**
     * @brief Manipula atributos da classe game para fazer com que o jogo reexecute a simulação do nível atual.
     */
    void replayCurrentLevel();

    /**
     * @brief Manipula atributos da classe game para fazer com que o jogo reexecute a simulação desde o nível inicial.
     */
    void restartGameLevels();

    /**
     * @brief Processa os argumentos informados a fim de verificar se houve algum
     * erro ou falta de argumento na hora de executar o programa.
     * @param argc número de argumentos
     * @param argv argumentos
     */
    void processArguments(int argc, char *argv[]);

    /**
     * @brief chamado no main, este loop executa o jogo indefinidamente até que o usuário escolha terminar!
     */
    void loop();

private:
    /**
     * @brief realiza a inicialização geral do jogo, fique à vontade para adicionar parâmetros se achar que deve
     **/
    void initialize_game();

    /**
     * @brief atualiza o estado do jogo, basicamente movendo os objetos, sorteando novas posições de comida
     **/
    void update();

    /**
     * @brief processa as entradas do jogador
     **/
    void process_actions();

    /**
     * @brief testa o estado do jogo e desenha a tela correspondente
     **/
    void render();

    /**
     * @brief é chamada quando o jogo termina a fim de destruir/resetar elementos do estado do jogo
     **/
    void game_over();
};

#endif