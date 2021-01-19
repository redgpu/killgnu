#pragma once

typedef struct KillGnuTimeSpec {
  long tv_sec;
  long tv_nsec;
} KillGnuTimeSpec;

typedef struct KillGnuUtc {
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
} KillGnuUtc;

typedef struct KillGnuFileStatus {
  long            st_dev;
  long            st_ino;
  unsigned        st_nlink;
  unsigned        st_mode;
  unsigned        st_uid;
  unsigned        st_gid;
  unsigned        __pad0;
  long            st_rdev;
  long            st_size;
  long            st_blksize;
  long            st_blocks;
  KillGnuTimeSpec st_atim;
  KillGnuTimeSpec st_mtim;
  KillGnuTimeSpec st_ctim;
  long            __unused[3];
} KillGnuFileStatus;

void   killGnuPrint                                (const char * stringNullTerminated);
void * killGnuMalloc                               (unsigned long bytesCount);
void   killGnuFree                                 (void * pointer);
int    killGnuOpen                                 (const char * path, int flags, int mode);
int    killGnuClose                                (int fd);
long   killGnuPread                                (int fd, void * outBuffer, unsigned long fdBytesCount, long fdBytesFirst);
long   killGnuPwrite                               (int fd, const void * buffer, unsigned long bufferBytesCount, long fdBytesFirst);
int    killGnuFstat                                (int fd, KillGnuFileStatus * outFileStatus);
int    killGnuClockGetTime                         (int clockId, KillGnuTimeSpec * outTimeSpec);
int    killGnuSecondsToUtc                         (long secondsSinceUnixEpoch, KillGnuUtc * outUtc);
int    killGnuToCharsSInt32d                       (int value, char * outChars);
int    killGnuToCharsUInt32u                       (unsigned value, char * outChars);
int    killGnuToCharsSInt64lld                     (long value, char * outChars);
int    killGnuToCharsUInt64llu                     (unsigned long value, char * outChars);
int    killGnuToCharsSFloat32Dot9g                 (float value, char * outChars);
int    killGnuToCharsSFloat64Dot17g                (double value, char * outChars);
void   killGnuToCharsWithoutNullTerminatorBinary32 (unsigned value32Bit, char * outCharsWithoutNullTerminator);
void   killGnuToCharsWithoutNullTerminatorHex8     (unsigned value32Bit, char * outCharsWithoutNullTerminator);
void   killGnuToCharsWithoutNullTerminatorBinary64 (unsigned long value64Bit, char * outCharsWithoutNullTerminator);
void   killGnuToCharsWithoutNullTerminatorHex16    (unsigned long value64Bit, char * outCharsWithoutNullTerminator);
int    killGnuGetPid                               (void);
int    killGnuGetTid                               (void);
