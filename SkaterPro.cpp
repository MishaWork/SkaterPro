//  1  разные фоны по которым будет ехать скейтер.
//  2  препятствие скейтеру, при столкнавении с которым он бы терял очки или проигрывал.
//  3  скейтер доезжает до конца экрана, то сменяется фон и скейтер телепортируется на начало экрана.

#include  "TXlib.h"

//=+=+=+=+===+=+=+=+=

void SkateMove (int *SktX, int *SktY);
int Moving ();
void SkaterMove (int *SktrX, int *SktrY);
int Distance (int SktrX, int SktrY, int SktX, int SktY);
void ScoreBoard (int Score, int TimeStart);
void Text (int TextX, int TextY, char TextOut []);
void Levels (int *Level, int *SktrX, int *SktX);
void Drawing (HDC SktrP, int SktrPx, int SktrPy, int SktrPX, HDC Bench, int BenchX, HDC City, int CityX, int Frames, int *Level, int *t);
void MakingMeasuring (int *Level, int Dist, int GshThy, int GshThx, HDC GshTh, int GshNx, int GshNy, int GshN2, HDC GshN, int GshX, int GshY, HDC Gsh, char TextOut [], int *Score, int *t);
void ShowingHelp ();
int Ending (int Score);

//=+=+=+=+===+=+=+=+=

int main ()
    {

     //_txWindowStyle &= ~WS_CAPTION; // FullScreen: окно без заголовка, размером с экран
    txCreateWindow (GetSystemMetrics (SM_CXSCREEN), GetSystemMetrics (SM_CYSCREEN));


    while (2 > 1)
        {
        ShowingHelp ();

        int Score = Moving ();

        int ButtonNumber = Ending (Score);
        if (ButtonNumber == 1) break;
        }
    }

//=+=+=+=+===+=+=+=+=

void ShowingHelp ()
    {
    HDC Rules = txLoadImage ("Images/GameRules.bmp");
    if (Rules == NULL) printf ("Images/GameRules.bmp isn't found");

    txBitBlt (txDC (), 0, 0, 0, 0, Rules);

    int ButtonX = 805;
    int ButtonY = 910;

    while (2 > 1)
        {
        int MouseX = txMouseX ();
        int MouseY = txMouseY ();

        //если расстояние меньше 200 и нажата левая кнопка мыши, то цикл прерывается.

        if (Distance (ButtonX, ButtonY, MouseX, MouseY) < 200 && txMouseButtons () == 1)
            {
            break;
            }
        }

    txDeleteDC (Rules);

    }

//=+=+=+=+===+=+=+=+=

int Ending (int Score)
    {

    HDC End = txLoadImage ("Images/Ending.bmp");
    if (End == NULL) printf ("Images/Ending.bmp isn't found");

    if (Score > 20) txBitBlt (txDC (), 0, 0, 0, 0, End);

    txSleep (100);

    int ButtonX1 = 620;
    int ButtonY1 = 880;

    int ButtonX2 = 1280;
    int ButtonY2 = 880;

    int ButtonNumber = 0;

    while (2 > 1)
        {

        int MouseX = txMouseX ();
        int MouseY = txMouseY ();

        if (Distance (ButtonX1, ButtonY1, MouseX, MouseY) < 200 && txMouseButtons () == 1)
            {
            printf ("ты нажал толстым пальцем на кнопку 1");
            ButtonNumber = 1;
            break;
            }

        if (Distance (ButtonX2, ButtonY2, MouseX, MouseY) < 200 && txMouseButtons () == 1)
            {
            printf ("ты нажал толстым пальцем на кнопку 2");
            ButtonNumber = 2;
            break;
            }


        }

    txDeleteDC (End);

    return ButtonNumber;

    }

//=+=+=+=+===+=+=+=+=

