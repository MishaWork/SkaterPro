#include  "TXlib.h"

void HumanDraw (int x, int y, int HandUp, int Legs);
void SkateDraw (int x, int y, int SkateUp);
void HumanMove ();
void SkateMove ();
void HumanAndSkateMove ();
void Moving ();
void RampDraw (int xRamp, int yRamp);
void RampMove (int *xRamp, int *yRamp, int *vRampX, int *vRampY);
void Move (int *x, int *y, int *vX, int *vY);
void KeyControl (int *vX, int *vY);

int main()
    {
    txCreateWindow (1024, 768);

    //HumanDraw (50, 700, 100, 20);
    //HumanDraw (500, 500);
    //SkateDraw (300, 600, 100);
    //SkateDraw (500 ,500);
    //HumanMove ();
    //SkateMove ();
    //HumanAndSkateMove ();
    Moving ();
    }

void HumanDraw (int x, int y, int HandUp, int Legs)
    {
    txSetColor (TX_BROWN);
    txLine (x-Legs, y, x+20, y-50);
    txLine (x+20, y-50, x+50+Legs, y);
    txEllipse (x+5, y-50, x+35, y-130);
    txLine (x+30, y-125, x+60, y-70-HandUp);
    txLine (x+10, y-125, x-20, y-70);
    txCircle (x+20, y-143, 13);
    //x = 50, y = 700
    }

void SkateDraw (int x, int y, int SkateUp)
    {
    txSetColor (TX_RED, 2);
    txLine (x, y-SkateUp, x+100, y-SkateUp);
    txLine (x+100, y-SkateUp, x+70, y+25-SkateUp);
    txLine (x+70, y+25-SkateUp, x-30, y+25-SkateUp);
    txLine (x-30, y+25-SkateUp, x, y-SkateUp);
    txCircle (x, y+32-SkateUp, 7);
    txCircle (x+65, y+32-SkateUp, 7);
    //x = 300, y = 600
    }

void HumanMove ()
    {
    int t = 0;
    while (t < 1000)
        {
        txSetFillColor (TX_BLACK);
        txClear ();

        HumanDraw (4*t+50, 700, t%40*2, t%4*5);

        txSleep (100);
        t ++;
        }
    }

void SkateMove ()
    {
    int t = 0;
    while (t < 850)
        {
        txSetFillColor (TX_BLACK);
        txClear ();

        SkateDraw (4*t+50, 630, t%40*2);

        txSleep (100);
        t ++;
        }
    }

void HumanAndSkateMove ()
    {
    int t = 0;
    while (t < 850)
        {
        txSetFillColour (TX_BLACK);
        txClear ();

        SkateDraw (4*t+50, 630, t%40*2);

        HumanDraw (4*t+50, 700, t%40*2, t%4*5);

        txSleep (100);
        t ++;
        }
    }

void Moving ()
    {
    int xSkate = 70;
    int ySkate = 690;
    int xHuman = 67;
    int yHuman = 700;
    int xRamp = 100;
    int yRamp = 100;


    int vSkateX = 5;
    int vSkateY = 0;
    int vHumanX = 8;
    int vHumanY = 0;
    int vRampX = 2;
    int vRampY = 0;

    int t = 0;
    while (t < 850)
        {
        txSetFillColour (TX_BLACK);
        txClear ();

        SkateDraw (xSkate, ySkate, 0);

        HumanDraw (xHuman, yHuman, 0, 0);

        //RampDraw (xRamp, yRamp);

        KeyControl (&vHumanX, &vHumanY);

        //RampMove (&xRamp, &yRamp, &vRampX, &vRampY);

        Move (&xHuman, &yHuman, &vHumanX, &vHumanY);

        Move (&xSkate, &ySkate, &vSkateX, &vSkateY);

        int distance = sqrt ((xSkate - xHuman)*(xSkate - xHuman) + (ySkate - yHuman)*(ySkate - yHuman));

        if (distance > 45) {txSetColor (TX_GREEN); txSelectFont ("Arial Black", 100, 20, 500); txTextOut (500, 500, "You Have Lost"); }

        txSleep (100);
        t ++;
        }
    }

void RampDraw (int xRamp, int yRamp)
    {
    txLine (xRamp, yRamp+600, xRamp, yRamp+500);
    txLine (xRamp, yRamp+500, xRamp+20, yRamp+500);
    txLine (xRamp+20, yRamp+500, xRamp+90, yRamp+600);
    txLine (xRamp+90, yRamp+600, xRamp, yRamp+600);
    }

void RampMove (int* yRamp, int* xRamp, int* vRampX, int* vRampY)
    {
    *xRamp = *xRamp + *vRampX;
    *yRamp = *yRamp + *vRampY;
    if (GetAsyncKeyState (VK_RIGHT)) *vRampX = 3;
    if (GetAsyncKeyState (VK_LEFT)) *vRampX = -3;
    if (GetAsyncKeyState (VK_UP)) *vRampY = -3;
    if (GetAsyncKeyState (VK_DOWN)) *vRampY = 3;
    if (GetAsyncKeyState (VK_SPACE)) { *vRampX = 0; *vRampY = 0; }
    }

void Move (int* x, int* y, int* vX, int* vY)
    {
    *y = *y + *vY;
    *x = *x + *vX;
    if (*x > 1024) *vX = -*vX;
    if (*x <    0) *vX = -*vX;
    if (*y <  768) *vY = -*vY;
    if (*y <    0) *vY = -*vY;
    }

void KeyControl (int* vX, int* vY)
    {
    if (GetAsyncKeyState (VK_LEFT))  *vX = -10;
    if (GetAsyncKeyState (VK_RIGHT)) *vX =  10;
    if (GetAsyncKeyState (VK_UP))    *vY = -10;
    if (GetAsyncKeyState (VK_DOWN))  *vY =  10;
    }
