#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_CHARS 256

int is_permutation(char *str1, char *str2) {
    if(strlen(str1) != strlen(str2)) {
        return 0;
    }

    uint8_t str1_table[ASCII_CHARS] = {0};
    uint8_t str2_table[ASCII_CHARS] = {0};

    int32_t i;
    for(i = 0; i < strlen(str1); i++) {
        str1_table[str1[i]]++;
    }
    for(i = 0; i < strlen(str2); i++) {
        str2_table[str2[i]]++;
    }
    for(i = 0; i < ASCII_CHARS; i++) {
        if(str1_table[i] != str2_table[i]) {
            return 0;
        }
    }

    return 1;
}

int main(char *argv[], int argc) {
    char *s1, *s2;

    s1 = malloc(sizeof(char) * 512);
    s2 = malloc(sizeof(char) * 512);

    scanf("%s", s1);
    scanf("%s", s2);

    printf("%d\n", is_permutation(s1, s2));

    free(s1);
    free(s2);
}
