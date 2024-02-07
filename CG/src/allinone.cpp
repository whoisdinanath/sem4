#include <graphics.h>
#include <iostream>
#include <cmath>

inline int round(const float x) { return int(x + 0.5); }

struct Point
{
    int x, y;
};

void drawAxes()
{
    int x, y;
    for (x = 0; x < getmaxx(); x++)
    {
        putpixel(x, getmaxy() / 2, WHITE);
    }
    for (y = 0; y < getmaxy(); y++)
    {
        putpixel(getmaxx() / 2, y, WHITE);
    }
}

void toActualCoordinates(int &x, int &y)
{
    x += getmaxx() / 2;
    y = getmaxy() / 2 - y;
}

void setPixel(int x, int y)
{
    toActualCoordinates(x, y);
    putpixel(x, y, WHITE);
}

void lineDDA(int x0, int y0, int xEnd, int yEnd)
{
    int dx = xEnd - x0, dy = yEnd - y0, steps, k;
    float xIncrement, yIncrement, x = x0, y = y0;

    if (fabs(dx) > fabs(dy))
    {
        steps = fabs(dx);
    }
    else
    {
        steps = fabs(dy);
    }
    xIncrement = float(dx) / float(steps);
    yIncrement = float(dy) / float(steps);

    setPixel(round(x), round(y));
    for (k = 0; k < steps; k++)
    {
        x += xIncrement;
        y += yIncrement;
        setPixel(round(x), round(y));
    }
}

void lineBLA(int x0, int y0, int xEnd, int yEnd)
{
    int dx = fabs(x0 - xEnd), dy = fabs(y0 - yEnd);
    int x, y, twoDelY = 2 * dy, twoDelYMinusTwoDelX = 2 * (dy - dx), p = 2 * dy - dx;
    if (x0 > xEnd)
    {
        x = xEnd;
        y = yEnd;
        xEnd = x0;
    }
    else
    {
        x = x0;
        y = y0;
    }
    setPixel(x, y);
    while (x < xEnd)
    {
        x++;
        if (p < 0)
        {
            p += twoDelY;
        }
        else
        {
            y++;
            p += twoDelYMinusTwoDelX;
        }
        setPixel(x, y);
    }
}

void circleMP(int x_c, int y_c, int r)
{
    int x = 0, y = r, p = 1 - r;
    while (x < y)
    {
        setPixel(x + x_c, y + y_c);
        setPixel(-x + x_c, y + y_c);
        setPixel(x + x_c, -y + y_c);
        setPixel(-x + x_c, -y + y_c);
        setPixel(y + x_c, x + y_c);
        setPixel(-y + x_c, x + y_c);
        setPixel(y + x_c, -x + y_c);
        setPixel(-y + x_c, -x + y_c);
        if (p < 0)
        {
            x++;
            p += 2 * x + 1;
        }
        else
        {
            x++;
            y--;
            p += 2 * x - 2 * y + 1;
        }
    }
}

void ellipseMP(int x_c, int y_c, int rx, int ry)
{
    int x = 0, y = ry, x2 = rx, y2 = 0;
    int p1 = round(ry * ry - rx * rx * ry + 0.25 * rx * rx), p2 = round(rx * rx + ry * ry * rx + 0.25 * ry * ry);
    while (2 * ry * ry * x2 > 2 * rx * rx * y2)
    {
        setPixel(x + x_c, y + y_c);
        setPixel(-x + x_c, y + y_c);
        setPixel(x + x_c, -y + y_c);
        setPixel(-x + x_c, -y + y_c);
        setPixel(x2 + x_c, y2 + y_c);
        setPixel(-x2 + x_c, y2 + y_c);
        setPixel(x2 + x_c, -y2 + y_c);
        setPixel(-x2 + x_c, -y2 + y_c);
        if ((2 * ry * ry * x < 2 * rx * rx * y))
        {
            if (p1 < 0)
            {
                x++;
                p1 += 2 * ry * ry * x + ry * ry;
            }
            else
            {
                x++;
                y--;
                p1 += 2 * ry * ry * x + ry * ry - 2 * rx * rx * y;
            }
        }

        if (p2 < 0)
        {
            y2++;
            x2--;
            p2 += 2 * ry * ry * x2 - 2 * rx * rx * y2 + rx * rx;
        }
        else
        {
            y2++;
            p2 += -2 * rx * rx * y2 + rx * rx;
        }
    }
}

