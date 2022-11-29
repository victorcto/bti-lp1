# Bingo (de Palavras)!

O jogo de bingo consiste num globo contendo um conjunto de bolas numeradas de 1 à 99, sorteadas uma a uma. Os jogadores recebem uma quantidade de números
fixa em uma "Cartela" e devem marcar os números que foram sorteados. O jogo termina quando um jogador completa uma cartela inteira.

Nesta questão você fará um simulador simples de bingo, o simulador deve receber do usuário incialmente o _seed_ do jogo(um número _long_) e a quantidade e os nomes dos jogadores. O Simulador deve então imprimir as cartelas de cada jogador com **24 números diferentes** cada, e realizar a simulação do jogo: 

1. A cada rodada um número número/bola é sorteada
2. A simulação deve primir quais jogadores marcaram alguma coisa em sua cartela (na ordem que foram fornecidos ao jogo no inicio)
3. O simulador repete 1 e 2 até até que algum jogador(es) termine o jogo completando sua cartela, neste caso o simulador imprime o(s) vencedor(es).

O _seed_ do jogo é um conceito chave nesta questão, junto com a função srand o seed fornece um conjunto de números aleatórios "previsíveis", ou seja
se você usar o mesmo gerador de números aleatórios que eu usarei na solução, os números sorteados no jogo serão os mesmos! Para garantir que vocês usarão
os mesmos conjuntos de números aleatórios que eu, usem os métodos do BingoRand.hpp para configurar o seed e toda vez que um número aleatório for necessário!

Nesta atividade você deverá tentar usar classes e objetos para modelar o problema, veja que o problema se resume a praticamente 4 passos:

1. Configurar a seed, os jogadores e suas cartelas
2. Realizar o sorteio e verificar os numeros marcados pelos jogadores
3. Se ninguém venceu: Imprimir o sorteio atual e quais jogadores marcaram alguma coisa
4. Se alguém venceu: Imprimir o(s) vencedor(es)

Use a lógica com base nas entradas e saídas bem como na descrição do problema para escolher quais classes e métodos você vai implementar, veja que as entradas e saídas que você vai obter não devem ser diferentes das que são testadas aqui! No entanto, dependendo da implementação pode ser que os números sejam 
um pouco diferentes. Apenas tenha certeza de que você está com a seed correta e que está usando os métodos da classe BingoRand!

## Exemplos de Entrada/Saída

Como dito antes a entrada do jogo é composta pelo seed e pelos jogadores no formato:
```
13256364241414176048
4
Larissa Isabel Stella Drumond
Raquel Ana Marli Moreira
Fátima Bianca Fernanda da Conceição
Larissa Regina Campos
```

Veja que o seed é um número bem grande, atente para verificar se seu programa está conseguindo lê-lo corretamente.

A saída é um conjunto de textos mostrando a simulação, iniciando pelos nomes dos jogadores e suas cartelas; seguido pela simulação do jogo:

```c++
Jogador Larissa Isabel Stella Drumond
Cartela: [37, 9, 94, 55, 82, 52, 92, 86, 84, 12, 97, 4, 29, 38, 1, 96, 93, 95, 53, 35, 36, 26, 8, 58]
Jogador Raquel Ana Marli Moreira
Cartela: [43, 66, 82, 9, 41, 88, 78, 26, 29, 40, 12, 76, 98, 33, 57, 15, 2, 21, 38, 51, 18, 80, 85, 13]
Jogador Fátima Bianca Fernanda da Conceição
Cartela: [57, 28, 37, 5, 10, 98, 50, 38, 74, 45, 88, 12, 35, 2, 93, 53, 32, 14, 34, 3, 60, 20, 52, 55]
Jogador Larissa Regina Campos
Cartela: [40, 19, 13, 25, 28, 47, 91, 7, 46, 2, 56, 41, 48, 90, 69, 30, 16, 65, 70, 99, 92, 62, 15, 17]
Bola sorteada foi: 25
Jogador: Larissa Regina Campos marcou!
Bola sorteada foi: 19
Jogador: Larissa Regina Campos marcou!
//... //similar para todas as jogadas até que
Bola sorteada foi: 55
Jogador: Larissa Isabel Stella Drumond Bingo!!
Jogador: Fátima Bianca Fernanda da Conceição marcou!
Foram sorteados 90 números:
25, 19, 14, 37, 91, 72, 2, 28, 83, 21, 73, 76, 99, 26, 60, 92, 12, 62, 6, 34, 81, 24, 36, 78, 97, 75, 18, 46, 39, 65, 54, 44, 50, 32, 68, 33, 4, 86, 43, 41, 88, 56, 40, 27, 1, 38, 17, 20, 15, 23, 87, 45, 77, 95, 69, 8, 16, 48, 49, 96, 57, 93, 79, 84, 35, 51, 90, 22, 80, 29, 53, 59, 47, 71, 61, 94, 7, 58, 82, 31, 3, 89, 66, 63, 9, 52, 98, 70, 13, 55
Vencedores
Larissa Isabel Stella Drumond
```

## Executando os testes

Nesta questão para executar os testes você precisa fazer os seguintes comandos, no terminal, a partir do diretório onde este README está:

```
mkdir build
cd build
cmake ..
cmake --build . --target verify
```

Ou caso queira rodar seus próprios testes:

```
mkdir build
cd build
cmake ..
cmake --build . --target program
```

## Importante

1. Atente que, nesta questão, você precisa documentar os .h seguindo o formato doxygen apresentado na questão [casa_e_rua](../casa_e_rua)
2. Lembre de adicionar os .cpp das classes que você tenha criado no [CMakeLists.txt](./CMakeLists.txt)