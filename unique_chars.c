#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_MAX 255
#define BYTES_NECESSARY ((ASCII_MAX+1) / 8)
#define BYTE_POS(c) (c / 8)
#define BIT_POS(c) (c % 8)

bool all_unique_chars(char *str) {
    if(strlen(str) > ASCII_MAX)
        return false;

    /* make an array to contain bools of whether or not we've seen a character 
       before use bits instead of bytes to use only 32 bytes of space
       rather than 256 bytes. */
    uint8_t char_has_appeared[BYTES_NECESSARY] = {false};

    uint8_t size = 0;
    char c = str[size];

    /* loop thru string, check if the bit whose index equals the chars
       ascii value. if not, set to 1, since it's true we've seen this char */
    while(c != '\0') {
        if(char_has_appeared[BYTE_POS(c)] >> BIT_POS(c) & 0x01) {
            return false;
        }

        /*  set bit 'n' to 1 for true, we've seen this before, where 'n'
            is the ascii value of char c */
        char_has_appeared[BYTE_POS(c)] |= (0x01 << BIT_POS(c));
        size++;
        c = str[size];
    }
    return true;
}


int main(int argc, char *argv[]) {
    if(argc <= 1) {
        fprintf(stdout, "Usage: ./unique \"Test string here\"\n");
        return 1;
    }

    bool unique_only = all_unique_chars(argv[1]);
    fprintf(stdout, "%s\n", unique_only ? "true" : "false");
    
    return 0;
}
