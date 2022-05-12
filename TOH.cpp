#include<iostream>
#include<graphics.h>

class A{
	int maxLen=210,maxheight=25;
	//int left=0,top=650-height,right=left+width,bottom=top+height;

	void createPreA(int n){
		line(100,50,100,650); //first pillar
		
	}
};

void initDraw(int totalDisk,int *diskMargin){
	line(100,50,100,650); //first pillar
	line(400,50,400,650); //second pillar
	line(800,50,800,650); //third pillar
	line(50,650,800,650); //base
	int width=200,height=25,left=0,top=650-height,right=left+width,bottom=top+height;
	//float percentageM=margin/(width/(float)100), blockWidth=(width*percentageM/100);
	int blockWidth = (width/totalDisk)/2;
//	float percentageM= (blockWidth*100)/width;
//	int margin = width*percentageM/100;
	//std::cout<<percentageM<<" "<<blockWidth<<" "<<margin<<std::endl;	
	for(int i=0;i<totalDisk;i++){	
		std::cout<<left<<" "<<right<<std::endl;
		diskMargin[i]=left;	
//		setfillstyle(SOLID_FILL ,RED); 
//		rectangle(left,top,right,bottom);
//		floodfill(left+1,bottom-1,WHITE);
//		floodfill(101,bottom-1,WHITE);
		left+=blockWidth;
		top-=height;
		right-=blockWidth;
		bottom=top+height;
	}
//	for(int j=0;j<totalDisk;j++){
//		std::cout<<diskMargin[j];
//	}
}

void hanoi(int n,char src,char dest, char aux){
	if(n==0) return;
	hanoi(n-1,src,aux,dest);	
	//Alternative movement
	//[first, third,... put always on aux][Second, fourth,... put always on dest]
	std::cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<std::endl;
	hanoi(n-1,aux,dest,src);	
	//Alternative movement
	//[first, third,... put always on dest][second, fourth,... put always on aux]
}

int main(){
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\BGI");
	initwindow(1000,800);
	int n=0;
	std::cout<<"Enter no. of disks\n";
	std::cin>>n;
	int diskWidth[n];
	//init plane
	initDraw(n,diskWidth);
	//hanoi(n,'A','B','C');
	floodfill(2,649,BLACK);
	//floodfill(101,bottom-1,BLACK);
	getch();
	closegraph();
	return 0;
}
