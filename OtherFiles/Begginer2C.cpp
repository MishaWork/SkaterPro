#include  "TXlib.h"

void HumanDraw (int x, int y, int HandUp, int Legs);
void SkateDraw (int x, int y, int SkateUp);
void HumanMove ();
void SkateMove ();
void HumanAndSkateMove ();
void HumanSkateMove ();

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
    HumanSkateMove ();
    }

void HumanDraw (int x, int y, int HandUp, int Legs)
    {
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

void HumanSkateMove ()
    {
    int xSkate = 90;
    int xHuman = 67;
    int ySkate = 630;
    int yHuman = 700;

    int vX = 5;
    int vY = -7;

    int t = 0;
    while (t < 850)
        {
        txSetFillColour (TX_BLACK);
        txClear ();

        SkateDraw (xSkate, ySkate, t%40*2);

        HumanDraw (xHuman, yHuman, t%40*2, t%4*5);

        txLine (200, 310, 250, 280);
        txLine (250, 280, 400, 280);
        txLine (400, 280, 400, 400);
        txLine (400, 400, 395, 400);
        txCircle (383, 400, 12);
        txLine (383, 400, 370, 400);
        txCircle (110, 400, 12);
        txLine (346, 400, 100, 400);
        txLine (100, 310, 100, 400);
        txLine (100, 310, 200, 310);

        vX = vX + 1;

        xSkate = xSkate + vX;
        ySkate = ySkate + vY;
        if (xSkate <    0) vX = -vX;
        if (xSkate > 1024) vX = -vX;
        if (ySkate <  768) vY = -vY;
        if (ySkate <    0) vY = -vY;

        yHuman = yHuman + vY;
        xHuman = xHuman + vX;
        if (xHuman > 1024) vX = -vX;
        if (xHuman <    0) vX = -vX;
        if (yHuman <  768) vY = -vY;
        if (yHuman <    0) vY = -vY;

        txSleep (100);
        t ++;
        }
    }
