#include "hangman.hpp"
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>

// Implementação do construtor
Hangman::Hangman(std::string words_filename, std::string scores_filename){
    this->words_filename = words_filename;
    this->scores_filename = scores_filename;
}

// Implementação dos getters e setters
std::string Hangman::get_words_filename(){
    return this->words_filename;
}

std::string Hangman::get_scores_filename(){
    return this->scores_filename;
}

std::vector<std::pair<std::string, int>> Hangman::get_words_and_frequency(){
    return this->words_and_frequency;
}

std::vector<std::string> Hangman::get_words(){
    return this->words;
}

void Hangman::clear_words(){
    words.clear();
}

void Hangman::clear_guess_list(){
    guess_list.clear();
}

void Hangman::clear_revelead_letter(){
    revealed_letter.clear();
}

std::string Hangman::get_current_word(){
    return this->current_word;
}

void Hangman::set_current_word(std::string word){
    current_word = word;
}

std::string Hangman::get_current_word_formatted(){
    return this->current_word_formatted;
}

void Hangman::set_current_word_formatted(std::string wordf){
    current_word_formatted = wordf;
}

std::vector<char> Hangman::get_guess_list(){
    return this->guess_list;
}

void Hangman::set_guess_list(char guess){
    guess_list.push_back(guess);
}

int Hangman::get_scores(){
    return this->scores; 
}

void Hangman::set_scores(int new_scores){
    scores = new_scores; 
}

int Hangman::get_n_attempts(){
    return this->n_attempts; 
}

void Hangman::set_n_attempts(int new_n_attempts){
    n_attempts = new_n_attempts;
}

int Hangman::get_remove_points(){
    return this->remove_points;
}

std::vector<char> Hangman::get_revealed_letter(){
    return this->revealed_letter;
}

