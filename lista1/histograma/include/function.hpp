#ifndef FUNCTION_H
#define FUNCTION_H

#include <utility>
#include <vector>
#include <algorithm>

template<typename T>
std::vector<std::pair<T, int>> histograma(std::vector<T> V){
    int count = 0, k = 0;
    std::vector<std::pair<T,int>> h;

    std::sort(V.begin(),V.end());

    for(unsigned int i=0; i<V.size(); i++){
        for(unsigned int j=i; V[i] == V[j]; j++){
            count++;
            k++;
        }
        h.push_back(std::make_pair(V[i],count));
        count = 0;
        i = k - 1;
    }
    
    return h;
}

#endif
