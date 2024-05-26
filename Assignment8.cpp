#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>

// Function prototypes
void menu();
void lineClipping(int algorithm);

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    menu();

    getch();
    closegraph();
    return 0;
}

void menu()
{
    int choice;
    do
    {
        printf("\n=========================\n");
        printf("     Clipping Menu\n");
        printf("=========================\n");
        printf("1. Cohen-Sutherland Algorithm\n");
        printf("2. Midpoint Clipping Algorithm\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            lineClipping(1); // Cohen-Sutherland Algorithm
            break;
        case 2:
            lineClipping(2); // Midpoint Clipping Algorithm
            break;
        case 3:
            printf("\nExiting...\n");
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
            break;
        }
    } while (choice != 3);
}

void lineClipping(int algorithm)
{
    int a[4], b[4];
    float m, xnew, ynew;
    float xl, yl, xh, yh, xa, ya, xb, yb;

    printf("\nEnter coordinates for the rectangle (xl, yl, xh, yh): ");
    scanf("%f%f%f%f", &xl, &yl, &xh, &yh);

    printf("Enter coordinates for the line (xa, ya, xb, yb): ");
    scanf("%f%f%f%f", &xa, &ya, &xb, &yb);

    setcolor(5);
    line(xa, ya, xb, yb);
    setcolor(12);
    rectangle(xl, yl, xh, yh);
    m = (yb - ya) / (xb - xa);

    if (xa < xl)
        a[3] = 1;
    else
        a[3] = 0;

    if (xa > xh)
        a[2] = 1;
    else
        a[2] = 0;

    if (ya < yl)
        a[1] = 1;
    else
        a[1] = 0;

    if (ya > yh)
        a[0] = 1;
    else
        a[0] = 0;

    if (xb < xl)
        b[3] = 1;
    else
        b[3] = 0;

    if (xb > xh)
        b[2] = 1;
    else
        b[2] = 0;

    if (yb < yl)
        b[1] = 1;
    else
        b[1] = 0;

    if (yb > yh)
        b[0] = 1;
    else
        b[0] = 0;

    printf("Press any key to continue...");
    getch();

    if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && b[0] == 0 && b[1] == 0 && b[2] == 0 && b[3] == 0)
    {
        printf("\nNo clipping");
        line(xa, ya, xb, yb);
    }
    else if (a[0] && b[0] || a[1] && b[1] || a[2] && b[2] || a[3] && b[3])
    {
        printf("\nLine discarded");
        rectangle(xl, yl, xh, yh);
    }
    else
    {
        if (algorithm == 1)
        { 
            // Cohen-Sutherland Algorithm
            if (a[3] == 1 && b[3] == 0)
            {
                ynew = (m * (xl - xa)) + ya;
                setcolor(12);
                rectangle(xl, yl, xh, yh);
                setcolor(0);
                line(xa, ya, xb, yb);
                setcolor(15);
                line(xl, ynew, xb, yb);
            }
            else if (a[2] == 1 && b[2] == 0)
            {
                ynew = (m * (xh - xa)) + ya;
                setcolor(12);
                rectangle(xl, yl, xh, yh);
                setcolor(0);
                line(xa, ya, xb, yb);
                setcolor(15);
                line(xl, ynew, xb, yb);
            }
            else if (a[1] == 1 && b[1] == 0)
            {
                xnew = xa + (yl - ya) / m;
                setcolor(0);
                line(xa, ya, xb, yb);
                setcolor(15);
                line(xnew, yh, xb, yb);
            }
            else if (a[0] == 1 && b[0] == 0)
            {
                xnew = xa + (yh - ya) / m;
                setcolor(0);
                line(xa, ya, xb, yb);
                setcolor(15);
                line(xnew, yh, xb, yb);
            }
        }
        else if (algorithm == 2)
        { 
            // Midpoint Clipping Algorithm
            float dx = xb - xa;
            float dy = yb - ya;
            float p[4] = {-dx, dx, -dy, dy};
            float q[4] = {xa - xl, xh - xa, ya - yl, yh - ya};

            float t1 = 0, t2 = 1;

            for (int i = 0; i < 4; i++)
            {
                float r = q[i] / p[i];
                if (p[i] < 0)
                {
                    if (r > t2)
                    {
                        printf("\nLine discarded");
                        rectangle(xl, yl, xh, yh);
                        return;
                    }
                    else if (r > t1)
                        t1 = r;
                }
                else if (p[i] > 0)
                {
                    if (r < t1)
                    {
                        printf("\nLine discarded");
                        rectangle(xl, yl, xh, yh);
                        return;
                    }
                    else if (r < t2)
                        t2 = r;
                }
                else if (q[i] < 0)
                {
                    printf("\nLine discarded");
                    rectangle(xl, yl, xh, yh);
                    return;
                }
            }

            float x1 = xa + t1 * dx;
            float y1 = ya + t1 * dy;
            float x2 = xa + t2 * dx;
            float y2 = ya + t2 * dy;

            setcolor(12);
            rectangle(xl, yl, xh, yh);
            setcolor(0);
            line(xa, ya, xb, yb);
            setcolor(15);
            line(x1, y1, x2, y2);
        }
    }
}


/*
200 200 500 500
150 150 350 350
*/

/*
100 100 300 300
10 200 250 150
*/