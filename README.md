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
  {
    int           minSInt32 = 0b10000000000000000000000000000000;
    unsigned      maxUInt32 = 0b11111111111111111111111111111111;
    long          minSInt64 = 0b1000000000000000000000000000000000000000000000000000000000000000;
    unsigned long maxUInt64 = 0b1111111111111111111111111111111111111111111111111111111111111111;
    char minSInt32Chars[21];
    char maxUInt32Chars[21];
    char minSInt64Chars[21];
    char maxUInt64Chars[21];
    int  minSInt32CharsCount = killGnuToCharsSInt32d(minSInt32, minSInt32Chars);
    int  maxUInt32CharsCount = killGnuToCharsUInt32u(maxUInt32, maxUInt32Chars);
    int  minSInt64CharsCount = killGnuToCharsSInt64lld(minSInt64, minSInt64Chars);
    int  maxUInt64CharsCount = killGnuToCharsUInt64llu(maxUInt64, maxUInt64Chars);
    char minSInt32CharsCountChars[21];
    char maxUInt32CharsCountChars[21];
    char minSInt64CharsCountChars[21];
    char maxUInt64CharsCountChars[21];
    killGnuToCharsSInt32d(minSInt32CharsCount, minSInt32CharsCountChars);
    killGnuToCharsSInt32d(maxUInt32CharsCount, maxUInt32CharsCountChars);
    killGnuToCharsSInt32d(minSInt64CharsCount, minSInt64CharsCountChars);
    killGnuToCharsSInt32d(maxUInt64CharsCount, maxUInt64CharsCountChars);
    {
      killGnuPrint("minSInt32CharsCount: ");
      killGnuPrint(minSInt32CharsCountChars);
      killGnuPrint(", minSInt32 (%d): ");
      killGnuPrint(minSInt32Chars);
      killGnuPrint("\n");
    }
    {
      killGnuPrint("maxUInt32CharsCount: ");
      killGnuPrint(maxUInt32CharsCountChars);
      killGnuPrint(", maxUInt32 (%u): ");
      killGnuPrint(maxUInt32Chars);
      killGnuPrint("\n");
    }
    {
      killGnuPrint("minSInt64CharsCount: ");
      killGnuPrint(minSInt64CharsCountChars);
      killGnuPrint(", minSInt64 (%lld): ");
      killGnuPrint(minSInt64Chars);
      killGnuPrint("\n");
    }
    {
      killGnuPrint("maxUInt64CharsCount: ");
      killGnuPrint(maxUInt64CharsCountChars);
      killGnuPrint(", maxUInt64 (%llu): ");
      killGnuPrint(maxUInt64Chars);
      killGnuPrint("\n");
    }
  }
  {
    float sfloat32 = 1.f / 3.f;
    char  sfloat32Chars[512];
    int   sfloat32CharsCount = killGnuToCharsSFloat32Dot9g(sfloat32, 0);
    char  sfloat32CharsCountChars[21];
    killGnuToCharsSFloat32Dot9g(sfloat32, sfloat32Chars);
    killGnuToCharsSInt32d(sfloat32CharsCount, sfloat32CharsCountChars);
    killGnuPrint("sfloat32CharsCount: ");
    killGnuPrint(sfloat32CharsCountChars);
    killGnuPrint(", sfloat32 (%.9g): ");
    killGnuPrint(sfloat32Chars);
    killGnuPrint("\n");
  }
  {
    int  tid = killGnuGetTid();
    char tidChars[21];
    killGnuToCharsSInt32d(tid, tidChars);
    killGnuPrint("TID: ");
    killGnuPrint(tidChars);
    killGnuPrint("\n");
  }
  {
    int  pid = killGnuGetPid();
    char pidChars[21];
    killGnuToCharsSInt32d(pid, pidChars);
    killGnuPrint("PID: ");
    killGnuPrint(pidChars);
    killGnuPrint("\n");
  }
  {
    unsigned value = 2654435769;
    char     valueCharsInHex[9];
    valueCharsInHex[8] = 0;
    killGnuToCharsWithoutNullTerminatorHex8(value, valueCharsInHex);
    killGnuPrint("2654435769 in hex: 0x");
    killGnuPrint(valueCharsInHex);
    killGnuPrint("\n");
  }
  {
    unsigned long value = 14627333968358199309UL;
    char          valueCharsInHex[17];
    valueCharsInHex[16] = 0;
    killGnuToCharsWithoutNullTerminatorHex16(value, valueCharsInHex);
    killGnuPrint("14627333968358199309 in hex: 0x");
    killGnuPrint(valueCharsInHex);
    killGnuPrint("\n");
  }
  killGnuFree(memory);
}
```

```
cc main.c -nostdinc -nostdlib -fno-stack-protector -fno-asynchronous-unwind-tables killgnu/libkillgnu.a
```

```
$ valgrind ./a.out 
==12085== Memcheck, a memory error detector
==12085== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==12085== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==12085== Command: ./a.out
==12085== 
Hello, World!
Arg: ./a.out
minSInt32CharsCount: 12, minSInt32 (%d): -2147483648
maxUInt32CharsCount: 11, maxUInt32 (%u): 4294967295
minSInt64CharsCount: 21, minSInt64 (%lld): -9223372036854775808
maxUInt64CharsCount: 21, maxUInt64 (%llu): 18446744073709551615
sfloat32CharsCount: 12, sfloat32 (%.9g): 0.333333343
TID: 12085
PID: 12085
2654435769 in hex: 0x9E3779B9
14627333968358199309 in hex: 0xCAFEBABECAFED00D
==12085== 
==12085== HEAP SUMMARY:
==12085==     in use at exit: 0 bytes in 0 blocks
==12085==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==12085== 
==12085== All heap blocks were freed -- no leaks are possible
==12085== 
==12085== For counts of detected and suppressed errors, rerun with: -v
==12085== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
