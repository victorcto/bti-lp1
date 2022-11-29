#ifndef Rua_hpp
#define Rua_hpp

#include <iostream>
#include <vector>
#include "Casa.hpp"
#include <tuple>

/** 
 * Esta classe representa uma rua, com dois lados A e B usando a forma snake_case (padrão do c++).
 * A rua contém dois parâmetros e dois conjuntos representando as casas da rua. As casas do lado A
 * tem números pares enquanto as casas do lado B tem números ímpares. Os números são gerados pela própria
 * classe Rua a medida que novas casas são adicionadas.
 */
class Rua{

    public:
        enum lado_rua{
            LADO_A,
            LADO_B
        };

    private:
        std::string m_nome; //<! uma string com o nome da rua
        std::string m_CEP; //<! uma string no formato XX-XXX-XXX
        std::vector<Casa*> m_lado_a, m_lado_b; //<! containers contendo um conjunto de casas em cada lado da Rua

    public:
        /**
         * Construtor com o nome e cep da rua
         * @param nome o nome da rua
         * @param cep o cep atribuido à rua
         **/
        Rua(std::string nome, std::string cep);

        /**
         * Adiciona uma casa no vetor de casas do lado A ou lado B, da rua dependendo do valor de l. 
         * O número da casa deve ser modificado conforme sua posição no vetor A ou B, casas do lado A só tem numeros pares, 
         * começando em 0, as do lado B, começando em 1 números ímpares. Se o valor de l não for A ou B este comando não tem efeito.
         * @param c uma referencia para a casa a ser adicionada, veja que o número da casa será modificado.
         * @param l o lado da rua em que a casa deve ser adicionada, pode ser LADO_A ou LADO_B.
         **/
        void adiciona_casa(Casa *c, lado_rua l);

        /**
         * Retorna um par contendo os visinhos de uma casa da rua. 
         * Uma casa é considerada vizinha da ESQUERDA se ela é anterior à casa c no vetor em que c está adicionada, outra casa
         * pode ser considerada vizinha da DIREITA, se ela é posterior à c.
         * Uma casa tem um terceiro vizinho que é a casa que fica à FRENTE dela no vetor que representa as casas
         * do lado oposto à rua, ex: se c estiver do lado A, o visinho da frente está no lado B e tem índice
         * igual ao de c no vetor oposto; 
         * Se a casa em questão não tiver qualquer um dos vizinhos, a casa correspondente na tupla retornada tem valor nullptr.
         * @param c a casa que este método deve usar para procurar os vizinhos
         * @return uma tupla contendo referencias para dos vizinhos à frente, da esquerda e da direita de c.
         **/
        std::tuple<Casa*, Casa*, Casa*> vizinhos(Casa *c);
        
        /**
         * Retorna uma tupla contendo as casas que são vizinhas à casa com o número fornecido.
         * Os termos de vizinhança são os mesmos do método anterior.
         * @param num o número da casa cuja qual se deseja encontrar os vizinhos
         * @return uma tupla contendo referencias para os vizinhos da casa fornecida, se houverem.
         **/
        std::tuple<Casa*, Casa*, Casa*> vizinhos(int num);

        /**
         * Retorna o endereço da casa de uma pessoa com número passado. 
         * O endereço é formatado segundo o formato: <nome_rua>, Cep: <cep>; Casa No. <numero>, Área: <const> / <tot> m2; Lado <lado>.
         * ex:  Rua Osvaldo Montenegro, Cep: 59-513-491; Casa No. 3, Área: 250.20 / 300 m2; Lado B
         * Esta função retorna uma string vazia se o nome procurado não pertencer a nenhuma casa da rua.
         * @param nome o nome de algum dono de alguma casa da rua
         * @return o endereço no formato:<nome_rua>, Cep: <cep>; Casa No. <numero>, Área: <const> / <tot> m2; Lado <lado>.
         **/
        std::string endereco(int numero);

        /**
         * Retorna um vetor com todas as casas da rua cujo status ocupado é false.
         * @return um vetor contendo casas que estão com status "desocupado"
        **/
        std::vector<Casa*> get_desocupadas();

        /**
         * Getter das casas do lado A.
         * @return as casas do lado A. 
         */
        std::vector<Casa*> get_lado_a();

        /**
         * Getter das casas do lado B.
         * @return as casas do lado B. 
         */
        std::vector<Casa*> get_lado_b();

};
#endif //Rua_hpp