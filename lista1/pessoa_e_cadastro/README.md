# Pessoa e Cadastros

Um exemplo simples do uso de structs pode ser representado por uma aplicação com Pessoas e Cadastros. 
O ato de cadastrar pessoas em base de dados e realizar ações de consultas e manipulações neste cadastro são boas
práticas de modelagem de dados que podem usar structs e outras construções.

Neste exercício você irá modelar uma struct para armazenar três dados relativos a uma pessoa, seu endereço(string),
seu nome (string) e seu cpf (string). Usando a struct que você modelou você deve carregar
a base de dados contida no arquivo [./data/CadastroUnico.txt](./data/CadastroUnico.txt). 

Use o vector, disponível no arquivo [./include/database.hpp](./include/database.hpp) e preencha-o com as
informações contidas na base. Você deve ter notado que o container que você precisa usar, usa **referencias** para
a struct pessoa ao invés de usar cópias. Em C e C++ (bem como qualquer outra linguagem), é boa prática usar referencias
em qualquer tipo de dado que não seja um tipo básico, assim, ao invés de armazenar cópias, armazenaremos referencias para
a struct pessoa.

Para criar uma nova instancia da struct pessoa, C++ usa o operador **new**, que substitui a função _malloc_ de C.
O operador new cria uma nova instancia de um tipo de dados na _heap_ e retornando uma referencia para essa região da memória. 
De forma similar à C, quando não precisamos mais daquela memória alocada, devemos liberar o espaço na _heap_ usando o operador **delete**.

Após carregar a base de dados seu programa deverá realizar as seguintes funções: 

1. criar_pessoa: recebe os dados de uma pessoa como parâmetro e retorna uma referencia para nova instancia da struct pessoa
2. procurar_cpf: recebe a base de dados criada e um cpf, retorna **uma referência** para a pessoa buscada caso exista ou **nullptr**
caso não seja encontrado.
3. inserir_pessoa: recebe a base de dados criada e uma **referencia** para uma instancia da struct pessoa, retorna false se o cpf já existir na base e não insere
a pessoa, retorna true caso contrário e insere a pessoa na base.
4. procurar_nome: recebe a base de dados criada e um nome, retorna um vetor contendo todas as instancias da struct pessoa
que tenham o nome recebido. Caso o nome não exista na base, retorna um vetor vazio.
5. remover_pessoa: recebe a base de dados criada e um cpf, retorna false se o cpf não existir na base e não realiza qualquer operação,
retorna true caso contrário e remove/deleta a instância da struct pessoa da base dedados/programa.

Além de implementar as funções, implemente um programa que carrega a base de dados contida em [./data/CadastroUnico.txt](./data/CadastroUnico.txt) e depois
lê uma quantidade não definida de comandos como os que estão listados na dabela que segue. De forma similar à questão [intervalos](../intervalos/), 
voce deve usar a leitura de dados em um loop, porém, como neste caso temos textos com espaços em branco, ao invés de usar cin, 
use o comando getline como no exemplo abaixo:

```c++
std::string line;
while( std::getline(std::cin, line) ) {
  // faz alguma coisa com "line"
}
```

### Tabela com exemplos de entrada / saída

<table>
  <tr>
    <th>Entrada</th> <th>Saída</th>
  </tr>
  <tr>
    <td>
<pre>
procurar_cpf
204.075.312-54
</pre>
    </td>
    <td>
<pre>
encontrada!
204.075.312-54
Quadra J1, 677, Primavera
Eliane Sophie Cavalcanti
</pre>
    </td>
  </tr>
    <tr>
    <td>
<pre>
procurar_cpf
121.131.312-54
</pre>
    </td>
    <td>
<pre>
Nenhuma pessoa encontrada com o cpf 121.131.312-54!
</pre>
    </td>
  </tr>
    <tr>
    <td>
<pre>
inserir_pessoa
204.075.312-54
Quadra J1, 677, Primavera
Eliane Sophie Cavalcanti
</pre>
    </td>
    <td>
<pre>
cpf 204.075.312-54 já existe no banco!
</pre>
    </td>
  </tr>
  <tr>
    <td>
<pre>
inserir_pessoa
204.075.312-35
Quadra J1, 677, Primavera
Eliane Sophie Cavalcanti
</pre>
    </td>
    <td>
<pre>
cpf 204.075.312-35 inserido!
</pre>
    </td>
  </tr>
  <tr>
    <td>
<pre>
remover_pessoa
204.075.312-54
</pre>
    </td>
    <td>
<pre>
Pessoa Eliane Sophie Cavalcanti removida!
</pre>
    </td>
  </tr>
  <tr>
    <td>
<pre>
remover_pessoa
204.075.312-17
</pre>
    </td>
    <td>
<pre>
Pessoa com cpf 204.075.312-17 não econtrada!
</pre>
    </td>
  </tr>
  <tr>
    <td>
<pre>
procurar_nome
Eliane Sophie Cavalcanti
</pre>
    </td>
    <td>
<pre>
Pessoas:
Eliane Sophie Cavalcanti, cpf: 234.471.164-39
Eliane Sophie Cavalcanti, cpf: 675.877.892-43
</pre>
    </td>
  </tr>
  <tr>
    <td>
<pre>
procurar_nome
João Batista de Deus
</pre>
    </td>
    <td>
<pre>
Pessoas:
Nenhuma
</pre>
    </td>
  </tr>
</table>

Ao fim do programa, lembre de deletar todos os elementos ainda restantes na base de dados!

## Conhecimentos Necessários

Uso de vector e iterators(opcional), uso de structs, uso de referencias, alocação dinamica (new e delete), uso de getline, uso de streams ifstream para leitura de arquivos.

## Executando os testes

Esta questão usa os dois tipo de teste :dizzy_face:! Para executar os testes das funções use:

```
mkdir build
cd build
cmake ..
cmake --build . --target run_tests
```

Para executar os testes de entrada/saída use:

```
mkdir build
cd build
cmake ..
cmake --build . --target verify
```

Por fim, para executar seus próprios testes faça:

```
mkdir build
cd build
cmake ..
cmake --build .
./program
```
