#include <graphics.h>

void drawVehicle(int x, int y, int isBus)
{
    rectangle(x, y, x + 200, y + 100); // Body
    rectangle(x, y - 50, x + 200, y);  // Roof

    rectangle(x + 30, y - 40, x + 80, y - 10);   // Window 1
    rectangle(x + 120, y - 40, x + 170, y - 10); // Window 2

    circle(x + 50, y + 100, 25);  // Wheel 1
    circle(x + 150, y + 100, 25); // Wheel 2

    line(0, y + 125, getmaxx(), y + 125); // Road

    if (isBus)
    {
        // Bus-specific details
        rectangle(x + 20, y - 60, x + 180, y - 50);
        rectangle(x + 20, y - 60, x + 30, y);
        rectangle(x + 170, y - 60, x + 180, y);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw a car
    // for (int i = 40; i < 1000; i++)
    // {
    //     cleardevice();
    //     drawVehicle(i, 300, 0);
    //     delay(10);
    // }

    getch();
    closegraph();
    return 0;
}
