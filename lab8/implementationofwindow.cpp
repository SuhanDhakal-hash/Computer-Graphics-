#include<graphics.h>
#include<stdio.h>
#include<conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float wxmin, wymin, wxmax, wymax;
    float vxmin, vymin, vxmax, vymax;

    printf("Enter Window (xmin ymin xmax ymax): ");
    scanf("%f%f%f%f", &wxmin, &wymin, &wxmax, &wymax);

    printf("Enter Viewport (xmin ymin xmax ymax): ");
    scanf("%f%f%f%f", &vxmin, &vymin, &vxmax, &vymax);

    rectangle(wxmin, wymin, wxmax, wymax);
    outtextxy(wxmin + 10, wymin - 20, "WINDOW");

    rectangle(vxmin, vymin, vxmax, vymax);
    outtextxy(vxmin + 10, vymin - 20, "VIEWPORT");

    circle(50, 50, 20);

    float sx = (vxmax - vxmin) / (wxmax - wxmin);
    float sy = (vymax - vymin) / (wymax - wymin);

    circle(
        vxmin + (50 - wxmin) * sx,
        vymin + (50 - wymin) * sy,
        20 * sx
    );

    setcolor(WHITE);
    outtextxy(300, 450, "Suhan Dhakal");

    getch();
    closegraph();
    return 0;
}
