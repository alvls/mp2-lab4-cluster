#ifndef __CONSOLE_H__
#define __CONSOLE_H__


#include <string>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include <memory.h>

class Console
{
private:
    static HANDLE hConsole;
    static CONSOLE_SCREEN_BUFFER_INFO buf_info;
    static COORD buf_coord;
    static CHAR_INFO* buf;
    static int buf_size;
    static int background;
    static int foreground;
    static int attr;

public:
    enum TColor {
        BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY,
        DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED,
        LIGHTMAGENTA, YELLOW, WHITE
    };

    static void init();
    static int wherex();
    static int wherey();
    static COORD wherexy();
    static void clrscr();
    static void gotoxy(int x, int y);
    static void textcolor(int color);
    static void textbackground(int color);
    static void textattr(int color);
    static void setwindow(int width, int height);
    static void setWindow(SMALL_RECT rect, COORD size);
    static void getwindow(SMALL_RECT* rect, COORD* size);
    static void hidecursor();
    static void showcursor();
    static void flush();
    static void clear();
    static void write(int x, int y, std::wstring s);
    static void set_pixel(int x, int y, wchar_t value);
    static void set_pixel_foreground(int color);
    static void set_pixel_background(int color);
    static void free();
};

#endif