#ifndef FREADFILE_H
#define FREADFILE_H

#include <sys/types.h>
#include <sys/stat.h>

struct MP
{
    char** HackBuffer;
    size_t sizeOfFile;
    const char* nameFile;
};

size_t InputOnegin (MP* ongn);

bool   SizeFile (struct stat* fileInf, const char* nameFile);

#endif
