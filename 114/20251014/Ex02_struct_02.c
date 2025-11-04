#include <stdio.h>
#include <string.h>

// 1. Define the structure
struct Book {
    char title[100];
    char author[100];
    int pages;
    float price;
} a;

int main() {
    printf("\n");
    strcpy(a.title, "The C Programming Language, 2nd Edition");
    strcpy(a.author, "Dennis Ritchie");
    printf("%s (by %s)\n", a.title, a.author);
    return 0;
}