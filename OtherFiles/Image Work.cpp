// TODO  1 ���� ������� ������ ���� �� ������� ����� ����� �������.
// TODO  2 ������� ����������� ��������, ��� ������������ � ������� �� �� ����� ���� ��� ����������.
// TODO  3 ������ ���, ��� ���� ������� �������� �� ����� ������, �� ��������� ��� � ������� ��������������� �� ������ ������.
#include  "TXlib.h"

void SkateMove (int *SktX, int *SktY);
void Moving ();
void SkaterMove (int *SktrX, int *SktrY);
int Distance (int SktrX, int SktrY, int SktX, int SktY);
void ScoreBoard (int Score, int TimeStart);
void Text (int TextX, int TextY, char TextOut []);
void Levels (int *Level, int *SktrX, int *SktX);
void Drawing (HDC SktrP, int SktrPx, int SktrPy, int SktrPX, HDC Bench, int BenchX, HDC City, int CityX, int Frames, int *Level, int *t);
void MakingMeasuring (int *Level, int Dist, int GshThy, int GshThx, HDC GshTh, int GshNx, int GshNy, int GshN2, HDC GshN, int GshX, int GshY, HDC Gsh, char TextOut [], int *Score, int *t);
void ShowingHelp ();

int main ()
    {

     //_txWindowStyle &= ~WS_CAPTION; // FullScreen: ���� ��� ���������, �������� � �����
    txCreateWindow (GetSystemMetrics (SM_CXSCREEN), GetSystemMetrics (SM_CYSCREEN));

    ShowingHelp ();
    Moving ();
    }

void ShowingHelp ()
    {
    HDC Rules = txLoadImage ("GameRules.bmp");
    if (Rules == NULL) printf ("Rules.bmp isn't found");

    txAlphaBlend (txDC (), 0, 0, 0, 0, Rules);

    int ButtonX = 805;
    int ButtonY = 910;





    while (2 > 1)
        {
        int MouseX = txMouseX ();
        int MouseY = txMouseY ();

        //���� ���������� ������ 200 � ������ ����� ������ ����, �� ���� �����������.

        if (Distance (ButtonX, ButtonY, MouseX, MouseY) < 200 && txMouseButtons () == 1)
            {
            break;
            }
        }

    txDeleteDC (Rules);

    }

void Moving ()
    {
    HDC Sktr2 = txLoadImage ("SkaterTWO.bmp");
    if (Sktr2 == NULL) printf ("SkaterTWO isn't found");
    //HDC Sktr = txLoadImage ("SkaterAlpha.bmp");
    //if (Sktr == NULL) printf ("SkaterAlpha.bmp isn't found");
    //HDC SktrN = txLoadImage ("SkaterAlphaNew.bmp");
    //if (SktrN == NULL) printf ("SkaterAlphaNew isn't found");

    HDC Skt = txLoadImage ("SkateAlpha.bmp");
    if (Skt == NULL) printf ("SkateAlpha.bmp isn't found");
    HDC Gsh = txLoadImage ("GaishnikAlpha.bmp");
    if (Gsh == NULL) printf ("GaishnikAlpha.bmp isn't found");
    HDC SktrP = txLoadImage ("SkatePark (2).bmp");
    if (SktrP == NULL) printf ("SkatePark (2).bmp isn't found");
    HDC GshN = txLoadImage ("GaishnikNEW2.bmp");
    if (GshN == NULL) printf ("GaishnikNEW2.bmp isn't found");
    HDC GshTh = txLoadImage ("GaishnikThree.bmp");
    if (GshTh == NULL) printf ("GaishnikThree.bmp isn't found");

    HDC Mash = txLoadImage ("MaMin Men.bmp");
    if (Mash == NULL) printf ("MaMin Men.bmp isnt't found");

    HDC Cat = txLoadImage ("Cat.bmp");
    if (Cat == NULL) printf ("Cat.bmp isnt't found");

    HDC Bench = txLoadImage ("Bench.bmp");
    if (Bench == NULL) printf ("Bench.bmp isn't found");

    HDC City = txLoadImage ("CityWallpaper.bmp");
    if (City == NULL) printf ("CityWallpaper.bmp isn't found");


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

    char TextOut [100] = "� ���� ������";

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

        printf ("� ����\n %d", distance);
         */
        ScoreBoard (Score, (GetTickCount () - TimeStart) / 1000);

        if (Score > 200)
            {
            strcpy (TextOut, "��� ��� �����������");
            Text (TextX, TextY, TextOut);
            break;
            }

        Text (TextX, TextY, TextOut);

        Levels (&Level, &SktrX, &SktX);

        //Drawing (HDC SktrP, int SktrPx, int SktrPy, int SktrPX, HDC Bench, int BenchX, HDC City, int CityX, int Frames, int *Level, int *t);


        //printf ("� ���� ������ %d\n",  Dist);

        txSleep (10);

        //printf ("� ���� ������\n %d", SktX, SktY);

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

    }

