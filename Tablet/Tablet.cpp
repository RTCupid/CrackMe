#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/colors.h"
#include "../FreadFile/FreadFile.h"
#include "Tablet.h"

bool Tablet (FILE* PatchingFile, const char* namefile)
{
    char* HackBuffer = NULL;

    struct MP Ongn                                                  // buffer's structure
    {
        &HackBuffer,
        0,
        namefile,
    };

    if (!InputOnegin (&Ongn))                                       // func to find len of file
    {                                                               // and make buffer from file
        printf (RED "ERROR: CAN'T MAKE BUFFER FROM FILE" RESET);
        return 0;
    }

    //printf (GRN "%s\n" RESET, *Ongn.HackBuffer);                    // this operation doesn't work correctly

    int ptr     = 0;
    int byte    = 0;
    int endfile = 0;

    while (1)
    {
        endfile = fscanf (PatchingFile, "%d", &ptr);
        if (endfile == EOF)
        {
            break;
        }
        fscanf (PatchingFile, "%d", &byte);

        (*Ongn.HackBuffer)[ptr] = char(byte);
    }

    FILE* Hacked_file = fopen ("DimaMorg/HACKED_CRACKME.COM", "w");

    fwrite (*Ongn.HackBuffer, sizeof (char), Ongn.sizeOfFile, Hacked_file); // write hacking code to new file

    fclose (Hacked_file);

    free (*Ongn.HackBuffer);

    return 1;
}
