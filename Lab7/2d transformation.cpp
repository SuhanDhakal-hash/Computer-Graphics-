#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int choice;
    int x1 = 100, y1 = 100, x2 = 200, y2 = 200;

    printf("2D Transformations\n");
    printf("1. Translation\n");
    printf("2. Scaling\n");
    printf("3. Rotation\n");
    printf("4. Shearing\n");
    printf("5. Reflection\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        {
            int tx, ty;
            printf("Enter translation factors tx and ty: ");
            scanf("%d%d", &tx, &ty);

            rectangle(x1, y1, x2, y2);
            rectangle(x1 + tx, y1 + ty,
                      x2 + tx, y2 + ty);
            break;
        }

        case 2:
        {
            float sx, sy;
            printf("Enter scaling factors sx and sy: ");
            scanf("%f%f", &sx, &sy);

            rectangle(x1, y1, x2, y2);
            rectangle((int)(x1 * sx), (int)(y1 * sy),
                      (int)(x2 * sx), (int)(y2 * sy));
            break;
        }

        case 3:
        {
            float angle, rad;
            int xr, yr;

            printf("Enter angle of rotation: ");
            scanf("%f", &angle);

            rad = angle * 3.1416 / 180;

            line(x1, y1, x2, y2);

            xr = x1 + (int)((x2 - x1) * cos(rad)
                          - (y2 - y1) * sin(rad));

            yr = y1 + (int)((x2 - x1) * sin(rad)
                          + (y2 - y1) * cos(rad));

            line(x1, y1, xr, yr);
            break;
        }

        case 4:
        {
            float shx;
            printf("Enter shearing factor: ");
            scanf("%f", &shx);

            rectangle(x1, y1, x2, y2);
            rectangle((int)(x1 + shx * y1), y1,
                      (int)(x2 + shx * y2), y2);
            break;
        }

        case 5:
        {
            rectangle(x1, y1, x2, y2);

            /* Reflection about Y-axis */
            rectangle(x2 + 300, y1,
                      x1 + 300, y2);

            break;
        }

        default:
        {
            printf("Invalid choice!");
            break;
        }
    }

    getch();
    closegraph();

    return 0;
}