void SkateMove (int* SktX, int* SktY)
    {
    if (GetAsyncKeyState ('D')) *SktX = *SktX + 5;
    if (GetAsyncKeyState ('A')) *SktX = *SktX - 5;
    if (GetAsyncKeyState ('W')) *SktY = *SktY - 5;
    if (GetAsyncKeyState ('S')) *SktY = *SktY + 5;
    }

void SkaterMove (int* SktrX, int* SktrY)
    {
    if (GetAsyncKeyState (VK_RIGHT)) *SktrX = *SktrX + 6;
    if (GetAsyncKeyState (VK_LEFT))  *SktrX = *SktrX - 6;
    if (GetAsyncKeyState (VK_UP))    *SktrY = *SktrY + 6;
    if (GetAsyncKeyState (VK_DOWN))  *SktrY = *SktrY - 6;
    }
int Distance (int X1, int Y1, int X2, int Y2)
    {
    return sqrt ((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
    }

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

void Levels (int* Level, int* SktrX, int* SktX)
    {

    if (*SktrX >= 1680 && *Level == 1)   //���������� �������� �� ������� � ������ ������
        {                               //������� ������� 1 �� ������� 2
        *Level = 2;
        *SktrX = 100;
        *SktX = 100;
        printf ("�� ������� �� ������� 2\n");
        }

    if (*SktrX >= 1680 && *Level == 2)   //���������� �������� �� ������� � ������ ������
        {                                //������� ������� 2 �� ������� 3
        *Level = 3;
        *SktrX = 100;
        *SktX = 100;
        printf ("�� ������� �� ������� 3\n %d");
        }


    if (*SktrX >= 1680 && *Level == 3)   //�������� �������� �� ������� � ������ ������
        {                                //������� ������� 3 �� ������� 1
        *Level = 1;
        *SktrX = 100;
        *SktX = 100;
        printf ("�� ������� �� ������� 1\n %d");
        }

    }

void Drawing (HDC SktrP, int SktrPx, int SktrPy, int SktrPX, HDC Bench, int BenchX, HDC City, int CityX, int Frames, int* Level, int* t)
    {
    if (*Level == 1)
        {
        txAlphaBlend (txDC (), 0, 0, SktrPX, 0, SktrP, *t / 10 % 4 * 1680, 0);
        }

    if (*Level == 2)
        {
        txAlphaBlend (txDC (), 0, 0, BenchX, 0, Bench, *t / 35 % Frames * 1680, 0);
        }

    if (*Level == 3)
        {
        txAlphaBlend (txDC (), 0, 0, CityX, 0, City, *t / 35 % 4 * 1680, 0);
        }
    }

void MakingMeasuring (int* Level, int Dist, int GshThy, int GshThx, HDC GshTh, int GshNx, int GshNy, int GshN2, HDC GshN, int GshX, int GshY, HDC Gsh, char TextOut [], int* Score, int* t)
    {

    if (Dist < 40 && Dist > 20)
        {
        txAlphaBlend (GshThx, GshThy, GshTh, 0, 0, 0);
        strcpy (TextOut, "����� �� �����");
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
        strcpy (TextOut, "�� �������� ���������");
        //*Level = 2;
        }
    }


