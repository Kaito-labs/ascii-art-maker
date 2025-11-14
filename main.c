#include <stdio.h>
#include <string.h>

// Function to display welcome message
void welcome_message() {
    printf("=== ASCII ART MAKER ===\n");
    printf("Turn text into cool art!\n\n");
}

// Function to get user input
void get_user_input(char* text, int max_length) {
    printf("Enter text to convert: ");
    fgets(text, max_length, stdin);
    // Remove newline character
    text[strcspn(text, "\n")] = 0;
}

// Simple ASCII art generator (basic version)
void generate_ascii_art(const char* text) {
    printf("\nYour ASCII Art:\n");
    printf("====================\n");
    
    // Simple implementation -
    for(int i = 0; i < strlen(text); i++) {
        printf(" %c  ", text[i]);
    }
    printf("\n");
    
    for(int i = 0; i < strlen(text); i++) {
        printf("=== ");
    }
    printf("\n");
}

int main() {
    char text[100];
    
    welcome_message();
    get_user_input(text, sizeof(text));
    generate_ascii_art(text);
    
    return 0;
}
