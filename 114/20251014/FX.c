#include <stdio.h>
#include <string.h>
 

typedef struct Book {
char title[100];
char author[100];
int pages;
float price;
} book;
int choice;
int num_books = 5;
book library[5] = {
{"The C Programming Language", "Dennis Ritchie", 272, 45.99},
{"Effective C", "Robert C. Seacord", 704, 55.50},
{"Clean Code", "Robert C. Martin", 464, 40.25},
{"Code Complete", "Steve McConnell", 960, 62.00},
{"Design Patterns", "Erich Gamma", 416, 50.75}
};

char* libfunc() {
    if (choice >= 1 && choice <= num_books) {
        int index = choice - 1;

        printf("\n✅ You chose: %s\n", library[index].title);
        printf("----------------------------------------\n");
        printf(" Title: %s\n", library[index].title);
        printf(" Author: %s\n", library[index].author);
        printf(" Pages: %d\n", library[index].pages);
        printf(" Price: $%.2f\n", library[index].price);
        printf("----------------------------------------\n");
    }
    return NULL;
}

int main() {
printf("📚 Welcome to the Digital Library! 📚\n");
printf("Please choose a book from the list below:\n");
printf("---------------------------------------\n");
for (int i = 0; i < num_books; i++) {
printf("%d. %s (by %s)\n", i + 1, library[i].title, library[i].author);
}
printf("---------------------------------------\n");
printf("Enter the number of your choice (1 to %d): ", num_books);
scanf("%d", &choice);
char* nchoice = "This book is not available";
char* result;
result = (choice <= 5) ? libfunc() : nchoice;

return 0;
}