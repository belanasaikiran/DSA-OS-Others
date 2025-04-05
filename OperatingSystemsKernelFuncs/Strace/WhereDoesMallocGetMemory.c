#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// When running this program with `strace` you can observe the brk.
// **brk:** It's like the boundary which grows/shrinks as you allocate and de-allocate memory in your programs.
//
// check `man brk`
//
// There is also `sbrk` which a wrapper around brk which instead of using address, it uses increment.

// sbrk returns the previous break


int main(){
    for(int i = 0; i < 5; i++){
        char *ptr = malloc(50000);
        printf("Got Memory! (Address=%p)\n", ptr);

        // free(ptr);
        // printf("Free Memory! (Address=%p)\n", ptr);
        // ptr = NULL; // free the pointer also
    }


    // sbrk:
    void* first = sbrk(0);
    void* second = sbrk(4096);
    void* third = sbrk(0);

    // it generally use 4k due to modern paging size in virtual memory.
    printf("First: %p\n", first);
    printf("second: %p\n", second);
    printf("third: %p\n", third);


}
