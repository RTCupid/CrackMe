#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/colors.h"
#include "../FreadFile/FreadFile.h"
#include "Tablet.h"
#include "../common/crack.h"

bool Tablet (patch_t patch, inpt_t* input)
{
    int ptr     = 0;
    int byte    = 0;
    int endfile = 0;

    while (1)
    {
        endfile = fscanf (patch.file, "%d", &ptr);
        if (endfile == EOF)
        {
            break;
        }
        fscanf (patch.file, "%d", &byte);

        (input->buffer)[ptr] = char(byte);
    }

    FILE* Hacked_file = fopen ("DimaMorg/HACKED_CRACKME.COM", "w");

    fwrite (input->buffer, sizeof (char), input->size, Hacked_file); // write hacking code to new file

    fclose (Hacked_file);

    return 1;
}
