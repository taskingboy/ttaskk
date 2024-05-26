#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void kochCurve(int x1, int y1, int x2, int y2, int it)
{
    float angle = 60 * (3.14159265 / 180);
    int x3 = (2 * x1 + x2) / 3;
    int y3 = (2 * y1 + y2) / 3;
    int x4 = (x1 + 2 * x2) / 3;
    int y4 = (y1 + 2 * y2) / 3;
    int x = x3 + (x4 - x3) * cos(angle) + (y4 - y3) * sin(angle);
    int y = y3 - (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle);
    if (it > 0)
    {
        kochCurve(x1, y1, x3, y3, it - 1);
        kochCurve(x3, y3, x, y, it - 1);
        kochCurve(x, y, x4, y4, it - 1);
        kochCurve(x4, y4, x2, y2, it - 1);
    }
    else
    {
        line(x1, y1, x3, y3);
        line(x3, y3, x, y);
        line(x, y, x4, y4);
        line(x4, y4, x2, y2);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    
    int x1 = 50, y1 = 300;
    int x2 = 450, y2 = 300;
    int iterations = 16; // You can change the number of iterations for different levels of detail
    
    kochCurve(x1, y1, x2, y2, iterations);
    
    getch();
    closegraph();
    return 0;
}