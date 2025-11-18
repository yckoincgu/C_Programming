#include <stdio.h>
#include <string.h>

#define MAX_USERS 5
#define MAX_LENGTH 20

int main() {
    char usernames[MAX_USERS][MAX_LENGTH] = {"alice", "bob", "charlie", "david", "eve"};
    char passwords[MAX_USERS][MAX_LENGTH] = {"alice123", "bob456", "charlie789", "david321", "eve654"};

    char inputUser[MAX_LENGTH];
    char inputPass[MAX_LENGTH];
    int found = 0;

    printf("===== Welcome to Bank Management System =====\n");

    printf("Enter Username: ");
    scanf("%s", inputUser);

    printf("Enter Password: ");
    scanf("%s", inputPass);

    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(usernames[i], inputUser) == 0 && strcmp(passwords[i], inputPass) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Login Successful! Welcome, %s.\n", inputUser);
    } else {
        printf("Invalid username or password. Access Denied.\n");
    }

    return 0;
}
// Start
//   |
//   v
// #define MAX_USERS 5
// #define MAX_LENGTH 20
//Row 0: "alice"     -> ['a','l','i','c','e','\0', ?, ?, ...]
//Row 1: "bob"       -> ['b','o','b','\0', ?, ?, ...]
//Row 2: "charlie"   -> ['c','h','a','r','l','i','e','\0', ?, ...]
//Row 3: "david"     -> ['d','a','v','i','d','\0', ?, ?, ...]
//Row 4: "eve"       -> ['e','v','e','\0', ?, ?, ...]
//   |
//   v
// Display "Welcome to Bank Management System"
//   |
//   v
// Ask for Username -> inputUser
//   |
//   v
// Ask for Password -> inputPass
//   |
//   v
// For i = 0 to MAX_USERS-1
//   |
//   +--> if (usernames[i] == inputUser AND passwords[i] == inputPass)
//   |         |
//   |         v
//   |    Login Successful -> Display "Welcome" -> End
//   |
//   +--> else continue loop
//   |
// If no match after loop ends
//   |
//   v
// Display "Invalid username or password" -> End