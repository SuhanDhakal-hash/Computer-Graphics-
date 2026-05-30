#include <graphics.h>
#include <conio.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    rectangle(50, 50, 200, 120);

    rectangle(250, 50, 350, 150);

    circle(450, 100, 50);


    
    circle(600, 80, 30);

    
    line(600, 110, 600, 200);

    
    line(600, 140, 560, 170); 
    line(600, 140, 650, 170); 

    
    line(600, 200, 570, 250); 
    line(600, 200, 630, 250); 
outtextxy(280,280,"Suhan Dhakal");

    getch();
    closegraph();

    return 0;
}
