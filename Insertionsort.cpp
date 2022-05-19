#include<iostream>
#include<graphics.h>
#include<cmath>
#include<string>

int n;
int maxHeight=30;
int top=200,bottom=top+maxHeight;

int digits(int v){
	if(v==0) return 1;
	int count = 0;
	while(v!=0){
		v=v/10;
		count++;
	}
	return count;
}

void integertostring(int startPos,int size,int v){
	char* str = new char[size+1];
	for(int i=size-1;i>=0;i--){
		int r = v%10;
		char c = 48 + r;
		v=v/10;
		str[i]=c;
		//std::cout<<c<<" "<<str<<std::endl;		
	}
	str[size]='\0';
	settextstyle(0,0,3);
	outtextxy(startPos+2,top+5,str);
	delete str;
}

void printArr(int* arr){
	cleardevice();
	int startPos=25,endPos=startPos;
	for(int i=0;i<n;i++){
		int size = digits(arr[i]);
		rectangle(startPos,top,endPos+(28*size),bottom);
		integertostring(startPos,size,arr[i]);
		startPos+=28*size;
		endPos=startPos;
	}
	Sleep(1000);
}

void insertionsort(int* arr){
	for(int i=1;i<n;i++){
		int key = arr[i];
		int j=i-1;
		while(j>=0 && arr[j]>key){
			int temp = arr[j];
			arr[j+1] = arr[j];
			arr[j] = key;
			printArr(arr);
			j--;
		}
	}
}

int main(){

	int gd=DETECT,gm;  
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    initwindow(1080,720);
	std::cout<<"Enter array size"<<std::endl;
	std::cin>>n;
	int arr[n];
	std::cout<<"Enter elements in the array"<<std::endl;
	for(int i=0;i<n;i++){
		std::cin>>arr[i];
	}
	printArr(arr);
	insertionsort(arr);
	getch();
	closegraph();
}
