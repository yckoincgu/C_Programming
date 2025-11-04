#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Include for standard library definitions if needed, though not strictly required here

// Global declarations (Moved to standard global scope)
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

/**
 * @brief Prints the details of the selected book if the global 'choice' is valid.
 * @return A static empty string ("") on success (book printed).
 *         The function must return a char* value to be compatible with the ternary operator.
 */
char* libfunc() {
    // NOTE: This function still uses an if-statement to check the validity of 'choice' 
    // before attempting to access the array index.
    if (choice >= 1 && choice <= num_books) {
        int index = choice - 1;

        printf("\n✅ You chose: %s\n", library[index].title);
        printf("----------------------------------------\n");
        printf("  Title:  %s\n", library[index].title);
        printf("  Author: %s\n", library[index].author);
        printf("  Pages:  %d\n", library[index].pages);
        printf("  Price:  $%.2f\n", library[index].price);
        printf("----------------------------------------\n");
    }
    return NULL;
} 


int main() {
    // FIX 1: Correct the declaration of invalidResult to a simple char* (pointer to a string literal)
    char* invalidResult = "\n❌ Invalid choice. Please run the program again and select a valid book number.\n";
    
    printf("📚 Welcome to the Digital Library! 📚\n");
    printf("Please choose a book from the list below:\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s (by %s)\n", i + 1, library[i].title, library[i].author);
    }
    printf("---------------------------------------\n");
    printf("Enter the number of your choice (1 to %d): ", num_books);
    
    // Check for successful read, but proceed with original logic
    if (scanf("%d", &choice) != 1) {
        choice = 0; // Set to an invalid choice to trigger the error path below
    }
    
    char* result_message;
    
    // FIX 2 & 3: Fix the syntax (removed extra ')') and use the ternary operator.
    // Condition checks for valid choice (1 to 5).
    // If true, libfunc() is called (prints details, returns "").
    // If false, invalidResult string is returned.
    result_message = (choice >= 1 && choice <= num_books) ? libfunc() : invalidResult;
    
    // The result_message (either "" or the error string) is printed here.
    printf("%s", result_message); 

    return 0;
}