#include <graphics.h>
#include <stdio.h>
void boundaryfill(int x, int y ,int b_color,int fill_color)
{
  int value =  getpixel(x, y);
  if(value!=b_color && value!=fill_color)
  {
  	  putpixel(x, y, fill_color);
  	boundaryfill(x + 1, y, b_color, fill_color);
    boundaryfill(x - 1, y, b_color, fill_color);
    boundaryfill(x, y + 1, b_color, fill_color);
    boundaryfill(x, y - 1, b_color, fill_color);
  }
  
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    rectangle(100, 100, 200, 200);
    boundaryfill(150, 150, WHITE, RED);
    getch();
    closegraph();
    return 0;
}


