#ifndef WORD_HPP
#define WORD_HPP
#include <iostream>

class Word {
    private:
        unsigned int relevance; // Peso da sentença
        std::string sentence; // Sentença

    public:

        /**
         * @brief Construtor personalizado da classe
         * @param relevance o pesso da sentença
         * @param sentence  a sentença
         */
        Word(unsigned int relevance, std::string sentence);

        /**
         * @brief Pega o peso da sentença.
         * @return unsigned int peso da sentença.
         */
        unsigned int getRelevance();

        /**
         * @brief Defini o peso da sentença.
         * @param relevance valor a ser atribuído ao peso da sentença.
         */
        void setRelevance(unsigned int relevance);

        /**
         * @brief Pega a sentença.
         * @return std::string sentença.
         */
        std::string getSentence();

        /**
         * @brief Defini a sentença.
         * @param sentence valor a ser atribuído à sentença.
         */
        void setSentence(std::string sentence);
};

#endif