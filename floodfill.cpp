#include <graphics.h>  // Include graphics library
#include <stdio.h>     // Include standard I/O library

// Function to perform flood fill
void flood(int x, int y, int new_col, int old_col) {
    // Check if the current pixel is within the window boundaries
    if (x < getmaxx() && y < getmaxy() && x >= 0 && y >= 0) {
        // Check if the current pixel color is the old color
        if (getpixel(x, y) == old_col) 
        {
            // Change the color of the current pixel to the new color
            putpixel(x, y, new_col);
            // Recursively call flood fill for neighboring pixels
            flood(x + 1, y, new_col, old_col); // Right neighbor
            flood(x - 1, y, new_col, old_col); // Left neighbor
            flood(x, y + 1, new_col, old_col); // Bottom neighbor
            flood(x, y - 1, new_col, old_col); // Top neighbor
        }
    }
}

int main() {
    int gd, gm = DETECT;  // Variables for graphics mode
    initgraph(&gd, &gm, "");  // Initialize graphics mode

    initwindow(800, 600);  // Create a window of size 800x600

    int top, left, bottom, right;

    top = left = 50;  // Define the coordinates for the top-left corner of the rectangle
    bottom = right = 300;  // Define the coordinates for the bottom-right corner of the rectangle

    rectangle(left, top, right, bottom);  // Draw a rectangle

    int x = 100;  // Seed point x-coordinate
    int y = 100;  // Seed point y-coordinate

    int newcolor = 12;  // New color for flood fill
    int oldcolor = 0;   // Old color to be replaced by flood fill

    flood(x, y, newcolor, oldcolor);  // Perform flood fill from the seed point

    getch();  // Wait for a key press
    closegraph();  // Close the graphics window
    return 0;  // Return from the main function
}
