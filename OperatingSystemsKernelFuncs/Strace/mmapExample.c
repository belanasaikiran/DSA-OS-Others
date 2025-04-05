#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>

// MMAP:
//  Map file or devices into memory
#define PAGESIZE 4096


// It is better to use mmap instead of using brk. it is better than malloc.
int main(){
    uint8_t *first = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    uint8_t *second = mmap(NULL, 4*PAGESIZE, PROT_READ, MAP_PRIVATE, -1, 0); // mapping for pages

    printf("First: %p\n", first); // printing address of mmap
    printf("second: %p\n", second);
}
