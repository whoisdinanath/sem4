#include <graphics.h>
#include <math.h>

// Structure to represent a 2D point
struct Point
{
    int x, y;
};

// Function to draw a colored pentagon
void drawColoredPentagon(struct Point pentagon[], int color)
{
    setcolor(color);
    for (int i = 0; i < 5; ++i)
    {
        line(pentagon[i].x, pentagon[i].y, pentagon[(i + 1) % 5].x, pentagon[(i + 1) % 5].y);
    }
}

// Function to perform shear transformation on a point
void shearPoint(struct Point *p, float shearX, float shearY)
{
    int x = p->x;
    int y = p->y;

    p->x = x + shearX * y;
    p->y = y + shearY * x;
}

// Function to perform scale transformation on a point
void scalePoint(struct Point *p, float scaleX, float scaleY)
{
    p->x = (int)(p->x * scaleX);
    p->y = (int)(p->y * scaleY);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Initial coordinates of the pentagon
    struct Point originalPentagon[] = {
        {55, 100},
        {110, 100},
        {100, 200},
        {190, 250},
        {60, 200}};

    // Drawing the original pentagon in red
    drawColoredPentagon(originalPentagon, RED);

    // Shear parameters
    float shearX = 0.5;
    float shearY = 0.0;

    // Applying shear transformation to each point in the pentagon
    for (int i = 0; i < 5; ++i)
    {
        shearPoint(&originalPentagon[i], shearX, shearY);
    }

    // Drawing the sheared pentagon in blue
    drawColoredPentagon(originalPentagon, BLUE);

    // Scale parameters
    float scaleX = 1.5;
    float scaleY = 1.5;

    // Applying scale transformation to each point in the pentagon
    for (int i = 0; i < 5; ++i)
    {
        scalePoint(&originalPentagon[i], scaleX, scaleY);
    }

    // Drawing the scaled pentagon in green
    drawColoredPentagon(originalPentagon, GREEN);

    getch();
    closegraph();
    return 0;
}