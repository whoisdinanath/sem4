#include <stdio.h>
#include <graphics.h>
#include <cmath>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define PI 3.1415

void translate_as_standard(int *x, int *y)
{
    *x += *x + SCREEN_WIDTH / 2;
    *y = -*y + SCREEN_HEIGHT / 2;
}

void draw_triangle(int x1, int x2, int x3, int y1, int y2, int y3)
{
    translate_as_standard(&x1, &y1);
    translate_as_standard(&x2, &y2);
    translate_as_standard(&x3, &y3);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

void rotate_draw(int x1, int x2, int x3, int y1, int y2, int y3, int x_r, int y_r, float x)
{
    float angle = PI / 180.0 * x;
    translate_as_standard(&x1, &y1);
    translate_as_standard(&x2, &y2);
    translate_as_standard(&x3, &y3);
    translate_as_standard(&x_r, &y_r);

    int new_x1 = x_r + (x1 - x_r) * cos(angle) - (y1 - y_r) * sin(angle);
    int new_y1 = y_r + (x1 - x_r) * sin(angle) + (y1 - y_r) * cos(angle);

    int new_x2 = x_r + (x2 - x_r) * cos(angle) - (y2 - y_r) * sin(angle);
    int new_y2 = y_r + (x2 - x_r) * sin(angle) + (y2 - y_r) * cos(angle);

    int new_x3 = x_r + (x3 - x_r) * cos(angle) - (y3 - y_r) * sin(angle);
    int new_y3 = y_r + (x3 - x_r) * sin(angle) + (y3 - y_r) * cos(angle);

    line(new_x1, new_y1, new_x2, new_y2);
    line(new_x1, new_y1, new_x3, new_y3);
    line(new_x3, new_y3, new_x2, new_y2);
}

void draw_axis()
{
    setlinestyle(2, 2, 2);
    line(0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);
    line(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT);
}

int main()
{
    initwindow(1280, 720, "Dinanath Padhya");
    settextstyle(DEFAULT_FONT, 0, 2);
    setcolor(GREEN);
    draw_axis();
    setlinestyle(0, 2, 2);
    outtextxy(20, 20, "Reflection and Rotation(30 degree)");
    int x[3] = {50, 100, 220};
    int y[3] = {50, 200, 30};
    setcolor(WHITE);
    draw_triangle(x[0], x[1], x[2], y[0], y[1], y[2]);
    // reflection along x-axis
    draw_triangle(-x[0], -x[1], -x[2], y[0], y[1], y[2]);
    draw_triangle(x[0], x[1], x[2], -y[0], -y[1], -y[2]);
    draw_triangle(-x[0], -x[1], -x[2], -y[0], -y[1], -y[2]);
    setcolor(RED);
    // rotation in anti-clockwise 90
    rotate_draw(x[0], x[1], x[2], y[0], y[1], y[2], x[0], y[0], -60.0);

    getch();
    closegraph();
    return 0;
}