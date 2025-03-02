#include <stdio.h>
#include <stdint.h>

uint64_t HashCounterBuf (const char* buffer, size_t size);

int main ()
{
    const char* password = "KOGORTASPIRT";

    uint64_t Hash = HashCounterBuf (password, 12);

    printf ("Hash = %lu\n", Hash);

    return (0);
}


uint64_t HashCounterBuf (const char* buffer, size_t size)
{
    uint64_t hash = 5381;
    for (size_t i = 0; i < size; i++)
        {
        hash = hash * 33 ^ buffer[i];
        }
    return hash;
}
