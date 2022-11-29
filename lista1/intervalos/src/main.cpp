#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
using std::setprecision;
using std::fixed;
#include <vector>
using std::vector;
#include "func.hpp"

int main(void){
    int x, count = 0;
    float sum = 0.0;
    vector<int> v1, v2;

    while(cin >> std::ws >> x){
        if(count < 5)
            v1.push_back(x);
        if(count >= 5)
            v2.push_back(x);
        
        count++;
    }

    for(unsigned int i=0; i<v1.size() - 1; i++){
        cout << fixed << setprecision(2);
        cout << "[" << v1[i] << ", " << v1[i+1] << "[" << " = " << percentage(v1[i], v1[i+1], v2) << endl;
        sum += percentage(v1[i], v1[i+1], v2);
    }
    
    cout << "outros = " << 100.0 - sum;

    return 0;
}