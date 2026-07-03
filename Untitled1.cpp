#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

    float xwmin, ywmin, xwmax, ywmax;
    float xvmin, yvmin, xvmax, yvmax;

    printf("Enter Window (xmin ymin xmax ymax): ");
    scanf("%f %f %f %f", &xwmin, &ywmin, &xwmax, &ywmax);

    printf("Enter Viewport (xmin ymin xmax ymax): ");
    scanf("%f %f %f %f", &xvmin, &yvmin, &xvmax, &yvmax);

    /* Draw Window */
    rectangle((int)xwmin, (int)ywmin, (int)xwmax, (int)ywmax);
    outtextxy((int)xwmin + 10, (int)ywmin - 20, "WINDOW");

    /* Draw Viewport */
    rectangle((int)xvmin, (int)yvmin, (int)xvmax, (int)yvmax);
    outtextxy((int)xvmin + 10, (int)yvmin - 20, "VIEWPORT");

    /* Draw circle inside window */
    int xc = 50, yc = 50, r = 20;
    circle(xc, yc, r);

    /* Scaling factors */
    float sx = (xvmax - xvmin) / (xwmax - xwmin);
    float sy = (yvmax - yvmin) / (ywmax - ywmin);

    /* Window to Viewport Mapping */
    int vx = (int)(xvmin + (xc - xwmin) * sx);
    int vy = (int)(yvmin + (yc - ywmin) * sy);

    /* Scale radius */
    int vr = (int)(r * ((sx + sy) / 2));

    setcolor(RED);
    circle(vx, vy, vr);

    outtextxy(300, 450, "Rajil");

    getch();
    closegraph();
    return 0;
}
