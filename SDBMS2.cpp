#include<stdio.h>
#include<bios.h>
#include<conio.h>
#include<ctype.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
enum TYPE {
    PASSWORD,
    INT,
    FLOAT,
    TEXT,
    ALL,
};
union REGS i,o;

int buttonm,xm,ym,gd=9,gm=1,close=1,set=1,midx,midy;

//declearation function
void getmousepos(int *buttonm,int *xm, int *ym);
void restrictmouse(int x1,int y1,int x2,int y2);
void showmouse();
int initmouse();
void setmousepos(int &xpos,int &ypos);
void hidemouse();
int menu(int);
int doctor();
void adddoc();
void deletedoc();
void searchdoc();
int patient();
void updatepat();
void searchpat();
void deleteatt();
void welgr();
void userl();
void notice();
void setusrl();
void changeusrl();
void removeusrl();
int dropmenu(char menu[7][30],int x1,int y1,int x2,int y2,int opt);
void button(char name[15],int x1,int y1,int x2,int y2,int c);
void clrwin(int opt);
void drawwindow(char head[30],int x1, int y1, int x2, int y2, int c);
int program();
void managetype();
int about();
int sth();
int rooms();
void manageroom();
void input(int x,int y,char result[50],int limit ,int tc,int bkc,int type);
void inputbox(int x,int y,int limit,int bkc);
//end declearation
void main(){
 _setcursortype(0);
 initgraph(&gd,&gm,"..\\BGI");
 int menu1=-1;
 midx=getmaxx()/2;
 midy=getmaxy()/2;
 clrscr();
 welgr();
 setfillstyle(1,BLUE);
 bar(0,0,getmaxx(),getmaxy());
 setcolor(3);
 settextstyle(2,0,5);
 settextjustify(CENTER_TEXT, TOP_TEXT);
 outtextxy(midx,0,"==== Student Database Management System ====");
 settextjustify(LEFT_TEXT, TOP_TEXT);
 settextstyle(0,0,0);
 clrwin(2);
 restrictmouse(10,18,getmaxx()-10,getmaxy()-10);
 setmousepos(midx,midy);
 showmouse();
 getmousepos(&buttonm,&xm,&ym);
 menu(menu1);
 while(1){
  showmouse();
  getmousepos(&buttonm,&xm,&ym);
  if(buttonm==1){
   if(xm>=10&&xm<=34&&ym>=18&&ym<=32){
    menu1=0;
   }else if(xm>=37&&xm<=110&&ym>=18&&ym<=32){
     menu1=1;
   }else if(xm>=112&&xm<=202&&ym>=18&&ym<=32){
     menu1=2;
   }else if(xm>=203&&xm<=238&&ym>=18&&ym<=32){
     menu1=3;
   }else if(xm>=243&&xm<=318&&ym>=18&&ym<=32){
     menu1=4;
   }else if(xm>=323&&xm<=366&&ym>=18&&ym<=32){
     menu1=5;} else menu1=-1;
   clrwin(1);
   menu(menu1);
   switch(menu1){
    case 0:program();break;
    case 1:doctor();break;
    case 2:patient();break;
    case 3:rooms();break;
    case 4:sth();break;
    case 5:about();break;
   }
  }
 }
}
//mouse function
int initmouse(){
 i.x.ax=0;//for  initialising mouse.
 int86(0x33,&i,&o);
 return (o.x.ax);
}

void showmouse(){
 i.x.ax=1; // for displaying mouse pointer.
 int86(0x33,&i,&o);
}
void hidemouse(){
 i.x.ax=2;
 int86(0x33,&i,&o);
}

void setmousepos(int &xpos,int &ypos){
 i.x.ax=4;
 i.x.cx=xpos;
 i.x.dx=ypos;
 int86(0x33,&i,&o);
}

void restrictmouse(int x1,int y1,int x2,int y2){
 i.x.ax=7;     //to define the upper left boundry of mouse.
 i.x.cx=x1;
 i.x.dx=x2;
 int86(0x33,&i,&o);
 i.x.ax=8;   //to define the bottom right boundry of mouse.
 i.x.cx=y1;
 i.x.dx=y2;
 int86(0x33,&i,&o);
}
void getmousepos(int *buttonm,int *x, int *y){
 i.x.ax=3; //to move mouse.
 int86(0x33,&i,&o);
 *buttonm=o.x.bx;
 *x=o.x.cx;
 *y=o.x.dx;
}
//end mouse function

