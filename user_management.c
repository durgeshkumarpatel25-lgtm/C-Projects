#include <stdio.h>
#include <string.h>
#include <conio.h>

#define MAX_USERS 10
#define CREDENTIAL_LENGTH 30

typedef struct {
    char username[30];
    char password[30];
} User;

User users[MAX_USERS];
int user_count = 0;

void register_user();
int login_user();  // returns the user index
void fix_fgets_input(char *);
void input_password(char *);

int main() {
    int option;
    int user_index;
    while (1) {
        printf("\nWelcome to the User Management");
        printf("\n1. Register");
        printf("\n2. Login");
        printf("\n3. Exit");
        printf("\nSelect an option: ");
        if (scanf("%d", &option) != 1) { // basic validation
            while (getchar() != '\n'); // clear bad input
            printf("\nInvalid input!\n");
            continue;
        }
        getchar(); // to consume leftover '\n' from scanf

        switch (option) {
            case 1:
                register_user();
                break;
            case 2:
                user_index = login_user();
                if (user_index >= 0) {
                    printf("\nLogin Successful! Welcome, %s\n", users[user_index].username);
                } else {
                    printf("\nLogin Failed! Invalid username or password.\n");
                }
                break;
            case 3:
                printf("\nExiting Program.\n");
                return 0;
            default:
                printf("\nInvalid option! Please try again.\n");
                break;
        }
    }
    return 0;
}

void register_user() {
    if (user_count == MAX_USERS) {
        printf("Maximum %d users are supported! No more registrations allowed!\n", MAX_USERS);
        return;
    }

    int new_index = user_count;

    printf("\nRegister a new user");
    printf("\nEnter username: ");
    fgets(users[new_index].username, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(users[new_index].username);

    input_password(users[new_index].password);

    user_count++;
    printf("\nRegistration successful!\n");
}

int login_user() {
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];

    printf("\nEnter username: ");
    fgets(username, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(username);

    input_password(password);

    for (int i = 0; i < user_count; i++) {
        if (strcmp(username, users[i].username) == 0 &&
            strcmp(password, users[i].password) == 0) {
            return i;
        }
    }
    return -1;
}

/*
 Windows version: use _getch() to read single characters.
 Shows '*' for each typed character and supports Backspace.
*/
void input_password(char *password) {
    int i = 0;
    int ch;

    printf("Enter password: ");

    while (1) {
        ch = _getch(); // returns int; does not echo
        if (ch == '\r' || ch == '\n') { // Enter pressed
            break;
        } else if (ch == 8) { // Backspace
            if (i > 0) {
                i--;
                // remove last '*' from console
                printf("\b \b");
                fflush(stdout);
            }
        } else if (ch == 0 || ch == 224) {
            // handle special keys (arrow keys) by consuming next byte
            _getch();
            continue;
        } else if (i < CREDENTIAL_LENGTH - 1) {
            password[i++] = (char)ch;
            printf("*");
            fflush(stdout);
        }
    }
    password[i] = '\0';
    printf("\n");
}

void fix_fgets_input(char *string) {
    int index = strcspn(string, "\n");
    string[index] = '\0';
}
