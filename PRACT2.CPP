#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<graphics.h>
void drawobject(int x[], int y[], int n){
for(int i = 0; i<n-1;i++){
line(x[i], y[i], x[i+1], y[i+1]);
}
line(x[n-1], y[n-1], x[0], y[0]);
}

void translate(int x[], int y[], int n, int tx, int ty){
for(int i = 0; i<n;i++)
{
x[i]+=tx;
y[i]+=ty;
}
drawobject(x,y,n);
}

void scale(int x[], int y[], int n, int sx, int sy){
for(int i = 0; i<n; i++){
x[i] *= sx;
y[i] *= sy;
}
drawobject(x,y,n);
}
void rotate(int x[], int y[], float angle, int n)
{
float radian = angle * (M_PI/180.0);
int xt,yt;
for(int i = 0; i<n ; i++){
xt = x[i];
yt = y[i];
x[i] = xt * cos(radian) - yt * sin(radian);
y[i] = xt * sin(radian) + yt * cos(radian);
}
}

void shear(int x[], int y[], int n, float sx, float sy){
for(int i = 0; i<n; i++){
int new_x = x[i] + sx * y[i];
int new_y = y[i] + sy * x[i];
x[i] = new_x;
y[i] = new_y;
}
drawobject(x,y,n);
}
int main(){
clrscr();
int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

int n = 4, tx, ty;
int x[] = {100,200,200,100};
int y[] = {100,100,200,200};
drawobject(x,y,n);
/*printf("Enter translation factors Tx & Ty: ");
scanf("%d %d", &tx, &ty);
translate(x,y,n,tx,ty);

printf("Enter scaling factors Sx & Sy: ");
scanf("%d %d", &tx, &ty);
scale(x,y,n,tx,ty);

rotate(x,y,45,n);
drawobject(x,y,n);
*/

shear(x,y,n,0.2,0.1);
getch();
return 0;
}
