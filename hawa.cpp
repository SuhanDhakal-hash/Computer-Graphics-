#include<stdio.h>
#include<graphics.h>
int main()
{
	int choice, gd= DETECT, gm;
	initgraph(&gd,&gm,"");
	line(100,200,300,400);
	printf("Enter a choice");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			line(200,300,500,900);
		case 2:
			circle(100,100,50);
	}
	getch();
	closegraph();
	return 0;
}