// Implementação dos métodos
void Hangman::load_files(){
    std::ifstream words_file, scores_file;
    std::string line, world;
    int frequency;

    // Leitura do arquivo de palavras e frequência
    words_file.open(words_filename);

    if(!words_file.is_open()){
        return;
    }

    while(!words_file.eof()){
        getline(words_file,line);
        if(!line.empty()){
            for(int i=0; i<line.size(); i++){
                // Verifica é um espaço ou uma tabulação e se o proximo caracter é um número
                if((line[i] == ' ' || line[i] == 9) && (line[i+1] >= '0' && line[i+1] <= '9')){
                    world = line.substr(0,i);
                    frequency = stoi(line.substr(i+1,line.size()));
                    break;
                }
                // Verifica se é uma palavra seguido de uma quebra de linha (sem frequência)
                else if(((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) && (line[i+1]=='\0')){
                    world = line.substr(0,i+1);
                    frequency = 0;
                    break;
                }
            }
            words_and_frequency.push_back(std::make_pair(world,frequency));
        }
    }

    words_file.close();

    // Leitura do arquivo de scores
    scores_file.open(scores_filename);

    if(!scores_file.is_open()){
        return;
    }

    scores_file.close();
}

std::pair<bool, std::string> Hangman::validate_file(){
    std::ifstream words_file, scores_file;
    std::string line;
    bool error = false;
    int count = 0, count_line = 1;

    words_file.open(words_filename);
    scores_file.open(scores_filename);

    // Verifica a existência dos arquivos
    if(!words_file.is_open() && !scores_file.is_open()){
        return std::make_pair(false,"Os arquivos contendo as palavras e os scores não foram encontrados.");
    }
    if(!words_file.is_open()){
        return std::make_pair(false,"O arquivo contendo as palavras e as frequências não foi encontrado.");
    }
    
    // Valida as palavras
    for(int i=0; i<words_and_frequency.size(); i++){
        for(int j=0; j<words_and_frequency[i].first.size(); j++){
            // Verifica se palavra possui caracteres inválidos
            if(words_and_frequency[i].first[j] < 'A' && (words_and_frequency[i].first[j] != ' ' && words_and_frequency[i].first[j] != '-')){
                error = true;
            }
            else if((words_and_frequency[i].first[j] > 'Z' && words_and_frequency[i].first[j] < 'a') || words_and_frequency[i].first[j] > 'z'){
                error = true;
            }

            if(error){
                std::string msg_error("A palavra \"");
                msg_error += words_and_frequency[i].first;
                msg_error += "\" da linha ";
                msg_error += std::to_string(i+1);
                msg_error += " não é uma palavra válida.";
                
                return std::make_pair(false,msg_error);
            }
        }
        // Verifica se a palavra não possui ou se a frequência é <= 0
        if(words_and_frequency[i].second <= 0){
            std::string msg_error("A palavra \"");
            msg_error += words_and_frequency[i].first;
            msg_error += "\" da linha ";
            msg_error += std::to_string(i+1);
            msg_error += " não é uma palavra válida, pois não possui frequência válida.";

            return std::make_pair(false,msg_error);
        }
        // Verifica se a palavra tem o tamanho menor ou igual a 4
        if(words_and_frequency[i].first.length() <= 4){
            std::string msg_error("A palavra \"");
            msg_error += words_and_frequency[i].first;
            msg_error += "\" da linha ";
            msg_error += std::to_string(i+1);
            msg_error += " não é uma palavra válida, pois possui tamanho menor ou igual a 4.";

            return std::make_pair(false,msg_error);

        }
    }

    if(!scores_file.is_open()){
        return std::make_pair(false,"O arquivo contendo os scores não foi encontrado.");
    }   

    while(!scores_file.eof()){
        getline(scores_file,line);
        std::string str;
        // Verifica se o arquivo tem menos os dois primeiros campos vazios
        for(int i=0; i<line.size(); i++){
            str += line[i];
            if(line[i] == ';'){
                count++;
                str.erase(str.end()-1);
                if((str.empty() || str == " ") && count <= 2){
                    std::string msg_error("O arquivo contendo os scores está com algum campo vazio na linha ");
                    msg_error += std::to_string(count_line);
                    return std::make_pair(false,msg_error);
                }
                str = "";
            }
            // Verifica se o último campo é vazio
            if(count == 3){
                for(int j=i+1; j<line.size(); j++){
                    str += line[j];
                }
                if((str.empty() || str == " " || str == "\0" || str == "\n")){
                    std::string msg_error("O arquivo contendo os scores está com algum campo vazio na linha ");
                    msg_error += std::to_string(count_line);
                    return std::make_pair(false,msg_error);
                }
            }
        }
        // Verifica se tem menos ou mais que 3 ;
        if(count != 3){
            std::string msg_error("O arquivo contendo os scores não está formato corretamente na linha ");
            msg_error += std::to_string(count_line);
            return std::make_pair(false,msg_error);
        }
        count = 0;
        count_line++;
        str = "";
    }
    words_file.close();
    scores_file.close();

    return std::make_pair(true,"");
}

void Hangman::config_difficulty_level(Difficulty_level dl){
    std::srand(unsigned(std::time(0)));
    double sum = 0.0, average;
    std::vector<std::pair<std::string, int>> wf = get_words_and_frequency();
    bool contains = false;
    int value;

    difficulty = dl;

    // Calcula a frequência média das palavras
    for(int i=0; i<wf.size(); i++){
        sum += words_and_frequency[i].second;
    }

    average = sum / wf.size();

    // Gera a aleatoridade das palavras, sem repetir, para cada um dos níveis de dificuldade
    if(dl == EASY){
        while(words.size() != 10){

            value = rand() % wf.size();

            for(std::string word : words){
                if(word == wf[value].first){
                    contains = true;
                    break;
                }
            }

            if(wf[value].second > average && contains == false){
                words.push_back(wf[value].first);
            }

            contains = false;
        }

        std::random_shuffle(words.begin(),words.end());

        for(std::string word:words){
            std::cout << word << std::endl;
        }

    } else if(dl == MEDIUM){
        int count = 0;

        while(words.size() != 20){

            value = rand() % wf.size();

            for(std::string word : words){
                if(word == wf[value].first){
                    contains = true;
                    break;
                }
            }
            
            if(count < 7){
                if(wf[value].second < average && contains == false){
                    words.push_back(wf[value].first);
                    count++;
                }
            }
            else{
                if(wf[value].second >= average && contains == false){
                    words.push_back(wf[value].first);
                    count++;
                }
            }
            contains = false;
        }

        std::random_shuffle(words.begin(),words.end());

        for(std::string w:words){
            std::cout << w << std::endl;
        }
    } else if(dl == HARD){
        int count = 0;

        while(words.size() != 30){

            value = rand() % wf.size();

            for(std::string word : words){
                if(word == wf[value].first){
                    contains = true;
                    break;
                }
            }
            
            if(count < 22){
                if(wf[value].second < average && contains == false){
                    words.push_back(wf[value].first);
                    count++;
                }
            }
            else{
                if(wf[value].second >= average && contains == false){
                    words.push_back(wf[value].first);
                    count++;
                }
            }
            contains = false;
        }

        std::random_shuffle(words.begin(),words.end());

        for(std::string w:words){
            std::cout << w << std::endl;
        }
    }
}

std::pair<bool, bool> Hangman::guesses(char guess){
    std::string c_word = get_current_word();
    std::vector<char> guess_list = get_guess_list();
    bool contains_letter = false, contains_guess = false;
    int count = 0;

    // Verifica se ele já jogou aquela letra
    for(int i=0; i<guess_list.size(); i++){ 
        if(guess_list[i] == guess)
            count++;

        if(count > 1){
            contains_letter = true;
            break;
        }
    }

    // Verifica se o palpite jogado está correto
    for(int i=0; i<c_word.size(); i++){ 
        if(c_word[i] == guess){
            contains_guess = true;
        }
    }

    if(contains_guess && !contains_letter){ // acertou o palpite e o palpite não é repetido
        main_guess(guess,c_word,get_scores());
        return std::make_pair(true,true);
    } else if(!contains_guess && !contains_letter){ // errou o palpite e o palpite não é repetido
        return std::make_pair(false,true);
    } else if(contains_guess && contains_letter){ // acertou o palpite e o palpite é repetido
        return std::make_pair(true,false);
    } else if(!contains_guess && contains_letter){ // errou o palpite e o palpite é repetido
        return std::make_pair(false,false);  
    }

    return std::make_pair(true,true);
}

void Hangman::main_guess(char guess, std::string word, int scores){
    int count = 0, k = 0;
    std::string word_formatted = get_current_word_formatted();

    for(int i=0; i<word.size(); i++){
        if(word[i] == guess && i == (word.size() - 1)){
            scores += 2;
        }
        else if(word[i] == guess){
            scores++;
        }
    }

    for(int i=0; i<word.size(); i++){
        if(word[i] == guess){
            word_formatted[k] = guess;
        }
        k+=2;
    }

    set_scores(scores);
    set_current_word_formatted(word_formatted);
}

void Hangman::next_word(std::vector<std::string> words, int round_number, Difficulty_level dl){
    std::srand(unsigned(std::time(0)));
    char vowel;

    std::for_each(words[round_number].begin(), words[round_number].end(), [](char & c){
        c = ::toupper(c);
    });

    set_current_word(words[round_number]);
    std::string format;

    unsigned int number, count = 0;

    if(dl == EASY)
        number = (rand() % (get_current_word().size() / 5)+1);

    if(dl == MEDIUM){
        char vowels[] = {'A', 'E', 'I', 'O', 'U'};
        vowel = vowels[(rand() % (5 + 1))];

        while (get_current_word().find(vowel,0) == std::string::npos){
            vowel = vowels[(rand() % (5 + 1))];
        }
    }

    for(int i=0; i<get_current_word().size(); i++){
        if(count < number && dl == EASY) {
            if(get_current_word()[i] != 'A' && get_current_word()[i] != 'E' && get_current_word()[i] != 'I' 
            && get_current_word()[i] != 'O' && get_current_word()[i] != 'U' ){
                format.append(1,get_current_word()[i]);
                format.append(" ");
                count++;
                if(get_current_word()[i] >= 'a' && get_current_word()[i] <= 'z')
                    revealed_letter.push_back(char(get_current_word()[i]-32));
                else 
                    revealed_letter.push_back(get_current_word()[i]);
            } else {
                if(get_current_word()[i] == '-')
                    format.append("- ");
                else if(get_current_word()[i] == ' ')
                    format.append("  ");
                else
                    format.append("_ ");
            }
        }
        else if(count < 1 && dl == MEDIUM){
            if(get_current_word()[i] == vowel){
                format.append(1,get_current_word()[i]);
                format.append(" ");
                count++;
                if(get_current_word()[i] >= 'a' && get_current_word()[i] <= 'z')
                    revealed_letter.push_back(char(get_current_word()[i]-32));
                else 
                    revealed_letter.push_back(get_current_word()[i]);
            } else {
                if(get_current_word()[i] == '-')
                    format.append("- ");
                else if(get_current_word()[i] == ' ')
                    format.append("  ");
                else
                    format.append("_ ");
            }
        }
        else{
            if(get_current_word()[i] == '-')
                format.append("- ");
            else if(get_current_word()[i] == ' ')
                format.append("  ");
            else
                format.append("_ ");
        }
    }

    remove_points = count;
    
    set_current_word_formatted(format);
}

void Hangman::import_scores(std::vector<std::pair<std::vector<std::string>,std::string>> words_players, std::vector<std::pair<int,int>> scores_dl){
    export_scores(words_players,scores_dl);
    
    std::string line, aux_names, aux_words;
    std::ifstream is_file;
    is_file.open(scores_filename);
    int max_w_size = 8, max_n_size = 7, tab, count = 0, k = 0, auxcount = 0;
    int pos1, pos2, pos3;

    if(!is_file.is_open())
        return;

    while(!is_file.eof()){
        getline(is_file,line);

        for(int i=0; i<line.size(); i++){
            if(line[i] == ';'){
                count++;
                if(count == 1){
                    pos1 = i;
                }
                else if(count == 2){
                    pos2 = i;
                }
                else{
                    pos3 = i;
                }
            }
        }

        aux_names = line.substr(pos1+2,pos2-pos1-2);
        if(aux_names.size() > max_n_size)
            max_n_size = aux_names.size();

        for(int i=pos2+2; i<=pos3; i++){
            if(line[i] == ',' || line[i] == ';'){
                aux_words = line.substr(pos2+2,k);
                auxcount = i;
                break;
            }
            k++;
        }

        k = 0;

        if(aux_words.size() > max_w_size)
            max_w_size = aux_words.size();

        for(int i=auxcount+2; i<pos3; i++){
            if(line[i] == ','){
                aux_words = line.substr(i-1,k);
                auxcount = i;
            }

            if(aux_words.size() > max_w_size)
                max_w_size = aux_words.size();
            
            k++;
        }

        aux_words = line.substr(auxcount+2,pos3-auxcount-2);

        if(aux_words.size() > max_w_size)
            max_w_size = aux_words.size();

        count = 0;
        auxcount = 0;
        k = 0;
    }
    
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "\033[2mDificuldade\033[0m | ";

    std::cout << "\033[2mJogador\033[0m";
    for(int i=0; i<max_n_size - 5; i++){
        std::cout << " ";
    }
    std:: cout << "| \033[2mPalavras\033[0m";
    if(max_w_size >= 9){
        for(int i=0; i<max_w_size - 6; i++){
            std::cout << " ";
        }
    }
    else{
        for(int i=0; i<max_w_size - 7; i++){
            std::cout << " ";
        }
    
    }

    count = 0, k = 0, auxcount = 0;
    std::cout << "| \033[2mPontos\033[0m\n";
    tab = 14 + max_n_size;
    
    is_file.close();
    is_file.open(scores_filename);

    while(!is_file.eof()){
        getline(is_file,line);

        for(int i=0; i<line.size(); i++){
            if(line[i] == ';'){
                count++;
                if(count == 1){
                    pos1 = i;
                }
                else if(count == 2){
                    pos2 = i;
                }
                else{
                    pos3 = i;
                }
            }
        }

        std::cout << "\033[35m" << line.substr(0,pos1) << "\033[0m ";

        if(line.substr(0,pos1) == "Fácil")
            std::cout << "      |";
        
        else if(line.substr(0,pos1) == "Médio")
            std::cout << "      |";
        
        else
            std::cout << "    |";
    

        if(line.substr(pos1+2,pos2-pos1-2).size() < max_n_size){
            std::cout << "\033[34m " << line.substr(pos1+2,pos2-pos1-2) << "\033[0m";
            for(int j=0; j<max_n_size - line.substr(pos1+2,pos2-pos1-2).size(); j++){
                std::cout << " ";
            }
        }
        else{
            std::cout << "\033[34m " << line.substr(pos1+2,pos2-pos1-2) << "\033[0m";
        }
        std::cout << "  |";

        for(int i=pos2+2; i<=pos3; i++){
            if(line[i] == ',' || line[i] == ';'){
                std::cout << "\033[33m " << line.substr(pos2+2,k) << "\033[0m\n";
                auxcount = i;
                for(int y=0; y<tab; y++){
                    if(y == 12)
                        std::cout << "| ";
                    std::cout << " ";
                }
                std::cout << "| ";
                break;
            }
            
            k++;
        }

        k = 0;

        for(int i=auxcount+2; i<pos3-1; i++){
            if(line[i] == ','){
                std::cout << "\033[33m" << line.substr(auxcount+2,k) << "\033[0m\n";
                for(int y=0; y<tab; y++){
                    if(y == 12)
                        std::cout << "| ";
                    std::cout << " ";
                }
                std::cout << "| ";
                auxcount = i;
            }
            
            k++;
        }


        std::cout << "\033[33m" << line.substr(auxcount+2,pos3-auxcount) << "\033[0m\n";

        std::cout << "|";

        std::cout << "\n-----------------------------------------------------" << std::endl;
        count = 0;
        k = 0;
        auxcount = 0;
    }

    is_file.close();
    
}

void Hangman::print_scores(std::vector<std::pair<std::vector<std::string>,std::string>> words_players, std::vector<std::pair<int,int>> scores_dl){
    export_scores(words_players,scores_dl);
    
    int max_w_size = 8, max_n_size = 7;
    
    for(int i=0; i<words_players.size(); i++){
        if(words_players[i].first.empty()){
            max_w_size = 9;
            break;
        }
    }

    std::string max_word, max_name;
    int tab;

    for(auto wp : words_players){
        for(std::string w : wp.first){
            if(w.size() > max_w_size)
                max_w_size = w.size();
        }
        if(wp.second.size() > max_n_size)
            max_n_size = wp.second.size();
    }
    std::cout << "-----------------------------------------------------" << std::endl;
    std::cout << "\033[2mDificuldade\033[0m | ";
    std::cout << "\033[2mJogador\033[0m";
    for(int i=0; i<max_n_size - 5; i++){
        std::cout << " ";
    }
    std:: cout << "| \033[2mPalavras\033[0m";
    if(max_w_size >= 9){
        for(int i=0; i<max_w_size - 6; i++){
            std::cout << " ";
        }
    }
    else{
        for(int i=0; i<max_w_size - 7; i++){
            std::cout << " ";
        }
    }
    std::cout << "| \033[2mPontos\033[0m\n";

    tab = 14 + max_n_size;
    for(int i=0; i<words_players.size(); i++){
        if(scores_dl[i].first == 1){
            std::cout << "\033[35mFácil       \033[0m| ";
        }

        else if(scores_dl[i].first == 2){
            std::cout << "\033[35mMédio       \033[0m| ";
        }

        else{
            std::cout << "\033[35mDifícil     \033[0m| ";
        }

        if(words_players[i].second.size() < max_n_size){
            std::cout << "\033[34m" << words_players[i].second << "\033[0m";
            for(int j=0; j<max_n_size - words_players[i].second.size(); j++){
                std::cout << " ";
            }
        }
        else{
            std::cout << "\033[34m" << words_players[i].second << "\033[0m";
        }
        std::cout << "  |";

        if(words_players[i].first.size() == 0){
            words_players[i].first.push_back("<nenhuma>");
        }

        for(int j=0; j<words_players[i].first.size(); j++){
            if(j != 0){
                for(int k=0; k<tab; k++){
                    if(k == 12)
                        std::cout << "| ";
                    std::cout << " ";
                }
                std::cout << "| ";
            }
            else{
                std::cout << " ";
            }

            std::cout << "\033[33m" << words_players[i].first[j] << "\033[0m";

            if(words_players[i].first[j].size() <= max_w_size){
                for(int k=0; k<max_w_size - words_players[i].first[j].size() + 2; k++){
                    std::cout << " ";
                }
            }

            std::cout << "|";
            if(j == 0){
                if(scores_dl[i].second <= 0)
                    std::cout << " \033[1m\033[31m" << scores_dl[i].second << "\033[0m";
                else
                    std::cout << " \033[1m\033[32m" << scores_dl[i].second << "\033[0m";
            }

            std::cout << std::endl;
        }
        std::cout << "-----------------------------------------------------" << std::endl;
    }
}

void Hangman::export_scores(std::vector<std::pair<std::vector<std::string>,std::string>> words_players, std::vector<std::pair<int,int>> scores_dl){
    std::ofstream ex;

    ex.open(scores_filename,std::ios::app);

    if(!ex.is_open())
        return;
    
    ex << "\n";
    for(int i=0; i<words_players.size(); i++){
        if(scores_dl[i].first == 1)
            ex << "Fácil; ";

        else if(scores_dl[i].first == 2)
            ex << "Médio; ";

        else
            ex << "Difícil; ";

        ex << words_players[i].second << "; ";

        if(words_players[i].first.size() == 0)
            ex << "; ";
        
        for(int j=0; j<words_players[i].first.size(); j++){
            if(j < words_players[i].first.size() - 1)
                ex << words_players[i].first[j] << ", ";
            else
                ex << words_players[i].first[j] << "; ";
        }

        ex << scores_dl[i].second;
    }

    ex.close();
}