int Moving ()
    {
    HDC Sktr2 = txLoadImage ("Images/SkaterTWO.bmp");
    if (Sktr2 == NULL) printf ("Images/SkaterTWO isn't found");
    //HDC Sktr = txLoadImage ("SkaterAlpha.bmp");
    //if (Sktr == NULL) printf ("SkaterAlpha.bmp isn't found");
    //HDC SktrN = txLoadImage ("SkaterAlphaNew.bmp");
    //if (SktrN == NULL) printf ("SkaterAlphaNew isn't found");

    HDC Skt = txLoadImage ("Images/SkateAlpha.bmp");
    if (Skt == NULL) printf ("Images/SkateAlpha.bmp isn't found");
    HDC Gsh = txLoadImage ("Images/GaishnikAlpha.bmp");
    if (Gsh == NULL) printf ("Images/GaishnikAlpha.bmp isn't found");
    HDC SktrP = txLoadImage ("Images/SkatePark (2).bmp");
    if (SktrP == NULL) printf ("Images/SkatePark (2).bmp isn't found");
    HDC GshN = txLoadImage ("Images/GaishnikNEW2.bmp");
    if (GshN == NULL) printf ("Images/GaishnikNEW2.bmp isn't found");
    HDC GshTh = txLoadImage ("Images/GaishnikThree.bmp");
    if (GshTh == NULL) printf ("Images/GaishnikThree.bmp isn't found");

    HDC Mash = txLoadImage ("Images/MaMin Men.bmp");
    if (Mash == NULL) printf ("Images/MaMin Men.bmp isnt't found");

    HDC Cat = txLoadImage ("Images/Cat.bmp");
    if (Cat == NULL) printf ("Images/Cat.bmp isnt't found");

    HDC Bench = txLoadImage ("Images/Bench.bmp");
    if (Bench == NULL) printf ("Images/Bench.bmp isn't found");

    HDC City = txLoadImage ("Images/CityWallpaper.bmp");
    if (City == NULL) printf ("Images/CityWallpaper.bmp isn't found");


    int Sktr2x = txGetExtentX (Sktr2) / 4;

    //printf ("Skater2x = %d\n", Sktr2x);

    int GshN2 = txGetExtentX (GshN) / 2;

    int Mash2 = txGetExtentX (Mash) / 2;

    int Catt = txGetExtentX (Cat) / 2;

    int Catx = 0;
    int Caty = 0;

    int SktrPX = txGetExtentX (SktrP) / 4;

    int SktX = 100;
    int SktY = 639;

    int SktrX = 100;
    int SktrY = 639;
    int TimeStart = GetTickCount ();
    int Score = 0;

    int GshX = 1100;
    int GshY = 650;

    int CityX = txGetExtentX (City)/ 4;

    int Frames = 3;

    int BenchX = txGetExtentX (Bench) / Frames;

    int SktrPx = 0;
    int SktrPy = 0;

    int GshNx = 1500;
    int GshNy = 590;

    int GshThx = 1250;
    int GshThy = 700;

    int MashX = 1350;
    int MashY = 600;

    int TextX = 900;
    int TextY = 950;

    char TextOut [100] = "я убил касулю";

    int t = 0;

    int Level = 1;

    while (!GetAsyncKeyState ('C'))
        {
        txSetFillColor (TX_BLACK);

        txClear();

        Drawing (SktrP, SktrPx, SktrPy, SktrPX,
                 Bench, BenchX,
                 City,  CityX,
                 Frames, &Level, &t);


        txAlphaBlend (txDC (), SktrX-334, SktrY-639, Sktr2x, 0, Sktr2, t / 5 % 4 * 730, 0);

        txAlphaBlend (txDC (), Catx, Caty, Catt, 0, Cat, t / 30 % 2 * 1300, 0);

        //if (t % 2)
            {
            //txAlphaBlend (SktrX-334, SktrY-639, SktrN, 0, 0);
            }
        //else txAlphaBlend (SktrX-334, SktrY-639, Sktr, 0, 0);

        //t =         0, 1,   2, 3,   4,   5, 6,   7, 8,   9, 10

        //t % 2 =       0, 1,   0, 1,   0,   1, 0,   1, 0,   1,  0

        //t % 2 * 730 = 0, 730, 0, 730, 0, 730, 0, 730, 0, 730,  0

        txAlphaBlend (SktX-270, SktY-13, Skt, 0, 0);
        txSetFillColor (TX_NULL);
        txSetColor (TX_PINK, 5);
        txCircle (SktX, SktY, 6);
        txSetColor (TX_RED, 5);
        txCircle (SktrX, SktrY, 10);

        SkateMove (&SktX, &SktY);

        SkaterMove (&SktrX, &SktrY);

        int Dist = Distance (SktrX, SktrY, SktX, SktY);

        txAlphaBlend (txDC (), MashX, MashY, Mash2, 0, Mash, t / 5 % 2 * 227, 0);

        MakingMeasuring (&Level, Dist, GshThx, GshThy, GshTh, GshNx, GshNy, GshN2, GshN, GshX, GshY, Gsh, TextOut, &Score, &t);
        //void MakingMeasuring (int *Level, int Dist, int GshThx, int GshThy, HDC GshTh, int GshNx, int GshNy, int GshN2, HDC GshN, int GshX, int GshY, HDC Gsh, char TextOut [], int *Score, int *t);

        /*
        int distance = Distance (&SktrX, &SktrY, &SktX, &SktY);

        if (distance > 40)
            {
            txSetColor (TX_GREEN);
            txSelectFont ("Arial Black", 100, 20, 500);
            txTextOut (500, 500, "You Have Lost");
            }

        printf ("я убил\n %d", distance);
         */
        ScoreBoard (Score, (GetTickCount () - TimeStart) / 1000);

        if (Score > 200)
            {
            strcpy (TextOut, "Как все звпущеноооо");
            Text (TextX, TextY, TextOut);
            break;
            }

        Text (TextX, TextY, TextOut);

        Levels (&Level, &SktrX, &SktX);

        //Drawing (HDC SktrP, int SktrPx, int SktrPy, int SktrPX, HDC Bench, int BenchX, HDC City, int CityX, int Frames, int *Level, int *t);


        //printf ("Я убил касулю %d\n",  Dist);

        txSleep (10);

        //printf ("я убил касулю\n %d", SktX, SktY);

        //printf ("Time %d, Score %d\n" , (GetTickCount () - TimeStart) / 1000, ScoreBoard);

        if ((GetTickCount () - TimeStart) / 1000 > 60)
            {
            txSetColor (TX_ORANGE);
            txSelectFont ("Arial Black", 100, 20, 500);
            txTextOut (500, 500, "You Won!!");
            break;
            }

        t++;

        }

    txDeleteDC (Sktr2);
    txDeleteDC (Skt);
    txDeleteDC (Gsh);
    txDeleteDC (SktrP);
    txDeleteDC (GshN);
    txDeleteDC (GshTh);
    txDeleteDC (Mash);
    txDeleteDC (Cat);
    txDeleteDC (Bench);
    txDeleteDC (City);

    return Score;
    }

