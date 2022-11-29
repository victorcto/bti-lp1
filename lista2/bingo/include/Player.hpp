#ifndef Player_hpp
#define Player_hpp
#include <iostream>
#include <vector>

class Player{
    
    private:
        std::string name; // nome do jogador;
        std::vector<int> card; // cartela do jogador
        bool win = false; // condição do jogador (vencedor ou perdedor)
    
    public:
        /**
         * Construtor da classe jogador.
         * @param name o nome do jogador.
         * @param card a cartela do jogador.
         */
        Player(std::string name, std::vector<int> card);

        /**
         * Getter da cartela do jogador.
         * @return a cartela do jogador.
         */
        std::vector<int> getCard();

        /**
         * Getter do nome do jogador.
         * @return o nome do jogador.
         */
        std::string getName();

        /**
         * Setter da conidção do jogador.
         * @param win a condição que deve ser atribuído ao jogador (T = ganhou / F = perdeu).
         */
        void setWin(bool win);

        /**
         * Getter da condição do jogador.
         * @return a condição do jogador.
         */
        bool getWin();

};
#endif