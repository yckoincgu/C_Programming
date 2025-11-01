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
    // 2. Initialize an array of 5 Book structures
    struct Book library[5] = {
        {"The C Programming Language", "Dennis Ritchie", 272, 45.99},
        {"Effective C", "Robert C. Seacord", 704, 55.50},
        {"Clean Code", "Robert C. Martin", 464, 40.25},
        {"Code Complete", "Steve McConnell", 960, 62.00},
        {"Design Patterns", "Erich Gamma", 416, 50.75}
    };

    int choice;
    int num_books = 5;
    int index=0;

    // 3. Display the menu for the user
    printf("📚 Welcome to the Digital Library! 📚\n");
    printf("Please choose a book from the list below:\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < num_books; i++) {
        printf("%d. %s (by %s)\n", i + 1, library[i].title, library[i].author);
    }
    printf("---------------------------------------\n");
    printf("Enter the number of your choice (1 to %d): ", num_books);

    // 4. Get user input
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a number.\n");
        return 1; // Exit with error
    }

    // 5. Validate the input and display the selected book's details
    if (choice >= 1 && choice <= num_books) {
        // Adjust the choice to the array index (0 to 4)
        index = choice - 1;

        printf("\n✅ You chose: %s\n", library[index].title);
        printf("----------------------------------------\n");
        printf("  Title:  %s\n", library[index].title);
        printf("  Author: %s\n", library[index].author);
        printf("  Pages:  %d\n", library[index].pages);
        printf("  Price:  $%.2f\n", library[index].price);
        printf("----------------------------------------\n");
    } else {
        printf("\n❌ Invalid choice! Please select a number between 1 and %d.\n", num_books);
    }

    // pointer to a structure example
    struct Book *ptr = &library[0]; // pointer to the first book
    printf("\n✅ Retrieving a variable, i.e. ptr[index] :\n");
        printf("----------------------------------------\n");
        printf("  Title:  %s\n", ptr[index].title);
        printf("  Author: %s\n", ptr[index].author);
        printf("  Pages:  %d\n", ptr[index].pages);
        printf("  Price:  $%.2f\n", ptr[index].price);
        printf("----------------------------------------\n");

    printf("\n✅ Getting a pointer by ptr+index then retrieving:\n");
        printf("----------------------------------------\n");
        printf("  Title:  %s\n", (ptr+index)->title);
        printf("  Author: %s\n", (ptr+index)->author);
        printf("  Pages:  %d\n", (ptr+index)->pages);
        printf("  Price:  $%.2f\n", (ptr+index)->price);
        printf("----------------------------------------\n");
        printf("conslusion: ptr[index] is same as *(ptr+index) \n");


    return 0;
}