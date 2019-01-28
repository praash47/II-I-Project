#include<windows.h>

#define USERS_MENU_ADD 1
#define USERS_MENU_VIEW 2
#define USERS_MENU_UPDATE 3
#define USERS_MENU_DELETE 4
#define USERS_MENU_LOGOUT 5

#define STUDENTS_MENU_ENROLL 6
#define STUDENTS_MENU_UPDATE 7
    #define STUDENTS_MENU_UPDATE_ID 30
    #define STUDENTS_MENU_UPDATE_FN 31
    #define STUDENTS_MENU_UPDATE_LN 32
    #define STUDENTS_MENU_UPDATE_GRADE 33
#define STUDENTS_MENU_SEARCH 8
    #define STUDENTS_MENU_SEARCH_ID 34
    #define STUDENTS_MENU_SEARCH_FN 35
    #define STUDENTS_MENU_SEARCH_LN 36
    #define STUDENTS_MENU_SEARCH_GRADE 37
#define STUDENTS_MENU_DELETE 9
    #define STUDENTS_MENU_DELETE_ID 38
    #define STUDENTS_MENU_DELETE_FN 39
    #define STUDENTS_MENU_DELETE_LN 40
    #define STUDENTS_MENU_DELETE_GRADE 41
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

#define SUBMIT_STUDENT_DETAILS 28
#define CANCEL 29


LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);
void AddMenus(HWND hWnd);
void clearscr(HWND hWnd);
HMENU hMenu;
HWND temp_fn,temp_ln,temp_dob,temp_gen,temp_add,temp_phone,temp_prog,temp_start;

void addUser(HWND);
void updateUser(HWND);
void viewUser(HWND);
void deleteUser(HWND);
void logoutUser(HWND);

void enrollStudent(HWND);
void updateStudentID(HWND);
void updateStudentFN(HWND);
void updateStudentLN(HWND);
void updateStudentGrade(HWND);
void searchStudentID(HWND);
void searchStudentFN(HWND);
void searchStudentLN(HWND);
void searchStudentGrade(HWND);
void deleteStudentID(HWND);
void deleteStudentFN(HWND);
void deleteStudentLN(HWND);
void deleteStudentGrade(HWND);
void viewStudent(HWND);

void about_group(HWND);
void about_project(HWND);

