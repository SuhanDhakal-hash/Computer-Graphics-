#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main()
{
int gd = DETECT, gm;
int x = -170;
initgraph(&gd, &gm, "");
while (!kbhit())
{
cleardevice();
line(0, 300, getmaxx(), 300);
rectangle(x + 50, 220, x + 170, 270);
line(x + 70, 220, x + 90, 190);
line(x + 90, 190, x + 140, 190);
line(x + 140, 190, x + 160, 220);
circle(x + 75, 270, 15);
circle(x + 145, 270, 15);
x = x + 5;
if (x > getmaxx())
x = -170;
delay(30);
}
closegraph();
    return 0;
}
