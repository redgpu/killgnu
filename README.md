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
    if (fd == -1) {
      killGnuPrint("killGnuOpen write: fd == -1\n");
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
    if (fd == -1) {
      killGnuPrint("killGnuOpen read: fd == -1\n");
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
