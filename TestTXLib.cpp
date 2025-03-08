#include "TXLib.h"

int main()
    {
    txCreateWindow (800, 600);

    txLine   (320, 290, 320, 220);
    txLine   (320, 290, 280, 350);
    txLine   (320, 290, 360, 350);
    txLine   (320, 230, 270, 275);
    txLine   (320, 230, 400, 220);
    txCircle (320, 190, 30);

    txSelectFont ("Times New Roman", 60);
    txTextOut (240, 400, "Hello, world!");

    return 0;
    }
