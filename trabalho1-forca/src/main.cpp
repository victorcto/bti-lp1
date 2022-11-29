#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include "view.hpp"
#include "hangman.hpp"
using namespace std;

int main(int argc, char *argv[]){
    string command, options, name;
    char menu, guess = '\0', play_again = 's';
    pair<bool, bool> guesses;
    bool error = false, win;
    vector<pair<vector<string>,string>> words_players;
    vector<pair<int,int>> scores_dl;
    vector<string> right_words;
    int save_scores = 0;

    Hangman hangman(argv[1], argv[2]);
    hangman.load_files();
    auto valid = hangman.validate_file();

    if(!valid.first){
        cout<<"\033[1;31m Erro: \033[0m"<< valid.second <<endl;
        exit(-1);
    }

    while(true){
        command = "Escolha uma das opções:";
        options = "[1] Iniciar o jogo\n[2] Ver os scores anteriores\n\n[0] Sair\n[c] Clear";
        header_and_or_menu(command,options);
        cout << "\033[32m"; cin >> menu; cout << "\033[0m";

        if(menu == '1'){

            hangman.clear_words();

            while(menu != '0'){
                command = "Qual nível de dificuldade que você deseja jogar?";
                options = "[1] Fácil\n[2] Médio\n[3] Difícil\n\n[0] Voltar ao menu iniciar";
                header_and_or_menu(command,options);
                cout << "\033[32m"; cin >> menu; cout << "\033[0m";

                if(menu == '1' || menu == '2' || menu == '3'){
                    
                    play_again = 's';
                    hangman.set_scores(0);

                    while(true){
                        if(menu == '1'){
                            while(play_again == 's'){
                                if(error == false){           
                                    int round_number = 0;
                                    int number_attempts = 0;
                                    hangman.clear_guess_list();
                                    hangman.clear_revelead_letter();

                                    if(round_number == 0){
                                        loading_msg("Prepare-se o jogo vai começar...");
                                        hangman.config_difficulty_level(Hangman::EASY);
                                        header_and_or_menu("\a\033[0m\033[1m\033[32mBoa sorte!\033[0m","");
                                    }

                                    hangman.next_word(hangman.get_words(),round_number,Hangman::EASY);
                                    
                                    
                                    while(play_again != 'n'){
                                        if(error == false) {
                                            win = true;

                                            board("Fácil",hangman.get_scores(),hangman.get_guess_list());
                                            game_body();

                                            cout << hangman.get_current_word_formatted() << endl;                            
                                            cout << endl << "► ";
                                            cout << "\033[32m"; cin >> guess; cout << "\033[0m";
                                    
                                            if(guess >= 'a' && guess <= 'z')
                                                guess = char(guess-32);

                                            hangman.set_guess_list(guess);
                                            guesses = hangman.guesses(guess);

                                            if(guesses.first && guesses.second){
                                                for(char rl : hangman.get_revealed_letter()){
                                                    if(guess == rl)
                                                        hangman.set_scores(hangman.get_scores()-1);
                                                    }
                                                result_msg(true,true,guess);
                                            } else if(!guesses.first && guesses.second) {
                                                number_attempts++;
                                                hangman.set_scores(hangman.get_scores()-1);
                                                result_msg(false,true,guess);
                                            } else if(guesses.first && !guesses.second) {
                                                result_msg(true,false,guess);
                                            } else if(!guesses.first && !guesses.second) {
                                                result_msg(false,false,guess);
                                            }
                                    
                                            hangman_view(number_attempts);

                                            if(number_attempts == 6){
                                                cout << "\033[45mQue pena, acabaram suas tentativas. :(\033[0m" << endl;
                                                loading_msg("A palavra era " + hangman.get_current_word());
                                                save_scores = hangman.get_scores();
                                                play_again = 'n';
                                                break;
                                            }

                                            for(char c: hangman.get_current_word_formatted()){
                                                if(c == '_'){
                                                    win = false;
                                                    break;
                                                }
                                            }
                                        }  
                                        if(win == true){
                                            if(error == false){
                                                right_words.push_back(hangman.get_current_word());
                                                cout << "\n\033[45mPARABÉNS, Você venceu :)\033[0m" << endl;
                                            }
                                        
                                            command = "Deseja jogar novamente?";
                                            options = "[s] Sim\n[n] Não";
                                            header_and_or_menu(command,options);
                                            cout << "\033[32m"; cin >> play_again; cout << "\033[0m";
                                        
                                            if(play_again == 's'){
                                                round_number++;
                                                error = false;
                                                break;
                                            } else if (play_again == 'n'){
                                                save_scores = hangman.get_scores();
                                                hangman.set_scores(0);
                                                error = false;
                                                break;
                                            } else{
                                                cout << "\n\033[41mOpção inválida, por favor escolha alguma opção válida.\033[0m" << endl;
                                                error = true;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        }

                        if(menu == '2'){
                            while(play_again == 's'){
                                if(error == false){    
                                    int round_number = 0;
                                    int number_attempts = 0;
                                    hangman.clear_guess_list();
                                    hangman.clear_revelead_letter();   

                                    if(round_number == 0){
                                        loading_msg("Prepare-se o jogo vai começar...");
                                        hangman.config_difficulty_level(Hangman::MEDIUM);
                                        header_and_or_menu("\a\033[0m\033[1m\033[32mBoa sorte!\033[0m","");
                                    }

                                    hangman.next_word(hangman.get_words(),round_number,Hangman::MEDIUM);
                                    while(play_again != 'n'){
                                        if(error == false) {
                                            win = true;
                                    
                                            board("Médio",hangman.get_scores(),hangman.get_guess_list()); 
                                            game_body();
                                    
                                            cout << hangman.get_current_word_formatted() << endl;                            
                                            cout << endl << "► ";
                                            cout << "\033[32m"; cin >> guess; cout << "\033[0m";

                                            if(guess >= 'a' && guess <= 'z')
                                                guess = char(guess-32);

                                            hangman.set_guess_list(guess);
                                            guesses = hangman.guesses(guess);

                                            if(guesses.first && guesses.second){
                                                if(guess == hangman.get_revealed_letter()[0])
                                                    hangman.set_scores(hangman.get_scores()-1);
                                                result_msg(true,true,guess);
                                            } else if(!guesses.first && guesses.second) {
                                                number_attempts++;
                                                hangman.set_scores(hangman.get_scores()-1);
                                                result_msg(false,true,guess);
                                            } else if(guesses.first && !guesses.second) {
                                                result_msg(true,false,guess);
                                            } else if(!guesses.first && !guesses.second) {
                                                result_msg(false,false,guess);
                                            }
                                    
                                            hangman_view(number_attempts);
                                    
                                            if(number_attempts == 6){
                                                cout << "\033[45mQue pena, acabaram suas tentativas. :(\033[0m" << endl;
                                                loading_msg("A palavra era " + hangman.get_current_word());
                                                save_scores = hangman.get_scores();
                                                play_again = 'n';
                                                break;
                                            }

                                            for(char c: hangman.get_current_word_formatted()){
                                                if(c == '_'){
                                                    win = false;
                                                    break;
                                                }
                                            }
                                        }
                                        if(win == true){
                                            if(error == false){
                                                right_words.push_back(hangman.get_current_word());
                                                cout << "\n\033[45mPARABÉNS, Você venceu :)\033[0m" << endl;
                                            }
                                            
                                            command = "Deseja jogar novamente?";
                                            options = "[s] Sim\n[n] Não";
                                            header_and_or_menu(command,options);
                                            cout << "\033[32m"; cin >> play_again; cout << "\033[0m";
                                            
                                            if(play_again == 's'){
                                                round_number++;
                                                error = false;
                                                break;
                                            } else if (play_again == 'n'){
                                                save_scores = hangman.get_scores();
                                                hangman.set_scores(0);
                                                error = false;
                                                break;
                                            } else{
                                                cout << "\n\033[41mOpção inválida, por favor escolha alguma opção válida.\033[0m" << endl;
                                                error = true;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        }
                        if(menu == '3') {
                            while(play_again == 's'){
                                if(error == false){
                                    hangman.clear_guess_list();
                                    int round_number = 0;
                                    int number_attempts = 0;       
                                    loading_msg("Prepare-se o jogo vai começar...");

                                    if(round_number == 0){
                                        hangman.config_difficulty_level(Hangman::HARD);
                                        header_and_or_menu("\a\033[0m\033[1m\033[32mBoa sorte!\033[0m","");
                                    }
        
                                    hangman.next_word(hangman.get_words(),round_number,Hangman::HARD);

                                    while(play_again != 'n'){
                                        if(error == false) {
                                            win = true;

                                            board("Difícil",hangman.get_scores(),hangman.get_guess_list());
                                            game_body();

                                            cout << hangman.get_current_word_formatted() << endl;                            
                                            cout << endl << "► ";
                                            cout << "\033[32m"; cin >> guess; cout << "\033[0m";

                                            if(guess >= 'a' && guess <= 'z')
                                                guess = char(guess-32);

                                            hangman.set_guess_list(guess);
                                            guesses = hangman.guesses(guess);

                                            if(guesses.first && guesses.second){
                                                result_msg(true,true,guess);
                                            } else if(!guesses.first && guesses.second) {
                                                number_attempts++;
                                                hangman.set_scores(hangman.get_scores()-1);
                                                result_msg(false,true,guess);
                                            } else if(guesses.first && !guesses.second) {
                                                result_msg(true,false,guess);
                                            } else if(!guesses.first && !guesses.second) {
                                                result_msg(false,false,guess);
                                            }
                                        
                                            hangman_view(number_attempts);

                                            if(number_attempts == 6){
                                                cout << "\033[45mQue pena, acabaram suas tentativas. :(\033[0m" << endl;
                                                loading_msg("A palavra era " + hangman.get_current_word());
                                                save_scores = hangman.get_scores();
                                                play_again = 'n';
                                                break;
                                            }

                                            for(char c: hangman.get_current_word_formatted()){
                                                if(c == '_'){
                                                    win = false;
                                                    break;
                                                }
                                            }
                                        }

                                        if(win == true){
                                            if(error == false){
                                                right_words.push_back(hangman.get_current_word());
                                                cout << "\n\033[45mPARABÉNS, Você venceu :)\033[0m" << endl;
                                            }
                                            
                                            command = "Deseja jogar novamente?";
                                            options = "[s] Sim\n[n] Não";
                                            header_and_or_menu(command,options);
                                            cout << "\033[32m"; cin >> play_again; cout << "\033[0m";

                                            if(play_again == 's'){
                                                round_number++;
                                                error = false;
                                                break;
                                            } else if (play_again == 'n'){
                                                save_scores = hangman.get_scores();
                                                hangman.set_scores(0);
                                                error = false;
                                                break;
                                            } else{
                                                cout << "\n\033[41mOpção inválida, por favor escolha alguma opção válida.\033[0m" << endl;
                                                error = true;
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        }
                    }

                    command = "Qual é seu nome?";
                    header_and_or_menu(command,"");
                    cin.ignore();
                    cout << "\n►\033[32m "; getline(cin,name); cout << "\033[0m";
                    words_players.push_back(make_pair(right_words,name));
                    scores_dl.push_back(make_pair(hangman.difficulty,save_scores));
                    right_words.clear();
                    break;

                } else if(menu == '0'){
                    break;
                } else{
                    cout << "\n\033[41mOpção inválida, por favor escolha alguma opção válida.\033[0m" << endl;
                }
            }
        }
        else if(menu == '2'){
            loading_msg("Carregando as informações...");
            sleep(1);
            cout << endl;
            hangman.import_scores(words_players,scores_dl);
            cout << endl;
        }
        else if(menu == '0'){
            loading_msg("Saindo do jogo...");
            cout << "\033[45mAté a próxima!\033[0m" << endl;
            break;
        }
        else if(menu == 'c'){
            system("clear");
        } else{
            cout << "\n\033[41mOpção inválida, por favor escolha alguma opção válida.\033[0m" << endl;
        }
    }
    
    return 0;
}