#include <stdio.h>
// Global variables - accessible by all files
char email[50], password[50], ques[100], ans[50];
int account_created = 0;
// External function declarations from other files
extern void create_account();
extern int login();
extern void forgot_password();
extern void change_password();
// Simple function to read integer only
int read_integer() {
    char input[100];
    int value;
    
    fgets(input, sizeof(input), stdin);
    
    // Try to take exactly one integer
    if (sscanf(input, "%d", &value) == 1) {
        return value;
    }
    
    return -1;  // Invalid input
}
// Function to display main menu for non-logged users
void show_main_menu(int *logged_in) {
    int choice;
    printf("\n--- MENU ---\n");
    printf("1. Create Account\n");
    printf("2. Login\n");
    printf("3. Forgot Password\n");
    printf("4. Exit\n");
    printf("Choice: ");
    choice = read_integer();
    // Using switch-case instead of if-else chain
    switch(choice) {
        case 1:
            create_account();
            break;
        case 2:
            if (login()) {
                *logged_in = 1;
            }
            break;
        case 3:
            forgot_password();
            break;
        case 4:
            *logged_in = -1;  // Exit signal
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
}
// Function to display user menu for logged-in users
void show_user_menu(int *logged_in) {
    int choice;
    printf("\n--- USER MENU ---\n");
    printf("Email: %s\n", email);
    printf("1. Change Password\n");
    printf("2. Logout\n");
    printf("Choice: ");
    choice = read_integer();
    // Using switch-case for user menu
    switch(choice) {
        case 1:
            change_password();
            break;
        case 2:
            printf("Logged out!\n");
            *logged_in = 0;
            break;
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
}
int main() {
    int logged_in = 0;  // Session state: 0 = not logged in, 1 = logged in, -1 = exit
    
    printf("\n*** USER AUTHENTICATION SYSTEM ***\n");
    
    // Main program loop
    while (logged_in != -1) {
        if (logged_in == 0) {
            show_main_menu(&logged_in);
        } else {
            show_user_menu(&logged_in);
        }
    }
    
    printf("Goodbye!\n");
    return 0;
}