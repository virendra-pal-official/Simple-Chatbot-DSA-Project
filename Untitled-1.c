#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void printWelcomeMessage() {
    printf("====================================\n");
    printf("       Welcome to Simple Chatbot    \n");
    printf("        (Type 'exit' to quit)       \n");
    printf("====================================\n\n");
}

void printUserPrompt() {
    printf("You > ");
}

void printBotResponse(const char *response) {
    printf("Bot > %s\n\n", response);
}

int main() {
    char input[100];
    printWelcomeMessage();

    while (1) {
        printUserPrompt();
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;  // remove newline

        toLowerCase(input);

        if (strcmp(input, "hello") == 0) {
            printBotResponse("Hello! How can I assist you today?");
        }
        else if (strcmp(input, "how are you") == 0) {
            printBotResponse("I'm just a program, but I'm doing well!");
        }
        else if (strcmp(input, "what is your name") == 0) {
            printBotResponse("I am a simple C chatbot.");
        }
        else if (strcmp(input, "exit") == 0) {
            printBotResponse("Goodbye! Have a great day!");
            break;
        }
        else {
            printBotResponse("Sorry, I didn't understand that.");
        }
    }

    return 0;
}
