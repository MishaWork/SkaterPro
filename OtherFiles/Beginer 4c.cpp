#include  "TXlib.h"

int main ()
    {
    txCreateWindow (1080, 720);
    txSelectFont ("Arial Black", 100, 20, 500);


    txTextOut (500, 500, "Hello");
    }
