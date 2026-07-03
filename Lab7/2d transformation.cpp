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
    int cx, cy;

    printf("Enter angle of rotation: ");
    scanf("%f", &angle);

    rad = angle * 3.1416 / 180;

    cx = (x1 + x2) / 2;
    cy = (y1 + y2) / 2;

   rectangle(x1, y1, x2, y2);

    
    int x[4] = {x1, x2, x2, x1};
    int y[4] = {y1, y1, y2, y2};

    int rx[4], ry[4];

    for(int i = 0; i < 4; i++)
    {
        rx[i] = cx + (x[i] - cx) * cos(rad) - (y[i] - cy) * sin(rad);
        ry[i] = cy + (x[i] - cx) * sin(rad) + (y[i] - cy) * cos(rad);
    }

    
    line(rx[0], ry[0], rx[1], ry[1]);
    line(rx[1], ry[1], rx[2], ry[2]);
    line(rx[2], ry[2], rx[3], ry[3]);
    line(rx[3], ry[3], rx[0], ry[0]);

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
outtextxy (250,250,"Suhan Dhakal ");
    getch();
    closegraph();

    return 0;
}
