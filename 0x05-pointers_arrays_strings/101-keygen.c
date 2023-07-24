#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10 // Adjust this to set the desired password length

// Function to generate a random character
char getRandomCharacter() {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int index = rand() % (sizeof(charset) - 1);
    return charset[index];
}

// Function to generate a random valid password
void generateRandomPassword(char *password, int length) {
    for (int i = 0; i < length; i++) {
        password[i] = getRandomCharacter();
    }
    password[length] = '\0'; // Null-terminate the password string
}

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    char password[PASSWORD_LENGTH + 1]; // +1 for null-terminator

    generateRandomPassword(password, PASSWORD_LENGTH);

    printf("Random valid password: %s\n", password);

    return 0;
}
