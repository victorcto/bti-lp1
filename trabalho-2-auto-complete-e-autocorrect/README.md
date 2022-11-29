# Autocomplete e Autocorrect

## O há no projeto?

- Diretório <b>data</b>: diretório contendo três arquivos de texto simples (.txt). Esses arquivos contém um conjunto de sentenças e seus respectivos pesos. Você pode utilizá-los para rodar o programa;
- Diretório <b>include</b>: diretório contendo os cabeçalhos/headers (.h) do progama;
- Diretório <b>src</b>: diretório contendo as implementações dos headers (.cpp), bem como o arquivo principal (main.cpp);
- Diretório <b>tests</b>: diretório contendo alguns testes do programa. Você pode utilizá-los para conferir a corretude do programa;
- <b>.gitignore</b>: arquivo do git para ignorar arquivos e diretórios do projeto.
- <b>CMakeLists.txt</b>: arquivo de configuração do Cmake deste projeto;
- <b>README.MD</b>: arquivo do tipo markdown que é este. 😛
## O que é necessário ter para rodar o projeto?

### cmake

- <b>Instalação no Ubuntu:</b>

    ``` Bash
    sudo apt update && sudo apt upgrade -y
    sudo apt install build-essential -y
    sudo apt install cmake -y
    ```

## Como obter o projeto?

Para obter o projeto você tem duas opções:

1. no GitHub clicar em <b>code</b> > <b>Download ZIP</b>
2. no terminal, tendo o git instalado e adicionado as variáveis de ambiente:
``` bash
git clone https://github.com/JulioMelo-Classes/trabalho-2-auto-complete-e-autocorrect-victorcto.git
```

## Como executar o programa?

<b>1º passo: construir ("buildar") o projeto</b>

``` bash
mkdir build
cd build
cmake ..
cmake --build .
```
<b>2º passo: rodar o executável do projeto</b>

``` bash
./words_complete_correct <database_file>
```
onde <database_file> é o caminho onde está a lista das sentenças com seus respectivos pesos, ex.: <code> ../data/cities.txt</code>
```bash
./words_complete_correct ../data/cities.txt
```

## Executando testes

<b>1º passo: construir ("buildar") o projeto (mesmo processo descrito acima)</b>

<b>2º passo: rodar o executável do projeto apontando para os dados de teste e passando a flag de teste</b>

```bash
./words_complete_correct  ../tests/testData.txt --test
```

O arquivo de teste é validado com base em dois outros arquivos, o de inputs e o de resultados. A classe responsável pela validação é a Test.



