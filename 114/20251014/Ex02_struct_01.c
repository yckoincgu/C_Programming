#include <stdio.h>
#include <string.h>

// 1. Define the structure
struct Book {
    char title[100];
    char author[100];
    int pages;
    float price;
};

int main() {
    printf("\n");
    // 2. Initialize an array of 5 Book structures
    struct Book a = {"", "Dennis Ritchie", 272, 45.99};
    strcpy(a.title, "The C Programming Language, 2nd Edition");
    printf("Access via variable: %s (by %s)\n", a.title, a.author);

    printf("\n");
    struct Book *ptr = &a;
    printf("Access via pointer: %s (by %s)\n", ptr->title, ptr->author);

    return 0;
}