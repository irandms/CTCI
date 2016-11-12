#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 512
#define MAX_COUNT_DIGITS 4

char *compress_str(char *str) {
    int i;
    char ch = 'a'; // Something that isnt '\0'
    int ch_count = 1;

    if(strlen(str) < 2) {
        return str;
    }

    char *ret = malloc(sizeof(char) * MAX_SIZE);
    char count[4];

    for(i = 1; ch != '\0'; i++) {
        ch = str[i];
        if(ch != str[i-1]) {
            snprintf(count, 4, "%d", ch_count);

            strncat(ret, &str[i-1], 1);
            strncat(ret, count, 4);

            ch_count = 1;
        }
        else {
            ch_count++;
        }
    }

    if(strlen(str) < strlen(ret)) {
        return str;
    }

    return ret;
}

int main() {
    char s1[] = "This is a str";

    printf("%s\n", compress_str(s1));
}
