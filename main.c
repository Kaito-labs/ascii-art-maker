#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT 100

void welcome_message() {
    printf("╔══════════════════════════╗\n");
    printf("║     ASCII ART MAKER      ║\n");
    printf("╚══════════════════════════╝\n");
    printf("Type 'quit' to exit\n\n");
}

void get_user_input(char* text) {
    printf("Enter text: ");
    if (fgets(text, MAX_TEXT, stdin) == NULL) {
        text[0] = '\0';
        return;
    }
    text[strcspn(text, "\n")] = '\0';
}

void print_line(const char* text, char border_char) {
    int len = strlen(text);
    for (int i = 0; i < len * 4 + 1; i++) {
        putchar(border_char);
    }
    putchar('\n');
}

void generate_ascii_art(const char* text) {
    if (strlen(text) == 0) {
        printf("No text entered!\n");
        return;
    }
    
    printf("\n═══════ RESULT ═══════\n\n");
    
    print_line(text, '=');
    
    printf("|");
    for (int i = 0; text[i] != '\0'; i++) {
        printf(" %c |", toupper(text[i]));
    }
    printf("\n");
    
    // Middle border
    print_line(text, '-');
    
    // ASCII codes
    printf("|");
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%3d|", text[i]);
    }
    printf("\n");
    
    print_line(text, '=');
    
    printf("\nText length: %zu characters\n", strlen(text));
}

int main() {
    char text[MAX_TEXT];
    
    welcome_message();
    
    while (1) {
        get_user_input(text);
        
        if (strcmp(text, "quit") == 0 || strcmp(text, "exit") == 0) {
            printf("\nGoodbye!\n");
            break;
        }
        
        generate_ascii_art(text);
        printf("\n%s\n", "─".repeat(30));
    }
    
    return 0;
}