//=+=+=+=+===+=+=+=+=

void SkateMove (int* SktX, int* SktY)
    {
    if (GetAsyncKeyState ('D')) *SktX = *SktX + 5;
    if (GetAsyncKeyState ('A')) *SktX = *SktX - 5;
    if (GetAsyncKeyState ('W')) *SktY = *SktY - 5;
    if (GetAsyncKeyState ('S')) *SktY = *SktY + 5;
    }

//=+=+=+=+===+=+=+=+=

void SkaterMove (int* SktrX, int* SktrY)
    {
    if (GetAsyncKeyState (VK_RIGHT)) *SktrX = *SktrX + 6;
    if (GetAsyncKeyState (VK_LEFT))  *SktrX = *SktrX - 6;
    if (GetAsyncKeyState (VK_UP))    *SktrY = *SktrY + 6;
    if (GetAsyncKeyState (VK_DOWN))  *SktrY = *SktrY - 6;
    }

//=+=+=+=+===+=+=+=+=

int Distance (int X1, int Y1, int X2, int Y2)
    {
    return sqrt ((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
    }

//=+=+=+=+===+=+=+=+=

void ScoreBoard (int Score, int Time)
    {
    txSetColor (TX_ORANGE, 8);
    txRectangle (1600, 10, 1400, 110);
    txLine (1500, 10, 1500, 110);
    txSelectFont ("Fixedsys", 100, 20, 100);
    txSetTextAlign (TA_CENTER);

    if (Score > 200)
        {
        txSetColor (TX_LIGHTRED);
        txSelectFont ("Fixedsys", 100, 20, 500);
        txTextOut (1500, 200, "YOU HAVE LOST");
        }


    char StrTime [30] = "";
    sprintf (StrTime, "%d", Time);
    txTextOut (1440, 15, StrTime);

    char StrScore [15] = "";
    sprintf (StrScore, "%d", Score);
    txTextOut (1540, 15, StrScore);

    txTextOut (1440, 110, "Time");
    txTextOut (1560, 110, "Score");
    //printf ("Score %d\n", Score);
    }

//=+=+=+=+===+=+=+=+=

void Text (int TextX, int TextY, char TextOut [])
    {
    txSetColor   (TX_BLACK);
    txSelectFont ("Fixedsys", 50, 20, 500);
    txTextOut    (TextX + 2, TextY, TextOut);
    txTextOut    (TextX - 2, TextY, TextOut);
    txTextOut    (TextX,     TextY + 2, TextOut);
    txTextOut    (TextX,     TextY - 2, TextOut);
    txSetColor   (TX_WHITE);
    txTextOut    (TextX, TextY, TextOut);
    }

//=+=+=+=+===+=+=+=+=

void Levels (int* Level, int* SktrX, int* SktX)
    {

    if (*SktrX >= 1680 && *Level == 1)   //перемещает скейтера со скейтом в начало экрана
        {                               //сменяет уровень 1 на уровень 2
        *Level = 2;
        *SktrX = 100;
        *SktX = 100;
        printf ("вы перешли на уровень 2\n");
        }

    if (*SktrX >= 1680 && *Level == 2)   //перемещает скейтера со скейтом в начало экрана
        {                                //сменяет уровень 2 на уровень 3
        *Level = 3;
        *SktrX = 100;
        *SktX = 100;
        printf ("вы перешли на уровень 3\n %d");
        }


    if (*SktrX >= 1680 && *Level == 3)   //перещает скейтера со скейтом в начало экрана
        {                                //сменяет уровень 3 на уровень 1
        *Level = 1;
        *SktrX = 100;
        *SktX = 100;
        printf ("вы перешли на уровень 1\n %d");
        }

    }

//=+=+=+=+===+=+=+=+=

void Drawing (HDC SktrP, int SktrPx, int SktrPy, int SktrPX, HDC Bench, int BenchX, HDC City, int CityX, int Frames, int* Level, int* t)
    {
    if (*Level == 1)
        {
        txBitBlt (txDC (), 0, 0, SktrPX, 0, SktrP, *t / 10 % 4 * 1680, 0);
        }

    if (*Level == 2)
        {
        txBitBlt (txDC (), 0, 0, BenchX, 0, Bench, *t / 35 % Frames * 1680, 0);
        }

    if (*Level == 3)
        {
        txBitBlt (txDC (), 0, 0, CityX, 0, City, *t / 35 % 4 * 1680, 0);
        }
    }

//=+=+=+=+===+=+=+=+=

void MakingMeasuring (int* Level, int Dist, int GshThy, int GshThx, HDC GshTh, int GshNx, int GshNy, int GshN2, HDC GshN, int GshX, int GshY, HDC Gsh, char TextOut [], int* Score, int* t)
    {

    if (Dist < 40 && Dist > 20)
        {
        txAlphaBlend (GshThx, GshThy, GshTh, 0, 0, 0);
        strcpy (TextOut, "фигаа ты лооох");
        }

    if (Dist < 20)
        {
        txAlphaBlend (txDC (), GshNx, GshNy, GshN2, 0, GshN, *t / 5 % 2 * 121, 0);
        }


    if (Dist > 40)
        {
        txSetColor (TX_GREEN);
        txSelectFont ("Arial Black", 100, 20, 500);
        txAlphaBlend (GshX, GshY, Gsh, 0, 0);
        *Score = *Score + 1;
        strcpy (TextOut, "Вы потеряли телевизор");
        //*Level = 2;
        }
    }