wchar_t firstName[20],lastName[20],dob[10],gen[10],add[50],phone[10],prog[20],start[10];
int f=0;

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
            addUser(hWnd);
            break;
        case USERS_MENU_VIEW:
            viewUser(hWnd);
            break;
        case USERS_MENU_UPDATE:
            updateUser(hWnd);
            break;
        case USERS_MENU_DELETE:
            deleteUser(hWnd);
            break;
        case USERS_MENU_LOGOUT:
            DestroyWindow(hWnd);
            break;

        case STUDENTS_MENU_ENROLL:
            clearscr(hWnd);
            enrollStudent(hWnd);
            break;

        case STUDENTS_MENU_UPDATE_ID:
            updateStudentID(hWnd);
            break;
        case STUDENTS_MENU_UPDATE_FN:
            updateStudentFN(hWnd);
            break;
        case STUDENTS_MENU_UPDATE_LN:
            updateStudentLN(hWnd);
            break;
        case STUDENTS_MENU_UPDATE_GRADE:
            updateStudentGrade(hWnd);
            break;

        case STUDENTS_MENU_SEARCH_ID:
            searchStudentID(hWnd);
            break;
        case STUDENTS_MENU_SEARCH_FN:
            searchStudentFN(hWnd);
            break;
        case STUDENTS_MENU_SEARCH_LN:
            searchStudentLN(hWnd);
            break;
        case STUDENTS_MENU_SEARCH_GRADE:
            searchStudentGrade(hWnd);
            break;

        case STUDENTS_MENU_DELETE_ID:
            deleteStudentID(hWnd);
            break;
        case STUDENTS_MENU_DELETE_FN:
            deleteStudentFN(hWnd);
            break;
        case STUDENTS_MENU_DELETE_LN:
            deleteStudentLN(hWnd);
            break;
        case STUDENTS_MENU_DELETE_GRADE:
            deleteStudentGrade(hWnd);
            break;

        case STUDENTS_MENU_DISPLAY:
            viewStudent(hWnd);
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
        case FEES_MENU_CHECK:
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
            clearscr(hWnd);
            about_group(hWnd);
            break;
        case ABOUT_MENU_PROJECT:
            clearscr(hWnd);
            about_project(hWnd);
            break;
        case ABOUT_MENU_GUIDE:
            DestroyWindow(hWnd);
            break;

        case SUBMIT_STUDENT_DETAILS:
            GetWindowTextW(temp_fn,firstName,20);
            GetWindowTextW(temp_ln,lastName,20);
            GetWindowTextW(temp_dob,dob,10);
            GetWindowTextW(temp_gen,gen,10);
            GetWindowTextW(temp_add,add,50);
            GetWindowTextW(temp_phone,phone,10);
            GetWindowTextW(temp_prog,prog,20);
            GetWindowTextW(temp_start,start,10);
            clearscr(hWnd);
            CreateWindowW(L"Static",L"Enroll Student - Submitted",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,175,25,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",L"Submitted Details",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",L"First Name",WS_VISIBLE | WS_CHILD ,5,85,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,85,100,50,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",L"Last Name",WS_VISIBLE | WS_CHILD ,5,125,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,125,100,50,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",L"DOB",WS_VISIBLE | WS_CHILD ,5,165,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,165,100,50,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",L"Gender",WS_VISIBLE | WS_CHILD ,5,205,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,205,100,50,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",L"Address",WS_VISIBLE | WS_CHILD ,5,245,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,245,100,50,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",L"Phone",WS_VISIBLE | WS_CHILD ,5,285,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,285,100,50,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",L"Program",WS_VISIBLE | WS_CHILD ,5,325,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,325,100,50,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",L"Start Year",WS_VISIBLE | WS_CHILD ,5,365,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,365,100,50,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",firstName,WS_VISIBLE | WS_CHILD ,125,85,150,20,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",lastName,WS_VISIBLE | WS_CHILD,125,125,150,20,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",dob,WS_VISIBLE | WS_CHILD,125,165,150,20,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",gen,WS_VISIBLE | WS_CHILD,125,205,150,20,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",add,WS_VISIBLE | WS_CHILD,125,245,150,20,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",phone,WS_VISIBLE | WS_CHILD,125,285,150,20,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",prog,WS_VISIBLE | WS_CHILD,125,325,150,20,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",start,WS_VISIBLE | WS_CHILD,125,365,150,20,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",L"                                                           ",WS_VISIBLE | WS_CHILD,5,400,400,50,hWnd,NULL,NULL,NULL);
            CreateWindowW(L"Static",L"                                                           ",WS_VISIBLE | WS_CHILD,125,410,400,50,hWnd,NULL,NULL,NULL);
            break;
        case CANCEL:
            clearscr(hWnd);
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
void addUser(HWND hWnd)
{
    clearscr(hWnd);
    CreateWindowW(L"Static",L"Add User",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,75,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Enter the details of Users to Add",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Username",WS_VISIBLE | WS_CHILD ,5,85,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,85,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,85,150,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Password",WS_VISIBLE | WS_CHILD ,5,125,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,125,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,125,150,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE | WS_CHILD | WS_BORDER,5,160,75,35,hWnd,(HMENU)SUBMIT_STUDENT_DETAILS,NULL,NULL);;CreateWindowW(L"Button",L"Cancel",WS_VISIBLE | WS_CHILD | WS_BORDER,125,160,75,35,hWnd,(HMENU)CANCEL,NULL,NULL);
}

void updateUser(HWND hWnd)
{
    clearscr(hWnd);
    CreateWindowW(L"Static",L"Update User",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,100,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Enter the details of Users to Update",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Username",WS_VISIBLE | WS_CHILD ,5,85,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,85,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,85,150,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE | WS_CHILD | WS_BORDER,5,115,75,35,hWnd,(HMENU)SUBMIT_STUDENT_DETAILS,NULL,NULL);;CreateWindowW(L"Button",L"Cancel",WS_VISIBLE | WS_CHILD | WS_BORDER,125,115,75,35,hWnd,(HMENU)CANCEL,NULL,NULL);
}

void viewUser(HWND hWnd)
{
    clearscr(hWnd);
    CreateWindowW(L"Static",L"View Users",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,75,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Users List:",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
}

void deleteUser(HWND hWnd)
{
    clearscr(hWnd);
    CreateWindowW(L"Static",L"Delete User",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,100,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Enter the details of Users to Delete",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Username",WS_VISIBLE | WS_CHILD ,5,85,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,85,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,85,150,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE | WS_CHILD | WS_BORDER,5,115,75,35,hWnd,(HMENU)SUBMIT_STUDENT_DETAILS,NULL,NULL);;CreateWindowW(L"Button",L"Cancel",WS_VISIBLE | WS_CHILD | WS_BORDER,125,115,75,35,hWnd,(HMENU)CANCEL,NULL,NULL);
}

void enrollStudent(HWND hWnd)
{
    CreateWindowW(L"Static",L"Enroll Student",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,100,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Enter the details of Students",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"First Name",WS_VISIBLE | WS_CHILD ,5,85,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,85,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Last Name",WS_VISIBLE | WS_CHILD ,5,125,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,125,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"DOB",WS_VISIBLE | WS_CHILD ,5,165,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,165,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Gender",WS_VISIBLE | WS_CHILD ,5,205,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,205,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Address",WS_VISIBLE | WS_CHILD ,5,245,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,245,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Phone",WS_VISIBLE | WS_CHILD ,5,285,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,285,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Program",WS_VISIBLE | WS_CHILD ,5,325,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,325,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Start Year",WS_VISIBLE | WS_CHILD ,5,365,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,365,100,50,hWnd,NULL,NULL,NULL);
    temp_fn = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,85,150,20,hWnd,NULL,NULL,NULL);
    temp_ln = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,125,150,20,hWnd,NULL,NULL,NULL);
    temp_dob = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,165,150,20,hWnd,NULL,NULL,NULL);
    temp_gen = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,205,150,20,hWnd,NULL,NULL,NULL);
    temp_add = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,245,150,20,hWnd,NULL,NULL,NULL);
    temp_phone = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,285,150,20,hWnd,NULL,NULL,NULL);
    temp_prog = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,325,150,20,hWnd,NULL,NULL,NULL);
    temp_start = CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,365,150,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE | WS_CHILD | WS_BORDER,5,400,75,35,hWnd,(HMENU)SUBMIT_STUDENT_DETAILS,NULL,NULL);CreateWindowW(L"Button",L"Cancel",WS_VISIBLE | WS_CHILD | WS_BORDER,125,400,75,35,hWnd,(HMENU)CANCEL,NULL,NULL);
}

