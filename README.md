# Kill GNU

```c
void killGnuPrint(const char * stringNullTerminated);
void * killGnuMalloc(unsigned long bytesCount);
void killGnuFree(void * pointer);

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
  killGnuFree(memory);
}
```

```
cc main.c -nostdinc -nostdlib -fno-stack-protector -fno-asynchronous-unwind-tables killgnu/libkillgnu.a
```
