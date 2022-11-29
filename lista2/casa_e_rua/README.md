# Classe Casa e Classe Rua

Classes são normalmente usadas para modelar dados assim como qualquer Registro de linguagens mais baixo nível. Dessa forma é comum
que exemplos básicos sejam compostos de modelagem de dados simples, por isso as dezenas de exemplos da classe Pessoa, Animal, etc.
Uma diferença inicial de classes para Registros é a possibilidade de modelarmos comportamentos que tem a ver com a classe/objeto em
questão e seus próprios atributos internos.

Um tipo interessante, e bastante comum, de objeto são os objetos compostos (ou tipos compostos). Esses objetos são caracterizados
por _agregarem_ outros objetos de outros tipos. Um exemplo simples dessa construção são as classes Casa e Rua:

- A classe Casa contem os seguintes atributos, todos privados:
    - Numero, do tipo inteiro, contendo um número que representa aquela casa
    - Area Construída e Área Total, do tipo double, contendo os valores das áreas do terreno e construída das casas.
    - Ocupada, do tipo booleano, indicando se a casa está ou não ocupada.
- Implemente ainda os seguintes métodos na classe casa:
    - `Casa(double area_construida, double area_total)`: construtor com nome do dono da casa, o número deve ser inicializado com -1, e a casa deve estar
    desocupada.
    - `int getNumero() e void setNumero(int n)`: retorna/modifica o número da casa.
    - `bool isOcupada() e void setOcupada(bool ocupada)`: retorna/modifica o estado da casa.

- A classe Rua contém os seguintes atributos:
    - nome, uma string com o nome da rua
    - CEP, uma string no formato XX-XXX-XXX
    - Dois containers, A container contendo um conjunto de casas e B contendo outro contjunto de casas
- Na classe rua iremos implementar os seguintes métodos:
    - `Rua(std::string nome, std::string cep)`: construtor com o nome e cep da rua
    - `void adiciona_casa(Casa *c, LadoRua l)`: adiciona uma casa no vetor de casas do lado A ou B da rua, dependendo do valor de l. O número da casa deve ser modifiado conforme sua posição no vetor A ou B, casas do lado A só tem numeros pares, começando em 0; as casas do lado B possuem apenas números ímpares, começando em 1.
    - `std::tuple<Casa*, Casa*, Casa*> vizinhos(Casa *c)`: retorna uma tupla contendo os visinhos da casa _c_. Uma casa é considerada
    vizinha ma casa é considerada vizinha da ESQUERDA se ela é anterior à casa c no vetor em que c está adicionada; uma casa pode ser considerada vizinha da DIREITA, se ela é posterior à c neste mesmo vetor. Uma casa tem um terceiro vizinho que é a casa que fica à FRENTE dela no vetor que representa as casas
    do lado oposto à rua, ex: se c estiver do lado A, o visinho da frente está no lado B e tem índice igual ao de c no vetor oposto; Caso
    _c_ não tenha algum vizinho correspondente, apenas retorne nullptr na posição correspondente.
    - `std::tuple<Casa*, Casa*, Casa*> vizinhos(int num)`: similar ao anterior só que usa como referencia o número da casa e não o objeto inteiro.
    - `std::string endereco(int num)`: retorna o endereço da casa de uma pessoa com _nome_ passado. 
    No formato: `Rua <nome>, No. <numero_casa>, Cep: <CEP>`, caso a casa não pertença à rua, retorne uma string vazia.

Veja que neste caso, assim como nos próximos usaremos referencias com o objeto Casa, pelas boas práticas em relação aos tipos em C++, para evitar cópias
usaremos referencias sempre que um tipo não básico for necessário! 



## Usando as funções em um programa

Usando as classes implementadas escreva um programa que lê da entrada padrão, inicialmente o nome da rua e o CEP, seguido por um conjunto
de linhas contendo o lado da casa, a área ocupada e total e o estado, ocupada ou desocupada.

```
Rua do Comércio 126
57-515-970
B
245.85 311.20
desocupada
A
176.74 210.40
ocupada
A
235.20 280.00
ocupada
A
224.20 236.00
ocupada
A
193.80 258.40
ocupada
```

O programa deverá então imprimir o endereço e área de todas as casas que são desocupadas
bem como seus vizinhos (esquerda, direita e frente).

```
Casas Desocupadas
Rua do Comércio 126, 57-515-970, Casa no. 1, Área: 245.85 / 311.20, lado B
Vizinhos
Frente: Rua do Comércio 126, 57-515-970, Casa no. 0, Área: 176.74 / 210.40, lado A (ocupada)
Esquerda: <nenhum>
Direita: <nenhum>
```

Caso não hajam casas de desocupadas a saída será apenas:

```
Casas Desocupadas
<nenhuma>
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

Esta questão mostra exemplos de documentação seguindo o estilo do [Doxygen](https://www.doxygen.nl/manual/docblocks.html), esta ferramenta
é usada junto com programas em C++ e outras linguagens para gerar documentação automaticamente com base em comentários escritos nos arquivos
de código.

Outro ponto é que ambos os headers estão escritos em formatos de nomes diferentes, enquanto [rua.hpp](./include/rua.hpp) usa [snake_case](https://en.wikipedia.org/wiki/Snake_case) Casa.hpp usa [CamelCase](https://en.wikipedia.org/wiki/Camel_case). Ambas as conversões de nomes estão ok para serem usadas com C++, porém
cada base de código tende a usar alguma convenção, tente escolher a que te agradar melhor!
