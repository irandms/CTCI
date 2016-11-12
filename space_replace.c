#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 512
#define SHIFT_SIZE 2

void _shift_chars_to_right(char *str, int idx) {
    /* Assumes there is space in the string after the terminating \0
       Shift everything right of idx 2 spaces to the right, to make
       room for the '2' and '0' characters. */
    int end_idx = strlen(str) + SHIFT_SIZE;

    while((end_idx != idx+SHIFT_SIZE) && (end_idx-SHIFT_SIZE > 0)) {
        str[end_idx] = str[end_idx-SHIFT_SIZE];
        end_idx--;
    }
}

void replace_spaces(char *str) {
    char c = 1; // Just to start with something not '\0'
    int i;
    
    for(i = 0; c != '\0'; i++) {
        c = str[i];
        if(c == ' ') {
            _shift_chars_to_right(str, i);
            str[i] = '%';
            str[i+1] = '2';
            str[i+2] = '0';
            i = i+2;
        }
    }
}

int main(char *argv[], int argc) {
    char str1[] = "Test string please ignore\0______________________________________";

    replace_spaces(str1);
    puts(str1);

    char *str2 = malloc(sizeof(char) * MAX_STR_LEN);
    fgets(str2, MAX_STR_LEN, stdin);

    replace_spaces(str2);
    puts(str2);
}
