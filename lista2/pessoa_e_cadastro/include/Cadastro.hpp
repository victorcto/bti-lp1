#ifndef Cadastro_hpp
#define Cadastro_hpp
#include <vector>
#include <iostream>

#include "Pessoa.hpp"

/**
 * Um cadastro de um conjunto de Pessoas
 */
class Cadastro{
    private:
        std::vector<Pessoa*> m_cadastrados; //<! lista de pessoas cadastradas
        std::string m_nome; //<! nome do cadastro
    public:
        /**
         * Construtor padrão
         * @param nome o nome do cadastro em questão
         */
        Cadastro(std::string nome);

        /**
         * Adiciona uma nova pessoa aos cadastrados
         * @param p uma pessoa a ser adicionada
         */
        void adicionaPessoa(Pessoa *p);

        /**
         * Remove uma pessoa do cadastro.
         * @param cpf o cpf da pessoa que deve ser removida
         * @return a referencia para o objeto pessoa que foi removida ou nullptr caso não seja encontrada.
         */
        Pessoa* removePessoa(std::string cpf);

        /**
         * Encontra uma pessoa neste cadastro.
         * @param cpf o cpf da pessoa procurada
         * @return uma referencia para o objeto pessoa, se a pessoa foi encontrada ou nullptr caso não seja encontrada.
         */
        Pessoa* encontraPessoa(std::string cpf);

        /**
         * Remove todas as pessoas cadastradas
         * Esse método chama diretamente o método clear do container vector, logo os dados não são deletados.
         */
        void limpaCadastro();

        /**
         * 
         * @return Conjunto de pessoas com cadastro. 
         */
        std::vector<Pessoa*> get_m_cadastrados();
};
#endif // Cadastro_hpp