void translate(struct Point *X, int t_x, int t_y)
{
    int transformMatrix[3][3] = {
        {1, 0, t_x},
        {0, 1, t_y},
        {0, 0, 1}};
    int origPoints[3] = {X->x, X->y, 1};
    int newPoints[3] = {0};

    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            newPoints[i] += transformMatrix[i][j] * origPoints[j];
        }
        // printf("%d\n", newPoints[i]);
    }
    X->x = newPoints[0];
    X->y = newPoints[1];
}

void rotate(struct Point *X, double angle)
{
    angle = angle * 3.14159 / 180.0;
    double transformMatrix[3][3] = {
        {cos(angle), -sin(angle), 0},
        {sin(angle), cos(angle), 0},
        {0, 0, 1}};
    double origPoints[3] = {(float)X->x, (float)X->y, 1};
    double newPoints[3] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            newPoints[i] += transformMatrix[i][j] * origPoints[j];
        }
    }
    X->x = round(newPoints[0]);
    X->y = round(newPoints[1]);
}

void scale(struct Point *X, int s_x, int s_y)
{
    int transformMatrix[3][3] = {s_x, 0, 0, 0, s_y, 0, 0, 0, 1};
    int origPoints[3] = {X->x, X->y, 1};
    int newPoints[3] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            newPoints[i] += transformMatrix[i][j] * origPoints[j];
        }
    }
    X->x = newPoints[0];
    X->y = newPoints[1];
}

void reflect(struct Point *X, int choice)
{
    int transformMatrix[3][3] = {0};
    switch (choice)
    {
    case 1:
        transformMatrix[0][0] = 1;
        transformMatrix[1][1] = -1;
        transformMatrix[2][2] = 1;
        break;
    case 2:
        transformMatrix[0][0] = -1;
        transformMatrix[1][1] = 1;
        transformMatrix[2][2] = 1;
        break;
    case 3:
        transformMatrix[0][0] = -1;
        transformMatrix[1][1] = -1;
        transformMatrix[2][2] = 1;
        break;
    default:
        std::cout << "Invalid choice\n";
        return;
    }
    int origPoints[3] = {X->x, X->y, 1};
    int newPoints[3] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            newPoints[i] += transformMatrix[i][j] * origPoints[j];
        }
    }
    X->x = newPoints[0];
    X->y = newPoints[1];
}

void shear(struct Point *X, float s_x, float s_y)
{
    float transformMatrix[3][3] = {1, s_x, 0, 0, s_y, 0, 0, 0, 1};
    float origPoints[3] = {float(X->x), float(X->y), 1};
    float newPoints[3] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            newPoints[i] += transformMatrix[i][j] * origPoints[j];
        }
    }
    X->x = round(newPoints[0]);
    X->y = round(newPoints[1]);
}

void rotateAboutPoint(struct Point *X, struct Point *P, int angle)
{
    translate(X, -P->x, -P->y);
    rotate(X, angle);
    translate(X, P->x, P->y);
}

void scaleAboutPoint(struct Point *X, struct Point *P, int s_x, int s_y)
{
    translate(X, -P->x, -P->y);
    scale(X, s_x, s_y);
    translate(X, P->x, P->y);
}

void reflectAboutLine(struct Point *X, struct Point *P1, struct Point *P2)
{
    int m = (P2->y - P1->y) / (P2->x - P1->x);
    int c = P1->y - m * P1->x;
    int x = X->x, y = X->y;
    X->x = (x * (1 - m * m) - 2 * m * y - 2 * m * c) / (1 + m * m);
    X->y = (m * m * y - 2 * m * x - 2 * c) / (1 + m * m);
}

