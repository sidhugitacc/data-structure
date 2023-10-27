#include<stdio.h>

void readString(char *str) {
    printf("Enter a string: ");
    scanf("%s", str);
}

void displayString(char *str) {
    printf("String entered: %s\n", str);
}

int stringLength(char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void reverseString(char *str) {
    int length = stringLength(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void copyString(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int countChar(char *str, char ch) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

int main() {
    char input[100], output[100];
    char character;

    readString(input);
    displayString(input);

    int length = stringLength(input);
    printf("String length: %d\n", length);

    reverseString(input);
    printf("Reversed string: %s\n", input);

    copyString(output, input);
    printf("Copied string: %s\n", output);

    printf("Enter a character to search in the string: ");
    scanf(" %c", &character);
    int charCount = countChar(input, character);
    if (charCount > 0) {
        printf("The character '%c' is present %d times in the string.\n", character, charCount);
    } else {
        printf("The character '%c' is not present in the string.\n", character);
    }

    return 0;
}
