#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <vector>

void header_and_or_menu(std::string command, std::string options);
void board(std::string level, int points, std::vector<char> guesses);
void loading_msg(std::string msg);
void result_msg(bool r1, bool r2, char letter);
void game_body();
void hangman_view(int attempt);