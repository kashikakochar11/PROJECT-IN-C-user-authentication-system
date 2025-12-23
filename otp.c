#include <stdio.h>
#include <string.h>
static int counter = 123456; 

void otp(char otp[]) {
    counter++;
    int value = (counter % 900000) + 100000;

    sprintf(otp, "%d", value);
    
    printf("Your OTP: %s\n", otp);
}

int check_otp(char user_otp[], char real_otp[]) {
    return strcmp(user_otp, real_otp) == 0;
}