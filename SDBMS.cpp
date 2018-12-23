#include<iostream.h>
#include<conio.h>
<<<<<<< HEAD
#include<math.h>
=======
#include<graphics.h> // For drawing graphics & mouse controls
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

/* Mouse Functions(M) */
int gd = DETECT, gm; // graphic variables
union REGS i,o; // Mouse input & output controller

int initmouse() // Mouse initialization(M)
{
    i.x.ax = 0;
    int86(0x33, &i, &o);
    return(o.x.ax);
}
void showmouseptr() // Mouse pointer show(M)
{
    i.x.ax = 1;
    int86(0x33, &i, &o);
}

void restrictmouse(int x1, int y1, int x2, int y2) // Mouse restriction in screen (M)
{
    i.x.ax = 7; // Top left boundary
    i.x.cx = x1;
    i.x.dx = x2;
    int86(0x33, &i, &o);
    i.x.ax = 8; // Bottom right boundary
    i.x.cx = y1;
    i.x.dx = y2;
    int86(0x33, &i, &o);
}

void header() // Logo printing function
{
    cout << "                  === STUDENT DATABASE MANAGEMENT SYSTEM ===";
}

void drawwindow()
{

}

void main()
{
    initgraph(&gd,&gm,"C:\\turboc3\\BGI"); // Loads driver for graphics

    showmouseptr(); // This shows mouse!(M)

    header();


    getch();
}
>>>>>>> 08bac56ff26755747348dab5eda2ab92771a903c

void stu()
{
    cout<<"the following is just for fun. i am testing git bash. you can delete this okay."<<endl;
}
