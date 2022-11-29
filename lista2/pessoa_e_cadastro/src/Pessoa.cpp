#include "Pessoa.hpp"

Pessoa::Pessoa(std::string nome, std::string cpf){
    m_nome = nome;
    m_cpf = cpf;
}

void Pessoa::setEndereco(std::string endereco){
    m_endereco = endereco;
}

std::string Pessoa::getEndereco(){
    return m_endereco;
}

std::string Pessoa::getNome(){
    return m_nome;
}

std::string Pessoa::getCPF(){
    return m_cpf;
}