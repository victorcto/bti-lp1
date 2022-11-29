#include <iostream>
#include <fstream>


#include "database.hpp"

using namespace std;

int main(){
    string line, nome, cpf, endereco;
    int count = 0;

    // LEITURA DO ARQUIVO;
    
    ifstream file("../data/CadastroUnico.txt");

    if(!file.is_open()){
        cout << "Falha ao abrir o arquivo." << endl;
        abort();
    }

    while(getline(file,line)){
        if(count != 3){
            if(count == 0){
                nome = line;
                count++;
            }
            else if(count == 1){
                cpf = line;
                count++;
            }
            else{
                endereco = line;
                count = 0;
                base.push_back(criar_pessoa(nome,cpf,endereco));
            }
        }
    }

    file.close();

    // LEITURA DOS COMANDOS

    while(getline(cin, line)){
        if(line.compare("inserir_pessoa") == 0){
            getline(cin,cpf);
            cin.ignore();
            getline(cin,endereco);
            cin.ignore();
            getline(cin,nome);
            Pessoa *p = new Pessoa;
            p = criar_pessoa(nome,cpf,endereco);
            inserir_pessoa(base,p);
            cout << "cpf " << cpf << " inserido!\n";  
        }
        else if (line.compare("remover_pessoa") == 0){
            cin.ignore();
            getline(cin,cpf);
            Pessoa *p = new Pessoa;
            p = remover_pessoa(base,cpf);
            cout << "Pessoa " << p->nome << " removida!";
        }
        else if (line.compare("procurar_nome") == 0) {
            cin.ignore();
            getline(cin,nome);
            cout << "Pessoas:\n";
            if(procurar_nome(base,nome).empty()){
                cout << "Nenhuma";
            } else{
                for(auto i:procurar_nome(base,nome)){
                    cout << i->nome << ", cpf: " << i->cpf << endl;
                }
            }
        }
        else if(line.compare("procurar_cpf") == 0){
            cin >> cpf; 
            Pessoa *p = new Pessoa;
    
            p = procurar_cpf(base,cpf);
            if(p != nullptr){
                cout << "encontrada!\n";
                cout << p->cpf << "\n" << p->endereco << "\n" << p->nome;
            }
            else{
                cout << "Nenhuma pessoa encontrada com o cpf " << cpf;
            }
        }
        else if(line.compare("criar_pessoa") == 0){
            cin.ignore();
            getline(cin,nome);
            cin.ignore();
            getline(cin,cpf);
            cin.ignore();
            getline(cin,endereco);
            // criar_pessoa(nome,cpf,endereco);
            cout << criar_pessoa(nome,cpf,endereco);
        }
    }

    return EXIT_SUCCESS;
}