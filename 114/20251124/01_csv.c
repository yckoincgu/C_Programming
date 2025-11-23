#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "01_data.csv"
#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 128

// Define a structure to hold the CSV data
typedef struct {
    int id;
    char name[MAX_FIELD_LENGTH];
    int age;
    char city[MAX_FIELD_LENGTH];
} Person;

/* Function to Create a CSV file and Insert Data */
void create_csv_file() {
    FILE *file = fopen(FILENAME, "w"); // "w" mode creates a new file or overwrites existing
    
    if (file == NULL) {
        perror("Unable to create file");
        exit(1);
    }

    // 1. Write Header
    fprintf(file, "ID,Name,Age,City\n");

    // 2. Insert Data Rows
    fprintf(file, "101,John Doe,25,New York\n");
    fprintf(file, "102,Jane Smith,30,Los Angeles\n");
    fprintf(file, "103,Bob Johnson,22,Chicago\n");
    fprintf(file, "104,Alice Brown,28,Seattle\n");
    fprintf(file, "105,Charlie Black,35,Houston\n"); // Added a new entry

    printf("File '%s' created and data written successfully.\n", FILENAME);

    // 3. Close the file (Important to save changes to disk)
    fclose(file);
}

/* Function to Read Data from the CSV and Display it */
void read_csv_file() {
    FILE *file;
    char buffer[MAX_LINE_LENGTH];
    char *token;
    
    // 1. Open the file for reading
    file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file for reading");
        exit(1);
    }

    printf("\n--- Reading Data from CSV ---\n");
    printf("%-5s %-20s %-5s %-15s\n", "ID", "NAME", "AGE", "CITY");
    printf("------------------------------------------------\n");

    // Skip the header line
    fgets(buffer, MAX_LINE_LENGTH, file);

    // 2. Read line by line
    while (fgets(buffer, MAX_LINE_LENGTH, file)) {
        
        // Remove trailing newline character
        buffer[strcspn(buffer, "\n")] = 0;

        Person p;

        // 3. Parse fields using strtok
        // ID
        token = strtok(buffer, ",");
        if (token == NULL) continue;
        p.id = atoi(token);

        // Name
        token = strtok(NULL, ",");
        if (token == NULL) strcpy(p.name, "Unknown");
        else strncpy(p.name, token, MAX_FIELD_LENGTH); 

        // Age
        token = strtok(NULL, ",");
        if (token == NULL) p.age = 0;
        else p.age = atoi(token);

        // City
        token = strtok(NULL, ",");
        if (token == NULL) strcpy(p.city, "Unknown");
        else strncpy(p.city, token, MAX_FIELD_LENGTH);

        // Print the parsed data
        printf("%-5d %-20s %-5d %-15s\n", p.id, p.name, p.age, p.city);
    }

    // 4. Close the file
    fclose(file);
    printf("\nFile closed successfully.\n");
}

int main() {
    // Step 1: Create and Write
    create_csv_file();

    // Step 2: Read and Display
    read_csv_file();

    return 0;
}