#include <iostream>
#include <fstream>
#include <vector>
#include "Pessoa.hpp"
#include "Cadastro.hpp"
using namespace std;

int main(){
    ifstream arquivo;
    string linha, nome, cpf, endereco, cod;
    unsigned int i = 0;

    arquivo.open("../data/CadastroUnico.txt");
    if(!arquivo.is_open())
        return EXIT_FAILURE;
    
    Cadastro* cadastro_unico = new Cadastro("Cadastro Único");
    Cadastro* cadastro_sus = new Cadastro("Sistema único de Saúde");
    Cadastro* cadastro_estadual = new Cadastro("Cadastro Estadual");
    Cadastro* cadastro_municipal = new Cadastro("Cadastro Municipal");

    while(!arquivo.eof()){
        getline(arquivo,linha);
        if(i == 0){
            nome = linha;
            i++;
        }
        else if(i == 1){
            cpf = linha;
            i++;
        }
        else if(i == 2){
            endereco = linha;
            Pessoa* pessoa = new Pessoa(nome,cpf);
            pessoa->setEndereco(endereco);
            cadastro_unico->adicionaPessoa(pessoa);
            i = 0;
        }
    }

    arquivo.close();

    while(cin >> std::ws >> linha){
        if(linha.size() > 3)
            cpf = linha;
        else if(linha.size() == 3 || linha.size() == 2){
            Pessoa* pessoa = cadastro_unico->encontraPessoa(cpf);
            if(pessoa != nullptr){
                if(linha[1] == 'E')
                    cadastro_estadual->adicionaPessoa(pessoa);
                else if (linha[1] == 'M')
                    cadastro_municipal->adicionaPessoa(pessoa);
                else
                    cadastro_sus->adicionaPessoa(pessoa);
            }
        }
    }

    cout << "Sistema único de Saúde" << endl;
    if(cadastro_sus->get_m_cadastrados().empty()){
        cout << "Ninguém Cadastrado" << endl;
    }
    else{
        for(auto p:cadastro_sus->get_m_cadastrados()){
            cout << p->getNome() << endl;
        }
    }

    cout << "\nCadastro Estadual" << endl;
    if(cadastro_estadual->get_m_cadastrados().empty()){
        cout << "Ninguém Cadastrado" << endl;
    }
    else{
        for(auto p:cadastro_estadual->get_m_cadastrados()){
            cout << p->getNome() << endl;
        }
    }

    cout << "\nCadastro Municipal" << endl;
    if(cadastro_municipal->get_m_cadastrados().empty()){
        cout << "Ninguém Cadastrado" << endl;
    }
    else{
        for(auto p:cadastro_municipal->get_m_cadastrados()){
            cout << p->getNome() << endl;
        }
    }

    for(Pessoa* p : cadastro_unico->get_m_cadastrados()){
        delete p;
    }

    delete cadastro_unico;
    delete cadastro_sus;
    delete cadastro_estadual;
    delete cadastro_municipal;

    return EXIT_SUCCESS;
}