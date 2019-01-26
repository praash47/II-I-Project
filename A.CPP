#include<iostream>
#include<windows.h>

#define USERS_MENU_ADD 1
#define USERS_MENU_VIEW 2
#define USERS_MENU_UPDATE 3
#define USERS_MENU_DELETE 4
#define USERS_MENU_LOGOUT 5

#define STUDENTS_MENU_ENROLL 6
#define STUDENTS_MENU_UPDATE 7
#define STUDENTS_MENU_SEARCH 8
#define STUDENTS_MENU_DELETE 9
#define STUDENTS_MENU_DISPLAY 10

#define ATTENDANCE_MENU_PERFORM 11
#define ATTENDANCE_MENU_VIEW 12
#define ATTENDANCE_MENU_DELETE 13
#define ATTENDANCE_MENU_DISPLAY 14

#define FEES_MENU_ADD 15
#define FEES_MENU_CHECK 16
#define FEES_MENU_BILL 17
#define FEES_MENU_UNCLEARED 18
#define FEES_MENU_DISPLAY 19

#define MARKSHEET_MENU_ADD 20
#define MARKSHEET_MENU_VIEW 21
#define MARKSHEET_MENU_UPDATE 22
#define MARKSHEET_MENU_DELETE 23
#define MARKSHEET_MENU_CALCULATE 24

#define ABOUT_MENU_GROUP 25
#define ABOUT_MENU_PROJECT 26
#define ABOUT_MENU_GUIDE 27


LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND hWnd);
HMENU hMenu;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL,IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if(!RegisterClassW(&wc))
        return -1;

    CreateWindowW(L"myWindowClass",L"STUDENT DATABASE MANAGEMENT SYSTEM",WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100,100,500,500,NULL,NULL,NULL,NULL);

    MSG msg = {0};

    while(GetMessage((&msg),NULL,NULL,NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;

}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_COMMAND:
        switch(wp)
        {
        case USERS_MENU_ADD:
            DestroyWindow(hWnd);
            break;
        case USERS_MENU_VIEW:
            DestroyWindow(hWnd);
            break;
        case USERS_MENU_UPDATE:
            DestroyWindow(hWnd);
            break;
        case USERS_MENU_DELETE:
            DestroyWindow(hWnd);
            break;
        case USERS_MENU_LOGOUT:
            DestroyWindow(hWnd);
            break;

        case STUDENTS_MENU_ENROLL:
            DestroyWindow(hWnd);
            break;
        case STUDENTS_MENU_UPDATE:
            DestroyWindow(hWnd);
            break;
        case STUDENTS_MENU_SEARCH:
            DestroyWindow(hWnd);
            break;
        case STUDENTS_MENU_DELETE:
            DestroyWindow(hWnd);
            break;
        case STUDENTS_MENU_DISPLAY:
            DestroyWindow(hWnd);
            break;

        case ATTENDANCE_MENU_PERFORM:
            DestroyWindow(hWnd);
            break;
        case ATTENDANCE_MENU_VIEW:
            DestroyWindow(hWnd);
            break;
        case ATTENDANCE_MENU_DELETE:
            DestroyWindow(hWnd);
            break;
        case ATTENDANCE_MENU_DISPLAY:
            DestroyWindow(hWnd);
            break;

        case FEES_MENU_ADD:
            DestroyWindow(hWnd);
            break;
        case FEES_MENU_DISPLAY:
            DestroyWindow(hWnd);
            break;
        case FEES_MENU_BILL:
            DestroyWindow(hWnd);
            break;
        case FEES_MENU_UNCLEARED:
            DestroyWindow(hWnd);
            break;
        case FEES_MENU_DISPLAY:
            DestroyWindow(hWnd);
            break;

        case MARKSHEET_MENU_ADD:
            DestroyWindow(hWnd);
            break;
        case MARKSHEET_MENU_VIEW:
            DestroyWindow(hWnd);
            break;
        case MARKSHEET_MENU_UPDATE:
            DestroyWindow(hWnd);
            break;
        case MARKSHEET_MENU_DELETE:
            DestroyWindow(hWnd);
            break;
        case MARKSHEET_MENU_CALCULATE:
            DestroyWindow(hWnd);
            break;


        case ABOUT_MENU_GROUP:
            DestroyWindow(hWnd);
            break;
        case ABOUT_MENU_PROJECT:
            DestroyWindow(hWnd);
            break;
        case ABOUT_MENU_GUIDE:
            DestroyWindow(hWnd);
            break;
        }
    case WM_CREATE:
        AddMenus(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd,msg,wp,lp);
    }
}

