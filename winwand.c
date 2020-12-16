#include <Windows.h>
#include <stdio.h>
#include <string.h>
int ToggleExStyle(char* title, long int param) {
    HWND hWnd = FindWindow(NULL, title);
	if(hWnd)
	{
        long int params = GetWindowLongPtr(hWnd, GWL_EXSTYLE);
		SetWindowLongPtr(hWnd, GWL_EXSTYLE, params ^ param);
        return 0;
	} else {
        return 1;
    }
}
int ToggleStyle(char* title, long int param) {
    HWND hWnd = FindWindow(NULL, title);
	if(hWnd)
	{
        long int params = GetWindowLongPtr(hWnd, GWL_STYLE);
		SetWindowLongPtr(hWnd, GWL_STYLE, params ^ param);
        return 0;
	} else {
        return 1;
    }
}
int ToggleWindowVisiblity(char* title) {
    HWND hWnd = FindWindow(NULL, title);
	if(hWnd)
	{
		if (IsWindowVisible(hWnd)) {
            ShowWindow(hWnd, SW_HIDE);
        } else {
            ShowWindow(hWnd, SW_SHOW);
        }
        return 0;
	} else {
        return 1;
    }
}
int ToggleWindowTopmost(char* title) {
    HWND hWnd = FindWindow(NULL, title);
    if (hWnd) {
        if (GetWindowLong(hWnd, GWL_EXSTYLE) & WS_EX_TOPMOST) {
            SetWindowPos(hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        } else {
            SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        }
        return 0;
    } else {
        return 1;
    }
}
int ShowHelp() {
    printf(
        "winwand [help|visiblity|rtl|min|max|resize|dialog|sysmenu|top|caption] [window [window ...]]\n\n"
        "help: Show this help\n"
        "visiblity: Toggle visiblity\n"
        "rtl: Change system buttons position. May cause unexpected behavior, like mouse position mirroring, window mirroring or something bad.\n"
        "min: Toggle Minimize button\n"
        "max: Toggle Maximize button\n"
        "resize: Toggle resizing\n"
        "toolbar: Toggle toolbar UI. May cause unexpected behavior when minimizing the window.\n"
        "sysmenu: Toggle system menu\n"
        "top: Pins window to the foreground\n"
        "caption: Toggle caption");
    return 0;
}
int main(int argc, char *argv[]) {
    if (argc < 3) {
        ShowHelp();
    } else {
            if (strcmp(argv[1], "help") == 0) {
                ShowHelp();
            } else if (strcmp(argv[1], "visiblity") == 0) {
                for (unsigned int c = 2;c < argc;c++) {
                    ToggleWindowVisiblity(argv[c]);
                }
            } else if (strcmp(argv[1], "rtl") == 0) {
                for (unsigned int c = 2;c < argc;c++) {
                    ToggleExStyle(argv[c], WS_EX_LAYOUTRTL);
                }
            } else if (strcmp(argv[1], "min") == 0) {
                for (unsigned int c = 2;c < argc;c++) {
                    ToggleStyle(argv[c], WS_MINIMIZEBOX);
                }
            } else if (strcmp(argv[1], "max") == 0) {
                for (unsigned int c = 2;c < argc;c++) {
                    ToggleStyle(argv[c], WS_MAXIMIZEBOX);
                }
            } else if (strcmp(argv[1], "resize") == 0) {
                for (unsigned int c = 2;c < argc;c++) {
                    ToggleStyle(argv[c], WS_SIZEBOX);
                }
            } else if (strcmp(argv[1], "toolbar") == 0) {
                for (unsigned int c = 2;c < argc;c++) {
                    ToggleExStyle(argv[c], WS_EX_TOOLWINDOW);
                }
            } else if (strcmp(argv[1], "sysmenu") == 0) {
                for (unsigned int c = 2;c < argc;c++) {
                    ToggleStyle(argv[c], WS_SYSMENU);
                }
            } else if (strcmp(argv[1], "top") == 0) {
                for (unsigned int c = 2;c < argc;c++) {
                    ToggleWindowTopmost(argv[c]);
                }
            } else if (strcmp(argv[1], "caption") == 0) {
                for (unsigned int c = 2;c < argc;c++) {
                    ToggleStyle(argv[c], WS_CAPTION);
                }
            } else {
                ShowHelp();
            }
    }
}