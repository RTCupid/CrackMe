#ifndef CRACK_H
#define CRACK_H

typedef struct patch_t
{
    char* name;
    size_t hash;
    FILE* file;
} patch_t;

typedef struct inpt_t
{
    char* name;
    size_t hash;
    char* buffer;
    size_t size;
} inpt_t;

const size_t MAX_LEN_NAME_FILE= 30;

bool   CheckArgc (int argc);

bool   PatchCtor (patch_t* patch, char* patch_file);

bool   InptCtor  (inpt_t* input);

size_t HashCount (size_t size, char* buffer);

bool   PatchDtor (patch_t* patch);

bool   InptDtor (inpt_t* input);

#endif
