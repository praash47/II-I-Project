#include<iostream.h>
#include<conio.h>
#include<graphics.h> // For drawing graphics
#include<dos.h> // For getting date

class user
{
private:
    char user[10][20],pass[10][20]; // Variables for storing usernames & passwords of 10 users
};

class student
{
private:
    char name[30]; // 30 characters full name
};

/* Mouse Showing Functions */
union REGS i,o;

int initmouse() // Mouse Initialization
{
    i.x.ax = 0;
    int86(0X33, &i, &o);
    return(o.x.ax);
}
void showmouseptr() // Mouse pointer show
{
    i.x.ax = 1;
    int86(0X33, &i, &o);
}

void main()
{
    int status, gd = DETECT, gm;

    initgraph(&gd,&gm,"C:\\TC\\BGI");

    showmouseptr(); // This shows mouse!

    getch();
}
