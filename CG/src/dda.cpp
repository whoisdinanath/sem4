#include "graphics.h"
#include <stdio.h>

void DDA(int x1, int y1, int x2, int y2)
{
    float x, y, xinc, yinc;
    int dx, dy, i, steps;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    xinc = dx / (float)steps;
    yinc = dy / (float)steps;
    x = x1;
    y = y1;
    putpixel(x, y, 15);
    for (i = 0; i < steps; i++)
    {
        x += xinc;
        y += yinc;
        putpixel(x, y, 15);
    }
}

void BLA()
{
}

int main()
{
    int gdrive = DETECT;
    int gmode;

    // initwindow(640, 480, "DinanathP(THA078BEI010)", 100, 100);
    initgraph(&gdrive, &gmode, NULL);
    int x1, y1, x2, y2;

    printf("Enter the value of x1 and y1: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the value of x2 and y2: ");
    scanf("%d %d", &x2, &y2);

    DDA(x1, y1, x2, y2);
    getch();
    closegraph();
    return 0;
}