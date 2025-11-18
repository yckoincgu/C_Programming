#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_USERS 100
#define MAX_USERNAME 30
#define MAX_PASSWORD 30
#define MAX_NAME 50
#define MAX_ATTEMPTS 3

// Structure to store user credentials
typedef struct {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    char fullName[MAX_NAME];
    int accountNumber;
    int isActive;
} User;

// Global array to store users
User users[MAX_USERS];
int userCount = 0;

// Function prototypes
void initializeSystem();
void registerUser();
int loginUser();
void displayMenu();
void displayUserInfo(int index);
int findUser(char username[]);
void clearInputBuffer();

int main() {
    int choice;
    int loggedIn = 0;
    int currentUserIndex = -1;
    
    initializeSystem();
    
    while (1) {
        printf("\n========================================\n");
        printf("   BANK MANAGEMENT SYSTEM - LOGIN\n");
        printf("========================================\n");
        printf("1. Register New User\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                currentUserIndex = loginUser();
                if (currentUserIndex != -1) {
                    loggedIn = 1;
                    printf("\n*** Login Successful! ***\n");
                    displayUserInfo(currentUserIndex);
                    
                    // After successful login, show user menu
                    printf("\nPress Enter to continue...");
                    getchar();
                }
                break;
            case 3:
                printf("\nThank you for using Bank Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

// Initialize system with some default users
void initializeSystem() {
    // Add default admin user
    strcpy(users[0].username, "admin");
    strcpy(users[0].password, "admin123");
    strcpy(users[0].fullName, "System Administrator");
    users[0].accountNumber = 1001;
    users[0].isActive = 1;
    
    // Add sample user
    strcpy(users[1].username, "john_doe");
    strcpy(users[1].password, "john123");
    strcpy(users[1].fullName, "John Doe");
    users[1].accountNumber = 1002;
    users[1].isActive = 1;
    
    userCount = 2;
    
    printf("\n*** System Initialized ***\n");
    printf("Default accounts created:\n");
    printf("  Username: admin | Password: admin123\n");
    printf("  Username: john_doe | Password: john123\n");
}

// Register a new user
void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("\nError: Maximum user limit reached!\n");
        return;
    }
    
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    char confirmPassword[MAX_PASSWORD];
    char fullName[MAX_NAME];
    
    printf("\n--- User Registration ---\n");
    
    // Get username
    printf("Enter username: ");
    fgets(username, MAX_USERNAME, stdin);
    username[strcspn(username, "\n")] = 0; // Remove newline
    
    // Check if username already exists
    if (findUser(username) != -1) {
        printf("\nError: Username already exists!\n");
        return;
    }
    
    // Get password
    printf("Enter password: ");
    fgets(password, MAX_PASSWORD, stdin);
    password[strcspn(password, "\n")] = 0;
    
    // Confirm password
    printf("Confirm password: ");
    fgets(confirmPassword, MAX_PASSWORD, stdin);
    confirmPassword[strcspn(confirmPassword, "\n")] = 0;
    
    if (strcmp(password, confirmPassword) != 0) {
        printf("\nError: Passwords do not match!\n");
        return;
    }
    
    // Get full name
    printf("Enter full name: ");
    fgets(fullName, MAX_NAME, stdin);
    fullName[strcspn(fullName, "\n")] = 0;
    
    // Store user data
    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    strcpy(users[userCount].fullName, fullName);
    users[userCount].accountNumber = 1000 + userCount + 1;
    users[userCount].isActive = 1;
    
    printf("\n*** Registration Successful! ***\n");
    printf("Account Number: %d\n", users[userCount].accountNumber);
    
    userCount++;
}

// Login user
int loginUser() {
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    char confirmPassword[MAX_PASSWORD];
    char fullName[MAX_NAME];
    char choice;
    int attempts = 0;
    
    printf("\n--- User Login ---\n");
    
    printf("Enter username: ");
    fgets(username, MAX_USERNAME, stdin);
    username[strcspn(username, "\n")] = 0;
    
    int userIndex = findUser(username);
    
    if (userIndex == -1) {
        printf("\n*** Account does not exist! ***\n");
        printf("Username '%s' not found in the system.\n", username);
        printf("\nWould you like to create a new account? (y/n): ");
        scanf("%c", &choice);
        clearInputBuffer();
        
        if (choice == 'y' || choice == 'Y') {
            if (userCount >= MAX_USERS) {
                printf("\nError: Maximum user limit reached!\n");
                return -1;
            }
            
            printf("\n--- Creating New Account ---\n");
            
            // Get password
            printf("Enter password: ");
            fgets(password, MAX_PASSWORD, stdin);
            password[strcspn(password, "\n")] = 0;
            
            // Confirm password
            printf("Confirm password: ");
            fgets(confirmPassword, MAX_PASSWORD, stdin);
            confirmPassword[strcspn(confirmPassword, "\n")] = 0;
            
            if (strcmp(password, confirmPassword) != 0) {
                printf("\nError: Passwords do not match!\n");
                return -1;
            }
            
            // Get full name
            printf("Enter full name: ");
            fgets(fullName, MAX_NAME, stdin);
            fullName[strcspn(fullName, "\n")] = 0;
            
            // Store user data
            strcpy(users[userCount].username, username);
            strcpy(users[userCount].password, password);
            strcpy(users[userCount].fullName, fullName);
            users[userCount].accountNumber = 1000 + userCount + 1;
            users[userCount].isActive = 1;
            
            printf("\n*** Account Created Successfully! ***\n");
            printf("Account Number: %d\n", users[userCount].accountNumber);
            printf("You are now logged in.\n");
            
            userCount++;
            return userCount - 1; // Return the newly created user index
        } else {
            printf("\nReturning to main menu...\n");
            return -1;
        }
    }
    
    if (!users[userIndex].isActive) {
        printf("\nError: Account is inactive!\n");
        return -1;
    }
    
    // Allow multiple password attempts
    while (attempts < MAX_ATTEMPTS) {
        printf("Enter password: ");
        fgets(password, MAX_PASSWORD, stdin);
        password[strcspn(password, "\n")] = 0;
        
        if (strcmp(users[userIndex].password, password) == 0) {
            return userIndex; // Successful login
        } else {
            attempts++;
            printf("\nIncorrect password! Attempts remaining: %d\n", MAX_ATTEMPTS - attempts);
            
            if (attempts < MAX_ATTEMPTS) {
                printf("Try again.\n");
            }
        }
    }
    
    printf("\nAccount locked due to too many failed attempts!\n");
    users[userIndex].isActive = 0; // Deactivate account
    return -1;
}

// Find user by username
int findUser(char username[]) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

// Display user information
void displayUserInfo(int index) {
    printf("\n========================================\n");
    printf("         USER INFORMATION\n");
    printf("========================================\n");
    printf("Full Name      : %s\n", users[index].fullName);
    printf("Username       : %s\n", users[index].username);
    printf("Account Number : %d\n", users[index].accountNumber);
    printf("Account Status : %s\n", users[index].isActive ? "Active" : "Inactive");
    printf("========================================\n");
}

// Clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}