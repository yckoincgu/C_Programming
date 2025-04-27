#ifndef LOGICAL_DEFINITIONS_H
#define LOGICAL_DEFINITIONS_H
#include <stdio.h>

// Define the structure (typically in the header file)
struct LogicalAtom {
    char symbol;
    int value;
};

// Declare an external variable of the struct type
extern struct LogicalAtom logicalAtom[5];



extern char *Logical_AND_Symbol_Pointer,
            *Logical_AND_code,
            *Logical_OR_Symbol_Pointer,
            *Logical_OR_code,
            *Logical_NOT_Symbol_Pointer,
            *Logical_NOT_code,
            *Logical_Implication_Symbol_Pointer,
            *Logical_Implication_code,
            *Logical_Equivalence_Symbol_Pointer,
            *Logical_Equivalence_code,
            *Logical_All_Symbol_Pointer,
            *Logical_All_code,
            *Logical_Exists_Symbol_Pointer,
            *Logical_Exists_code,
            *Logical_Therefore_Symbol_Pointer,
            *Logical_Therefore_code,
            *Logical_Because_Symbol_Pointer,
            *Logical_Because_code;
#endif /* LOGICAL_DEFINITIONS_H */

/* pointer codes of utf-8 logical operators 
Logical AND (∧): \u2227
Logical OR (∨): \u2228
Logical NOT (¬): \u00AC
Logical Implication (→): \u2192
Logical Equivalence (↔): \u2194
Universal Quantifier (∀) - Logical All: \u2200
Existential Quantifier (∃) - Logical Exists: \u2203
Therefore (∴): \u2234
Because (∵): \u2235
*/

/* programming codes of utf-8 logical operators
Logical AND (∧): E2 88 A7, "\xE2\x88\xA7" in a C string literal   
Logical OR (∨): E2 88 A8, "\xE2\x88\xA8" in a C string literal   
Logical NOT (¬): C2 AC, "\xC2\xAC" in a C string literal
Logical Implication (→): E2 86 92, "\xE2\x86\x92" in a C string literal   
Logical Equivalence (↔): E2 86 94, "\xE2\x86\x94" in a C string literal
Universal Quantifier (∀) - Logical All: E2 88 80, "\xE2\x88\x80" in a C string literal
Existential Quantifier (∃) - Logical Exists: E2 88 83, "\xE2\x88\x83" in a C string literal
Therefore (∴): E2 88 B4, "\xE2\x88\xB4" in a C string literal
Because (∵): E2 88 B5, "\xE2\x88\xB5" in a C string literal
*/

