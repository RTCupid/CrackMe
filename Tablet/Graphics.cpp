#include <stdio.h>
#include <string.h>

#include "TXLib.h"
#include "../common/colors.h"
#include "Graphics.h"

void Graphics(const char* wallpaper)
{
    txCreateWindow (950, 526);

    HDC image = txLoadImage (wallpaper, 950, 526);

    txBitBlt (txDC (), 0, 0, 0, 0, image);                          // + screen wallpaper
}

char* InputNameOfFile ()
{
    const char* InputString = txInputBox ("Enter file to hack:\n", "Hacker.com");

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
    txSetColor (TX_RED);
    txSelectFont ("Times New Roman", 45);
    txTextOut (240, 400, "ERROR: ERROR: ERROR: ERROR");
    txTextOut (240, 445, "ERROR: ERROR: unknown file");

    return 0;
}

void CorrectFile ()
{
    txSetColor (TX_GREEN);
    txSelectFont ("Times New Roman", 45);
    txTextOut    (400, 400, "I HACK IT!");
}
