# Trabalho 01: Lista básica de programação em C++


#  Introdução

Esse exercício tem por objetivos fazer você praticar/relembrar sua habilidade de **interpretar especificações de problemas**, aliada a sua capacidade de **projetar** e **implementar algoritmos**.

Além disso, a resolução desses exercícios irá te oferecer uma oportunidade prática para utilizar elementos básicos de programação em C++, como laços, condicionais simples e composto, tipos de dados básicos e heterogêneos, expressões lógicas, passagem de parâmetros, criação de funções, leitura de escrita de informações a partir da entrada e saída padrão, dentre outros.

Você deverá ter contato com alguns elementos da STL (_Standard Template Library_) do C++, mais especificamente o uso de _vetor dinâmico_ e _estático_, bem como alguns algoritmos básicos de manipulação de dados, dependendo das necessidades dos algoritmos que você projetar.

Outro ponto importante é que você tente fazer a compilação e execução dos programas através do terminal, e use o github de forma periódica para guardar o progresso. A sugestão é que faça ao menos um commit ao fim de cada questão, mas nada impede que você faça mais. O uso períodico do git commit (não precisa fazer push) é útil em projetos grandes pois permite você "navegar no tempo" dentro da base de código vendo a velocidade que ela evolui ou mesmo fazendo testes em algum ponto específico do passado.

# Suas Tarefas

As tarefas a serem implementadas correspondem a cada um dos diretórios neste repositório (exceto os diretórios `scripts` e `test_manager`) sendo a ordem sugerida:

1. [intervalos](./intervalos)
2. [ponto_em_retangulo](./ponto_em_retangulo)
3. [histograma](./histograma)
4. [pessoa_e_cadastro](./pessoa_e_cadastro)



Para facilitar a implementação de suas respostas, você vai encontrar nesse repositório o código de suporte organizado em várias pastas, uma para cada questão da lista. Esse código já está preparado para compilar cada projeto individualmente através do uso de `cmake` e contém indicações sobre o que você precisa alterar através de comentários como `// TODO` espalhados por alguns arquivos `.cpp` e `.h`. Para você usufruir dessa infraestrutura de compilação e testagem disponível, é importante que você **não altere nenhum arquivo além do que for indicado nesse documento**.

Em resumo, sua tarefa consiste em:
1. Implementar todos as questões requisitadas na lista, incluindo seu código nos locais apropriados em cada pasta.
2. Editar o arquivo [`autor.md`](autor.md) e adicionar suas informações pessoais na [Seção Identificação Pessoal](autor.md/#identificação-pessoal).
3. Marcar cada uma das questões que você conseguiu resolver, na [Seção Questões Finalizadas](autor.md/#questões-finalizadas) do arquivo [`autor.md`](autor.md).

# Compilando e Executando

Nessa seção abordamos o procedimento necessário para compilar e executar o código inicial fornecido com o exercício.

## Tipos de Questões
Existem duas categorias de exercícios: implementação de **programa** e implementação de **função**.

Para os exercícios que solicitam a implementação de um programa, você deve editar apenas o arquivo `src/main.cpp`. Se você desejar criar outros arquivos `.cpp` para modularizar melhor seu projeto você pode fazê-lo; nesse caso lembre-se de alterar o script do `cmake` correspondente de maneira a incluir o novo arquivo fonte na lista de dependências do target `${APP_NAME}` com o comando `target_sources( ${APP_NAME} PRIVATE "seu_arquivo.cpp" )`.

Nesta categoria você deve assumir que os dados de entrada para cada programa são lidos da **entrada padrão**, stdin, através da _operação de extração_(**>>**) do _objeto_ `std::cin`. Similarmente, a saída do programa deve ser enviada para a saída padrão, stdout, através do operador de _inseção_(**<<**) no _objeto_ `std::cout`.

```c++
int x;
std::cin>>std::ws>>x; //equivalente à scanf(" %d",&x);
std::cout<<x<<'\n'; //equivalente à scanf("%d\n",x);
```

Para os exercícios que solicitam a implementação de uma função, você precisa apenas editar o arquivo `src/function.cpp`. Lá você vai encontrar o corpo vazio da função que precisa ser desenvolvida. Neste caso, é importante que você não mude a assinatura da função específica, assim os testes automáticos funcionarão.

No geral é importante que você siga à risca as instruções sobre a implementação dos exercícios, uma vez que as respostas são validadas de forma automática. De preferencia, não modifique qualquer coisa nos testes automáticos, a memos que seja acordado com o professor. 

A forma como você executará/testará cada questão está descrita no readme em cada uma, fique à vontade para perguntar qualquer detalhe e seja curioso para modificar algumas
coisas no sistema de compilação e execução. Lembre que o objetivo é que você aprenda um pouco a usar essas ferramentas, elas serão úteis no restante da disciplina.

## Dependências (precisam ser instalados no seu ambiente)

Para você poder compilar e executar os testes preparados para o exercício é necessário os seguintes requisitos:
+ [GNU gcc](https://gcc.gnu.org/), [clang](https://clang.llvm.org/), ou outro: compilador C++.
+ [cmake](https://cmake.org/): para gerar os arquivos _Makefiles_, que gerenciam a compilação otimizada do projeto.
+ [Python 3.0](https://www.python.org/): para executar o script de teste de comparação de saída gerada/esperada. Teste no seu terminal se o comando `python3 --version` funciona!.

# Submissão das Respostas

A submissão deve ser feita através do Sigaa, conforme explicitado na turma, bem como usando o repositório do github correspondente.

--------
&copy; DIMAp/IMD/UFRN 2021.
