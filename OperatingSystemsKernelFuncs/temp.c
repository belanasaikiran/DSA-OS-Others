#include<stdio.h>
#include <string.h>

int safe_str_copy(char *dest, const char* src, size_t dest_size){
    if(!dest || !src || dest_size == 0){
        return -1;
    }

    size_t i = 0;
    for(; i < dest_size - 1 && src[i] != '\0'; ++i){
        memmove(&dest[i], &src[i], 1);
    }

    //  last one with null termination
    //
    dest[i] = '\0';
};




int main(){

    char buffer[10];

    const char* source = "Hello World!"; // longer than buffer

    if(safe_str_copy(buffer, source, sizeof(buffer)) == 0){
        printf("Copy Success for: %s\n", buffer);
    } else {
        printf("failed to copy string\n");
    }

    return 0;
}
