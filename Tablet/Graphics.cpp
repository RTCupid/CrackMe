#include <stdio.h>
#include <string.h>

#include "TXLib.h"
#include "../common/colors.h"
#include "Graphics.h"

void Graphics()
{
    txCreateWindow (950, 526);

    HDC image = txLoadImage ("./bmp/1.bmp", 950, 526);

    txBitBlt (txDC (), 0, 0, 0, 0, image);                          // + screen wallpaper
}

char* InputNameOfFile ()
{
    const char* InputString = txInputBox ("Enter file to hack:\n", "Hacker.com", "loh");

    printf (GRN "string =\"%s\"\n" RESET, InputString);

    char* InputNameFile = (char*) calloc (31, sizeof (*InputNameFile));
    if (InputNameFile == NULL)
    {
        printf (RED "ERROR: InputNameOfFile (): CALLOC RETURN NULL\n" RESET);
        return NULL;
    }

    strncpy (InputNameFile, InputString, 30);

    return InputNameFile;
}

bool CheckNameOfFile (char* InputNameFile)
{
    if (!strcmp (InputNameFile, "DimaMorg/CRACKME.COM"))
    {
        return 1;
    }
    txSelectFont ("Times New Roman", 60);
    txTextOut (240, 400, "ERROR: unknown file");

    return 0;
}

void CorrectFile ()
{
    txSelectFont ("Times New Roman", 60);
    txTextOut    (240, 400, "I HACK IT!");
}
