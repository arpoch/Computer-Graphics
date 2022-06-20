#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
union REGS in,out;

int detectmouse() {
 in.x.ax=0;
 int86(0x33,&in,&out);
 return out.x.ax;
}

void displaymouse(){
 in.x.ax=1;
 int86(0x33,&in,&out);
}

void hidemouse(){
 in.x.ax=2;
 int86(0x33,&in,&out);
}

void showmouselocation(){
 in.x.ax=3;
 int86(0x33,&in,&out);
 printf("X: %d\nY: %d\n",out.x.cx,out.x.dx);
}

void showbuttonstatus(){
 in.x.ax=3;
 int86(0x33,&in,&out);
 if(out.x.bx==0) printf("Button not pressed\n");
 else if(out.x.bx==1) printf("Left button pressed\n");
 else if(out.x.bx==2) printf("Right button pressed\n");
 else if(out.x.bx==3) printf("Center button pressed\n");
}

void setmouselocation(){
 int x,y;
 printf("Enter x positon\nEnter Y postion\n");
 scanf("%d%d",&x,&y);
 in.x.ax=4;
 in.x.cx=x;
 in.x.dx=y;
 int86(0x33,&in,&out);
}

void sethorizontallimit(){
 int x;
 printf("Enter X position\n");
 scanf("%d",&x);
 in.x.ax=7;
 in.x.cx=x;
 in.x.dx=x;
 int86(0x33,&in,&out);
}

void setverticallimit(){
 int y;
 printf("Enter Y position\n");
 scanf("%d",&y);
 in.x.ax=8;
 in.x.cx=y;
 in.x.dx=y;
 int86(0x33,&in,&out);

}
void main(){
 int gdriver=DETECT,gmode,opt;
 initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
 clrscr();
 if(detectmouse!=0) {
  printf("Mouse initialized\n");
  printf("Press: 1, To display mouse\n");
  printf("Press: 2, To hide mouse\n");
  printf("Press: 3, To show mouse location and status\n");
  printf("Press: 4, To set mouse location\n");
  printf("Press: 5, To set horizontal limit\n");
  printf("Press: 6, To set vertical limit\n");
  printf("Press: 8, To clear screen\n");
  printf("Press: 9, To exit\n");

  while(1){
   scanf("%d",&opt);
   if(opt==1) displaymouse();
   else if(opt==2) hidemouse();
   else if(opt==3) {
    showmouselocation();
    showbuttonstatus();
   }
   else if(opt==4){
    setmouselocation();
   }
   else if(opt==5){
    sethorizontallimit();
   }
   else if(opt==6){
    setverticallimit();
   }
   else if(opt==8){
    clrscr();
    printf("Mouse initialized\n");
    printf("Press: 1, To display mouse\n");
    printf("Press: 2, To hide mouse\n");
    printf("Press: 3, To show mouse location and status\n");
    printf("Press: 4, To set mouse location\n");
    printf("Press: 5, To set horizontal limit\n");
    printf("Press: 6, To set vertical limit\n");
    printf("Press: 8, To clear screen\n");
    printf("Press: 9, To exit\n");
   }
   else break;
  };
 }
 else printf("Mouse not initialized\n");

// getch();
 closegraph();
}