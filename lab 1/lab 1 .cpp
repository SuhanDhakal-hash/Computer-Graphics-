#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // ================= RECTANGLE =================
    rectangle(50, 50, 200, 120);

    // ================= SQUARE =================
    rectangle(250, 50, 350, 150);

    // ================= CIRCLE =================
    circle(450, 100, 50);

    // ================= MAN (STICK FIGURE) =================

    // Head
    circle(600, 80, 30);

    // Body
    line(600, 110, 600, 200);

    // Arms
    line(600, 140, 560, 170); // left arm
    line(600, 140, 650, 170); // right arm

    // Legs
    line(600, 200, 570, 250); // left leg
    line(600, 200, 630, 250); // right leg
outtextxy(280,280,"Suhan Dhakal");

    getch();
    closegraph();

    return 0;
}
