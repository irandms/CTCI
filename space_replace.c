#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 512

void _shift_chars_to_right(char *str, int idx, size_t extra_chars) {
    /* Assumes there is space in the string after the terminating \0
       Shift everything right of idx 2 spaces to the right, to make
       room for the '2' and '0' characters. */
    int end_idx = strlen(str) + extra_chars;

    while((end_idx != idx+extra_chars) && (end_idx-extra_chars > 0)) {
        str[end_idx] = str[end_idx-extra_chars];
        end_idx--;
    }
}

void replace_ch_with_substr(char *str, char ch, char *substr) {
    char c = 1; // Just to start with something not '\0'
    int i, j;
    size_t extra_chars = strlen(substr) - 1;
    
    for(i = 0; c != '\0'; i++) {
        c = str[i];
        if(c == ch) {
            _shift_chars_to_right(str, i, extra_chars);
            for(j = 0; j < strlen(substr); j++, i++) {
                str[i] = substr[j];
            }
        }
    }
}

int main(char *argv[], int argc) {
    char str1[] = "Test string please ignore\0______________________________________";

    replace_ch_with_substr(str1, ' ', "%20");
    puts(str1);

    char *str2 = malloc(sizeof(char) * MAX_STR_LEN);
    fgets(str2, MAX_STR_LEN, stdin);

    replace_ch_with_substr(str2, '1', "ONE");
    puts(str2);
}
