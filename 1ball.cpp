#include <graphics.h>
#include <conio.h>
#include <dos.h>

int main()
{
    int gd = DETECT, gm;
    int x = 20;
    int y = 200;

    initgraph(&gd, &gm, "");

    while (!kbhit())
    {
        cleardevice();

        setcolor(GREEN);
        circle(x, y, 20);

        setfillstyle(SOLID_FILL, GREEN);
        floodfill(x, y, GREEN);

        x = x + 10;

        if (x > 620)
            x = 20;

        delay(30);
    }
outtextxy(280,280,"Suhan Dhakal");
    closegraph();
    return 0;
}
