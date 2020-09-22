#pragma once

typedef struct KillGnuFileStatus {
  long     st_dev;
  long     st_ino;
  unsigned st_nlink;
  unsigned st_mode;
  unsigned st_uid;
  unsigned st_gid;
  unsigned __pad0;
  long     st_rdev;
  long     st_size;
  long     st_blksize;
  long     st_blocks;
  struct {long tv_sec; long tv_nsec;} st_atim;
  struct {long tv_sec; long tv_nsec;} st_mtim;
  struct {long tv_sec; long tv_nsec;} st_ctim;
  long     __unused[3];
} KillGnuFileStatus;

void   killGnuPrint  (const char * stringNullTerminated);
void * killGnuMalloc (unsigned long bytesCount);
void   killGnuFree   (void * pointer);
int    killGnuOpen   (const char * path, int flags, int mode);
int    killGnuClose  (int fd);
long   killGnuPread  (int fd, void * outBuffer, unsigned long fdBytesCount, long fdBytesFirst);
long   killGnuPwrite (int fd, const void * buffer, unsigned long bufferBytesCount, long fdBytesFirst);
int    killGnuFstat  (int fd, KillGnuFileStatus * outFileStatus);
