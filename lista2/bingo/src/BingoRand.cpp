#include "BingoRand.hpp"
#include <algorithm>
using namespace std;


/*inicialização da variável estática*/
std::minstd_rand BingoRand::rnd = std::minstd_rand();

void BingoRand::setSeed(unsigned long seed){
    rnd.seed(seed);
}

int BingoRand::rand(int a, int b){
    int min = std::min(a,b);
    
    if(a == b)
        return min;

    return rnd()%(std::abs(a - b)+1) + min;
}

std::vector<int> BingoRand::getNDifferent(int a, int b, int n){
    std::vector<int> ret;
    int retsize = std::min(abs(a-b),n);
    /*sorteia até preencher o vetor*/
    while((int)ret.size() != retsize){
        int num = BingoRand::rand(a,b);
        if(std::find(ret.begin(), ret.end(), num) == ret.end())
            ret.push_back(num);
    }
    return ret;
}