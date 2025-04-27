#include "menu.h"


int calculateAlgebra(int result, int num, char operatorChar) {
    if (operatorChar == '\0') {
        result = num;
    } else {
        switch (operatorChar) {
            case '∧':
			
				break;
			case '&':
				result &= num;
				break;
			default	


    	}
    return result;
}


