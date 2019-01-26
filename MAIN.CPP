#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<bios.h>

void welgr(){
 clrscr();
 int i, a=(getmaxx()-textwidth("<<<             >>>"))/2;
 setfillstyle(1,GREEN);
 bar(0,0,getmaxx(),getmaxy());
 setcolor(15);
 settextstyle(1, 0, 7);
 outtextxy((getmaxx()-textwidth("Student"))/2,1,"Student");
 outtextxy((getmaxx()-textwidth("Database"))/2,80,"Database");
 outtextxy((getmaxx()-textwidth("Management"))/2,160,"Management");
 outtextxy((getmaxx()-textwidth("System"))/2,240,"System");

 do{
 settextstyle(0, 0, 1);
 setcolor(BLUE);
 outtextxy(a,getmaxy()-15,"<<<             >>>");
 setcolor(15);
 outtextxy(a,getmaxy()-15,"    HIT ANY KEY    ");
 delay(250);if(kbhit()){getch();break;}
 setcolor(BLUE);
 outtextxy(a,getmaxy()-15,"<<<             >>>");
 setcolor(15);
 outtextxy(a,getmaxy()-15,"  < HIT ANY KEY >  ");
 delay(250);if(kbhit()){getch();break;}
 setcolor(BLUE);
 outtextxy(a,getmaxy()-15,"<<<             >>>");
 setcolor(15);
 outtextxy(a,getmaxy()-15," << HIT ANY KEY >> ");
 delay(250);if(kbhit()){getch();break;}
 setcolor(BLUE);
 outtextxy(a,getmaxy()-15,"<<<             >>>");
 setcolor(15);
 outtextxy(a,getmaxy()-15,"<<< HIT ANY KEY >>>");
 delay(250);if(kbhit()){getch();break;}
 }while(1);
 setcolor(0);
 for(i=0;i<getmaxy()/4;i++){
  delay(20);
  rectangle(midy-i,midy-i,getmaxx()+i-midy,midy+i);
  rectangle(i,i,getmaxx()-i,getmaxy()-i);
 }
}

void main()
{
 welgr();
}
