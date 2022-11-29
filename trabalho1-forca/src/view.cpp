#include <cctype>
#include "view.hpp"
using namespace std;


void header_and_or_menu(string command, string options){
    if(!command.empty()){
        cout << endl << "=================== \033[1mJOGO DA FORCA\033[0m ===================" << endl;
        cout << endl << "\033[33m\033[4m" << command << "\033[0m" << endl;
    }
    if(!options.empty()){
        cout << endl << options << endl;
        cout << endl << "► ";
    }
}

void loading_msg(string msg){
    cout << endl << "-----------------------------------------------------" << endl;
    cout << msg << endl;
    cout << "-----------------------------------------------------" << endl;
}

void board(string level, int points, vector<char> guesses){
    cout << "\n\033[4mNível:\033[0m \033[34m" << level << "\033[0m  ";
    cout << "\033[4mPontos:\033[0m \033[33m" << points << "\033[0m  ";
    cout << "\033[4mPalpites:\033[0m \033[35m ";
    for(auto g:guesses){
        cout << (char) toupper(g) << " ";
    }
    cout << "\033[0m";
}

void result_msg(bool r1, bool r2, char letter){
    if(r1 == true && r2 == true){
        cout << endl <<"\033[1m\033[32mBoa! A palavra contém a letra \'" << (char) toupper(letter) << "\'.\033[0m" << endl;
    } else if(r1 == false && r2 == true) {
        cout << endl << "\033[1m\033[31mPoxa! A palavra não contém a letra \'" << (char) toupper(letter) << "\'.\033[0m" << endl;
    } else if(r1 == true && r2 == false) {
        cout << endl <<"\033[1m\033[33mOps! Você já jogou a letra \'" << (char) toupper(letter) << "\' e acertou.\033[0m" << endl;
    } else if(r1 == false && r2 == false) {
        cout << endl <<"\033[1m\033[33mOps! Você já jogou a letra \'" << (char) toupper(letter) << "\' e errou.\033[0m" << endl;
    }
}   

void game_body(){
    for(int i=0; i<7; i++){
        cout << endl;
    }

}

void hangman_view(int attempt){
    if (attempt == 1){
        std::cout << "O" << std::endl;
    }
    else if (attempt == 2){
        std::cout << "O" << std::endl;
        std::cout << "|" << std::endl;
    }
    else if (attempt == 3){
        std::cout << " O " << std::endl;
        std::cout << "/|" << std::endl;
    }
    else if (attempt == 4){
        std::cout << " O " << std::endl;
        std::cout << "/|\\" << std::endl;
    }
    else if (attempt == 5){
        std::cout << " O " << std::endl;
        std::cout << "/|\\" << std::endl;
        std::cout << "/" << std::endl;
    }
    else if (attempt == 6){
        std::cout << " O " << std::endl;
        std::cout << "/|\\" << std::endl;
        std::cout << "/ \\" << std::endl;
    }
}