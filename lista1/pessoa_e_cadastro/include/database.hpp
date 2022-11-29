#ifndef database_hpp
#define database_hpp

#include <vector>
#include <iostream>

/*
TODO: definição da struct*/
struct Pessoa{
    std::string nome;
    std::string cpf;
    std::string endereco;
    /*campos aqui*/
};

static std::vector<Pessoa*> base;

/**
 * Cria uma nova instancia da struct pessoa
 * @param nome o nome da pessoa
 * @param cpf o cpf da pess
 * @param endereco o endereço da pessoa
 * @return uma referencia para a pessoa criada
 **/
Pessoa* criar_pessoa(std::string nome, std::string cpf, std::string endereco);

/**
 * Busca na base por uma pessoa com o cpf especificado
 * @param base uma referencia para a base de dados
 * @param cpf um cpf de uma pessoa
 * @return uma referencia para a pessoa que está na base com o cpf especifica, nullptr caso a pessoa não esteja na base
 **/
Pessoa* procurar_cpf(const std::vector<Pessoa*> &base, const std::string cpf);

/**
 * Insere uma pessoa nda base
 * @param base uma referencia para a base de dados
 * @param p uma pessoa para ser inserida
 * @return T caso a pessoa não exista na base, F caso contrário e não insere a pessoa.
 **/
bool inserir_pessoa(std::vector<Pessoa*> &base, Pessoa* p);

/**
 * Procura por pessoas com um nome específico na base
 * @param base uma referencia para a base de dados
 * @param nome um nome a ser buscado
 * @return um vetor com todas as pessoas com o nome buscado
 **/
std::vector<Pessoa*> procurar_nome(const std::vector<Pessoa*> &base, std::string nome);

/**
 * Remove uma pessoa da base de dados
 * @param base uma referencia para a base de dados
 * @param cpf o cpf da pessoa a ser removida
 * @return uma referencia para a pessoa que foi removida, se ela estava na base, nullptr caso contrário.
 **/
Pessoa* remover_pessoa(std::vector<Pessoa*> &base, std::string cpf);

#endif //database_hpp