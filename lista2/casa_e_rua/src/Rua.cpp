#include "Rua.hpp"

Rua::Rua(std::string nome, std::string cep){
    m_nome = nome;
    m_CEP = cep;
}

void Rua::adiciona_casa(Casa *c, lado_rua l){
    if(l == LADO_A){
        if(m_lado_a.empty()){
            c->setNumero(0);
        } else if(m_lado_a.size() == 1) {
            c->setNumero(2);
        } else{
            int n = m_lado_a[m_lado_a.size()-1]->getNumero() + 2;
            c->setNumero(n);
        }

        m_lado_a.push_back(c);
    }
    if(l == LADO_B){
        if(m_lado_b.empty()){
            c->setNumero(1);
        } else if(m_lado_b.size() == 1) {
            c->setNumero(3);
        } else{
            int n = m_lado_b[m_lado_b.size()-1]->getNumero() + 2;
            c->setNumero(n);
        }

        m_lado_b.push_back(c);
    } 
}

std::tuple<Casa*, Casa*, Casa*> Rua::vizinhos(Casa *c){
    std::tuple<Casa*, Casa*, Casa*> v;

    if(c->getNumero() % 2 == 0){
        if(m_lado_a.empty()){
            return std::make_tuple(nullptr,nullptr,nullptr);
        }

        for(unsigned int i=0; i<m_lado_a.size(); i++){
            if(m_lado_a[i]->getNumero() == c->getNumero()){
                if(i == 0){
                    std::get<0>(v) = nullptr;

                    if(m_lado_a[i+1] != 0){
                        std::get<1>(v) = m_lado_a[i+1];
                    } else {
                        std::get<1>(v) = nullptr;
                    }

                    if(!m_lado_b.empty()){
                        if(i<m_lado_b.size()){
                            std::get<2>(v) = m_lado_b[i];
                        } else {
                            std::get<2>(v) = nullptr;
                        }
                    } else{
                        std::get<2>(v) = nullptr;
                    }
                } else if (i == m_lado_a.size() - 1){
                    if(m_lado_a[i-1] != 0){
                        std::get<0>(v) = m_lado_a[i-1];
                    } else {
                        std::get<0>(v) = nullptr;
                    }

                    if(m_lado_a[i+1] != 0){
                        std::get<1>(v) = m_lado_a[i+1];
                    } else {
                        std::get<1>(v) = nullptr;
                    }

                    if(!m_lado_b.empty()){
                        if(i<m_lado_b.size()){
                            std::get<2>(v) = m_lado_b[i];
                        } else {
                            std::get<2>(v) = nullptr;
                        }
                    } else{
                        std::get<2>(v) = nullptr;
                    }
                } else {
                    if(m_lado_a[i-1] != 0){
                        std::get<0>(v) = m_lado_a[i-1];
                    } else { 
                        std::get<0>(v) = nullptr;
                    }

                    if(m_lado_a[i+1] != 0){
                        std::get<1>(v) = m_lado_a[i+1];
                    } else {
                        std::get<1>(v) = nullptr;
                    }

                    if(!m_lado_b.empty()){
                        if(i<m_lado_b.size()){
                            std::get<2>(v) = m_lado_b[i];
                        } else {
                            std::get<2>(v) = nullptr;
                        }
                    } else{
                        std::get<2>(v) = nullptr;
                    }
                }
            }
        }      
    } else {
        if(m_lado_b.empty()){
            return std::make_tuple(nullptr,nullptr,nullptr);
        }

        for(unsigned int i=0; i<m_lado_b.size(); i++){
            if(m_lado_b[i]->getNumero() == c->getNumero()){
                if(i == 0){
                    std::get<0>(v) = nullptr;

                    if(m_lado_b[i+1] != 0){
                        std::get<1>(v) = m_lado_b[i+1];
                    } else {
                        std::get<1>(v) = nullptr;
                    }

                    if(!m_lado_a.empty()){
                        if(i<m_lado_a.size()){
                            std::get<2>(v) = m_lado_a[i];
                        } else {
                            std::get<2>(v) = nullptr;
                        }
                    } else {
                        std::get<2>(v) = nullptr;
                    }
                } else if (i == m_lado_b.size() - 1){
                    if(m_lado_b[i-1] != 0){
                        std::get<0>(v) = m_lado_b[i-1];
                    } else {
                        std::get<0>(v) = nullptr;
                    }

                    if(m_lado_b[i+1] != 0){
                        std::get<1>(v) = m_lado_b[i+1];
                    } else {
                        std::get<1>(v) = nullptr;
                    }
                    
                    if(!m_lado_a.empty()){
                        if(i<m_lado_a.size()){
                            std::get<2>(v) = m_lado_a[i];
                        } else {
                            std::get<2>(v) = nullptr;
                        }
                    } else {
                        std::get<2>(v) = nullptr;
                    }
                } else {
                    if(m_lado_b[i-1] != 0){
                        std::get<0>(v) = m_lado_b[i-1];
                    } else { 
                        std::get<0>(v) = nullptr;
                    }

                    if(m_lado_b[i+1] != 0){
                        std::get<1>(v) = m_lado_b[i+1];
                    } else {
                        std::get<1>(v) = nullptr;
                    }
                    
                    if(!m_lado_a.empty()){
                        if(i<m_lado_a.size()){
                            std::get<2>(v) = m_lado_a[i];
                        } else {
                            std::get<2>(v) = nullptr;
                        }
                    } else {
                        std::get<2>(v) = nullptr;
                    }
                }
            }
        }
    }

    return v;
}

