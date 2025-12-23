#include <stdio.h>
#include <string.h>

// External variables from main.c
extern char email[50], password[50], ques[100], ans[50];
extern int account_created;

// External functions from other files
extern int check_strong_password(char pass[]);
extern void reset_with_otp();
extern void reset_with_question();

// Function to create a new user account
void create_account() {
    char pass2[50];
    int choice;
    
    printf("\n=== CREATE ACCOUNT ===\n");
    printf("Email: ");
    scanf("%s", email);
    
    // Loop until passwords match and are strong
    while (1) {
        printf("Password: ");
        scanf("%s", password);
        
        // Check password strength first
        if (!check_strong_password(password)) {
            continue;  // Password is not strong, try again
        }
        
        printf("Confirm: ");
        scanf("%s", pass2);
        
        // Check if passwords match
        if (strcmp(password, pass2) != 0) {
            printf("Passwords don't match!\n");
            continue;
        }
        
        break;  // Password is strong and matches, exit loop
    }
    
    // Security question setup using switch-case
    printf("\nSecurity Question (choose 1, 2, or 3):\n");
    printf("1. Pet's name?\n");
    printf("2. Birth city?\n");
    printf("3. Mother's name?\n");
    printf("Choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            strcpy(ques, "Pet's name?");
            break;
        case 2:
            strcpy(ques, "Birth city?");
            break;
        case 3:
            strcpy(ques, "Mother's name?");
            break;
        default:
            printf("Invalid choice! Defaulting to Pet's name.\n");
            strcpy(ques, "Pet's name?");
            break;
    }
    
    printf("Answer: ");
    scanf("%s", ans);
    
    account_created = 1;
    printf("Account created!\n");
}

// Function to login user
int login() {
    char user_email[50], user_pass[50];
    
    printf("\n=== LOGIN ===\n");
    
    // Check if any account exists
    if (account_created == 0) {
        printf("No account found!\n");
        return 0;
    }
    
    printf("Email: ");
    scanf("%s", user_email);
    
    // Verify email
    if (strcmp(user_email, email) != 0) {
        printf("Email not found!\n");
        return 0;
    }
    
    printf("Password: ");
    scanf("%s", user_pass);
    
    // Verify password
    if (strcmp(user_pass, password) == 0) {
        printf("Login successful!\n");
        return 1;
    }
    
    printf("Wrong password!\n");
    return 0;
}

// Function to handle forgot password
void forgot_password() {
    int choice;
    
    // Check if any account exists
    if (account_created == 0) {
        printf("No account found!\n");
        return;
    }
    
    printf("\n--- PASSWORD RECOVERY ---\n");
    printf("1. OTP\n");
    printf("2. Security Question\n");
    printf("Choice: ");
    scanf("%d", &choice);
    
    // Using switch-case for recovery method selection
    switch(choice) {
        case 1:
            reset_with_otp();
            break;
        case 2:
            reset_with_question();
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

// Function to change password for logged-in user
void change_password() {
    char old_pass[50], new_pass[50];
    
    printf("\n=== CHANGE PASSWORD ===\n");
    printf("Current password: ");
    scanf("%s", old_pass);
    
    // Verify current password
    if (strcmp(old_pass, password) != 0) {
        printf("Wrong password!\n");
        return;
    }
    
    
    while (1) {
        printf("New password: ");
        scanf("%s", new_pass);
        
        if (check_strong_password(new_pass)) {
            strcpy(password, new_pass);
            printf("Password changed!\n");
            return;
        }
    }
}