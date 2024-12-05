# README

Tutorial Link: [https://www.youtube.com/watch?v=Dq8l1_-QgAc&t=194s]

1. To compile, run `gcc -o main main.c -g`

> `-g` flag retains the debug info in the executable and if we use `-c` flag, it won't do that


2. To start debugging, we can run `gdb main`, just call the executable. 

3. to see the code and instructions line by line, run `lay next`

4. add break statement -> `break main` 

> `main` is the function name I want to put a break point at, I can put it for any function and multiple break points.

5. we can now run the program with the set break points for debugging. Just type `run` to start debugging.

6. Now, to go to next instruction, type `nexti`. To go to next line, just hit `next`

7. if you find an error, you can examine the PC with running `x/i $pc`

8. To see the registers state, you can run `info registers` to know what the state of registers are to see what it should've been. 

9. The given bug.c has a bug in scanf - main.c has correct code. 


Also, the link I pasted above, the same guy has an another video where he tells how to debug the segmentation fault (Core dumped) error. He analyses the core file.  
