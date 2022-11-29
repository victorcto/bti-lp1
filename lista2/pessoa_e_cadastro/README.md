# Pessoa e Cadastros

Outro exemplo clássico da orientação à objetos é o uso de Pessoas e Cadastros. O ato de cadastrar pessoas em base de dados e o fato de que o
objeto pessoa tem seus próprios atributos formam bons exemplos para iniciar os estudos com Orientação à Objetos. Neste exercício temos 2
classes já implementadas Pessoa e Cadastro.

A classe pessoa modela uma Pessoa em termos de seu cpf, nome e endereço, enquato a classe Cadastro apenas _agrega_ pessoas e tem um nome
para identificá-lo. Nesta questão, ao invés de guardar _cópias_ da classe pessoa dentro de instâncias da classe cadastro seguiremos
as boas práticas relacionadas à tipos não básicos e optaremos por guardar referencias através de _raw pointers_. 
Essa construção é especialmente útil neste caso, pois em um cenário com vários cadastros diferentes,
se uma mudança ocorre em um objeto da classe Pessoa em um cadastro qualquer, essa mudança é refletida em todos os demais cadastros.

Um cuidado quando usamos esse método é de que temos que usar new, ou seja alocação dinâmica, quando adicionamos um objeto do tipo
pessoa em algum cadastro. No entanto, para que o comportamento desejado ocorra corretamente é necessário que, 
**para um dado CPF, exista apenas uma instância do objeto pessoa**. Ou seja, uma vez instanciada uma pessoa para um cpf 
especifico, não devem ser mais criadas novas instâncias da classe Pessoa para aquele cpf, ao invés disso, 
**iremos procurar aquele objeto e usar sua referencia**.

Neste exercício você deve escrever um programa que cria inicialmente uma instância da classe Cadastro chamda "Cadastro Único". Depois mais 3
cadastros devem ser criados: Sistema único de Saúde(SUS), Cadastro Estadual(CE), Cadastro Municipal(CM). Você deve inicializar todas as
pessoas que estão no Cadastro Único do a partir da leitura do arquivo [CadastroUnico.txt](./data/CadastroUnico.txt). Depois o programa 
receberá como entrada um conjunto de pares CPFs seguidos pelo cadastro onde aquela pessoa deve ser adicionada como no exemplo abaixo:

```
234.471.164-39 SUS
234.471.164-39 CE
519.017.593-69 CM
519.017.593-69 CE
389.499.808-35 CE
175.659.343-48 CM
175.659.343-48 SUS
894.019.670-83 CM
```

Após ler a entrada, o programa deve exibir os nomes de todas as pessoas em cada um dos cadastros, exceto no cadastro único, usando o exemplo acima, o resultado seria:

```
Sistema único de Saúde
Eliane Sophie Cavalcanti
Ryan Levi Davi Duarte

Cadastro Estadual
Eliane Sophie Cavalcanti
Kamilly Maya Josefa Cardoso
Letícia Liz Rosângela Silva

Cadastro Municipal
Kamilly Maya Josefa Cardoso
Ryan Levi Davi Duarte
Rayssa Andrea da Silva
```

**Obs:** Caso não exista alguém cadastrado em um cadastro específico imprimia `Ninguém Cadastrado` como saída daquele cadastro.

Após a exibição das pessoas em cada cadastro **destrua** os objetos criados de forma que o programa termine sem vazamentos de memória. Para
destruir os objetos você deve usar o operador delete apenas 1 vez por pessoa/CPF. Para fazer isso, você pode adicionar algum método na
classe Cadastro, por exemplo. No entanto, **atente para deletar apenas uma vez por cpf**, caso contrário ocorrerá um segmentation fault!

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

## Sugestão

Para implementar as funcionalidades você pode fazer tudo no main, ou pode modificar a classe Cadastro, no entanto, lembre que o objetivo
desta questão é o uso de alocação dinâmica e referencias, ao modificar as classes, atente para não violar esse critério.
