#include "Casa.hpp"

Casa::Casa(double areaConstruida, double areaTotal){
    m_areaConstruida = areaConstruida;
    m_areaTotal = areaTotal;
    m_numero = -1;
    m_ocupada = false;
}

int Casa::getNumero(){
    return m_numero;
}

void Casa::setNumero(int n){
    m_numero = n;
}

double Casa::getAreaConstruida(){
    return m_areaConstruida;
}

double Casa::getAreaTotal(){
    return m_areaTotal;
}

bool Casa::isOcupada(){
    return m_ocupada;
}

void Casa::setOcupada(bool ocupada){
    m_ocupada = ocupada;
}

std::string Casa::toString(){
    return "Área: " + std::to_string(m_areaConstruida) + " / " + std::to_string(m_areaTotal);
}
