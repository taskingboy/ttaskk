#include <graphics.h> // Include graphics library
#include <conio.h>    // Include console input/output library
#include <stdio.h>    // Include standard input/output library

// Define region codes
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

// Define boundaries of the clipping rectangle
float xmin, ymin, xmax, ymax;

// Function to compute the region code for a point (x, y)
int computeCode(float x, float y)
{
    int code = 0;
    if (x < xmin)
        code |= LEFT; // Set the left bit
    else if (x > xmax)
        code |= RIGHT; // Set the right bit
    if (y < ymin)
        code |= BOTTOM; // Set the bottom bit
    else if (y > ymax)
        code |= TOP; // Set the top bit
    return code;     // Return the computed code
}

// Function to implement the Cohen-Sutherland line clipping algorithm
void cohenSutherlandLineClip(float x0, float y0, float x1, float y1)
{
    int outcode0 = computeCode(x0, y0); // Compute code for the first point
    int outcode1 = computeCode(x1, y1); // Compute code for the second point
    int accept = 0;                     // Initialize acceptance flag to false

    while (1)
    {
        if (!(outcode0 | outcode1))
        {               // If both endpoints lie within the rectangle
            accept = 1; // Accept the line
            break;
        }
        else if (outcode0 & outcode1)
        {          // If both endpoints share an outside region
            break; // Reject the line
        }
        else
        {
            float x, y;                                      // Variables to store intersection points
            int outcodeOut = outcode0 ? outcode0 : outcode1; // Choose the point outside the rectangle

            // Find the intersection point using the boundaries
            if (outcodeOut & TOP)
            { // Point is above the clip rectangle
                x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
                y = ymax;
            }
            else if (outcodeOut & BOTTOM)
            { // Point is below the clip rectangle
                x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
                y = ymin;
            }
            else if (outcodeOut & RIGHT)
            { // Point is to the right of the clip rectangle
                y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
                x = xmax;
            }
            else if (outcodeOut & LEFT)
            { // Point is to the left of the clip rectangle
                y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
                x = xmin;
            }

            // Replace the point outside the rectangle with the intersection point
            if (outcodeOut == outcode0)
            {
                x0 = x;
                y0 = y;
                outcode0 = computeCode(x0, y0);
            }
            else
            {
                x1 = x;
                y1 = y;
                outcode1 = computeCode(x1, y1);
            }
        }
    }

    if (accept)
    {                         // If the line is accepted
        setcolor(WHITE);      // Set color to white
        line(x0, y0, x1, y1); // Draw the clipped line
    }
}

// Function to handle input and perform line clipping
void lineClipping()
{
    float xa, ya, xb, yb;

    // Get coordinates for the clipping rectangle
    printf("Enter coordinates for the rectangle (xmin, ymin, xmax, ymax): ");
    scanf("%f%f%f%f", &xmin, &ymin, &xmax, &ymax);

    // Get coordinates for the line
    printf("Enter coordinates for the line (xa, ya, xb, yb): ");
    scanf("%f%f%f%f", &xa, &ya, &xb, &yb);

    // Draw the original line
    setcolor(5);
    line(xa, ya, xb, yb);
    // Draw the clipping rectangle
    setcolor(12);
    rectangle(xmin, ymin, xmax, ymax);

    // Perform Cohen-Sutherland line clipping
    cohenSutherlandLineClip(xa, ya, xb, yb);

    getch(); // Wait for user input
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Initialize graphics mode
    cleardevice();                           // Clear the screen

    lineClipping(); // Call the line clipping function

    closegraph(); // Close the graphics mode
    return 0;
}