int main()
{
    int gd = DETECT, gm;
    initwindow(800, 800, "Bibek's Graphics Window");
    // initgraph(&gd, &gm, NULL);
    drawAxes();
    // lineBLA(10, 10, 300, 250);
    // lineDDA(-10, 20, 100, -50);
    circleMP(10, 10, 50);
    lineDDA(-50, 20, 100, -70);
    ellipseMP(-50, -50, 50, 100);
    // endpoints of triangle
    struct Point A = {100, 100}, B = {200, 100}, C = {150, 200};
    lineDDA(A.x, A.y, B.x, B.y);
    lineDDA(B.x, B.y, C.x, C.y);
    lineDDA(C.x, C.y, A.x, A.y);

    // translate triangle
    translate(&A, 100, 200);
    translate(&B, 100, 200);
    translate(&C, 100, 200);
    lineDDA(A.x, A.y, B.x, B.y);
    lineDDA(B.x, B.y, C.x, C.y);
    lineDDA(C.x, C.y, A.x, A.y);

    // rotate triangle
    A = {100, 100},
    B = {200, 100}, C = {150, 200};
    rotate(&A, 40);
    rotate(&B, 40);
    rotate(&C, 40);
    lineDDA(A.x, A.y, B.x, B.y);
    lineDDA(B.x, B.y, C.x, C.y);
    lineDDA(C.x, C.y, A.x, A.y);

    // scale triangle
    A = {100, 100}, B = {200, 100}, C = {150, 200};
    scale(&A, 1, 2);
    scale(&B, 1, 2);
    scale(&C, 1, 2);
    lineDDA(A.x, A.y, B.x, B.y);
    lineDDA(B.x, B.y, C.x, C.y);
    lineDDA(C.x, C.y, A.x, A.y);

    // reflect triangle
    A = {100, 100}, B = {200, 100}, C = {150, 200};
    reflect(&A, 1);
    reflect(&B, 1);
    reflect(&C, 1);
    lineDDA(A.x, A.y, B.x, B.y);
    lineDDA(B.x, B.y, C.x, C.y);
    lineDDA(C.x, C.y, A.x, A.y);

    A = {100, 100}, B = {200, 100}, C = {150, 200};
    reflect(&A, 2);
    reflect(&B, 2);
    reflect(&C, 2);
    lineDDA(A.x, A.y, B.x, B.y);
    lineDDA(B.x, B.y, C.x, C.y);
    lineDDA(C.x, C.y, A.x, A.y);

    A = {100, 100}, B = {200, 100}, C = {150, 200};
    reflect(&A, 3);
    reflect(&B, 3);
    reflect(&C, 3);
    lineDDA(A.x, A.y, B.x, B.y);
    lineDDA(B.x, B.y, C.x, C.y);
    lineDDA(C.x, C.y, A.x, A.y);

    // shear triangle
    A = {0, 0}, B = {100, 0}, C = {50, 100};
    lineDDA(A.x, A.y, B.x, B.y);
    lineDDA(B.x, B.y, C.x, C.y);
    lineDDA(C.x, C.y, A.x, A.y);
    shear(&A, 0.5, 1);
    shear(&B, 0.5, 1);
    shear(&C, 0.5, 1);
    printf("A = %d, %d\n", A.x, A.y);
    printf("B = %d, %d\n", B.x, B.y);
    printf("C = %d, %d\n", C.x, C.y);
    lineDDA(A.x, A.y, B.x, B.y);
    lineDDA(B.x, B.y, C.x, C.y);
    lineDDA(C.x, C.y, A.x, A.y);

    // rotate about point
    A = {100, 100}, B = {200, 100}, C = {150, 200};
    struct Point P1 = {100, 100};
    rotateAboutPoint(&A, &P1, 45);
    rotateAboutPoint(&B, &P1, 45);
    rotateAboutPoint(&C, &P1, 45);
    lineDDA(A.x, A.y, B.x, B.y);
    lineDDA(B.x, B.y, C.x, C.y);
    lineDDA(C.x, C.y, A.x, A.y);
    getch();
    closegraph();
    return 0;
}