std::tuple<Casa*, Casa*, Casa*> Rua::vizinhos(int num){
    std::tuple<Casa*, Casa*, Casa*> v;

    if(num % 2 == 0){
        if(m_lado_a.empty()){
            return std::make_tuple(nullptr,nullptr,nullptr);
        }

        for(unsigned int i=0; i<m_lado_a.size(); i++){
            if(m_lado_a[i]->getNumero() == num){
                if(i == 0){
                    std::get<0>(v) = nullptr;

                    if(m_lado_a[i+1] != 0){
                        std::get<1>(v) = m_lado_a[i+1];
                    } else {
                        std::get<1>(v) = nullptr;
                    }
                } else if (i == m_lado_a.size() - 1){
                    if(m_lado_a[i-1] != 0){
                        std::get<0>(v) = m_lado_a[i-1];
                    } else {
                        std::get<0>(v) = nullptr;
                    }

                    if(m_lado_a[i+1] != 0){
                        std::get<1>(v) = m_lado_a[i+1];
                    } else {
                        std::get<1>(v) = nullptr;
                    }
                } else {
                    if(m_lado_a[i-1] != 0){
                        std::get<0>(v) = m_lado_a[i-1];
                    } else { 
                        std::get<0>(v) = nullptr;
                    }

                    if(m_lado_a[i+1] != 0){
                        std::get<1>(v) = m_lado_a[i+1];
                    } else {
                        std::get<1>(v) = nullptr;
                    }
                }

                if(!m_lado_b.empty()){
                    if(m_lado_b[i] != 0){
                        std::get<2>(v) = m_lado_b[i];
                    } else {
                        std::get<2>(v) = nullptr;
                    }
                } else{
                    std::get<2>(v) = nullptr;
                }
            }
        }      
    } else {
        if(m_lado_b.empty()){
            return std::make_tuple(nullptr,nullptr,nullptr);
        }

        for(unsigned int i=0; i<m_lado_b.size(); i++){
            if(m_lado_b[i]->getNumero() == num){
                if(i == 0){
                    std::get<0>(v) = nullptr;

                    if(m_lado_b[i+1] != 0){
                        std::get<1>(v) = m_lado_b[i+1];
                    } else {
                        std::get<1>(v) = nullptr;
                    }
                } else if (i == m_lado_b.size() - 1){
                    if(m_lado_b[i-1] != 0){
                        std::get<0>(v) = m_lado_b[i-1];
                    } else {
                        std::get<0>(v) = nullptr;
                    }

                    if(m_lado_b[i+1] != 0){
                        std::get<1>(v) = m_lado_b[i+1];
                    } else {
                        std::get<1>(v) = nullptr;
                    }
                } else {
                    std::get<0>(v) = m_lado_b[i-1];
                    std::get<1>(v) = m_lado_b[i+1];
                }


                if(!m_lado_a.empty()){
                    if(m_lado_a[i] != 0){
                        std::get<2>(v) = m_lado_a[i];
                    } else {
                        std::get<2>(v) = nullptr;
                    }
                } else {
                    std::get<2>(v) = nullptr;
                }
            }
        }
    }

    return v;
}

std::string Rua::endereco(int numero){
    bool pertence_a_rua = false;
    std::string areac, areat, lado;

    if(numero % 2 == 0){
        for(auto casa : m_lado_a){
            if(casa->getNumero() == numero){
                pertence_a_rua = true;
                areac = std::to_string(casa->getAreaConstruida());
                areat = std::to_string(casa->getAreaTotal());
            }
        }
        lado = "A";
    } else {
        for(auto casa : m_lado_b){
            if(casa->getNumero() == numero){
                pertence_a_rua = true;
                areac = std::to_string(casa->getAreaConstruida());
                areat = std::to_string(casa->getAreaTotal());
            }
        }
        lado = "B";
    }

    for(unsigned int i=0; i<areac.size(); i++){
        if(areac[i] == '.'){
            areac = areac.substr(0,i+3);
        }
    }
    for(unsigned int i=0; i<areat.size(); i++){
        if(areac[i] == '.'){
            areat = areat.substr(0,i+3);
        }
    }

    if(pertence_a_rua){
        return m_nome + ", " + m_CEP + ", Casa no. " 
        + std::to_string(numero) + ", Área: " + areac + " / " + areat + ", lado " + lado;
    }

    return "";
}

std::vector<Casa*> Rua::get_desocupadas(){
    std::vector<Casa*> desocupadas;

    for(auto casa : m_lado_a){
        if(!casa->isOcupada()){
            desocupadas.push_back(casa);
        }
    }
    
    for(auto casa : m_lado_b){
        if(!casa->isOcupada()){
            desocupadas.push_back(casa);
        }
    }

    return desocupadas;
}

std::vector<Casa*> Rua::get_lado_a(){
    return m_lado_a;
}

std::vector<Casa*> Rua::get_lado_b(){
    return m_lado_b;
}