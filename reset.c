#include <stdio.h>
#include <string.h>

// External variables from main.c
extern char email[50], password[50], ques[100], ans[50];

// External functions from other files
extern void otp(char otp[]);
extern int check_otp(char user_otp[], char real_otp[]);
extern int check_strong_password(char pass[]);

// Function to reset password using OTP
void reset_with_otp() {
    char otp_code[10], user_otp[10], new_pass[50];
    int tries = 0;
    
    printf("\n--- RESET WITH OTP ---\n");
    
    // Generate OTP
    otp(otp_code);
    
    // Allow maximum 3 attempts
    while (tries < 3) {
        printf("Enter OTP: ");
        scanf("%s", user_otp);
        getchar();  // Clear newline
        
        // Verify OTP
        if (check_otp(user_otp, otp_code)) {
            printf("OTP Correct!\n");
            
            // Loop until valid new password is entered
            while (1) {
                printf("New password: ");
                scanf("%s", new_pass);
                getchar();
                
                if (check_strong_password(new_pass)) {
                    strcpy(password, new_pass);
                    printf("Password changed successfully!\n");
                    return;
                }
            }
        }
        
        tries++;
        printf("Wrong OTP! %d tries left.\n", 3 - tries);
    }
    
    printf("Too many attempts! Password reset failed.\n");
}

// Function to reset password using security question
void reset_with_question() {
    char answer[50], new_pass[50];
    
    printf("\n--- RESET WITH SECURITY QUESTION ---\n");
    printf("Q: %s\n", ques);
    printf("Answer: ");
    scanf("%s", answer);
    getchar();  // Clear newline
    
    // Verify answer
    if (strcmp(answer, ans) == 0) {
        printf("Answer correct!\n");
        
        // Loop until valid new password is entered
        while (1) {
            printf("New password: ");
            scanf("%s", new_pass);
            getchar();
            
            if (check_strong_password(new_pass)) {
                strcpy(password, new_pass);
                printf("Password changed successfully!\n");
                return;
            }
        }
    }
    
    printf("Wrong answer! Password reset failed.\n");
}