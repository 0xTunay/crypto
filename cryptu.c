#include <stdio.h>
#include <string.h>

char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numAlph[256];  // ASCII characters



void initializeNumAlph() {
    for (int i = 0; i < strlen(alphabet); i++) {
        numAlph[alphabet[i]] = i;
    }
}
char* encode(const char* text, const char* key) {
    int textLength = strlen(text);
    int keyLength = strlen(key);
    char* code = (char*)malloc(textLength + 1);

    for (int i = 0; i < textLength; i++) {
        code[i] = alphabet[(numAlph[(int)text[i]] + numAlph[(int)key[i % keyLength]]) % strlen(alphabet)];
    }

    code[textLength] = '\0';
    return code;
}

int main() {
    initializeNumAlph();
    
        char text[100];  // Assuming a maximum length for the input
    printf("Enter the text: ");
    scanf("%s", text);

    char key[100];   // Assuming a maximum length for the key
    printf("Enter the key: ");
    scanf("%s", key);




    char* result = encode(text, key);

    printf("Encoded text: %s\n", result);

    free(result);

    return 0;

}
