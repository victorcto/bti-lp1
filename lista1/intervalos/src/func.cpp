#include "func.hpp"

float percentage(int a, int b, vector<int> v){
    int belongs = 0;

    for(unsigned int i=0; i<v.size(); i++){
        for(int j=a; j<b; j++){
            if(v[i] == j){
                belongs++;
            }
        }
    }

    return (float) belongs / v.size() * 100.0;
}