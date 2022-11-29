
#include "Cadastro.hpp"

#include <algorithm>

Cadastro::Cadastro(std::string nome){
    m_nome = nome;
    /*nada a fazer*/
}

void Cadastro::adicionaPessoa(Pessoa *p){
    m_cadastrados.push_back(p);
}


Pessoa* Cadastro::removePessoa(std::string cpf){
    auto pessoa_iterator = std::find_if(m_cadastrados.begin(), m_cadastrados.end(),
                            [cpf](Pessoa* p){ //função lambda para encontrar uma pessoa pelo cpf
                                return p->getCPF() == cpf;
                            });
    if(pessoa_iterator != m_cadastrados.end()){
        m_cadastrados.erase(pessoa_iterator); //remove do vetor
        return *pessoa_iterator; //retorna a referencia
    }
    else
        return nullptr;
}

Pessoa* Cadastro::encontraPessoa(std::string cpf){
    auto pessoa_iterator = std::find_if(m_cadastrados.begin(), m_cadastrados.end(),
                            [cpf](Pessoa* p){ //função lambda para encontrar uma pessoa pelo cpf
                                return p->getCPF() == cpf;
                            });
    if(pessoa_iterator != m_cadastrados.end())
        return *pessoa_iterator; //retorna a referencia
    else
        return nullptr;
}

/**
 * Remove todas as pessoas cadastradas
 * Esse método chama diretamente o método clear do container vector, logo os dados não são deletados.
 */
void Cadastro::limpaCadastro(){
    m_cadastrados.clear();
}
std::vector<Pessoa*> Cadastro::get_m_cadastrados(){
    return m_cadastrados;
}