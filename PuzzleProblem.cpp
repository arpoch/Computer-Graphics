#include<iostream>
#include<graphics.h>
#include<cmath>

int puzzle[4][4]={{1,2,5,6},{11,7,10,8},{13,4,9,12},{3,15,14,-1}};
int digits(int v){
	if(v<0) return 0;
	int count = 0;
	while(v!=0){
		v=v/10;
		count++;
	}
	return count;
}

char* integertostring(int v){
	int size = digits(v);
	char* str = new char[size+1];
	for(int i=size-1;i>=0;i--){
		int r = v%10;
		char c = 48 + r;
		v=v/10;
		str[i]=c;
		//std::cout<<c<<" "<<str<<std::endl;		
	}
	str[size]='\0';	
	return str;
}

void showPuzzle(int puzzle[][4]){
	cleardevice();
	//top
	line(100,100,400,100);
	//bottom
	line(100,400,400,400);
	//left
	line(100,100,100,400);
	//right
	line(400,100,400,400);
	
	//boxes
	for(int i=0;i<4;i++){
		int left=100,top=100;
		for(int j=0;j<4;j++){
			rectangle(left+j*75,top+i*75,left+(j+1)*75,top+(i+1)*75);
			settextstyle(0,0,3);
			outtextxy((left+j*75)+20,(top+i*75)+20,integertostring(puzzle[i][j]));
		}
	}
}

boolean isPuzzleSolved(int puzzle[][4]){
	int count=1;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(i==3&&j==3) continue;
			if(puzzle[i][j]!=count++) return false;
		}
	}
	return true;
}

void Puzzle(int puzzle[][4]){
	int currentRow=3,currentCol=3;
	while(1){
		if(isPuzzleSolved(puzzle)) break;
		if(kbhit()){
			char ch=getch();
			std::cout<<(int)ch;
			if(ch==72)	{
				//upkey
				if(currentRow+1<=3){
					int temp = puzzle[currentRow+1][currentCol];
					puzzle[currentRow+1][currentCol] = puzzle[currentRow][currentCol];										
					puzzle[currentRow][currentCol] = temp;
					currentRow++;
					showPuzzle(puzzle);					
				}
			}else if(ch==80) {
				//downkey
				if(currentRow-1>=0){
					int temp = puzzle[currentRow-1][currentCol];
					puzzle[currentRow-1][currentCol] = puzzle[currentRow][currentCol];										
					puzzle[currentRow][currentCol] = temp;
					currentRow--;
					showPuzzle(puzzle);					
				}
			}else if(ch==75) {
				//leftkey
				if(currentCol+1<=3){
					int temp = puzzle[currentRow][currentCol+1]; //value
					puzzle[currentRow][currentCol+1] = puzzle[currentRow][currentCol]; //empty										
					puzzle[currentRow][currentCol] = temp;
					currentCol++;
					showPuzzle(puzzle);
				}
			}else if(ch==77) {
				//rightkey
				if(currentCol-1>=0){
					int temp = puzzle[currentRow][currentCol-1];
					puzzle[currentRow][currentCol-1] = puzzle[currentRow][currentCol];
					puzzle[currentRow][currentCol] = temp;
					currentCol--;
					showPuzzle(puzzle);
				}
			}
		}
	}
}

int main(){
	int gd=DETECT,gm;  
    initgraph(&gd,&gm,"c:\\tc\\bgi");
	initwindow(500,500);
	showPuzzle(puzzle);

	Puzzle(puzzle);
	settextstyle(0,0,3);
	outtextxy(150,450,"Solved");
	getch();
	closegraph();
}