int sth(){
 char menu[5][30]={"Add Marksheet              <","View Marksheet             <",
 "Update Marksheet           <","Delete Marksheet           <","Calculate Gradewise Averages"};
 int opt=-1,j;
 close=1;
 dropmenu(menu,242,33,490,118,opt);
 do{
  showmouse();
  getmousepos(&buttonm,&xm,&ym);
  if(xm>=242+10&&xm<=490-10&&ym>=33+8&&ym<=118-8&&buttonm==1){
   for(j=0;j<(118-33-8)/14;j++)
    if((ym-33-8)/14==j){
     opt=j;
     break;
    }
   dropmenu(menu,242,33,490,118,opt);
   switch(opt){
    case 0:adddoc();break;
    case 1:updatepat();break;
    case 2:deletedoc();break;
    case 3:searchdoc();break;
    case 4:notice();break;
   }
  }else if(xm>=242&&xm<=490&&ym>=33&&ym<=118&&buttonm==1){
   dropmenu(menu,242,33,490,118,opt);
   continue;
  }else if(buttonm==1){
   break;
  }
 }while(close);
 clrwin(1);
 return 1;
}
int program(){
 int opt=-1,j;
 char menu[5][30]={"User Login >","Quit"};
 close=1;
 dropmenu(menu,10,33,131,76,opt);
 do{
  showmouse();
  getmousepos(&buttonm,&xm,&ym);
  if(xm>=10+10&&xm<=131-10&&ym>=33+8&&ym<=76-8&&buttonm==1){
   for(j=0;j<(76-33-8)/14;j++)
    if((ym-33-8)/14==j){
     opt=j;
     break;
    }
   dropmenu(menu,10,33,131,76,opt);
   switch(opt){
    case 0: userl();break;
    case 1: delay(100);cleardevice();closegraph();exit(0);
   }
  }else if(xm>=10&&xm<=34&&ym>=18&&ym<=32&&buttonm==1){
   dropmenu(menu,10,33,131,76,opt);
   continue;
  }else if(buttonm==1){
   break;
  }
 }while(close);
 return 0;
}
void userl(){
 int opt=-1,j;
 char menu[3][30]={"Set/Reset","Change","Remove"};
 dropmenu(menu,132,41,229,98,opt);
 do{
  showmouse();
  getmousepos(&buttonm,&xm,&ym);
  if(xm>=132+10&&xm<=229-10&&ym>=41+8&&ym<=98-8&&buttonm==1){
   for(j=0;j<(98-41-8)/14;j++)
    if((ym-41-8)/14==j){
     opt=j;
     break;
    }
   dropmenu(menu,132,41,229,98,opt);
   delay(200);
   switch(opt){
    case 0: setusrl();break;
    case 1: changeusrl();break;
    case 2: removeusrl();break;
   }
  }else if(buttonm==1){
   break;
  }
 }while(close);
 clrwin(1);
}

