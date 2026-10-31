/*
 * Студент: Мареева Ангелина Ильинична
 * Группа: ПИ 11
 * Назначение: Строки и безопасный ввод
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char text[32];

    if (fgets(text, sizeof text, stdin) == NULL) {
        puts("Input error");
        return 1;
    }

    size_t pos = strcspn(text, "\n");
    if (text[pos] == '\n') {
        text[pos] = '\0';
    }

    if (strlen(text) > 30) {
        puts("Too long");
        return 1;
    }

    int digits = 0;
    int spaces = 0;

    for (size_t i = 0; text[i] != '\0'; i++) {
        if (text[i] >= '0' && text[i] <= '9') {
            digits++;
        } else if (text[i] == ' ') {
            spaces++;
        }
    }

    printf("Digits: %d; Spaces: %d\n", digits, spaces);
    return 0;
}