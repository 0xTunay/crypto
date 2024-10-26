#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {

char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numAlph[256];  // ASCII characters
} Sex;
// КОГДА НИБУДЬ ДОДЕЛАТЬ ЭТО 
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
    free(code);
}

int main(void) {
    initializeNumAlph();
    
    char text[100],key[100];  // Assuming a maximum length for the input
    puts("Enter the text: ");
    fgets(text,sizeof(text),stdin);

    puts("Enter the key: ");
    fgets(key,sizeof(key),stdin);

    char* result = encode(text, key);

    printf("Encoded text: %s\n", encode(text, key));

    result = NULL;

    return 0;

}