void setusrl(){
 char head[30]="SET USER LOGIN";
 char usr[30]="",pwd[30]="",code[30]="";
 int a=midx/2+15+textwidth("Program Code : ");
 set=1;
 clrwin(2);
 drawwindow(head, midx/2, midy/2, (getmaxx()*3)/4, (getmaxy()*3)/4,1 );
 button("Set",midx+30,midy*3/2-22,midx+90,midy*3/2-8,7);
 button("Cancel",midx-90,midy*3/2-22,midx-30,midy*3/2-8,7);
 setcolor(15);moveto(midx/2+15,midy-26);
 outtext("Program Code :");inputbox(a,midy-26,15,15);
 setcolor(15);moveto(midx/2+15,midy-7);
 outtext("Username     :");inputbox(a,midy-7,15,15);
 setcolor(15);moveto(midx/2+15,midy+12);
 outtext("Password     :");inputbox(a,midy+12,15,15);
 do{
  getmousepos(&buttonm,&xm,&ym);
  if(buttonm==1){
   if(xm>=a-2&&xm<=a+15*8+1&&ym>=midy-26-2&&ym<=midy-26+8){
    set=1;
   }
   if(xm>=a-2&&xm<=a+15*8+1&&ym>=midy-7-2&&ym<=midy-7+8){
    set=2;
   }
   if(xm>=a-2&&xm<=a+15*8+1&&ym>=midy+12-2&&ym<=midy+12+8){
    set=3;
   }
   if(xm>=midx-90&&ym>=midy*3/2-22&&xm<=midx-30&&ym<=midy*3/2-8){
    button("Cancel",midx-90,midy*3/2-22,midx-30,midy*3/2-8,3);
    delay(100);close=0;set=0;
   }

   if(xm>=midx+30&&ym>=midy*3/2-22&&xm<=midx+90&&ym<=midy*3/2-8&&strlen(code)>0&&strlen(usr)>0&&strlen(pwd)>0){
    button("Set",midx+30,midy*3/2-22,midx+90,midy*3/2-8,3);
    delay(100);notice();close=0;set=0;
   }
  }
  if(set==4)set=1;
  if(set==1)
   input(a,midy-26,code,15 ,0,15,INT);
  if(set==2)
   input(a,midy-7,usr,15 ,0,15,TEXT);
  if(set==3)
   input(a,midy+12,pwd,15 ,0,15,PASSWORD);
  }while(close);
}
void changeusrl(){
 char head[30]="CHANGE USER LOGIN";
 char cusr[30]="",cpwd[30]="";
 int a=midx/2+15+textwidth("Current Username : ");
 set=1;
 //display before input data
 clrwin(2);
 drawwindow(head, midx/2, midy/2, (getmaxx()*3)/4, (getmaxy()*3)/4,1 );
 button("OK",midx+30,midy*3/2-22,midx+90,midy*3/2-8,7);
 button("Cancel",midx-90,midy*3/2-22,midx-30,midy*3/2-8,7);
 setcolor(15);moveto(midx/2+15,midy-26);
 outtext("Current Username :");inputbox(a,midy-26,15,15);
 setcolor(15);moveto(midx/2+15,midy+12);
 outtext("Current Password :");inputbox(a,midy+12,15,15);
 //start input data
 do{
  getmousepos(&buttonm,&xm,&ym);
  if(buttonm==1){
   if(xm>=a-2&&xm<=a+15*8+1&&ym>=midy-26-2&&ym<=midy-26+8){
    set=1;
   }
   if(xm>=a-2&&xm<=a+15*8+1&&ym>=midy+12-2&&ym<=midy+12+8){
    set=2;
   }
   if(xm>=midx-90&&ym>=midy*3/2-22&&xm<=midx-30&&ym<=midy*3/2-8){
    button("Cancel",midx-90,midy*3/2-22,midx-30,midy*3/2-8,3);
    delay(100);close=0;set=0;
   }

   if(xm>=midx+30&&ym>=midy*3/2-22&&xm<=midx+90&&ym<=midy*3/2-8&&strlen(cusr)>0&&strlen(cpwd)>0){
    button("OK",midx+30,midy*3/2-22,midx+90,midy*3/2-8,3);
    delay(100);notice();close=0;set=0;
   }
  }
  if(set==3)set=1;
  if(set==1)
   input(a,midy-26,cusr,15 ,0,15,TEXT);
  if(set==2)
   input(a,midy+12,cpwd,15 ,0,15,PASSWORD);
  }while(close);
}
void notice(){
 char head[30]="It's just interface";
 clrwin(2);
 drawwindow(head, midx/2, midy/2, (getmaxx()*3)/4, (getmaxy()*3)/4,9);
 button("OK",midx-30,midy*3/2-22,midx+30,midy*3/2-8,7);
 settextstyle(7,0,1);
 setcolor(15);
 outtextxy(midx-((17/2)*17),midy-25,"Best Project Group of all!");
 settextstyle(0,0,0);
 do{
  getmousepos(&buttonm,&xm,&ym);
  if(buttonm==1){
   if(xm>=midx-30&&ym>=midy*3/2-22&&xm<=midx+30&&ym<=midy*3/2-8){
    button("OK",midx-30,midy*3/2-22,midx+30,midy*3/2-8,3);
    delay(100);close=0;;
   }
  }
 }while(close);
}
void removeusrl(){
 char head[30]="REMOVE USER LOGIN";
 char usr[30]="",pwd[30]="";
 int a=midx/2+15+textwidth("Username : ");
 set=1;
 clrwin(2);
 drawwindow(head, midx/2, midy/2, (getmaxx()*3)/4, (getmaxy()*3)/4,1 );
 button("Remove",midx+30,midy*3/2-22,midx+90,midy*3/2-8,7);
 button("Cancel",midx-90,midy*3/2-22,midx-30,midy*3/2-8,7);
 setcolor(15);moveto(midx/2+15,midy-26);
 outtext("Username :");inputbox(a,midy-26,15,15);
 setcolor(15);moveto(midx/2+15,midy+12);
 outtext("Password :");inputbox(a,midy+12,15,15);
 do{
  getmousepos(&buttonm,&xm,&ym);
  if(buttonm==1){
   if(xm>=a-2&&xm<=a+15*8+1&&ym>=midy-26-2&&ym<=midy-26+8){
    set=1;
   }
   if(xm>=a-2&&xm<=a+15*8+1&&ym>=midy+12-2&&ym<=midy+12+8){
    set=2;
   }
   if(xm>=midx-90&&ym>=midy*3/2-22&&xm<=midx-30&&ym<=midy*3/2-8){
    button("Cancel",midx-90,midy*3/2-22,midx-30,midy*3/2-8,3);
    delay(100);close=0;set=0;
   }

   if((xm>=midx+30&&ym>=midy*3/2-22&&xm<=midx+90&&ym<=midy*3/2-8)&&strlen(usr)>0&&strlen(pwd)>0){
    button("Remove",midx+30,midy*3/2-22,midx+90,midy*3/2-8,3);
    delay(100);notice();close=0;set=0;
   }
  }
  if(set==3)set=1;
  if(set==1)
   input(a,midy-26,usr,15 ,0,15,TEXT);
  if(set==2)
   input(a,midy+12,pwd,15 ,0,15,PASSWORD);
  }while(close);
}
void input(int x,int y,char result[50],int limit ,int tc,int bkc,int type){
 char ch,text[2]="";
 int i=0,f=-1,key,j;
 close=1;
 hidemouse();
 setcolor(3);
 rectangle(x-3,y-3,x+limit*8+2,y+9);
 setfillstyle(1,bkc);
 bar(x-2,y-2,x+limit*8+1,y+8);
 showmouse();
 settextstyle(0,0,1);
 i=strlen(result);
 moveto(x,y);
 if(i>0){
  setcolor(tc);
  hidemouse();
  if(type!=0)
   outtext(result);
  else
   for(j=0;j<i;j++)
    outtext("*");
  showmouse();
 }
 if(i>0&&strstr(result,".")!=0){
  for(j=0;j<i;j++)
   if(result[j]=='.')
    break;
   f=j;
 }
 while(kbhit()){
  getch();
 }
 do{
  do{     hidemouse();
   setcolor(tc);
   line(x+i*8,y-1,x+i*8,y+7);
   showmouse();
   getmousepos(&buttonm,&xm,&ym);
   if(buttonm==1){
    if(xm<x-2||xm>x+limit*8+1||ym<y-2||ym>y+8){
     close=0;
     hidemouse();
     setcolor(bkc);
     line(x+i*8,y-1,x+i*8,y+7);
     showmouse();
     goto end;
    }
   }
   if(kbhit()){
    hidemouse();
    setcolor(bkc);
    line(x+i*8,y-1,x+i*8,y+7);
    showmouse();
    break;
   }else
    delay(100);
   hidemouse();
   setcolor(bkc);
   line(x+i*8,y-1,x+i*8,y+7);
   showmouse();
   getmousepos(&buttonm,&xm,&ym);
   if(buttonm==1){
    if(xm<x-2||xm>x+limit*8+1||ym<y-2||ym>y+8){
     close=0;
     hidemouse();
     setcolor(bkc);
     line(x+i*8,y-1,x+i*8,y+7);
     showmouse();
     goto end;
    }
   }
   if(!kbhit())
    delay(100);
  }while(bioskey(1)==0);
  key = bioskey(0);
  ch = key & 0xFF;
  hidemouse();
  if(type==3&&(isalpha(ch)||ch == ' ')&&i<limit){
   result[i++] = ch;
   text[0] = ch;
   text[1] = '\0';
   setcolor(tc);
   outtext(text);
  }
  if((type==1&&isdigit(ch)&&i<limit)||(((ch == '.'&&f==-1)||isdigit(ch))&&type==2&&i<limit)){
   if(ch=='.')
    f=i;
   result[i++] = ch;
   text[0] = ch;
   text[1] = '\0';
   setcolor(tc);
   outtext(text);
  }
  if((type==0||type==4)&&(isalpha(ch)||(ch>='!'&&ch<='@')||ch==95||ch == ' ')&&i<limit){//ch=95=_
   result[i++] = ch;
   text[0] = ch;
   text[1] = '\0';
   setcolor(tc);
   if(type==4)
    outtext(text);
   else
    outtext("*");
  }

  if(ch == 8 && i > 0){
   i--;
   if(i==f)
    f=-1;
   text[0] = result[i];
   text[1] = '\0';
   result[i] = '\0';
   setcolor(bkc);
   moveto(x+(i)*(textwidth(text)),y);
   if(type!=0)
    outtext(text);
   else
    outtext("*");
   moveto(x+textwidth(result),y);
  }
  if(type==0&&key==20992){//key=20992:insert key
   moveto(x,y);
   hidemouse();
   for(int j=0;j<i;j++){
    setcolor(bkc);
    outtext("*");//delete by outtext in same color to bkc;
   }
   result[i]='\0';
   moveto(x,y);
   setcolor(tc);
   outtext(result);
   showmouse();
   delay(70);
   if(!kbhit())
    delay(270);
   moveto(x,y);
   hidemouse();
   setcolor(bkc);
   outtext(result);
   moveto(x,y);
   setcolor(0);
   for(j=0;j<i;j++)
    outtext("*");
   showmouse();
  }
end: showmouse();
 }while(close==1);
 result[i]='\0';
 close=1;
 hidemouse();
 setfillstyle(1,bkc);
 rectangle(x-3,y-3,x+limit*8+2,y+9);
 setcolor(0);
 line(x-3,y-3,x-3,y+9);
 line(x-3,y-3,x+limit*8+2,y-3);
 showmouse();
}
void inputbox(int x,int y,int limit,int bkc){
 hidemouse();
 setfillstyle(1,bkc);
 bar(x-2,y-2,x+limit*8+2,y+8);
 setcolor(0);
 line(x-3,y-3,x-3,y+9);
 line(x-3,y-3,x+limit*8+2,y-3);
 showmouse();
}
int rooms(){
 char menu[5][30]={"Calculate Fees","Check Fees             >","Bill Fees","Uncleared Fees","Customize Fees Algorithm"};
 int opt=-1,j;
 close=1;
 dropmenu(menu,201,33,415,120,opt);
 do{
  showmouse();
  getmousepos(&buttonm,&xm,&ym);
  if(xm>=201+10&&xm<=415-10&&ym>=33+8&&ym<=120-8&&buttonm==1){
   for(j=0;j<(120-33-8)/14;j++)
    if((ym-33-8)/14==j){
     opt=j;
     break;
    }
   dropmenu(menu,201,33,415,120,opt);
   switch(opt){
    case 0:notice();break;
    case 1:manageroom();break;
    case 2:notice();break;
    case 3:notice();break;
    case 4:notice();break;
   }
  }
  else if(buttonm==1){
    break;
   }
 }while(close);
 return 3;
}
void manageroom(){
 int opt=-1,j;
 char menu[4][30]={"Check Fees by First Name","Check Fees by Last Name","Check Fees by ID","Check Fees by Grade"};
 dropmenu(menu,416,55,632,116,opt);
 do{
  getmousepos(&buttonm,&xm,&ym);
  if(xm>=416+10&&xm<=632-10&&ym>=55+8&&ym<=116-8&&buttonm==1){
   for(j=0;j<(116-55-8)/14;j++)
    if((ym-55-8)/14==j){
     opt=j;
     break;
    }
   dropmenu(menu,416,55,632,116,opt);
   delay(200);
   switch(opt){
    case 0: notice();break;
    case 1: notice();break;
    case 2: notice();break;
   }
  }else if(buttonm==1){
   break;
  }
 }while(close);
 clrwin(1);
}
void managetype(){
 int opt=-1,j;
 char menu[3][30]={"Add new","Delete","All types"};
 dropmenu(menu,301,83,397,140,opt);
 do{
  getmousepos(&buttonm,&xm,&ym);
  if(xm>=301+10&&xm<=397-10&&ym>=83+8&&ym<=140-8&&buttonm==1){
   for(j=0;j<(140-83-8)/14;j++)
    if((ym-83-8)/14==j){
     opt=j;
     break;
    }
   dropmenu(menu,301,83,397,140,opt);
   delay(200);
   switch(opt){
    case 0: notice();break;
    case 1: notice();break;
    case 2: notice();break;
   }
  }else if(buttonm==1){
   break;
  }
 }while(close);
 clrwin(1);
}

