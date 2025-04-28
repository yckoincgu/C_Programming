#include "menu.h"


int calculateAlgebra(int result, int operatorChar, int rightAtom) {
    if (operatorChar == '\0') {
        result = rightAtom;
    } else {
        switch (operatorChar) {
            case 0x2227: // Logical AND (∧)	
                // Assuming '∧' represents logical AND. Since we're working with integers,
                // we can treat non-zero as true and zero as false.
                result = result && rightAtom; // Logical AND
                break;
			case 0x2228: // Logical OR (∨)
				// Assuming '∨' represents logical OR.
				result = result || rightAtom; // Logical OR ('∨')
				break;

			case 0x00AC: // Unicode for '¬'
                // Assuming '!' represents logical NOT (unary, so might need different handling)
                // This case won't be directly reached in the current function signature.
                result = !result;
                break;

            default:
                printf("Unknown operator: %c\n", operatorChar);
                break;
        }
    }
    return result;
}


