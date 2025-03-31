### C Versions:

> NOTE for myself: Sanju, if you are having issue understanding whatever you wrote here(haha...), just go through this video and get a good understanding again.
> Video: [https://www.youtube.com/watch?v=9UIIMBqq1D4](https://www.youtube.com/watch?v=9UIIMBqq1D4)

1. C89

- Variables declared at the beginning of a block
- if dealing with structs, we need to enter every element, even if not used, we need to set it to 0.

```c
typedef struct {
    int x;
    int y;
    char z;
} Point;

Point p = { 10, 20, 'A' };
Point q = { 0, 0, 'B' }; // if not using x and y, we still need to declare.
```

2. **C99**

- Anywhere in the scope
- Dealing with Structs, we don't need to enter every element, we can use designated initializers.

  - Allows the specify members as a key value pair

  ```c
  typedef struct {
    int x;
    int y;
    char z;
  } Point;
  // using designated initializers
  Point p = { .x = 10, .y = 20, .z = 'A' };
  Point q = { .z = 'B' }; // if not using x and y, it should be fine.
  ```

```

3. C11
4. C23
```

### Compiler Flags

```bash
clang -std=c99 -Wall -Werror
```

- `-std=c99` - Enables C99 features.
- `-Wall` - Enables all warnings.
- `-Werror` - Treats all warnings as errors.

### Unity Build:

As programs become larger, it is common to have multiple source files.
To compile these files together, we can use a unity build.

> In C, we split the files into header files and source files.
> We can use header files to declare functions and variables, and source files to define them.
> Other files can use the header files to access the functions and variables declared in them.

> We also call this as `include hell`

That's why we need to use build systems like CMake or Meson.

```c
#include "file.h"
// contents of file.h
int globalVariable = 5;
```

If we include the file twice, we will get a duplicate symbol error.

To avoid this, we can use the `#pragma once` directive (single translation unit).

### Debugger:

Use this to stay happy : )

** Seg Fault**

- Very simple
- OS generally allocates memory in virtual memory for us when called functions like `malloc`.
- Segmentation Fault occurs when we try to access memory that we don't have permission to access or when we try to access memory that is not allocated to us.

  ```c
  int main() {
    int *ptr = NULL;
    *ptr = 5;
    return 0;
  }
  ```

````

```bash
# compile the file
clang -std=c99 -Wall -Werror -o main main.c

# run the file
./main
Segmentation fault (core dumped)
````

### Address Sanitization - ASan

Designed to help catch memory corruption issues.

Eg: we can try malloc to allocate memory and then try to access it.

```c
int* intArray = malloc(sizeof(int) * 10);
```

> Notes for Me: I know this is a huge pain, but trust me, you are doing well in advance. These concepts might be hard, but they are pretty interesting.

Malloc is a classic way of creating memory on the heap.

```c
intArray[5] = 8;
intArray[1000] = 2;
intArray[INT32_MAX] = 3;
```

Generally, `c` doesn't do any checks for out-of-bounds access.

```c
void AccesOutOfBounds(void){
    int* intArray = malloc(sizeof(int) * 10);
    intArray[INT32_MAX] = 3;
}
```

if we run it, it will throw an error in runtime.

```c
void IterateItems(void){
    int arrayLength = 10;
    int* intArray = malloc(sizeof(int) * arrayLength);
    for(int i = 0; i < arrayLength; ++i){
        intArray[i] = 5;
    }
}
```

The above program silently corrupts memory.

Address Sanitization (ASan) is a tool that helps detect memory errors at runtime. It can detect issues like accessing uninitialized memory, accessing memory after it has been freed, and accessing memory outside of the bounds of an array.

I think they are developed by Google.

So to avoid these issues, we can use Address Sanitization (ASan) by turning on the flag `-fsanitize=address`.

```bash
clang -std=c99 -Wall -Werror -fsanitize=address -o main main.c
./main
```

It adds a boundary for the memory allocated and checks for out-of-bounds access.

NOTE: ASAN comes with a cost in terms of performance. It adds a layer of indirection to memory accesses, which can slow down your program. However, it's a valuable tool for catching memory errors during development.
Don't use ASAN in production code, as it can significantly impact performance.

### Memory Arenas

When memory is allocated on the heap, it is not automatically organized into
a structured layout. Instead, it is simply a contiguous block of memory that
can be accessed using pointers.

- Memory arenas are a way to organize memory into a structured layout. They
  are a collection of memory blocks that are allocated and managed together.
  They are useful for managing memory in a structured way, and for reducing the
  overhead of memory allocation and deallocation.
- Memory arenas are typically implemented using a linked list of memory
  blocks. Each block contains a header that stores information about the block,
  such as its size and whether it is free or allocated. The blocks are linked
  together using pointers, and the linked list is used to keep track of the
  blocks.
- Memory arenas are useful for managing memory in a structured way, and for
  reducing the overhead of memory allocation and deallocation. They are also
  useful for managing memory in a way that is efficient for the specific needs
  of the application.

```c

typedef struct MemoryArena {
    size_t size;
    struct MemoryArena* next;
} MemoryArena;

MemoryArena* create_arena(size_t size) {
    MemoryArena* arena = malloc(sizeof(MemoryArena));
    arena->size = size;
    arena->next = NULL;
    return arena;
}

void destroy_arena(MemoryArena* arena) {
    MemoryArena* current = arena;
    MemoryArena* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
```

**One Lifetime**:
Instead of calling `malloc` on every single variable you need, we can call `malloc` for the entire arena and then divide it into smaller blocks. This reduces the overhead of memory allocation and deallocation.

> NOTE: Sanju, if you're not understanding this, go through the video again.