void updateStudentID(HWND hWnd)
{
    clearscr(hWnd);
    CreateWindowW(L"Static",L"Update Student By ID",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,150,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Enter the details of Student to Update",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"ID",WS_VISIBLE | WS_CHILD ,5,85,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,85,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,85,150,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE | WS_CHILD | WS_BORDER,5,115,75,35,hWnd,(HMENU)SUBMIT_STUDENT_DETAILS,NULL,NULL);;CreateWindowW(L"Button",L"Cancel",WS_VISIBLE | WS_CHILD | WS_BORDER,125,115,75,35,hWnd,(HMENU)CANCEL,NULL,NULL);
}
void updateStudentFN(HWND hWnd)
{
    clearscr(hWnd);
    CreateWindowW(L"Static",L"Update Student By First Name",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,200,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Enter the details of Student to Update",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"First Name",WS_VISIBLE | WS_CHILD ,5,85,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,85,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,85,150,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE | WS_CHILD | WS_BORDER,5,115,75,35,hWnd,(HMENU)SUBMIT_STUDENT_DETAILS,NULL,NULL);;CreateWindowW(L"Button",L"Cancel",WS_VISIBLE | WS_CHILD | WS_BORDER,125,115,75,35,hWnd,(HMENU)CANCEL,NULL,NULL);
}
void updateStudentLN(HWND hWnd)
{
    clearscr(hWnd);
    CreateWindowW(L"Static",L"Update Student By Last Name",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,200,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Enter the details of Student to Update",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Last Name",WS_VISIBLE | WS_CHILD ,5,85,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,85,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,85,150,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE | WS_CHILD | WS_BORDER,5,115,75,35,hWnd,(HMENU)SUBMIT_STUDENT_DETAILS,NULL,NULL);;CreateWindowW(L"Button",L"Cancel",WS_VISIBLE | WS_CHILD | WS_BORDER,125,115,75,35,hWnd,(HMENU)CANCEL,NULL,NULL);
}
void updateStudentGrade(HWND hWnd)
{
    clearscr(hWnd);
    CreateWindowW(L"Static",L"Update Student By Grade",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,175,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Enter the details of Student to Update",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Grade",WS_VISIBLE | WS_CHILD ,5,85,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,85,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,85,150,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE | WS_CHILD | WS_BORDER,5,115,75,35,hWnd,(HMENU)SUBMIT_STUDENT_DETAILS,NULL,NULL);;CreateWindowW(L"Button",L"Cancel",WS_VISIBLE | WS_CHILD | WS_BORDER,125,115,75,35,hWnd,(HMENU)CANCEL,NULL,NULL);
}
void searchStudentID(HWND hWnd)
{
    clearscr(hWnd);
    CreateWindowW(L"Static",L"Search Student By ID",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,150,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Enter the details of Student to Search",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"ID",WS_VISIBLE | WS_CHILD ,5,85,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,85,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,85,150,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE | WS_CHILD | WS_BORDER,5,115,75,35,hWnd,(HMENU)SUBMIT_STUDENT_DETAILS,NULL,NULL);;CreateWindowW(L"Button",L"Cancel",WS_VISIBLE | WS_CHILD | WS_BORDER,125,115,75,35,hWnd,(HMENU)CANCEL,NULL,NULL);
}
void searchStudentFN(HWND hWnd)
{
    clearscr(hWnd);
    CreateWindowW(L"Static",L"Search Student By First Name",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,200,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Enter the details of Student to Search",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"First Name",WS_VISIBLE | WS_CHILD ,5,85,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,85,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,85,150,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE | WS_CHILD | WS_BORDER,5,115,75,35,hWnd,(HMENU)SUBMIT_STUDENT_DETAILS,NULL,NULL);;CreateWindowW(L"Button",L"Cancel",WS_VISIBLE | WS_CHILD | WS_BORDER,125,115,75,35,hWnd,(HMENU)CANCEL,NULL,NULL);
}
void searchStudentLN(HWND hWnd)
{
    clearscr(hWnd);
    CreateWindowW(L"Static",L"Search Student By Last Name",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,200,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Enter the details of Student to Search",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Last Name",WS_VISIBLE | WS_CHILD ,5,85,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,85,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,85,150,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE | WS_CHILD | WS_BORDER,5,115,75,35,hWnd,(HMENU)SUBMIT_STUDENT_DETAILS,NULL,NULL);;CreateWindowW(L"Button",L"Cancel",WS_VISIBLE | WS_CHILD | WS_BORDER,125,115,75,35,hWnd,(HMENU)CANCEL,NULL,NULL);
}
void searchStudentGrade(HWND hWnd)
{
    clearscr(hWnd);
    CreateWindowW(L"Static",L"Search Student By Grade",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,175,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Enter the details of Student to Search",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Grade",WS_VISIBLE | WS_CHILD ,5,85,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,85,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,85,150,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE | WS_CHILD | WS_BORDER,5,115,75,35,hWnd,(HMENU)SUBMIT_STUDENT_DETAILS,NULL,NULL);;CreateWindowW(L"Button",L"Cancel",WS_VISIBLE | WS_CHILD | WS_BORDER,125,115,75,35,hWnd,(HMENU)CANCEL,NULL,NULL);
}
void deleteStudentID(HWND hWnd)
{
    clearscr(hWnd);
    CreateWindowW(L"Static",L"Delete Student By ID",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,150,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Enter the details of Student to Delete",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"ID",WS_VISIBLE | WS_CHILD ,5,85,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,85,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,85,150,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE | WS_CHILD | WS_BORDER,5,115,75,35,hWnd,(HMENU)SUBMIT_STUDENT_DETAILS,NULL,NULL);;CreateWindowW(L"Button",L"Cancel",WS_VISIBLE | WS_CHILD | WS_BORDER,125,115,75,35,hWnd,(HMENU)CANCEL,NULL,NULL);
}
void deleteStudentFN(HWND hWnd)
{
    clearscr(hWnd);
    CreateWindowW(L"Static",L"Delete Student By First Name",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,200,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Enter the details of Student to Delete",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"First Name",WS_VISIBLE | WS_CHILD ,5,85,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,85,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,85,150,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE | WS_CHILD | WS_BORDER,5,115,75,35,hWnd,(HMENU)SUBMIT_STUDENT_DETAILS,NULL,NULL);;CreateWindowW(L"Button",L"Cancel",WS_VISIBLE | WS_CHILD | WS_BORDER,125,115,75,35,hWnd,(HMENU)CANCEL,NULL,NULL);
}
void deleteStudentLN(HWND hWnd)
{
    clearscr(hWnd);
    CreateWindowW(L"Static",L"Delete Student By Last Name",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,200,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Enter the details of Student to Delete",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Last Name",WS_VISIBLE | WS_CHILD ,5,85,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,85,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,85,150,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE | WS_CHILD | WS_BORDER,5,115,75,35,hWnd,(HMENU)SUBMIT_STUDENT_DETAILS,NULL,NULL);;CreateWindowW(L"Button",L"Cancel",WS_VISIBLE | WS_CHILD | WS_BORDER,125,115,75,35,hWnd,(HMENU)CANCEL,NULL,NULL);
}
void deleteStudentGrade(HWND hWnd)
{
    clearscr(hWnd);
    CreateWindowW(L"Static",L"Delete Student By Grade",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,175,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Enter the details of Student to Delete",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Grade",WS_VISIBLE | WS_CHILD ,5,85,100,50,hWnd,NULL,NULL,NULL);CreateWindowW(L"Static",L":",WS_VISIBLE | WS_CHILD ,101,85,100,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Edit",L"",WS_VISIBLE | WS_CHILD | WS_BORDER,125,85,150,20,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Button",L"Submit",WS_VISIBLE | WS_CHILD | WS_BORDER,5,115,75,35,hWnd,(HMENU)SUBMIT_STUDENT_DETAILS,NULL,NULL);;CreateWindowW(L"Button",L"Cancel",WS_VISIBLE | WS_CHILD | WS_BORDER,125,115,75,35,hWnd,(HMENU)CANCEL,NULL,NULL);
}

void viewStudent(HWND hWnd)
{
    clearscr(hWnd);
    CreateWindowW(L"Static",L"View Students",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,110,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"Students List:",WS_VISIBLE | WS_CHILD ,5,45,500,50,hWnd,NULL,NULL,NULL);
}

void about_group(HWND hWnd)
{
    CreateWindowW(L"Static",L"About Group",WS_VISIBLE | WS_CHILD | WS_BORDER ,5,5,85,25,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"National College of Engineering, BCT 2074",WS_VISIBLE | WS_CHILD ,5,40,500,50,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"- Aashish Tamrakar (101)",WS_VISIBLE | WS_CHILD ,5,60,500,250,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"- Bigyat Bhattarai (106)",WS_VISIBLE | WS_CHILD ,5,80,500,250,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"- Niroj Bajracharya (123)",WS_VISIBLE | WS_CHILD ,5,100,500,250,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"- Ram Shrestha (128)",WS_VISIBLE | WS_CHILD ,5,120,500,250,hWnd,NULL,NULL,NULL);
    CreateWindowW(L"Static",L"- Sudip Gyawali (136)",WS_VISIBLE | WS_CHILD ,5,140,500,250,hWnd,NULL,NULL,NULL);
}

void about_project(HWND hWnd)
{
    CreateWindowW(L"Static",L"About Project",WS_VISIBLE | WS_CHILD | WS_BORDER,5,5,100,25,hWnd,NULL,NULL,NULL);
}

void AddMenus(HWND hWnd)
{
    hMenu = CreateMenu();
    HMENU hUsersMenu = CreateMenu();
    HMENU hStudentsMenu = CreateMenu();
        HMENU hStudentsMenu1 = CreateMenu();
        HMENU hStudentsMenu2 = CreateMenu();
        HMENU hStudentsMenu3 = CreateMenu();
        HMENU hStudentsMenu4 = CreateMenu();
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
        AppendMenu(hStudentsMenu,MF_POPUP,(UINT_PTR)hStudentsMenu1,"Update");
            AppendMenu(hStudentsMenu1,MF_STRING,STUDENTS_MENU_UPDATE_ID,"Update by ID");
            AppendMenu(hStudentsMenu1,MF_STRING,STUDENTS_MENU_UPDATE_FN,"Update by First Name");
            AppendMenu(hStudentsMenu1,MF_STRING,STUDENTS_MENU_UPDATE_LN,"Update by Last Name");
            AppendMenu(hStudentsMenu1,MF_STRING,STUDENTS_MENU_UPDATE_GRADE,"Update by Grade");
        AppendMenu(hStudentsMenu,MF_POPUP,(UINT_PTR)hStudentsMenu2,"Search");
            AppendMenu(hStudentsMenu2,MF_STRING,STUDENTS_MENU_SEARCH_ID,"Search by ID");
            AppendMenu(hStudentsMenu2,MF_STRING,STUDENTS_MENU_SEARCH_FN,"Search by First Name");
            AppendMenu(hStudentsMenu2,MF_STRING,STUDENTS_MENU_SEARCH_LN,"Search by Last Name");
            AppendMenu(hStudentsMenu2,MF_STRING,STUDENTS_MENU_SEARCH_GRADE,"Search by Grade");
        AppendMenu(hStudentsMenu,MF_POPUP,(UINT_PTR)hStudentsMenu3,"Delete");
            AppendMenu(hStudentsMenu3,MF_STRING,STUDENTS_MENU_DELETE_ID,"Delete by ID");
            AppendMenu(hStudentsMenu3,MF_STRING,STUDENTS_MENU_DELETE_FN,"Delete by First Name");
            AppendMenu(hStudentsMenu3,MF_STRING,STUDENTS_MENU_DELETE_LN,"Delete by Last Name");
            AppendMenu(hStudentsMenu3,MF_STRING,STUDENTS_MENU_DELETE_GRADE,"Delete by Grade");
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
    if(f<1)
    {
        CreateWindowW(L"Static",L"CHOOSE FROM THE WINDOW ABOVE TO PERFORM ACTIONS.",WS_VISIBLE| WS_CHILD,200,150,250,80,hWnd,NULL,NULL,NULL);
    }
    f++;
}

void clearscr(HWND hWnd)
{
    CreateWindowW(L"Static",L"",WS_VISIBLE| WS_CHILD,0,0,500,500,hWnd,NULL,NULL,NULL);
}