int about(){
}

int doctor(){
 char menu[5][30]={"Enroll","Update    >","Delete    >","Search    >","Display All"};
 int opt=-1,j;
 close=1;
 dropmenu(menu,35,33,150,118,opt);
 do{
  showmouse();
  getmousepos(&buttonm,&xm,&ym);
  if(xm>=35+10&&xm<=150-10&&ym>=33+8&&ym<=118-8&&buttonm==1){
   for(j=0;j<(118-33-8)/14;j++)
    if((ym-33-8)/14==j){
     opt=j;
     break;
    }
   dropmenu(menu,35,33,150,118,opt);
   switch(opt){
    case 0:adddoc();break;
    case 1:updatepat();break;
    case 2:deletedoc();break;
    case 3:searchdoc();break;
    case 4:notice();break;
   }
  }else if(xm>=35&&xm<=94&&ym>=18&&ym<=32&&buttonm==1){
   dropmenu(menu,35,33,150,118,opt);
   continue;
  }else if(buttonm==1){
   break;
  }
 }while(close);
 clrwin(1);
 return 1;
}

void adddoc(){
 int opt=-1,j;
 char menu[4][30]={"Add Marksheet by FN","Add Marksheet by LN","Add Marksheet by ID","Add Marksheet by Grade"};
 dropmenu(menu,151,69,335,140,opt);
 do{
  getmousepos(&buttonm,&xm,&ym);
  if(xm>=151+10&&xm<=237-10&&ym>=69+8&&ym<=112-8&&buttonm==1){
   for(j=0;j<(112-69-8)/14;j++)
    if((ym-69-8)/14==j){
     opt=j;
     break;
    }
   dropmenu(menu,151,69,237,112,opt);
   delay(200);
   switch(opt){
    case 0: notice();break;
    case 1: notice();break;
   }
  }else if(buttonm==1){
   break;
  }
 }while(close);
 clrwin(1);
   }
