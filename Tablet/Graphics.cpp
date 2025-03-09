#include "TXLib.h"

void LoadImageScreenHacker ();

int main()
{
    txCreateWindow (950, 526);

    LoadImageScreenHacker ();                               // + screen wallpaper

    txSetColor (TX_BLACK, 1);
    txSetFillColor	(TX_CYAN);
    txRectangle (325, 460, 625, 380);

    return 0;
}

//-------------------Hacker-Screen-------------------------

void LoadImageScreenHacker ()
{
    HDC image = txLoadImage ("./bmp/1.bmp", 950, 526);

    txBitBlt (txDC (), 0, 0, 0, 0, image);
}
