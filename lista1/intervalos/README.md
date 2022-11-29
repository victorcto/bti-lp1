# Intervalos | modificada (intervalos variáveis) + escrever funcoes | gerar novos testes

Escreva um programa em C++ que lê inicialmente 5 números inteiros, n1, n2, n3, n4 e n5. Após os 5 primeiros números, o programa deverá ler um 
número não conhecido de valores inteiros e contar quantos deles estão em cada um dos intervalos \[n1; n2\[, \[n2; n3\[, \[n3; n4\[, \[n4; n5\[ e quantos estão fora de qualquer desses intervalos. A única restrição a respeito dos números dos intervalos é que n2, n3 e n4 estão no intervalo \[n1, n2\], veja que você não precisa checar essa condição
ela sempre será verdadeira para os casos de teste!

Para ler um número indeterminado de valores basta incluir o comando de extração associado ao `std::cin` como condição de parada em um laço (ver abaixo).

```c++
int x;
while( cin >> std::ws >> x) {
  // realização da contagem em relação aos intervalos
}
```

O programa deve ler os 5 números iniciais, armazená-los em um vetor, v1, e depois armazenar toda a entrada subsequente em outro vetor, v2. Após encerrada a entrada de dados, o programa deve imprimir a **porcentagem** de números para cada um dos quatro intervalos e de números fora deles, nessa ordem, um por linha e representados com quatro casas de precisão. Para definir a precisão use a funções `std::setprecision(2)` e `std::fixed` antes de imprimir assim: `cout<<std::fixed<<std::setprecision(2);`.

Para este problema, __use ao menos uma função que recebe o vetor que define os intervalos__ para realizar cômputo das porcentagens. A quantidade de funções necessárias fica à seu critério.

## Exemplos de Entrada/Saída

<table>
  <tr>
    <th>Entrada</th> <th>Saída</th>
  </tr>
  <tr>
    <td>
<pre>
0 25 50 75 100
-9 -8
1 5 15 20
25 30 35 40 45 46 47
50 55 60
78 85 90 99
100 120
</pre>
    </td>
    <td>
<pre>
[0, 25[ = 18.18
[25, 50[ = 31.82
[50, 75[ = 13.64
[75, 100[ = 18.18
outros = 18.18
</pre>
    </td>
  </tr>
    <tr>
    <td>
<pre>
0 25 50 75 100
25 30 35 40 45 46 47
78 85 90 99
100 120
</pre>
    </td>
    <td>
<pre>
[0, 25[ = 0
[25, 50[ = 53.85
[50, 75[ = 0
[75, 100[ = 30.77
outros = 15.38
</pre>
    </td>
  </tr>
</table>

## Conhecimentos Necessários

Leitura de entrada padrão, escrita em saída padrão, laços, condicionais, _type casting_, saída formatada, uso de vetores.

## Execução do programa

Nesta questão para executar os testes você precisa fazer os seguintes comandos, no terminal, a partir do diretório onde este README está:

```
mkdir build
cd build
cmake ..
cmake --build . --target verify
```

Rodando seus próprios testes:

```
mkdir build
cd build
cmake ..
cmake --build .
./program
```

Neste caso depois de executar, lembre-se que vc deve usar <kbd>CTRL</kbd>+<kbd>D</kbd> para que o laço de leitura acabe e o programa exiba a saída.