void deletedoc(){
 int opt=-1,j;
 char menu[4][30]={"Delete by First Name","Delete by Last Name","Delete by ID","Delete by Grade"};
 dropmenu(menu,151,69,335,140,opt);
 do{
  getmousepos(&buttonm,&xm,&ym);
  if(xm>=151+10&&xm<=237-10&&ym>=69+8&&ym<=112-8&&buttonm==1){
   for(j=0;j<(112-69-8)/14;j++)
    if((ym-69-8)/14==j){
     opt=j;
     break;
    }
   dropmenu(menu,151,69,237,112,opt);
   delay(200);
   switch(opt){
    case 0: notice();break;
    case 1: notice();break;
   }
  }else if(buttonm==1){
   break;
  }
 }while(close);
 clrwin(1);
}
void searchdoc(){
 int opt=-1,j;
 char menu[4][30]={"Search by First Name","Search by Last Name","Search by ID","Search by Grade"};
 dropmenu(menu,151,83,335,154,opt);
 do{
  getmousepos(&buttonm,&xm,&ym);
  if(xm>=151+10&&xm<=285-10&&ym>=83+8&&ym<=154-8&&buttonm==1){
   for(j=0;j<(154-83-8)/14;j++)
    if((ym-83-8)/14==j){
     opt=j;
     break;
    }
   dropmenu(menu,151,83,285,154,opt);
   delay(200);
   switch(opt){
    case 0: notice();break;
    case 1: notice();break;
    case 2: notice();break;
    case 3: notice();break;
   }
  }else if(buttonm==1){
   break;
  }
 }while(close);
 clrwin(1);
}
int patient(){
 char menu[4][30]={"Perform Attendance","View Attendance   >","Delete Attendance >","Display All"};
 int opt=-1,j;
 close=1;
 dropmenu(menu,111,33,285,105,opt);
 do{ showmouse();
  getmousepos(&buttonm,&xm,&ym);
  if(xm>=111+10&&xm<=285-10&&ym>=33+8&&ym<=105-8&&buttonm==1){
   for(j=0;j<(100-33-8)/14;j++)
    if((ym-33-8)/14==j){
     opt=j;
     break;
    }
   dropmenu(menu,111,33,285,105,opt);
   switch(opt){
    case 0:notice();break;
    case 1:searchpat();break;
    case 2:deleteatt();break;
    case 3:notice();break;
   }
  }else if(xm>=95&&xm<=169&&ym>=18&&ym<=32&&buttonm==1){
   dropmenu(menu,111,33,285,105,opt);
   continue;
  }else if(buttonm==1){
   break;
  }
 }while(close);
 return 2;
}
void deleteatt(){
 int opt=-1,j;
 char menu[2][30]={"Delete Attendance by Date","Delete Attendance by Grade"};
 dropmenu(menu,286,67,518,110,opt);
 do{
  getmousepos(&buttonm,&xm,&ym);
  if(xm>=286+10&&xm<=518-10&&ym>=67+8&&ym<=110-8&&buttonm==1){
   for(j=0;j<(110-67-8)/14;j++)
    if((ym-67-8)/14==j){
     opt=j;
     break;
    }
   dropmenu(menu,286,67,518,110,opt);
   delay(200);
   switch(opt){
    case 0: notice();break;
    case 1: notice();break;
   }
  }else if(buttonm==1){
   break;
  }
 }while(close);
 clrwin(1);
}
void updatepat(){
 int opt=-1,j;
 char menu[4][30]={"Update by First Name","Update by Last Name","Update by ID","Update by Grade"};
 dropmenu(menu,151,55,335,126,opt);
 do{
  getmousepos(&buttonm,&xm,&ym);
  if(xm>=211+10&&xm<=273-10&&ym>=69+8&&ym<=126-8&&buttonm==1){
   for(j=0;j<(126-69-8)/14;j++)
    if((ym-69-8)/14==j){
     opt=j;
     break;
    }
   dropmenu(menu,211,69,273,126,opt);
   delay(200);
   switch(opt){
    case 0: notice();break;
    case 1: notice();break;
   }
  }else if(buttonm==1){
   break;
  }
 }while(close);
 clrwin(1);
}
void searchpat(){
 int opt=-1,j;
 char menu[2][30]={"View Attendance by Date","View Attendance by Grade"};
 dropmenu(menu,286,55,500,100,opt);
 do{
  getmousepos(&buttonm,&xm,&ym);
  if(xm>=286+10&&xm<=500-10&&ym>=55+8&&ym<=100-8&&buttonm==1){
   for(j=0;j<(100-55-8)/14;j++)
    if((ym-55-8)/14==j){
     opt=j;
     break;
    }
   dropmenu(menu,286,55,500,100,opt);
   delay(200);
   switch(opt){
    case 0: notice();break;
    case 1: notice();break;
   }
  }else if(buttonm==1){
   break;
  }
 }while(close);
 clrwin(1);
}
int dropmenu(char menu[7][30],int x1,int y1,int x2,int y2,int opt){
 int i;
 char ch;
 setfillstyle(1,14);
 setcolor(15);
 hidemouse();
 line(x1,y1,x2,y1);
 line(x1,y1,x1,y2);
 setcolor(0);
 line(x2,y1,x2,y2);
 line(x1,y2,x2,y2);
 bar(x1+1,y1+1,x2-1,y2-1);
 rectangle(x1+5,y1+5,x2-5,y2-5);
 for(i=0;i<(y2-y1-15)/14;i++){
  if(i==opt){
  setcolor(15);
  setfillstyle(1,3);
  bar(x1+10,y1+8+(i*14),x2-10,y1+20+(i*14));
  outtextxy(x1+15,y1+10+(i*14),menu[i]);
  }else{
   setcolor(0);
   outtextxy(x1+15,y1+10+(i*14),menu[i]);
  }
 }
 showmouse();
 delay(100);
 return opt;
}

