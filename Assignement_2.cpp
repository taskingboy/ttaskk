// Assigenemt_2

/*
Write a menu-driven program to draw lines and objects using.
1. DDA Line drawing algorithm
2. Bresenham’s line drawing algorithm
3. Object using both algorithms
*/

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

void ddaline(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    //  printf("dx = %d\n", dx);
    //  printf("dy= %d\n", dy);

    int step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    // printf("step = %d\n", step);

    float x_inc = dx / (float)step;
    float y_inc = dy / (float)step;
   //  printf("x-inc = %f\n", x_inc);
   //  printf("y=inc = %f\n", y_inc);

    float x = x1;
    float y = y1;
    for (int i = 0; i <= step; i++)
    {
        putpixel(x, y, GREEN);
        x += x_inc;
        y += y_inc;
    }
}

void breshnamline(int x1, int y1, int x2, int y2)
{
   int dx, dy, p, x, y, sx, sy;

    // Calculate differences in x and y coordinates
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    // Initialize starting point (x, y)
    x = x1;
    y = y1;

    // Determine the sign of increments in x and y directions
    sx = x1 < x2 ? 1 : -1;
    sy = y1 < y2 ? 1 : -1;

    // If the change in x is greater than the change in y
    if (dx > dy) {
        p = 2 * dy - dx; // Initial decision parameter

        // Loop until the endpoint is reached in x-direction
        while (x != x2) {
            putpixel(x, y, 3); // Plot the pixel at (x, y)
            
            // Update y-coordinate and decision parameter
            if (p > 0) {
                y += sy;
                p -= 2 * dx;
            }
            x += sx; // Increment x-coordinate
            p += 2 * dy; // Update decision parameter for the next step
        }
    } else { // If the change in y is greater than the change in x
        p = 2 * dx - dy; // Initial decision parameter

        // Loop until the endpoint is reached in y-direction
        while (y != y2) {
            putpixel(x, y, 3); // Plot the pixel at (x, y)
            
            // Update x-coordinate and decision parameter
            if (p > 0) {
                x += sx;
                p -= 2 * dy;
            }
            y += sy; // Increment y-coordinate
            p += 2 * dx; // Update decision parameter for the next step
            delay(50); // Introduce a delay for visualization
        }
    }
}
    /*
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p, steps, i;

    if (dx > dy)
    {
        p = 2 * dy - dx;
        steps = dx;
        for (i = 0; i < steps; i++)
        {
            putpixel(x1, y1, BROWN);
            if (p < 0)
            {
                x1 += 1;
                p += 2 * dy;
            }
            else
            {
                x1 += 1;
                y1 += 1;
                p += 2 * (dy - dx);
            }
        }
    }
    else
    {
        p = 2 * dx - dy;
        steps = dy;

        for (i = 0; i < steps; i++)
        {
            putpixel(x1, y1, GREEN);
            if (p < 0)
            {
                y1 += 1;
                p += 2 * dx;
            }
            else
            {
                y1 += 1;
                x1 += 1;
                p += 2 * (dx - dy);
            }
        }
    }
    */


void drawobj()
{
    ddaline(200, 200, 300, 100);
    breshnamline(300, 100, 400, 200);
    ddaline(400, 200, 300, 300);
    breshnamline(200, 200, 300, 300);
}

int main()
{
    // clrscr();
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");

    int choice;
    int x1, y1, x2, y2;

    while (1)
    {

        printf("\nMenu|\n");
        printf("1.DDA Line\n");
        printf("2.Breshnam Line:\n");
        printf("3.Draw Object:\n");
        printf("4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the co-ordinates for DDA Line:\n");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            ddaline(x1, y1, x2, y2);
            break;

        case 2:
            printf("Enter the co-ordinates for Breshnam Line:\n");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            breshnamline(x1, y1, x2, y2);
            break;

        case 3:
            drawobj();
            break;

        case 4:
            exit(0);
        default:
            printf("Enter valid choice:");
        }
    }
    getch();
    return 0;
}


/*Output:-
    1. 350 200 250 300

    2. 200 300 300 400

    3. ---------------
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
void ddaline(int x1, int y1, int x2, int y2)
{
    int gd = DETECT, gm;
    int xincr, yincr, steps, dx, dy;
    int i;

    initgraph(&gd, &gm, "C:\\turboc3\\bgi");

    dx = x2 - x1;
    dy = y2 - y1;

    if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    
    xincr = dx / steps;
    yincr = dy / steps;

    for(i = 0; i < steps; i++)
    {
        putpixel(x1, y1, YELLOW);
        x1 = x1 + xincr;
        y1 = y1 + yincr;
        delay(50);
    }
    closegraph();
}

void breshnamline(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p, steps, i;

    if (dx > dy)
    {
        p = 2 * dy - dx;
        steps = dx;
        for (i = 0; i < steps; i++)
        {
            putpixel(x1, y1, BROWN);
            if (p < 0)
            {
                x1 += 1;
                p += 2 * dy;
            }
            else
            {
                x1 += 1;
                y1 += 1;
                p += 2 * (dy - dx);
            }
        }
    }
    else
    {
        p = 2 * dx - dy;
        steps = dy;

        for (i = 0; i < steps; i++)
        {
            putpixel(x1, y1, GREEN);
            if (p < 0)
            {
                y1 += 1;
                p += 2 * dx;
            }
            else
            {
                y1 += 1;
                x1 += 1;
                p += 2 * (dx - dy);
            }
        }
    }
    delay(100);
}

void drawobj()
{
    ddaline(200, 200, 300, 100);
    breshnamline(300, 100, 400, 200);
    ddaline(400, 200, 300, 300);
    breshnamline(200, 200, 300, 300);
}

int main()
{
    // clrscr();
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\turboc3\\bgi");

    int choice;
    int x1, y1, x2, y2;

    while (1)
    {

        printf("\nMenu|\n");
        printf("1.DDA Line\n");
        printf("2.Breshnam Line:\n");
        printf("3.Draw Object:\n");
        printf("4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the co-ordinates for DDA Line:\n");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            ddaline(x1, y1, x2, y2);
            break;

        case 2:
            printf("Enter the co-ordinates for Breshnam Line:\n");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            breshnamline(x1, y1, x2, y2);
            break;

        case 3:
            drawobj();
            break;

        case 4:
            exit(0);
        default:
            printf("Enter valid choice:");
        }
    }
    getch();
    return 0;
}
*/


/*Output:-
    1. 350 200 250 300

    2. 200 300 300 400

    3. ---------------
*/