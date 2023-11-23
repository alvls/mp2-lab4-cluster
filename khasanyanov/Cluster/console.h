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
    HANDLE hConsole;
    CONSOLE_SCREEN_BUFFER_INFO buf_info;
    COORD buf_coord = { 0, 0 };
    CHAR_INFO* buf;
    int buf_size;

    int background = BLACK;
    int foreground = LIGHTGRAY;
    int attr = background * 16 + foreground;

public:
    enum TColor {
        BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY,
        DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED,
        LIGHTMAGENTA, YELLOW, WHITE
    };

    Console();
    int wherex();
    int wherey();
    COORD wherexy();
    void clrscr();
    void gotoxy(int x, int y);
    void textcolor(int color);
    void textbackground(int color);
    void textattr(int color);
    void setwindow(int width, int height);
    void setWindow(SMALL_RECT rect, COORD size);
    void getwindow(SMALL_RECT* rect, COORD* size);
    void hidecursor();
    void showcursor();
    void flush();
    void clear();
    void write(int x, int y, std::wstring s);
    void set_pixel(int x, int y, wchar_t value);
    void set_pixel_foreground(int color);
    void set_pixel_background(int color);
    ~Console();
};

#endif