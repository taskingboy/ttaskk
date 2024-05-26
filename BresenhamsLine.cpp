#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

// Function to draw a line using Bresenham's line drawing algorithm
void drawline(int x1, int y1, int x2, int y2)
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
    if (dx > dy)
    {
        p = 2 * dy - dx; // Initial decision parameter

        // Loop until the endpoint is reached in x-direction
        while (x != x2)
        {
            putpixel(x, y, 3); // Plot the pixel at (x, y)

            // Update y-coordinate and decision parameter
            if (p > 0)
            {
                y += sy;
                p -= 2 * dx;
            }
            x += sx;     // Increment x-coordinate
            p += 2 * dy; // Update decision parameter for the next step
        }
    }
    else
    {                    // If the change in y is greater than the change in x
        p = 2 * dx - dy; // Initial decision parameter

        // Loop until the endpoint is reached in y-direction
        while (y != y2)
        {
            putpixel(x, y, 3); // Plot the pixel at (x, y)

            // Update x-coordinate and decision parameter
            if (p > 0)
            {
                x += sx;
                p -= 2 * dy;
            }
            y += sy;     // Increment y-coordinate
            p += 2 * dx; // Update decision parameter for the next step
            delay(50);   // Introduce a delay for visualization
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    initgraph(&gd, &gm, "c:\\turboc3\\bgi");

    // Input coordinates of the two endpoints
    printf("Enter the value of x1 and y1:");
    scanf("%d %d", &x1, &y1);
    printf("Enter the value of x2 and y2:");
    scanf("%d %d", &x2, &y2);

    // Call the drawline function to draw the line
    drawline(x1, y1, x2, y2);

    getch();      // Wait for user input
    closegraph(); // Close the graphics window
    return 0;
}












