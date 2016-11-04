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

int main() {
    char str[] = "hello";
    reverse_str(str);
    puts(str);
}
