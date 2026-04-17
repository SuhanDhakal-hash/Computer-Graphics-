#include <graphics.h>
#include <stdio.h>
#include <math.h>


void plotEllipsePoints(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

int main()
{
    int xc, yc, rx, ry;
    int x = 0, y;
    float p1, p2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    
    printf("Enter center (xc yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter rx and ry: ");
    scanf("%d %d", &rx, &ry);

    y = ry;


    p1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);

    while ((2 * ry * ry * x) <= (2 * rx * rx * y))
    {
        plotEllipsePoints(xc, yc, x, y);

        if (p1 < 0)
        {
            x++;
            p1 = p1 + (2 * ry * ry * x) + (ry * ry);
        }
        else
        {
            x++;
            y--;
            p1 = p1 + (2 * ry * ry * x) - (2 * rx * rx * y) + (ry * ry);
        }
    }

    
    p2 = (ry * ry * (x + 0.5) * (x + 0.5)) +
         (rx * rx * (y - 1) * (y - 1)) -
         (rx * rx * ry * ry);

    while (y >= 0)
    {
        plotEllipsePoints(xc, yc, x, y);

        if (p2 > 0)
        {
            y--;
            p2 = p2 - (2 * rx * rx * y) + (rx * rx);
        }
        else
        {
            x++;
            y--;
            p2 = p2 + (2 * ry * ry * x) - (2 * rx * rx * y) + (rx * rx);
        }
    }
outtextxy(250,250,"Suhan Dhakal");

    getch();
    closegraph();
    return 0;
}
