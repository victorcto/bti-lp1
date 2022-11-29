#ifndef Pessoa_hpp
#define Pessoa_hpp

#include <iostream>

/**
 * Classe que representa uma pessoa em termos de seu nome, cpf e endereço.
 */
class Pessoa{
    private:
        std::string m_nome; //<! nome da pessoa
        std::string m_endereco; //<! endereco da pessoa
        std::string m_cpf; //<! cpf da pessoa
    public:
        /**
         * Construtor da classe pessoa.
         * Constroi um objeto do tipo pessoa com endereço inicializado com uma string vazia
         * @param nome o nome da pessoa
         * @param cpf o cpf da pessoa.
         */
        Pessoa(std::string nome, std::string cpf);

        /**
         * Modifica o atributo endereço.
         * @param endereco o novo endereco da pessoa
         */
        void setEndereco(std::string endereco);
        
        /**
         * Getter do endereço.
         * @return o valor do atributo m_endereco
         */
        std::string getEndereco();

        /**
         * Getter do nome.
         * @return o valor do atributo m_nome
         */
        std::string getNome();

        /**
         * Getter do nome.
         * @return o valor do atributo m_cpf
         */
        std::string getCPF();

};

#endif //Pessoa_hpp