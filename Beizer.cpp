// hardcoded
#include <stdio.h>    // Standard input/output library for printf and scanf
#include <conio.h>    // Console input/output library for getch and delay
#include <graphics.h> // Graphics library for drawing functions
#include <math.h>     // Math library for pow function

int main()
{
    int x[4], y[4], i;          // Arrays to store the x and y coordinates of the control points, and a loop counter
    double put_y, put_x, t;     // Variables to store the coordinates of points on the Bezier curve and the parameter t
    int gd = DETECT, gm;        // Graphics mode variables
    initgraph(&gd, &gm, " ");   // Initialize the graphics system

    // Loop to input and plot the control points
    for (i = 0; i < 4; i++)
    {
        // Prompt user to enter coordinates of the control point
        printf(" Enter x and y coordinates of point %d: ", i + 1);
        // Read the coordinates from user input
        scanf("%d %d", &x[i], &y[i]);
        // Plot the control point on the screen
        putpixel(x[i], y[i], 3);
    }

    // Loop to calculate and plot points on the Bezier curve
    for (t = 0; t <= 1; t += 0.001)
    {
        // Calculate the x coordinate of the Bezier curve point using the cubic Bezier formula
        put_x = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * t * t * (1 - t) * x[2] + pow(t, 3) * x[3];
        // Calculate the y coordinate of the Bezier curve point using the cubic Bezier formula
        put_y = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * t * t * (1 - t) * y[2] + pow(t, 3) * y[3];
        // Plot the calculated point on the screen
        putpixel((int)put_x, (int)put_y, WHITE);
    }

    getch();        // Wait for a key press
    delay(10000);   // Delay for 10 seconds to allow viewing the curve
    closegraph();   // Close the graphics mode
    return 0;       // Return 0 to indicate successful completion
}





/*
// User IP
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

// Function to calculate factorial
int factorial(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) {
        f *= i;
    }
    return f;
}

// Function to calculate binomial coefficient
int binomialCoeff(int n, int k) 
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Function to calculate the Bezier curve point
void bezierCurve(int x[], int y[], int n, double t, double* px, double* py) {
    *px = 0;
    *py = 0;
    for (int i = 0; i < n; i++) {
        double coeff = binomialCoeff(n - 1, i) * pow(t, i) * pow(1 - t, n - 1 - i);
        *px += coeff * x[i];
        *py += coeff * y[i];
    }
}

int main() {
    int n, i;
    double put_y, put_x, t;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, " ");

    printf("Enter the number of control points (n >= 2): ");
    scanf("%d", &n);
    if (n < 2) {
        printf("Number of control points must be at least 2.\n");
        closegraph();
        return 1;
    }

    int x[n], y[n];
    for (i = 0; i < n; i++) {
        printf("Enter x and y coordinates of point %d: ", i + 1);
        scanf("%d %d", &x[i], &y[i]);
        putpixel(x[i], y[i], 3);
    }

    for (t = 0; t <= 1; t += 0.001) {
        bezierCurve(x, y, n, t, &put_x, &put_y);
        putpixel((int)put_x, (int)put_y, WHITE);
    }

    getch();
    delay(10000);
    closegraph();
    return 0;
}


*/