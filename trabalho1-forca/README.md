# Informações para o Checkpoint 1

## Sobre o carregamento dos arquivos

Os arquivos a serem utilizados a fim de testar o carregamento estão localizados na pasta *data*.

## Sobre as validações

As validações dos arquivos estão implementadas no método *validate_file*.

## Sobre a interface

É possível já testar algumas funcionalidades do menu, como: iniciar jogo, escolha do nível de dificuldade (apenas nível **fácil** implementado), sair, voltar ao menu iniciar, jogar novamente.Além disso, validações de opções escolhida errada pelo usuário já está implementada.

Entretanto, a fim de testes: depois da escolha do nível as palavras a serem usadas naquele nível serão carregadas e exibidas no terminal abaixo de "Prepare-se o jogo vai começar...", para encerrar os lances dos palpites (na qual ainda falta a implemntação completa) digite 0 (zero) e então, as opções de jogar novamente serão exibidas podendo então jogar novamente ou sair (encerrar o jogo).

## Sobre a funcionalidade da lógica do sorteio das palavras

As palavras sorteadas serão exibidas na tela depois da escolha do nível de dificuldade para comprovar que há um sorteio das palavras, sem repetição. Pode ocorrer uma demora (aleatoriamente) dependendo da randomização realizada pelo computador, se por "sorte" cair no 'melhor caso' kk :).

## Sobre o build

~~~shell
mkdir build
cd build
cmake ..
cmake --build .
./program arquivo_palavras arquivo_score
~~~

