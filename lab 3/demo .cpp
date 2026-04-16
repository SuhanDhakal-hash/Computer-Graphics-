#include <graphics.h>
#include <conio.h>
#include <stdio.h>


int main() {
    int gd = DETECT, gm;

float x1, y1, x2, y2;
float dx, dy, steps, xinc, yinc, x, y;
int i;
 printf("Enter x1 y1: ");
scanf("%f %f", &x1, &y1);
 printf("Enter x2 y2: ");
scanf("%f %f", &x2, &y2);
initgraph(&gd, &gm, "");
dx = x2 - x1;
dy = y2 - y1;
if (abs(dx) > abs(dy)) {
steps = abs(dx);
} else {
steps = abs(dy);
}
printf("dx = %.2f\n", dx);
printf("dy = %.2f\n", dy);
printf("steps = %.2f\n", steps);
xinc = dx / steps;
yinc = dy / steps;
x = x1;
y = y1;
for (i = 0; i <= steps; i++) {
putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE);
x += xinc;
 y += yinc;
}
outtextxy(250,250,"Suhan Dhakal");
getch();
closegraph();
return 0;

}
