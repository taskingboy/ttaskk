// Assignment_3
/*
Write a menu-driven program to draw circles and objects using:
1. Midpoint circle algorithm
2. Bresenham’s circle drawing algorithm
3. Object using both algorithms
*/

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

// Function to draw a circle using the Midpoint Circle Algorithm
void MidpointCircle(int xc, int yc, int r)
{
    int x = 0, y = r; // Initialize the starting point at (0, r)
    int p = 1 - r;    // Decision parameter initialized

    while (x < y) // Loop until x equals y
    {
        x++;
        if (p < 0) // If decision parameter is negative, choose the East pixel
            p += 2 * x + 1;
        else // If decision parameter is positive or zero, choose the South-East pixel
        {
            y--;
            p += 2 * (x - y) + 1;
        }

        // Plot the symmetrical points in all eight octants
        putpixel(xc + x, yc - y, RED);
        putpixel(xc - x, yc - y, RED);
        putpixel(xc + x, yc + y, RED);
        putpixel(xc - x, yc + y, RED);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
    }
}

// Function to draw a circle using the Bresenham’s Circle Drawing Algorithm
void BresenhamCircle(int xc, int yc, int r)
{
    int x = 0, y = r; // Initialize the starting point at (0, r)
    int d = 3 - 2 * r; // Decision parameter initialized

    while (x <= y) // Loop until x equals y
    {
        // Plot the symmetrical points in all eight octants
        putpixel(xc + x, yc + y, RED);
        putpixel(xc - x, yc + y, GREEN);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, BROWN);
        putpixel(xc + y, yc + x, GREEN);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, RED);
        putpixel(xc - y, yc - x, BROWN);
        x++;
        if (d < 0) // If decision parameter is negative, choose the East pixel
            d += 2 * x + 3;
        else // If decision parameter is positive or zero, choose the South-East pixel
        {
            d += 2 * (x - y) + 5;
            y--;
        }
    }
}

// Function to draw an object using both circle drawing algorithms
void drawobj()
{
    BresenhamCircle(200, 200, 50); // Draw circle using Bresenham’s algorithm
    MidpointCircle(250, 200, 50);  // Draw circle using Midpoint algorithm
    BresenhamCircle(300, 200, 50); // Draw another circle using Bresenham’s algorithm
    MidpointCircle(350, 200, 50);  // Draw another circle using Midpoint algorithm
}

int main()
{
    int gd = DETECT, gm; // Graphics driver and mode variables
    initgraph(&gd, &gm, "C:\\turboc3\\bgi"); // Initialize graphics mode

    int choice;
    int xc, yc, r; // Variables for circle parameters

    while (1) // Infinite loop to display menu until exit option is chosen
    {
        printf("\nMenu:\n");
        printf("1. Draw Midpoint Circle:\n");
        printf("2. Draw Bresenham Circle:\n");
        printf("3. Draw Object\n");
        printf("4. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter x, y-coordinate and radius of Midpoint circle:\n");
            scanf("%d %d %d", &xc, &yc, &r); // Input circle parameters
            MidpointCircle(xc, yc, r); // Draw circle using Midpoint algorithm
            break;

        case 2:
            printf("Enter x, y-coordinate and radius of Bresenham circle:\n");
            scanf("%d %d %d", &xc, &yc, &r); // Input circle parameters
            BresenhamCircle(xc, yc, r); // Draw circle using Bresenham’s algorithm
            break;

        case 3:
            drawobj(); // Draw object using both algorithms
            break;
        case 4:
            exit(0); // Exit the program
        default:
            printf("Enter a valid choice"); // Handle invalid menu choice
        }
    }
    getch(); // Wait for user input before closing the graphics mode
    return 0;
}


/*
    1. 300 300 60

    2. 350 400 50

    3. ----------
*/

// use "void" insted of "int" in the TurboC++ also add "clrscr"
















