#include "database.hpp"
#include <algorithm>
/*TODO implementação das funções*/

Pessoa* criar_pessoa(std::string nome, std::string cpf, std::string endereco){
    Pessoa *new_pessoa = new Pessoa;

    new_pessoa->nome = nome;
    new_pessoa->cpf = cpf;
    new_pessoa->endereco = endereco;

    return new_pessoa;
}

Pessoa* procurar_cpf(const std::vector<Pessoa*> &base, const std::string cpf){
    for(auto i:base){
        if(i->cpf.compare(cpf) == 0){
            return i;
        }
    }

    return nullptr;
}

bool inserir_pessoa(std::vector<Pessoa*> &base, Pessoa* p){
    if(procurar_cpf(base,p->cpf) != nullptr)
        return false;

    base.push_back(p);

    return true;
}

std::vector<Pessoa*> procurar_nome(const std::vector<Pessoa*> &base, std::string nome){
    std::vector<Pessoa*> p;
    int j = 0;

    for(auto i:base){
        if(i->nome.compare(nome) == 0){
            p[j]->nome = i->nome;
            p[j]->cpf = i->cpf;
            p[j]->endereco = i->endereco;
            j++;
        }
    }

    return p;
}

Pessoa* remover_pessoa(std::vector<Pessoa*> &base, std::string cpf){

    for (unsigned int i = 0; i < base.size(); i++){
        if(base[i]->cpf == cpf){
            base.erase(base.begin()+i);
            return criar_pessoa(base[i]->nome,base[i]->cpf,base[i]->endereco);
        }
    }

    return nullptr;
}
