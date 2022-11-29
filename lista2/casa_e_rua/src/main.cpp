#include <iostream>
#include <string>
#include "Casa.hpp"
#include "Rua.hpp"
using namespace std;
    
int main(){
    string nome, cep, lado, estado, linha;
    double areaConstruida, areaTotal;
    bool info_completa = false;
    int count = 0, i = 0;

    getline(cin,linha);
    nome = linha;
    getline(cin,linha);
    cep = linha;

    Rua *rua = new Rua(nome,cep);

    while(getline(cin >> ws,linha)){
        if(linha == "A" || linha == "B"){
            lado = linha;
        } else if(linha[0] >= '0' && linha[0] <= '9'){
            for(unsigned int i=0; i<linha.size(); i++){
                if(linha[i] == ' '){
                    areaConstruida = std::stod(linha.substr(0,i));
                    areaTotal = std::stod(linha.substr(i+1,linha.size()-1));
                    break;
                }
            }
        } else if(linha == "desocupada" || linha == "ocupada"){
            estado = linha;
            info_completa = true;
        }
        
        if(info_completa){
            Casa *casa = new Casa(areaConstruida,areaTotal);

            if(estado == "ocupada"){
                casa->setOcupada(true);
            } else {
                casa->setOcupada(false);
            }

            if(lado == "A")
                rua->adiciona_casa(casa,rua->LADO_A);
            else if (lado == "B")
                rua->adiciona_casa(casa,rua->LADO_B);
            
            info_completa = false;
            count++;
        }
    }

    tuple<Casa*, Casa*, Casa*> vizinhos;

    cout << "Casas Desocupadas" << endl;
    if(rua->get_desocupadas().empty()){
        cout << "<nenhuma>" << endl;
    } else {
        for(auto *casa : rua->get_desocupadas()){
            cout << rua->endereco(casa->getNumero()) << endl;

            if(i==0){
                cout << "Vizinhos" << endl;
                vizinhos = rua->vizinhos(casa);
            }

            cout << "Frente: ";
            if(get<2>(vizinhos) != 0){
                cout << rua->endereco(get<2>(vizinhos)->getNumero());
                if(get<2>(vizinhos)->isOcupada()){
                    cout << " (ocupada)" << endl;
                } else {
                    cout << " (desocupada)" << endl;
                }
            } else{
                cout << "<nenhum>" << endl;
            }

            cout << "Esquerda: ";
            if(get<0>(vizinhos) != 0){
                cout << rua->endereco(get<0>(vizinhos)->getNumero());
                if(get<0>(vizinhos)->isOcupada()){
                    cout << " (ocupada)" << endl;
                } else {
                    cout << " (desocupada)" << endl;
                }
            } else{
                cout << "<nenhum>" << endl;
            }

            cout << "Direita: ";
            if(get<1>(vizinhos) != 0){
                cout << rua->endereco(get<1>(vizinhos)->getNumero());
                if(get<1>(vizinhos)->isOcupada()){
                    cout << " (ocupada)" << endl;
                } else {
                    cout << " (desocupada)" << endl;
                }
            } else{
                cout << "<nenhum>" << endl;
            }
        }
    }

    for(auto *casa : rua->get_lado_a()){
        delete casa;
    }

    for(auto *casa : rua->get_lado_b()){
        delete casa;
    }
    
    delete rua;

    return EXIT_SUCCESS;
}