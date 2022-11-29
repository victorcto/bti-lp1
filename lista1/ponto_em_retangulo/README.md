# Ponto em Retângulo

Considerando a estrutura abaixo para representar as coordenadas Cartesianas de um ponto no plano bidimensional (2D), implemente
uma função em C++ que verifica se um ponto P = (x<sub>p</sub>,y<sub>p</sub>), determinado por suas coordenadas cartesianas, está localizado
**dentro, na borda ou fora** de um retângulo definido por dois pontos: o canto inferior esquerdo IE = (x<sub>ie</sub>,y<sub>ie</sub>) e o canto
superior direito SD = (x<sub>sd</sub>, y<sub>sd</sub>).

![Diagrama](https://gdurl.com/gtfp)

Struct que descreve um ponto:
```c++
struct Ponto {
  int x; // ! < coordenada X do ponto.
  int y; // ! < coordenada y do ponto.
  // Construtor padrão
  Ponto ( int xi =0, int yi =0 ) : x{xi}, y{yi} // copia args para os campos x e y
  { /* nada */ }
};
```

Implemente um programa em C++ que recebe da entrada padrão um número indeterminado de
linhas, cada uma correspondendo a um caso de teste. Cada caso de teste contém informções
correspondentes a um possível retângulo e um ponto, ambos definidos no plano Cartesiano
2D. Para cada caso de teste o programa deve (1) verificar se o retângulo é válido e usando
a função _validate_, em caso verdadeiro (2) classificar o ponto em relação ao retângulo em uma das 
três possibilidades: fora, na fronteira, ou dentro do retângulo;

Um retângulo é considerado válido se e somente se pelo menos uma das quatro coordenadas
dos vértices que o define for diferente, ou seja R1&ne;R2. Portanto, o programa deve aceitar
os chamados retângulos "degenerados" que formam uma linha vertical ou horizontal, como
por exemplo: IE(2; 5) x SD(2; 7) ou IE(-53;-4) x SD(-5;-4). Para realizar a validação use
obrigatóriamente a a função _validate\_rect_, que recebe como argumento os pontos pontos dos cantos inferior 
esquerdo  e superior direito, e retorna true quando um retângulo e válido e retornar false, caso contrário.

A classifição do posicionamento do ponto em relação ao retângulo deve ser feita
através da invocação da função _pt\_in\_rect_, também recebe os pontos dos cantos inferior esquerdo 
e superior direito de um retângulo e retorna um inteiro representado as possibilidades do ponto em relação ao retângulo.

Cada linha lida da entrada padrão deve corresponder a um caso de teste, tendo o formato:
x<sub>1</sub> y<sub>1</sub> x<sub>2</sub> y<sub>2</sub> x<sub>3</sub> y<sub>3</sub>, onde -1000 &le; 
x<sub>i</sub>,y<sub>i</sub> &le; 1000. Os quatro primeiros valores representam as coordenadas de dois 
vértices quaisquer do retângulo: R1 = (x<sub>1</sub>, y<sub>1</sub>) e R2 = (x<sub>2</sub>, y<sub>2</sub>).
__Note que esses dois vértices podem representar qualquer um dos quatro possíveis cantos de um retângulo__: 
inferior esquerdo, inferior direito, superior esquerdo, ou superior direito; assim o programa deve verificar
os pontos antes de passar para as funções, para que os cálculos funcionem corretamente. Os
últimos dois valores representam as coordenadas do ponto, P = (x<sub>3</sub>, y<sub>3</sub>), a ser testado contra
o retângulo definido na mesma linha.

## Exemplo de entrada/saída

Entrada | Saída
--------|------
`-3 -1 3 1 0 0` </br> `2 2 9 7 4 2` </br> `7 9 2 2 2 7` </br> `4 5 4 5 -1 -2` </br> `-3 0 5 5 1 6` </br> `-3 0 5 5 6 4` </br> `1 2 -5 7 -1 6` </br> `3 7 -2 -2 2 2` | inside </br> border </br> border </br> invalid </br> outside </br> outside </br> inside </br> inside

## Conhecimentos necessários

Utilização de funções, reutilização de código, tipos heterogêneos (struct), passagem de parâmetro
por referência constante, enumerações, Geometria 2D, condicionais, expressões lógicas.

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