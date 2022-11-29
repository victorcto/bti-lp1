# Snaze

## O que há no projeto?

- Diretório <b>data</b>: diretório contendo três arquivos de texto simples (.txt). Esses arquivos contém um conjunto de mapas e seus respectivos atributos. Você pode utilizá-los para rodar o programa;
- Diretório <b>include</b>: diretório contendo os cabeçalhos/headers (.h) do progama;
- Diretório <b>src</b>: diretório contendo as implementações dos headers (.cpp), bem como o arquivo principal (main.cpp);
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
git clone https://github.com/JulioMelo-Classes/trabalho-3-snaze-victor-joao-victor.git
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
./snaze ../data/maze1.txt -mode pacmaze -ia random 
```
Usage: ./snaze <level_file> -mode [pacmaze] -ia [random] onde <level_file> é um arquivo txt contendo a descrição dos níveis no formato especificado neste documento -mode [pacmaze] representa o modo do jogo, sendo possível um valor pacmaze -ia [random] representa o modo da ia do jogo, sendo possível: \"random\" onde a classe player apenas escolhe decisões aleatorias, possívelmente não letais para a Pacman;

## Executando testes

<b>1º passo: construir ("buildar") o projeto (mesmo processo descrito acima)</b>

<b>2º passo: rodar o executável do projeto apontando para os dados de teste.</b>

- Teste de níveis e fim de game (player chegando no último nível).

```bash
./snaze ../data/sequenciaNiveisFimDeGame.txt -mode pacmaze -ia random 
```
Esse arquivo representa uma sequência simulando o funcionamento esperado do game, há passagem de níveis de forma normal, não havendo uma situação onde o player seja forçado a morrer.

- Teste de níveis e morte do Player por colisão

```bash
./snaze ../data/sequenciaNiveisColisao.txt  -mode pacmaze -ia random 
```
Esse arquivo representa uma sequência de níveis onde há ao fim um nível específico em que é forçada a morte do player para validar o fluxo de morte (métodos implementados para decrementar vidas, zerar pontos, etc).