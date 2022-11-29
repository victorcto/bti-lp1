# Matrizes com Classe

Usar structs para modelar classes é praticamente um *must do* quando aprendemos structs em C. As matrizes tem importancia
crucial na matemática em vários campos, infelizmente, C++ também não tem estruturas padrão pré prontas que implementam operações matemáticas
em matrizes, mas nada que não seja possível de fazer, especialmente usando classes e objetos.

Neste problema você terá que modelar os elementos com base no que achar que deve ser necessário para os objetos, com base nas
entradas e saídas, use a lógica para estimar o que você precisa em termos de classes e métodos e como será a implementação do main.

No entanto, para que não fique tão aberto o problema, atente para os seguintes pontos:
- Não use atributos públicos!
- Não receba containers ou objetos por cópia nos métodos!
- Não retorne containers nos métodos! (mas fique à vontade para retornar outros objetos, mesmo que eles contenham containers, nesse caso tente retornar referencias.)

Seu programa deverá receber uma quantidade não determinada de matrizes bem como as operações que devem ser realizadas
e exibir, ao fim da execução o resultado da operação ou um erro caso a operação não possa ser realizada. As operações a
ser realizadas são: adição (add), multiplicação matricial (dot), multiplicação elemento à elemento (mul), ou multiplicação
por escalar (mue). **Não existe precedencia entre esses operadores**, execute as operações na ordem que aparecem na entrada!

A entrada é composta por um nome junto dos tamanhos da matriz inicial, seguida por seus elementos, seguida por uma operação
seguida por seus operandos. Não precisa considerar o caso em que existem erros nas entradas, ou seja, os valores das entradas
sempre são bem formatados na forma como mostram os exemplos:

## Exemplo 1
**Exemplo de entrada**
```
A 2 2
1 1
1 2
add
B 2 2
2 2
2 2
```
**Saída esperada:**
```
Resultado A add B
3 3
3 4
```
## Exemplo 2
**Exemplo de entrada**
```
M1 2 2
1 1
1 2
mue 3
dot
M3 2 1
1
0
mul
M4 2 1
1
2
```
**Saída esperada:**
```
Resultado M1 mue 3 dot M3 mul M4
3
6
```
**Obeserve**: veja que `mue` recebe apenas do valor do escalar na linha seguinte!

## Exemplo 3
**Exemplo de entrada**
```
M1 2 2
1 1
1 2
mue 3
dot
M3 3 3
1 2 1
0 3 2
1 2 1
mul
M4 2 1
1
2
```
**Saída esperada:**
```
Resultado M1 mue 3 dot M3 pôde ser calculado, resultado até aqui:
3 3
3 6
```
**Obeserve:** neste ultimo exemplo veja que quando um resultado não pode ser calculado o texto da operação para na
última operação que deu erro!


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