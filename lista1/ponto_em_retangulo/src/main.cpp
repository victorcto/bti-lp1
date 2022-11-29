#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ws;
#include <algorithm>
using std::min;
using std::max;

#include "function.h"

int main(void){
    int result, aux;
    Ponto p1, p2, p3;

    while (cin >> ws >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y){

        if(p1.x < p2.x and p1.y < p2.y)
            result = pt_in_rect(p1,p2,p3);

        else if(p1.x > p2.x and p1.y > p2.y)
            result = pt_in_rect(p2,p1,p3);

        else if(p1.x < p2.x and p1.y > p2.y){
            aux = p1.x;
            p1.x = p2.x;
            p2.x = aux;
            result = pt_in_rect(p2,p1,p3);
        }
        else if(p1.x > p2.x and p1.y < p2.y){
            aux = p1.x;
            p1.x = p2.x;
            p2.x = aux;
            result = pt_in_rect(p1,p2,p3);
        }
        else{
           result = pt_in_rect(p1,p2,p3);
        }

        if(result == -1){
            cout << "invalid" << endl;
        }
        else if(result == 0){
            cout << "border" << endl;
        } 
        else if(result == 1){
            cout << "outside" << endl;
        }
        else if(result == 2){
            cout << "inside" << endl;
        }
    }
  
    return 0;
}