void AddMenus(HWND hWnd)
{
    hMenu = CreateMenu();
    HMENU hUsersMenu = CreateMenu();
    HMENU hStudentsMenu = CreateMenu();
    HMENU hAttendanceMenu = CreateMenu();
    HMENU hFeesMenu = CreateMenu();
    HMENU hMarksheetMenu = CreateMenu();
    HMENU hAboutMenu = CreateMenu();

    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hUsersMenu,"Users");
        AppendMenu(hUsersMenu,MF_STRING,USERS_MENU_ADD,"Add");
        AppendMenu(hUsersMenu,MF_STRING,USERS_MENU_VIEW,"View");
        AppendMenu(hUsersMenu,MF_STRING,USERS_MENU_UPDATE,"Update");
        AppendMenu(hUsersMenu,MF_STRING,USERS_MENU_DELETE,"Delete");
        AppendMenu(hUsersMenu,MF_STRING,USERS_MENU_LOGOUT,"Logout");

    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hStudentsMenu,"Students");
        AppendMenu(hStudentsMenu,MF_STRING,STUDENTS_MENU_ENROLL,"Enroll");
        AppendMenu(hStudentsMenu,MF_STRING,STUDENTS_MENU_UPDATE,"Update");
        AppendMenu(hStudentsMenu,MF_STRING,STUDENTS_MENU_SEARCH,"Search");
        AppendMenu(hStudentsMenu,MF_STRING,STUDENTS_MENU_DELETE,"Delete");
        AppendMenu(hStudentsMenu,MF_STRING,STUDENTS_MENU_DISPLAY,"Display All");

    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hAttendanceMenu,"Attendance");
        AppendMenu(hAttendanceMenu,MF_STRING,ATTENDANCE_MENU_PERFORM,"Perform Attendance");
        AppendMenu(hAttendanceMenu,MF_STRING,ATTENDANCE_MENU_VIEW,"View Attendance");
        AppendMenu(hAttendanceMenu,MF_STRING,ATTENDANCE_MENU_DELETE,"Delete Attendance");
        AppendMenu(hAttendanceMenu,MF_STRING,ATTENDANCE_MENU_DISPLAY,"Display Attendance");

    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hFeesMenu,"Fees");
        AppendMenu(hFeesMenu,MF_STRING,FEES_MENU_ADD,"Add Fees");
        AppendMenu(hFeesMenu,MF_STRING,FEES_MENU_CHECK,"Check Fees");
        AppendMenu(hFeesMenu,MF_STRING,FEES_MENU_BILL,"Bill Fees");
        AppendMenu(hFeesMenu,MF_STRING,FEES_MENU_UNCLEARED,"Uncleared Fees");
        AppendMenu(hFeesMenu,MF_STRING,FEES_MENU_DISPLAY,"Display Fees");

    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hMarksheetMenu,"Marksheet");
        AppendMenu(hMarksheetMenu,MF_STRING,MARKSHEET_MENU_ADD,"Add Marksheet");
        AppendMenu(hMarksheetMenu,MF_STRING,MARKSHEET_MENU_VIEW,"View Marksheet");
        AppendMenu(hMarksheetMenu,MF_STRING,MARKSHEET_MENU_UPDATE,"Update Marksheet");
        AppendMenu(hMarksheetMenu,MF_STRING,MARKSHEET_MENU_DELETE,"Delete Marksheet");
        AppendMenu(hMarksheetMenu,MF_STRING,MARKSHEET_MENU_CALCULATE,"Calculate Gradewise Averages");

    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hAboutMenu,"About");
        AppendMenu(hAboutMenu,MF_STRING,ABOUT_MENU_GROUP,"About Group");
        AppendMenu(hAboutMenu,MF_STRING,ABOUT_MENU_PROJECT,"About Project");
        AppendMenu(hAboutMenu,MF_STRING,ABOUT_MENU_GUIDE,"Brief Usage Guide");

    SetMenu(hWnd,hMenu);
}
