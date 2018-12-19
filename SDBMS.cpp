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

/* Mouse Showing Functions(M) */
union REGS i,o; // Mouse input & output controller

int initmouse() // Mouse initialization(M)
{
    i.x.ax = 0;
    int86(0X33, &i, &o);
    return(o.x.ax);
}
void showmouseptr() // Mouse pointer show(M)
{
    i.x.ax = 1;
    int86(0X33, &i, &o);
}

void restrictmouse(int x1, int y1, int x2, int y2) // Mouse restriction in screen
{
    i.x.ax = 7; // Top left boundary
    i.x.cx = x1;
    i.x.dx = x2;
    int86(0X33, &i, &o);
    i.x.ax = 8; // Bottom right boundary
    i.x.cx = y1;
    i.x.dx = y2;
    int86(0X33, &i, &o);
}

void main()
{
    int gd = DETECT, gm; // graphic variables

    initgraph(&gd,&gm,"C:\\TC\\BGI"); // Loads driver for graphics

    showmouseptr(); // This shows mouse!(M)

    getch();
}
