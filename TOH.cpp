#include<iostream>
#include<graphics.h>
#include<cmath>

//For variable disk either change the width according to the number of disks given by the user or
// provide the width size upto which certain disk are allowed, increase the matrix size accordingly
//Storing the disk position in each tower using matrix
int a[10],b[10],c[10];
int totalDisk,heightOfDisk = 25;
int widthOfDisk = 200, margin =  widthOfDisk/20;
void onTowerA(){
	int left=0;	
	int right=left+widthOfDisk,bottom=600,top=bottom-heightOfDisk;
	for(int i=0;i<totalDisk;i++){
		if(a[i]!=0){
			int tempLeft = left + i*margin;
			int tempRight = right - i*margin;
			//std::cout<<margin<<" "<<left<<" "<<top<<" "<<right<<" "<<bottom<<std::endl;
			rectangle(tempLeft,top,tempRight,bottom);
			bottom = top;
			top -= heightOfDisk;
		}
	}
}

void onTowerB(){
	int left=300;
	int right=left+widthOfDisk,bottom=600,top=bottom-heightOfDisk;
	for(int i=0;i<totalDisk;i++){
		//std::cout<<margin<<" "<<left<<" "<<top<<" "<<right<<" "<<bottom<<std::endl;
		if(b[i]!=0){
			int tempLeft = left + i*margin;
			int tempRight = right - i*margin;
			rectangle(tempLeft,top,tempRight,bottom);
			bottom = top;
			top -=heightOfDisk;
		}	
	}
}

void onTowerC(){
	int left=700;
	int right=left+widthOfDisk,bottom=600,top=bottom-heightOfDisk;
	for(int i=0;i<totalDisk;i++){
		//std::cout<<margin<<" "<<left<<" "<<top<<" "<<right<<" "<<bottom<<std::endl;
		if(c[i]!=0){
			int tempLeft = left + i*margin;
			int tempRight = right - i*margin;
			rectangle(tempLeft,top,tempRight,bottom);
			bottom = top;
			top -=heightOfDisk;
		}		
	}
}

void drawDisk(){
	cleardevice();
	// Main Base
    line(0, 600, 1000, 600);
    // 1st Line
    line(100, 600, 100, 300);
    // 2nd Line
    line(400, 600, 400, 300);
    // 3rd Line
    line(800, 600, 800, 300); 
	onTowerA();
	onTowerB();
	onTowerC();
	Sleep(1000);
}

int getDisk(int totalDisks,int currDisk){
	return totalDisks-currDisk;
}

void TOHA(int disks,int *src,int *dest,int *aux){
	if(disks==0) return;
	TOHA(disks-1,src,aux,dest);
	std::cout<<"Move disk "<<disks<< " from " <<src<<" to "<<dest<<std::endl;
	src[getDisk(totalDisk,disks)]=0;
	dest[getDisk(totalDisk,disks)]=1;
	drawDisk();
	TOHA(disks-1,aux,dest,src);
}

int main(){
	int gd=DETECT,gm;  
    initgraph(&gd,&gm,"c:\\tc\\bgi");
	initwindow(1024,768);
	std::cout<<"Enter no. of disks(max:10) "<<std::endl;
	std::cin>>totalDisk;
	for(int i=0;i<10;i++){
		a[i]=1;
		b[i]=0;
		c[i]=0;
	}
	//onTowerA();
	drawDisk();
	TOHA(totalDisk,a,c,b);
	getch();
	closegraph();
}
