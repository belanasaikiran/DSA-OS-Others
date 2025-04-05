## System Call vs Library Call:



- Syscall is something a process wants to request from an OS.
- OS doesn't directly allow a process to access the hardware so that a system call can be used to handle.

In linux, type `man syscall`.



### strace

trace system calls and signals

>  In  the  simplest  case strace runs the specified command until it
      exits.  It intercepts and  records  the  system  calls  which  are
      called  by  a  process  and  the  signals  which are received by a
      process.  The name of each system call, its arguments and its  re‐
      turn  value are printed on standard error or to the file specified
      with the -o option.


- try writing a basic hello.c

compile -> `clang hello.c`

run -> `strace a.out`

You will observe all the system calls made while executiing this code. You will find the hello somewhere.


```bash

[sanju@xps Strace]$ strace -c ./write_file 
starting program
Done
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 57.97    0.000880          14        61           mmap
 13.24    0.000201          12        16           openat
  8.56    0.000130           8        16           mprotect
  5.60    0.000085           6        13           read
  5.34    0.000081           4        17           fstat
  5.14    0.000078           4        16           close
  1.25    0.000019           4         4           munmap
  0.92    0.000014          14         1           set_robust_list
  0.86    0.000013           6         2           pread64
  0.40    0.000006           6         1           arch_prctl
  0.40    0.000006           6         1           set_tid_address
  0.33    0.000005           5         1           rseq
  0.00    0.000000           0         3           write
  0.00    0.000000           0         3           brk
  0.00    0.000000           0         1           access
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         1           readlink
  0.00    0.000000           0         1           futex
  0.00    0.000000           0         1           prlimit64
  0.00    0.000000           0         1           getrandom
------ ----------- ----------- --------- --------- ----------------
100.00    0.001518           9       161           total

```

> Learn more about `strace` at [https://www.youtube.com/watch?v=mBfurelWwPQ](https://www.youtube.com/watch?v=mBfurelWwPQ)

try runnning an assembly version - generate with `gcc -S hello.c` to get hello.s

### ltrace
Try running with `ltrace`

Note: `printf` is a library call not a syscall.
