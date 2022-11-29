# Histograma

Um histograma é uma representação de um conjunto de dados C, onde não há elementos repetidos e cada
elemento é representado através de seu valor e a quantidade de vezes que se repete em C. 
Os histogramas são particularmente úteis para visualizar a dispersão no conjunto de dados, o que
os torna bastante úteis em uma série de aplicações.

Para qualquer conjunto de números inteiros o cálculo do histograma, é feito por um algoritmo
relativamente simples, que conta quantas vezes um determinado valor se repete no conjunto
e retorna um vetor de __pares__, contendo o elemento do histograma e sua quantidade de repetições,
como no exemplo abaixo:

Entrada: `[1 2 3 4 5 1 1 2 1 2]`
Histograma: `[(1, 4), (2, 3), (3, 1), (4, 1), (5, 1)]`

Para valores numéricos é relativamente simples implementar um programa ou função que calcula o histograma,
usando o algoritmo citado. No nosso caso, sua função deve suportar ao menos 6 tipos diferentes: `char, string,
int, double, float, bool`, a função (ou funções) deve calcular e retornar um vetor de pares contendo o histograma
ordenado de acordo com o valor do conjunto, ou seja, os valores menores do conjunto vem primeiro no histograma ex:

Entrada: `[c b a f x z a f b y]`
Histograma: `[(a, 2), (b, 2), (c, 1), (f, 2), (x, 1), (y, 1), (z, 1)]`

Assim, neste problema você deve escrever uma função que recebe como argumento um vetor com um conjunto de dados
e calcula e retorna seu histograma no formato especificado à cima.

__Dica:__ Nesta questão você pode resolver basicamente de duas formas, uma delas usa funções template
outra usa funções sobrecarregadas, use a forma que for mais confortável para você, mas aproveite para explorar e entender
os conceitos.

## Conhecimentos necessários

Utilização de funções, reutilização de código, uso de std::pair, uso de std::vector, implementação de funções
template ou implementação de funções sobrecarregadas.

## Execução do programa

 Nesta questão, devido a forma como o [src/function.cpp](src/function.cpp) e [include/function.cpp](include/function.cpp) estão, os testes não irão
compilar logo de cara, então você pode começar rodando seus próprios testes antes de tentar rodar os testes oficiais. Sempre fique à vontade
para ver como os testes são executados em [tests/main.cpp](tests/main.cpp). Para executar os testes você precisa fazer os comandos abaixo, 
no terminal, a partir do diretório onde este README está.

```
mkdir build
cd build
cmake ..
cmake --build . --target run_tests
```

Rodando seus próprios testes:

```
mkdir build
cd build
cmake ..
cmake --build . --target program
./program
```