#include <stdio.h>

size_t strlen(char *str) {
    int len = 0;
    while(*str != '\0') {
        str++;
        len++;
    }
    return len;
}

void reverse_str(char *str) {
    if(str) {
        char *end = str + strlen(str) - 1;
        char c;
        
        while(str < end) {
            c = *end;
            *end = *str;
            *str = c;
            
            str++;
            end--;
        }
    }
}

void reverse_str2(char *str) {
    if(str) {
        size_t len = strlen(str);
        char c;
        
        int i;
        for(i = 0; i < len/2; i++) {
            c = str[len-i-1];
            str[len-i-1] = str[i];
            str[i] = c;
        }
    }
}

int main() {
    char str[] = "hello";
    reverse_str(str);
    puts(str);
    reverse_str2(str);
    puts(str);
}
