/* Mine Sweeper Game */

#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <time.h>
#define MROW 8
#define MCOL 8
#define MINES 5
#define BSIZE 15
union REGS i,o;
//9 for mines
main()
{
int bm=DETECT,bg=DETECT,maxx,maxy,button,x,y,i,j,checkx,checky,nclick;
int arr[8][8],dot[MINES];
int count1,count2;
int row,col;
time_t t;
clrscr();
initgraph(&bm,&bg,"e:\tcc\bgi");
maxx=getmaxx();
maxy=getmaxy();
if(initmouse()==0)
		 {
		 closegraph();
		 restorecrtmode();
		 printf("MOUSE NOT FOUND");
		 exit(1);
		 }
while(!kbhit())
		 {
		 char loop='t';
		 setcolor(WHITE);
		 setviewport(0,0,getmaxx(),getmaxy(),1);
		 clearviewport();
		 showmouse();
		 //It Blanks the Array
		 for(i=0;i<MROW;i++)
		 		 for(j=0;j<MCOL;j++)
		 		 		 arr[i][j]=0;
		 //put mines in random blocks
		 srand((unsigned) time(&t));
		 for(i=0;i<MINES;i++)
		 		 {
		 		 dot[i]=rand()%64;
		 		 for(j=0;j<i;j++)
		 		 		 if(dot[i]==dot[j])
		 		 		 		 break;
		 		 if(i!=j)
		 		 		 {
		 		 		 i--;
		 		 		 continue;
		 		 		 }
		 		 else
		 		 		 {
		 		 		 row=dot[i]/MROW;
		 		 		 col=dot[i]%MCOL;
		 		 		 arr[row][col]=9;
		 		 		 }
		 		 }
		 //put mines value in other blocks
		 for(row=0;row<MROW;row++)
		 		 {
		 		 for(col=0;col<MCOL;col++)
		 		 		 {
		 		 		 if(arr[row][col]!=9)		 //No Mine
		 		 		 		 {
		 		 		 		 int i,num=0,temp,ecol,erow,startrow;
		 		 		 		 temp=col==0?col:col-1;
		 		 		 		 ecol=col!=MCOL-1?col+1:col;
		 		 		 		 startrow=row==0?row:row-1;
		 		 		 		 erow=row==MROW-1?row:row+1;
		 		 		 		 for(i=startrow;i<=erow;i++)
		 		 		 		 		 for(j=temp;j<=ecol;j++)
		 		 		 		 		 		 if(arr[i][j]==9)
		 		 		 		 		 		 		 num++;
		 		 		 		 arr[row][col]=num;
		 		 		 		 }
		 		 		 }
		 		 }

		 rectangle(0,0,maxx,maxy);
		 //sets view port to the play area only
		 setviewport(200,190,385,370,1);
		 nclick=0;
		 while(!kbhit()&&loop=='t')
		 		 {
		 		 int row=10,col=5;
		 		 setlinestyle(0,0,3);
		 		 rectangle(row-5,col-3,row*17,col*33); //Draws outer block
		 		 setlinestyle(0,0,2);
		 		 for(i=0;i<MROW;i++)
		 		 		 {
		 		 		 for(j=0;j<MCOL;j++)
		 		 		 		 {
		 		 		 		 rectangle(row,col,row+BSIZE,col+BSIZE);
		 		 		 		 if(arr[i][j]!=9)
		 		 		 		 		 {
		 		 		 		 		 int temp[3];
		 		 		 		 		 if(arr[i][j]>=80)
		 		 		 		 		 		 outtextxy(row+4,col+4,"F");
		 		 		 		 		 else
		 		 		 		 		 		 if(arr[i][j]>=50)
		 		 		 		 		 		 {
		 		 		 		 		 		 itoa((arr[i][j]-50),temp,10);
		 		 		 		 		 		 outtextxy(row+BSIZE/2,col+BSIZE/2,temp);
		 		 		 		 		 		 }
		 		 		 		 		 }
		 		 		 		 row+=BSIZE+5;
		 		 		 		 }
		 		 		 row=10;
		 		 		 col+=BSIZE+5;
		 		 		 }
		 		 if(nclick==MROW*MCOL-MINES)
		 		 		 {
		 		 		 setviewport(0,0,getmaxx(),getmaxy(),1);
		 		 		 outtextxy(200,100,"CONGRATS! YOU WON THE GAME");
		 		 		 getch();
		 		 		 loop='f';
		 		 		 }
		 		 getpos(&button,&x,&y);

		 		 //puts F tag in Array
		 		 if(button&2)
		 		 		 {
		 		 		 int val,prex=x,prey=y;
		 		 		 x=210+(x-210)/20*20;
		 		 		 y=195+(y-195)/20*20;
		 		 		 val=arr[(y-195)/20][(x-210)/20];
		 		 		 if(val<10 || val>=80)
		 		 		 		 {
		 		 		 		 val=val>=80?val-80:80+val;
		 		 		 		 arr[(y-195)/20][(x-210)/20]=val;

		 		 		 		 while(button&2)
		 		 		 		 		 getpos(&button,&x,&y);

		 		 		 		 hidemouse();
		 		 		 		 setpos(30,50);
		 		 		 		 clearviewport();
		 		 		 		 showmouse();
		 		 		 		 setpos(prex,prey);
		 		 		 		 }
		 		 		 }

		 		 if(button&1 && x>=210 && x<=365 && y>=195 && y<=350)
		 		 		 {
		 		 		 char temp[4];
		 		 		 int trow,tcol;
		 		 		 //determine current box
		 		 		 x=210+(x-210)/20*20;
		 		 		 y=195+(y-195)/20*20;
		 		 		 trow=(y-195)/20;
		 		 		 tcol=(x-210)/20;
		 		 		 if(arr[trow][tcol]==9)
		 		 		 		 {
		 		 		 		 int row=10,col=5;
		 		 		 		 setviewport(0,0,getmaxx(),getmaxy(),1);
		 		 		 		 hidemouse();
		 		 		 		 outtextxy(200,100,"SORRY,YOU LOOSE THE GAME");
		 		 		 		 setviewport(200,190,385,370,1);
		 		 		 		 //prints X marks in END on screen
		 		 		 		 for(i=0;i<MROW;i++)
		 		 		 		 		 {
		 		 		 		 		 for(j=0;j<MCOL;j++)
		 		 		 		 		 		 {
		 		 		 		 		 		 if(arr[i][j]==9 || arr[i][j]==89)
		 		 		 		 		 		 		 {
		 		 		 		 		 		 		 setfillstyle(1,RED);
		 		 		 		 		 		 		 bar(row,col,row+BSIZE,col+BSIZE);
		 		 		 		 		 		 		 outtextxy(row+5,col+5,"x");
		 		 		 		 		 		 		 }
		 		 		 		 		 		 row+=20;
		 		 		 		 		 		 }
		 		 		 		 		 row=10;
		 		 		 		 		 col+=20;
		 		 		 		 		 }
		 		 		 		 showmouse();
		 		 		 		 setviewport(0,0,getmaxx(),getmaxy(),1);
		 		 		 		 setfillstyle(1,YELLOW);
		 		 		 		 bar(170,400,270,425);
		 		 		 		 bar(330,400,430,425);
		 		 		 		 while(loop=='t')
		 		 		 		 		 {
		 		 		 		 		 setcolor(BLUE);
		 		 		 		 		 outtextxy(180,410,"PLAY AGAIN");
		 		 		 		 		 outtextxy(360,410,"QUIT");
		 		 		 		 		 getpos(&button,&x,&y);
		 		 		 		 		 if(!button&1)
		 		 		 		 		 		 {
		 		 		 		 		 		 if(x>=170 && x<=270 && y>=400 && y<=425)
		 		 		 		 		 		 		 {
		 		 		 		 		 		 		 setfillstyle(1,CYAN);
		 		 		 		 		 		 		 bar(170,400,270,425);
		 		 		 		 		 		 		 setfillstyle(1,YELLOW);
		 		 		 		 		 		 		 bar(330,400,430,425);
		 		 		 		 		 		 		 outtextxy(180,410,"PLAY AGAIN");
		 		 		 		 		 		 		 outtextxy(360,410,"QUIT");
		 		 		 		 		 		 		 while(x>=170 && x<=270 && y>=400 && y<=425 && !button&1)
		 		 		 		 		 		 		 		 getpos(&button,&x,&y);
		 		 		 		 		 		 		 }
		 		 		 		 		 		 if(x>=330 && x<=430 && y>=400 && y<=425)
		 		 		 		 		 		 		 {
		 		 		 		 		 		 		 setfillstyle(1,CYAN);
		 		 		 		 		 		 		 bar(330,400,430,425);
		 		 		 		 		 		 		 setfillstyle(1,YELLOW);
		 		 		 		 		 		 		 bar(170,400,270,425);
		 		 		 		 		 		 		 }
		 		 		 		 		 		 		 outtextxy(180,410,"PLAY AGAIN");
		 		 		 		 		 		 		 outtextxy(360,410,"QUIT");
		 		 		 		 		 		 		 while(x>=330 && x<=430 && y>=400 && y<=425 && !button&1)
		 		 		 		 		 		 		 		 getpos(&button,&x,&y);
		 		 		 		 		 		 }
		 		 		 		 		 else
		 		 		 		 		 		 {
		 		 		 		 		 		 if(x>=170 && x<=270 && y>=400 && y<=425)
		 		 		 		 		 		 		 {
		 		 		 		 		 		 		 setviewport(200,190,385,370,1);
		 		 		 		 		 		 		 loop='f';
		 		 		 		 		 		 		 hidemouse();
		 		 		 		 		 		 		 break;
		 		 		 		 		 		 		 }
		 		 		 		 		 		 if(x>=330 && x<=430 && y>=400 && y<=425)
		 		 		 		 		 		 		 {
		 		 		 		 		 		 		 restorecrtmode();
		 		 		 		 		 		 		 closegraph();
		 		 		 		 		 		 		 exit(0);
		 		 		 		 		 		 		 }
		 		 		 		 		 		 }
		 		 		 		 		 }
		 		 		 		 }
		 		 		 else
		 		 		 		 { //NOT ON DANGER AREA
		 		 		 		 if(arr[trow][tcol]<50)
		 		 		 		 		 {
		 		 		 		 		 nclick++;
		 		 		 		 		 arr[trow][tcol]+=50;
		 		 		 		 		 }
		 		 		 		 }
		 		 		 }
		 		 }
		 if(loop=='t')
		 		 {
		 		 restorecrtmode();
		 		 closegraph();
		 		 exit(0);
		 		 }
		 }
}

initmouse()
{
i.x.ax=0;
int86(0x0033,&i,&o);
return(o.x.ax);
}

showmouse()
{
i.x.ax=1;
int86(0x0033,&i,&o);
}

hidemouse()
{
i.x.ax=2;
int86(0x0033,&i,&o);
}

restarea(int x1,int x2,int y1,int y2)
{
i.x.ax=7;
i.x.cx=x1;
i.x.dx=x2;
int86(0x0033,&i,&o);
i.x.ax=8;
i.x.cx=y1;
i.x.dx=y2;
int86(0x0033,&i,&o);
}

setpos(int x,int y)
{
i.x.ax=4;
i.x.cx=x;
i.x.dx=y;
int86(0x0033,&i,&o);
}

getpos(int *button,int *x,int *y)
{
i.x.ax=3;
int86(0x0033,&i,&o);
*button=o.x.bx;
*x=o.x.cx;
*y=o.x.dx;
}