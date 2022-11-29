#ifndef Casa_hpp
#define Casa_hpp

#include <iostream>

/**
 * A classe Casa, contém informação do dono e número usando a forma CamelCase;
 * Aqui poderia vir uma descrição mais detalhada da classe casa, mas como ela é simples
 * essa descrição não é necessária. No entanto, o doxygen trata essa parte de forma diferente
 * da primeira linha. Os métodos devem ser implementados no arquivo Casa.cpp.
 */
class Casa{
    
    private:
        int m_numero; //!< número da casa. O número deve ser setado pela classe Rua.
        double m_areaConstruida; //!< áera construída da casa
        double m_areaTotal; //!< áera total do terreno
        bool m_ocupada; //!< indica se a casa está ocupada ou não
    
    public:
        /**
         * Construtor da classe casa.
         * @param areaConstruida a área construida da casa
         * @param areaTotal a area total do terreno
         */
        Casa(double areaConstruida, double areaTotal);

        /**
         * Getter do número da casa.
         * @return o número da casa.
         */
        int getNumero();
        
        /**
         * Setter do número da casa
         * @param n o número que deve ser atribuído à casa
         */
        void setNumero(int n);

        /**
         * Getter da área construída da casa.
         * @return a área construída da casa. 
         */
        double getAreaConstruida();

        /**
         * Getter da área total da casa.
         * @return a área total da casa. 
         */
        double getAreaTotal();

        /**
         * Setter do ocupada
         * @param ocupada o estado da casa, desocupada (F) / ocupada(T)
         */
        void setOcupada(bool ocupada);

        /**
         * Getter do estado da casa
         * @return T se ocupada, F caso contrário.
         */
        bool isOcupada();

        /**
         * Retorna uma representação de string da Casa no formato Área: area_ocupada / areaConstruida m2
         * @return a representação em string da casa.
         */
        std::string toString();

};
#endif