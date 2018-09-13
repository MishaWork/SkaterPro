#include  "TXlib.h"

void Check (HDC SkatePark);

int main ()
    {
    txCreateWindow (GetSystemMetrics (SM_CXSCREEN), GetSystemMetrics (SM_CYSCREEN));

    HDC SkatePark = txLoadImage ("Images/SkatePark (2).bmp");

    if (SkatePark == NULL) txMessageBox ("SkatePark (2) isn't found");

    Check (SkatePark);

    }

void Check (HDC SkatePark)
    {

    int Frames = 4;

    int SkateParkX = txGetExtentX (SkatePark) / Frames;
    int t = 0;

    while (!GetAsyncKeyState ('C'))
        {
        txClear ();

        txSetFillColor (TX_BLACK);

        //txAlphaBlend (txDC (), 0, 0, SkateParkX, 0, SkatePark, t % Frames * SkateParkX);
          txBitBlt (txDC (), 0, 0, SkateParkX, 0, SkatePark, t % Frames * SkateParkX);


        t++;

        txSleep (200);

        }

    txDeleteDC (SkatePark);
    }
