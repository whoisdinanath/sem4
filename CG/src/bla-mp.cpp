#include <graphics.h>
#include <iostream>

void draw_circle(int x_c, int y_c, int r, int color)
{
    putpixel(x_c, y_c, color);
    float p_k;
    int x_0 = 0, y_0 = r;
    p_k = (5 / 4.0) - r;
    while (x_0 <= y_0)
    {
        putpixel(x_0 + x_c, y_0 + y_c, color);
        putpixel(-x_0 + x_c, y_0 + y_c, color);
        putpixel(x_0 + x_c, -y_0 + y_c, color);
        putpixel(-x_0 + x_c, -y_0 + y_c, color);
        putpixel(y_0 + x_c, x_0 + y_c, color);
        putpixel(-y_0 + x_c, -x_0 + y_c, color);
        putpixel(y_0 + x_c, -x_0 + y_c, color);
        putpixel(-y_0 + x_c, x_0 + y_c, color);
        if (p_k < 0)
        {
            x_0++;
            p_k = p_k + 2 * x_0 + 1;
        }
        else
        {
            x_0++;
            y_0--;
            p_k = p_k + 2 * x_0 - 2 * y_0 + 1;
        }
        // std::cout << "The co-ordinate is: " << x_0 + x_c << "," << y_0 + y_c << std::endl;
    }
}

void draw_line(int x1, int y1, int x2, int y2)
{
    int dx, dy, x, y, p_k, x_end, y_end;
    dx = x2 - x1;
    dy = y2 - y1;
    p_k = 2 * dy - dx;
    x = x1;
    y = y1;
    x_end = x2;
    y_end = y2;
    while (x <= x_end)
    {
        putpixel(x, y, WHITE);
        if (p_k < 0)
        {
            x++;
            p_k = p_k + 2 * dy;
        }
        else
        {
            x++;
            y++;
            p_k = p_k + 2 * dy - 2 * dx;
        }
    }
}

int main()
{
    int gd = IBM8514, gm = IBM8514LO;
    // initwindow(1280, 720, "DinanathP(THA078BEI010)", 100, 100);
    initgraph(&gd, &gm, (char *)"");
    draw_circle(320, 240, 200, 7);
    draw_line(320, 240, 520, 240);
    getch();
    closegraph();
}