## linux ou windows + wsl ubuntu apenas
## usuarios do replit a primeira compilação da versão extra pode demorar *um pouco*
## por favor não tentem com mingw ou msvc (compiladores do windows)

cmake_minimum_required(VERSION 3.2)
project(Autocomplete)

#sem ncurses
add_executable(words_complete_correct
               src/main.cpp
               src/Word.cpp
               src/Database.cpp
               src/Interface.cpp
               src/Autocomplete.cpp
               src/Autocorrect.cpp
               src/Test.cpp
              )
              
target_include_directories(words_complete_correct PUBLIC
                           include
                           )

