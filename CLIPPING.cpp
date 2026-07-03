#include <stdio.h>
#include <graphics.h>
#include <conio.h>

#define INSIDE 0
#define LEFT   1
#define RIGHT  2
#define BOTTOM 4
#define TOP    8

int xmin, ymin, xmax, ymax;

int get_code(double x, double y)
{
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;

    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;

    return code;
}

void cohen_sutherland_clip(double x0, double y0, double x1, double y1)
{
    int code0 = get_code(x0, y0);
    int code1 = get_code(x1, y1);
    int accept = 0;

    while (1)
    {
        if (!(code0 | code1))
        {
            accept = 1;
            break;
        }
        else if (code0 & code1)
        {
            break;
        }
        else
        {
            double x, y;
            int code_out = code0 ? code0 : code1;

            if (code_out & TOP)
            {
                x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
                y = ymax;
            }
            else if (code_out & BOTTOM)
            {
                x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
                y = ymin;
            }
            else if (code_out & RIGHT)
            {
                y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
                x = xmax;
            }
            else if (code_out & LEFT)
            {
                y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
                x = xmin;
            }

            if (code_out == code0)
            {
                x0 = x;
                y0 = y;
                code0 = get_code(x0, y0);
            }
            else
            {
                x1 = x;
                y1 = y;
                code1 = get_code(x1, y1);
            }
        }
    }

    if (accept)
    {
        setcolor(GREEN);
        line((int)x0, (int)y0, (int)x1, (int)y1);
    }
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TurboC3\\BGI");

    outtextxy(300, 450, "Suhan Dhakal");

    xmin = 100;
    ymin = 100;
    xmax = 400;
    ymax = 400;

    setcolor(WHITE);
    rectangle(xmin, ymin, xmax, ymax);

    /* Original line before clipping */
    setcolor(RED);
    line(50, 50, 450, 450);

    /* Clipped line */
    cohen_sutherland_clip(50, 50, 450, 450);

    getch();
    closegraph();
    return 0;
}
