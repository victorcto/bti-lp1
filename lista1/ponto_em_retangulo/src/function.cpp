#include "function.h"

bool validate_rect( const Ponto &IE, const Ponto &SD){
    if(IE.x == SD.x and IE.y == SD.y)
        return false;
    
    return true;
}

int pt_in_rect( const Ponto &IE, const Ponto &SD, const Ponto &P ){
    
    if(validate_rect(IE,SD)){
        if((P.x >= IE.x and P.x <= SD.x) and (P.y == IE.y || P.y == SD.y)){
            return 0;
        }
        else if((P.y >= IE.x and P.y <= SD.y) and (P.x == IE.x || P.x == SD.x)){
            return 0;
        }
        else if(P.x < IE.x || P.x > SD.x || P.y < IE.y || P.y > SD.y){
            return 1;
        }
        else{
            return 2;
        }
    }

    return -1;
}