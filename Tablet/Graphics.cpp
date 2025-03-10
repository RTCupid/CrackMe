#include <stdio.h>
#include <string.h>

#include "TXLib.h"
#include "../common/colors.h"
#include "Graphics.h"

void  LoadHacking ()
{
    for (int i = 2; i <= 7; i++)
    {
        assert (i <=7);

        char namepng[12] = {};
        sprintf (namepng, "./bmp/%d.bmp", i);
        Graphics (namepng);
        txSleep (250);
    }
}

void CreateBaseWindow ()
{
    txCreateWindow (950, 526);
}

void Graphics(const char* wallpaper)
{
    HDC image = txLoadImage (wallpaper, 950, 526);

    txBitBlt (txDC (), 0, 0, 0, 0, image);                          // + screen wallpaper
}

char* InputNameOfFile ()
{
    const char* InputString = txInputBox ("Enter file to hack:\n", "Hacker.com");

    //printf (GRN "string =\"%s\"\n" RESET, InputString);

    char* InputNameFile = (char*) calloc (31, sizeof (*InputNameFile));
    if (InputNameFile == NULL)
    {
        printf (RED "ERROR: InputNameOfFile (): CALLOC RETURN NULL\n" RESET);
        return NULL;
    }

    strncpy (InputNameFile, InputString, 30);

    return InputNameFile;
}

bool  CheckNameOfFile  (char* OriginalNameOfPatchFile, char* InputNameFile)
{
    if (!strcmp (InputNameFile, OriginalNameOfPatchFile))
    {
        return 1;
    }

    Graphics ("bmp/2.bmp");
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
    txTextOut    (300, 400, "HACKING COMPLETED!");
}
