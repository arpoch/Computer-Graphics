#include<iostream>
#include<graphics.h>
#include<windows.h>
#include<cmath>
#include<ctime>
void drawClock(int sx,int sy,int mx,int my,int hx,int hy){
	circle(320,240,200);
	circle(320,240,10);
	
	line(320,40,320,60);	
	line(320,440,320,420);
	line(120,240,140,240);
	line(520,240,500,240);

	outtextxy(215,90,"11");
	outtextxy(160,155,"10");	
	outtextxy(135,233,"9");
	outtextxy(315,60,"12");
	outtextxy(405,90,"1");
	outtextxy(460,155,"2");	
	outtextxy(495,233,"3");
	outtextxy(400,380,"5");
	outtextxy(465,310,"4");
	outtextxy(315,410,"6");
	outtextxy(230,380,"7");
	outtextxy(165,310,"8");
	//second hand
	line(320,240,sx,sy);
	//min hand
	line(320,240,mx,my);
	//hour hand
	line(320,240,hx,hy);
}

int main(){
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	initwindow(640,480);
	
	while(true){
		cleardevice();
		std::time_t result = std::time(NULL);
		struct tm *tS = std::localtime(&result);
		
		float hx = cos((tS->tm_hour*30 + tS->tm_min / 2) * M_PI / 180 - M_PI / 2) * 120 + 320;
        float hy = sin((tS->tm_hour*30 + tS->tm_min / 2) * M_PI / 180 - M_PI / 2) * 120 + 240;
        float mx = cos(tS->tm_min * M_PI / 30 - M_PI / 2) * 140 + 320;
        float my = sin(tS->tm_min * M_PI / 30 - M_PI / 2) * 140 + 240;
        float sx = cos(tS->tm_sec * M_PI / 30 - M_PI / 2) * 180 + 320;
        float sy = sin(tS->tm_sec * M_PI / 30 - M_PI / 2) * 180 + 240;
		
		drawClock(sx,sy,mx,my,hx,hy);
		Sleep(1000);
		//cleardevice();		
	}
	getch();
	return 0;
}

