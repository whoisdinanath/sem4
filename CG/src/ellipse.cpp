
#include <graphics.h>
#include <iostream>

void draw_ellipse(int x_c, int y_c, int rad_x, int rad_y)
{
    int x = 0, y = rad_y, p;
    p = rad_y * rad_y - rad_x * rad_x * rad_y + 1.0 / 4.0 * rad_x * rad_x;

    while (2 * rad_y * rad_y * x <= 2 * rad_x * rad_x * y)
    {
        putpixel(x + x_c, y + y_c, WHITE);
        putpixel(-x + x_c, y + y_c, WHITE);
        putpixel(x + x_c, -y + y_c, WHITE);
        putpixel(-x + x_c, -y + y_c, WHITE);
        if (p < 0)
        {
            x++;
            p = p + 2 * rad_y * rad_y * x + rad_y * rad_y;
        }
        else
        {

            x++;
            y--;
            p = p + 2 * rad_y * rad_y * x - 2 * rad_x * rad_x * y + rad_y * rad_y;
        }
    }

    p = rad_y * rad_y * (x + 0.5) * (x + 0.5) + rad_x * rad_x * (y - 1) * (y - 1) - rad_x * rad_x * rad_y * rad_y;
    while (y >= 0)
    {
        putpixel(x + x_c, y + y_c, WHITE);
        putpixel(-x + x_c, y + y_c, WHITE);
        putpixel(x + x_c, -y + y_c, WHITE);
        putpixel(-x + x_c, -y + y_c, WHITE);
        if (p > 0)
        {
            y--;
            p = p - 2 * rad_x * rad_x * y + rad_x * rad_x;
        }
        else
        {
            x++;
            y--;
            p = p + 2 * rad_y * rad_y * x - 2 * rad_x * rad_x * y + rad_x * rad_x;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    draw_ellipse(320, 240, 160, 60);
    getch();
    closegraph();
    return 0;
}