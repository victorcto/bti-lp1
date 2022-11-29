#ifndef Rand_hpp
#define Rand_hpp

#include <random>
#include <vector>
/**
 * Classe para números aleatórios, use ela quando precisar de um número!
 */
class BingoRand{
    private:
        static std::minstd_rand rnd;

    public:
        /**
         * Configura a geração de números aleatórios usando a seed passada
         * @param a seed a ser usada na geração dos números
         **/
        static void setSeed(unsigned long seed);
        /**
         * Gera um inteiro aleatório entre a e b (inclusivo)
         * @param a o valor mínimo a ser incluído
         * @param b o valor máximo a ser incluído
         * @return um inteiro aleatório entre a e b.
         **/
        static int rand(int a=1, int b=99);
        
        /**
         * Gera um conjunto de n inteiros aleatórios com n números diferentes entre a e b.
         * Gera um conjunto de n inteiros diferentes no intervalo [a,b]. O vetor
         * gerado tem tamanho igual a min(abs(a - b), n).
         * @param a o valor inteiro mínimo a ser incluído
         * @param b o valor inteiro máximo a ser incluído
         * @param n o tamanho do vetor retornado desejado
         * @return um vetor com min(abs(a - b), n) inteiros aleatórios diferentes.
         **/
        static std::vector<int> getNDifferent(int a, int b, int n);

};

#endif //Rand_hpp