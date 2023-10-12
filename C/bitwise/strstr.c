#include <stdio.h>
#include <stdbool.h>

const char* my_strstr(const char* haystack, const char* needle) {
    while (*haystack != '\0') {
        const char* h = haystack;
        const char* n = needle;
        
        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }
        
        if (*n == '\0') {
            return haystack;
        }
        
        haystack++;
    }
    
    return NULL;
}

int main() {
    const char* haystack = "Hello, World!";
    const char* needle = "World";
    
    const char* result = my_strstr(haystack, needle);
    
    if (result) {
        printf("Needle found at index: %ld\n", result - haystack);
    } else {
        printf("Needle not found in haystack.\n");
    }

    return 0;
}