void button(char name[15],int x1,int y1,int x2 ,int y2,int c){
 setfillstyle(1,c);
 setcolor(15);
 hidemouse();
 line(x1,y1,x2,y1);
 line(x1,y1,x1,y2);
 setcolor(0);
 line(x2,y1,x2,y2);
 line(x1,y2,x2,y2);
 bar(x1+1,y1+1,x2-1,y2-1);
 outtextxy((x2+x1-textwidth(name))/2,(y2+y1-textheight(name))/2,name);
 showmouse();
}
void drawwindow(char head[30],int x1, int y1, int x2, int y2, int c){
 hidemouse();
 setfillstyle(1,7);
 bar(x1,y1-14,x2,y1-2);
 setfillstyle(1,c);
 bar(x1,y1,x2,y2);
 setcolor(15);
 line(x1-1,y1-15,x2+1,y1-15);
 line(x1-1,y1-15,x1-1,y2+1);
 setcolor(0);
 line(x2+1,y1-14,x2+1,y2+1);
 line(x1-1,y2+1,x2+1,y2+1);
 line(x1,y1-1,x2,y1-1);
 setcolor(15);
 rectangle(x1+5,y1+5,x2-5,y2-5);
 setcolor(0);
 settextstyle(0,0,1);
 outtextxy((x2+x1-textwidth(head))/2,y1-12,head);
 showmouse();

}
int menu(int select){
 char ch, menu[6][30]={"\360","Students","Attendance","Fees","Marksheet","About"};
 char date[11];
 struct date da;
 hidemouse();
 setfillstyle(1,6);
 setcolor(15);
 line(9,17,631,17);
 line(9,17,9,32);
 setcolor(0);
 line(631,18,631,32);
 bar(10,18,630,32);
 getdate(&da);
 setcolor(0);
 outtextxy(20,21,menu[0]);
 outtextxy(40,21,menu[1]);
 outtextxy(115,21,menu[2]);
 outtextxy(205,21,menu[3]);
 outtextxy(246,21,menu[4]);
 outtextxy(326,21,menu[5]);
 showmouse();
  switch(select){
   case 0: hidemouse();
    setfillstyle(9,9);
    setcolor(0);
    line(10,18,34,18);
    line(10,18,10,31);
    setcolor(15);
    line(35,18,35,32);
    line(10,32,35,32);
    bar(11,19,34,31);
    outtextxy(20,21,menu[0]);
    break;
   case 1: hidemouse();
    setfillstyle(9,9);
    setcolor(0);
    line(36,18,36,31);
    line(36,18,105,18);
    setcolor(15);
    line(105,18,105,32);
    line(36,32,105,32);
    bar(37,19,104,31);
    outtextxy(40,21,menu[1]);
    break;
   case 2: hidemouse();
    setfillstyle(9,9);
    setcolor(0);
    line(111,18,111,32);
    line(111,18,196,18);
    setcolor(15);
    line(196,18,196,32);
    line(111,32,196,32);
    bar(112,19,195,31);
    outtextxy(115,21,menu[2]);
    break;
   case 3: hidemouse();
    setfillstyle(9,9);
    setcolor(0);
    line(201,32,201,18);
    line(201,18,239,18);
    setcolor(15);
    line(239,18,239,32);
    line(201,32,239,32);
    bar(202,19,238,31);
    outtextxy(205,21,menu[3]);
    break;
   case 4: hidemouse();
    setfillstyle(9,9);
    setcolor(0);
    line(242,18,319,18);
    line(242,18,242,32);
    setcolor(15);
    line(242,32,319,32);
    line(319,18,319,32);
    bar(243,19,318,31);
    outtextxy(246,21,menu[4]);
    break;
   case 5: hidemouse();
    setfillstyle(9,9);
    setcolor(0);
    line(322,18,367,18);
    line(322,18,322,32);
    setcolor(15);
    line(322,32,367,32);
    line(367,18,367,32);
    bar(323,19,366,31);
    outtextxy(326,21,menu[5]);
    break;
  }
  sprintf(date,"%02d/%02d/%d",da.da_year,da.da_mon,da.da_day);
  setcolor(0);
  outtextxy(550,21,date);
  showmouse();
 return select;
}
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

void clrwin(int opt){
 if(opt==2)
  menu(-1);
 hidemouse();
 setcolor(0);
 line(9,33,631,33);
 line(9,34,9,340);
 setcolor(15);
 line(631,34,631,339);
 line(10,340,631,340);
 setfillstyle(1,11);
 bar(10,34,630,339);
 showmouse();
}
