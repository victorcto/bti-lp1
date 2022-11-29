#include <iostream>
#include <vector>

class Hangman {
    public:
        // Níveis de dificuldade do jogo
        enum Difficulty_level{
            EASY = 1, MEDIUM = 2, HARD = 3
        };
    
    private:
        std::string words_filename; // nome do arquivo com as palavras
        std::string scores_filename; // nome do arquivo com as pontuações
        std::vector<std::pair<std::string, int>> words_and_frequency; // armazena a palavra e a frequência
        std::vector<std::string> words; // Armazena as palavras usada no nível escolhido naquele jogo
        std::string current_word; // Palava atual a ser jogada
        std::string current_word_formatted; // Palava atual a ser jogada no formato do jogo da forca ex.: _ _ _ _
        std::vector<char> guess_list; // Lista de palpites jogada pelo jogador.
        std::vector<char> revealed_letter; // Armazena a letra revelada
        int n_attempts = 0; // Número de tentativas restantes
        int scores = 0; // Pontos do jogador
        int remove_points = 0;

    public:
        Difficulty_level difficulty = Difficulty_level::EASY;

        // Construtor
        Hangman(std::string words_filename, std::string scores_filename);

        // Carrega os arquivos de palavras e pontuações
        void load_files();

        // Valida os arquivos
        std::pair<bool, std::string> validate_file();

        // Definie a dificuldade do jogo
        void config_difficulty_level(Difficulty_level dl);

        // Palpite do jogador
        std::pair<bool, bool> guesses(char guess);

        // Verifica a palavra, exibi e conta os pontos
        void main_guess(char guess, std::string word, int scores);

        // Palavra a ser jogada
        void next_word(std::vector<std::string> words, int round_number, Difficulty_level dl);

        void print_scores(std::vector<std::pair<std::vector<std::string>,std::string>> words_players, std::vector<std::pair<int,int>> scores_dl);

        void import_scores(std::vector<std::pair<std::vector<std::string>,std::string>> words_players, std::vector<std::pair<int,int>> scores_dl);

        void export_scores(std::vector<std::pair<std::vector<std::string>,std::string>> words_players, std::vector<std::pair<int,int>> scores_dl);

        // Getters e setters
        std::string get_words_filename();
        std::string get_scores_filename();
        std::vector<std::pair<std::string, int>> get_words_and_frequency();
        std::vector<std::string> get_words();
        std::string get_current_word();
        void set_current_word(std::string word);
        std::string get_current_word_formatted();
        void set_current_word_formatted(std::string wordf);
        std::vector<char> get_guess_list();
        void set_guess_list(char guess);
        int get_scores();
        void set_scores(int new_scores);
        int get_n_attempts();
        void set_n_attempts(int new_n_attempts);
        int get_remove_points();
        std::vector<char> get_revealed_letter();

        // Clear's
        void clear_words();
        void clear_guess_list();
        void clear_revelead_letter();
};