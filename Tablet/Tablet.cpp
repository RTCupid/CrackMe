#include <stdio.h>
#include <stdlib.h>

#include "../common/colors.h"
#include "../FreadFile/FreadFile.h"
#include "Tablet.h"

bool Tablet (const char* namefile)
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

    printf (GRN "%s\n" RESET, *Ongn.HackBuffer);                    // this operation doesn't work correctly

    (*Ongn.HackBuffer)[103] = char(104);                            // call -> push in CRACKME.COM
    (*Ongn.HackBuffer)[104] = char(107);                            // ptr to func that
    (*Ongn.HackBuffer)[105] = char(1);                              // gives admin rights
                                                                    // because next operator is ret

    FILE* Hacked_file = fopen ("DimaMorg/HACKED_CRACKME.COM", "w");

    fwrite (*Ongn.HackBuffer, sizeof (char), Ongn.sizeOfFile, Hacked_file); // write hacking code to new file

    fclose (Hacked_file);

    free (*Ongn.HackBuffer);

    return 1;
}
