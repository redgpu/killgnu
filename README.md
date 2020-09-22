# Kill GNU

```c
#include "killgnu/killgnu.h"

int main(int ArgsCount, const char ** Args) {
  unsigned * memory = (unsigned *)killGnuMalloc(6 * sizeof(unsigned));
  memory[0] = 4;
  memory[1] = 8;
  memory[2] = 15;
  memory[3] = 16;
  memory[4] = 23;
  memory[5] = 42;
  killGnuPrint("Hello, World!\n");
  for (unsigned i = 0; i < ArgsCount; i += 1) {
    killGnuPrint("Arg: ");
    killGnuPrint(Args[i]);
    killGnuPrint("\n");
  }
  {
    int fd = killGnuOpen("/tmp/killgnu", 02 | 0100, 0400 | 0200);
    if (fd < 0) {
      killGnuPrint("killGnuOpen write: fd < 0\n");
    }
    killGnuPwrite(fd, memory, 6 * sizeof(unsigned), 0);
    killGnuClose(fd);
#if 0
    $ xxd -b /tmp/killgnu
    00000000: 00000100 00000000 00000000 00000000 00001000 00000000  ......
    00000006: 00000000 00000000 00001111 00000000 00000000 00000000  ......
    0000000c: 00010000 00000000 00000000 00000000 00010111 00000000  ......
    00000012: 00000000 00000000 00101010 00000000 00000000 00000000  ..*...
#endif
  }
  {
    int fd = killGnuOpen("/tmp/killgnu", 02, 0400 | 0200);
    if (fd < 0) {
      killGnuPrint("killGnuOpen read: fd < 0\n");
    }
    int lastNumber = 0;
    KillGnuFileStatus fileStatus = {};
    killGnuFstat(fd, &fileStatus);
    killGnuPread(fd, &lastNumber, 1 * sizeof(unsigned), fileStatus.st_size - (1 * sizeof(unsigned)));
    killGnuClose(fd);
    if (lastNumber != 42) {
      killGnuPrint("lastNumber != 42\n");
    }
  }
  killGnuFree(memory);
}
```

```
cc main.c -nostdinc -nostdlib -fno-stack-protector -fno-asynchronous-unwind-tables killgnu/libkillgnu.a
```

```
$ valgrind ./a.out 
==3224== Memcheck, a memory error detector
==3224== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==3224== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==3224== Command: ./a.out
==3224== 
Hello, World!
Arg: ./a.out
==3224== 
==3224== HEAP SUMMARY:
==3224==     in use at exit: 0 bytes in 0 blocks
==3224==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==3224== 
==3224== All heap blocks were freed -- no leaks are possible
==3224== 
==3224== For counts of detected and suppressed errors, rerun with: -v
==3224== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
