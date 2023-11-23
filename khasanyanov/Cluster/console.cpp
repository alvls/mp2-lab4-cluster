#include "console.h"

Console::Console() {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &buf_info);
    buf = new CHAR_INFO[buf_size = buf_info.dwSize.X * buf_info.dwSize.Y];
}

Console::~Console() {
    delete[] buf;
}

void Console::flush() {
    hidecursor();
    WriteConsoleOutput(
        hConsole,
        buf,
        buf_info.dwSize,
        buf_coord,
        &buf_info.srWindow);
}

void Console::clear() {
    memset(buf, 0, buf_size);
}

void Console::write(int x, int y, std::wstring s) {
    for (int xc = 0; xc < s.length(); xc++) {
        set_pixel(x + xc, y, s[xc]);
    }
}

void Console::set_pixel(int x, int y, wchar_t value) {
    buf[y * buf_info.dwSize.X + x].Char.UnicodeChar = value;
    buf[y * buf_info.dwSize.X + x].Attributes = attr;
}

void Console::set_pixel_foreground(int color) {
    foreground = color;
    attr = (foreground % 16) + background * 16;
}

void Console::set_pixel_background(int color) {
    background = color;
    attr = background * 16 + foreground;
}

int Console::wherex(void) {
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!Console)
        return -1;

    CONSOLE_SCREEN_BUFFER_INFO buf;

    GetConsoleScreenBufferInfo(Console, &buf);
    return buf.dwCursorPosition.X;
}

int Console::wherey(void) {
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!Console)
        return -1;

    CONSOLE_SCREEN_BUFFER_INFO buf;

    GetConsoleScreenBufferInfo(Console, &buf);
    return buf.dwCursorPosition.Y;
}

COORD Console::wherexy(void) {
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { -1, -1 };
    if (!Console)
        return pos;

    CONSOLE_SCREEN_BUFFER_INFO buf;

    GetConsoleScreenBufferInfo(Console, &buf);
    return buf.dwCursorPosition;
}

void Console::clrscr(void) {
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!Console)
        return;

    CONSOLE_SCREEN_BUFFER_INFO buf;
    GetConsoleScreenBufferInfo(Console, &buf);

    WORD Attr;
    DWORD Count;
    COORD pos = buf.dwCursorPosition;
    ReadConsoleOutputAttribute(Console, &Attr, 1, pos, &Count);

    int col = Attr;
    int width = buf.dwSize.X;
    int height = buf.dwSize.Y;

    COORD zpos;
    zpos.X = 0;
    zpos.Y = 0;
    SetConsoleCursorPosition(Console, zpos);

    FillConsoleOutputAttribute(Console, col, width * height, zpos, &Count);
    FillConsoleOutputCharacter(Console, ' ', width * height, zpos, &Count);
}

void Console::gotoxy(int x, int y) {
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!Console)
        return;

    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(Console, pos);
}

void Console::textcolor(int color) {
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!Console)
        return;

    CONSOLE_SCREEN_BUFFER_INFO buf;
    GetConsoleScreenBufferInfo(Console, &buf);

    WORD Attr;
    DWORD Count;
    COORD pos = buf.dwCursorPosition;
    ReadConsoleOutputAttribute(Console, &Attr, 1, pos, &Count);

    int bk_col = Attr / 16;
    int col = color % 16;
    col = col + bk_col * 16;

    SetConsoleTextAttribute(Console, col);
}

void Console::textbackground(int color) {
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!Console)
        return;

    CONSOLE_SCREEN_BUFFER_INFO buf;
    GetConsoleScreenBufferInfo(Console, &buf);

    WORD Attr;
    DWORD Count;
    COORD pos = buf.dwCursorPosition;
    ReadConsoleOutputAttribute(Console, &Attr, 1, pos, &Count);

    int text_col = Attr % 16;
    int col = color % 16;
    col = color * 16 + text_col;

    SetConsoleTextAttribute(Console, col);
}

void Console::textattr(int color) {
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!Console)
        return;

    SetConsoleTextAttribute(Console, color);
}

void Console::setwindow(int width, int height) {
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!Console)
        return;

    SMALL_RECT rect;
    rect.Left = 0;
    rect.Right = width - 1;
    rect.Top = 0;
    rect.Bottom = height - 1;
    COORD size;
    size.X = width;
    size.Y = height;
    SetConsoleWindowInfo(Console, 1, &rect);
    SetConsoleScreenBufferSize(Console, size);
}

void Console::setWindow(SMALL_RECT rect, COORD size) {
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!Console)
        return;

    SetConsoleScreenBufferSize(Console, size);
    SetConsoleWindowInfo(Console, 1, &rect);
}

void Console::getwindow(SMALL_RECT* rect, COORD* size) {
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!Console)
        return;

    CONSOLE_SCREEN_BUFFER_INFO buf;
    GetConsoleScreenBufferInfo(Console, &buf);

    *rect = buf.srWindow;
    size->X = buf.dwSize.X;
    size->Y = buf.dwSize.Y;
}

void Console::hidecursor(void) {
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!Console)
        return;

    CONSOLE_CURSOR_INFO buf;
    GetConsoleCursorInfo(Console, &buf);
    buf.bVisible = 0;
    SetConsoleCursorInfo(Console, &buf);
}

void Console::showcursor(void) {
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!Console)
        return;

    CONSOLE_CURSOR_INFO buf;
    GetConsoleCursorInfo(Console, &buf);
    buf.bVisible = 1;
    SetConsoleCursorInfo(Console, &buf);
}