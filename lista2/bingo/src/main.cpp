#include <iostream>
#include "BingoRand.hpp"
#include "Player.hpp"
using namespace std;

int main(){
    unsigned long seed;
    int number_players, drawn, count = 0;
    vector<Player*> players, winners;
    vector<int> drawn_numbers;
    string name;
    bool game_over = false, scored = false, contains = false;

    cin >> seed;
    cin >> number_players;

    BingoRand* bingoRand = new BingoRand();

    bingoRand->setSeed(seed);
    cin.ignore();
    for(int i=0; i<number_players; i++){
        getline(cin,name);
        Player* player = new Player(name,bingoRand->getNDifferent(1,99,24));
        players.push_back(player);
    }

    for(auto *p : players){
        cout << "Jogador " << p->getName() << endl;
        cout << "Cartela: [";
        for(unsigned int i = 0; i<24; i++){
            if(i < 23)
                cout << p->getCard()[i] << ", ";
            else
                cout << p->getCard()[i] << "]\n";
        }
    }

    while(true){
        scored = false;
        count = 0;
        contains = false;

        drawn = bingoRand->rand();

        for(auto d : drawn_numbers){
            if(drawn == d){
                contains = true; 
                break;
            }
        }

        if(!contains){
            drawn_numbers.push_back(drawn);
            cout << "Bola sorteada foi: " << drawn << endl;

            for(auto *p : players){
                for(unsigned int i=0; i<24; i++){
                    if(drawn == p->getCard()[i]){
                        scored = true;
                        break;
                    }
                }
        
                if(scored){
                    cout << "Jogador: " << p->getName() << " marcou!" << endl;
                }

                scored = false;
            }
            
            for(auto *p : players){
                if(drawn_numbers.size() >= 24){
                    for(unsigned int i=0; i<drawn_numbers.size(); i++){
                        for(unsigned int j=0; j<24; j++){
                            if(drawn_numbers[i] == p->getCard()[j]){
                                count++;
                            }
                        }
                    }
                    if(count == 24){
                        game_over = true;
                        cout << "Jogador: " << p->getName() << " Bingo!!" << endl;
                        winners.push_back(p);
                    }
                }
                count = 0;
            }

            if(game_over){
                break;
            }
        }
    }

    cout << "Foram sorteados " << drawn_numbers.size() << " números:" << endl;

    for(unsigned int i=0; i<drawn_numbers.size(); i++){
        if(i < drawn_numbers.size() - 1)
            cout << drawn_numbers[i] << ", ";
        else
            cout << drawn_numbers[i];
    }

    cout << "\nVencedores" << endl;
    
    for(auto *p : winners){
        cout << p->getName() << endl;
    }

    for(auto *p : players){
        delete p;
    }

    delete bingoRand;

    return 0;
}