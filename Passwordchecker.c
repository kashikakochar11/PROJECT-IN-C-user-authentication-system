#include <stdio.h>
#include <string.h>

// Function to validate password strength
int check_strong_password(char pass[]) {
    int i, len = strlen(pass);
    int upper = 0, lower = 0, digit = 0, special = 0;
    
    // Requirement 1: Minimum 8 characters
    if (len < 8) {
        printf("Password too short (min 8 chars).\n");
        return 0;
    }
    
    // Check each character in password
    for (i = 0; i < len; i++) {
        // Using switch-case for character classification
        if (pass[i] >= 'A' && pass[i] <= 'Z') {
            upper = 1;
        } else if (pass[i] >= 'a' && pass[i] <= 'z') {
            lower = 1;
        } else if (pass[i] >= '0' && pass[i] <= '9') {
            digit = 1;
        } else {
            special = 1;  // Any other character is special
        }
    }
    
    // Check if all requirements are met
    if (!upper || !lower || !digit || !special) {
        printf("Password must contain:\n");
        if (!upper) printf("  - At least one uppercase letter\n");
        if (!lower) printf("  - At least one lowercase letter\n");
        if (!digit) printf("  - At least one digit\n");
        if (!special) printf("  - At least one special character\n");
        return 0;
    }
    
    // All requirements met
    return 1;
}