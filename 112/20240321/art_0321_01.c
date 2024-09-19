#include <stdio.h>
#include <stdlib.h>
struct Student {
    int id;
    char name[];
};
int main() {
    struct Student *s;
    // s.id=10; without real space, it cannot be assigned an interger
    struct Student x;	// with a real space for Student x 
    x.id=10;
    printf("%d", x.id);
}

