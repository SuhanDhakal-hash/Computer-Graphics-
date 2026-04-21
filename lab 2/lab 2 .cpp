#include <graphics.h>
#include <stdio.h>

int main() {
    int x1 = 100, y1 = 100, x2 = 400, y2 = 300;
    float dx, dy, steps, xinc, yinc, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    xinc = dx / steps;
    yinc = dy / steps;

    x = x1;
    y = y1;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    for(int i = 0; i <= steps; i++) {
        putpixel(x, y, WHITE);
        x += xinc;
        y += yinc;
    }
outtextxy(300,200,"Suhan Dhakal");

    getch();
    closegraph();
    return 0;
}
