//
// Created by Yuno on 02/03/2020.
//

#include "LibNcurse.hpp"

static LibNcurse *lib = NULL;

LibNcurse::LibNcurse()
{
}

void LibNcurse::Init()
{
    initscr();
    _win = newwin(LINES, COLS, 0, 0);
    cbreak();
    _textMode = false;
    timeout(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    noecho();
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_RED);
    init_pair(3, COLOR_GREEN, COLOR_GREEN);
    init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(5, COLOR_BLUE, COLOR_BLUE);
    init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(7, COLOR_CYAN, COLOR_CYAN);
    init_pair(8, COLOR_WHITE, COLOR_WHITE);
    init_pair(11, COLOR_BLACK, COLOR_BLACK);
    init_pair(12, COLOR_RED, COLOR_BLACK);
    init_pair(13, COLOR_GREEN, COLOR_BLACK);
    init_pair(14, COLOR_YELLOW, COLOR_BLACK);
    init_pair(15, COLOR_BLUE, COLOR_BLACK);
    init_pair(16, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(17, COLOR_CYAN, COLOR_BLACK);
    init_pair(18, COLOR_WHITE, COLOR_BLACK);
    curs_set(0);
}

const int LibNcurse::getColor(std::string color) const {
    if (color == "black") return 1;
    if (color == "red") return 2;
    if (color == "green") return 3;
    if (color == "yellow") return 4;
    if (color == "blue") return 5;
    if (color == "magenta") return 6;
    if (color == "cyan") return 7;
    if (color == "white") return 8;
    return 1;
}

std::string LibNcurse::getString()
{
    int ch = getch();
    wmove(_win, 30, 50);
    if (ch != ' ') {
        if (std::isalpha(ch) != 0) {
            if (_input.length() <    6)
                _input += static_cast<char>(ch);
        }
        return "";
    } else if (_input.length() != 0) {
        cbreak();
        noecho();
        _textMode = false;
    }
    return "text: '" + _input + "'";
}

void LibNcurse::enterTextMode()
{
    _textMode = true;
    nocbreak();
    echo();
}

void LibNcurse::drawText(const std::string &text, const Vector2<int> &position, const std::string &color) {
    wmove(_win, position.y, position.x);
    wattron(_win, COLOR_PAIR(getColor(color) + 10));
    waddstr(_win, text.c_str());
    wattroff(_win, COLOR_PAIR(getColor(color) + 10));
}

void LibNcurse::drawRectangle(const Rectangle<int> &rect, const std::string &color)
{
    std::string shape;
    std::string ncolor = color;
    if (color.find(":") < color.length()) {
        ncolor = color.substr(0, color.find(":"));
    }
    wattron(_win, COLOR_PAIR(getColor(ncolor)));
    wmove(_win, rect.p2, rect.p1);
    for (int i = 0; i < rect.p4; ++i) {
        for (int j = 0; j < rect.p3 * 2; ++j)
            shape += "#";
        waddstr(_win, shape.c_str());
        wmove(_win, rect.p2 + i, rect.p1);
        shape = "";
    }
    wattroff(_win, COLOR_PAIR(getColor(ncolor)));
}

void LibNcurse::clearWindow()
{
    wclear(_win);
}

void LibNcurse::drawWindow(void)
{
    doupdate();
    if (_textMode) {
        wmove(_win, 30, 40);
        waddstr(_win, _input.c_str());
    }
    wnoutrefresh(_win);
}

void LibNcurse::loadTextures(std::vector <std::string> textures)
{
    (void) textures;
}

void LibNcurse::close()
{
    if (_win) {
        endwin();
        _win = nullptr;
    }
}

const bool LibNcurse::isOpen() const
{
    if (this->_win)
        return true;

    return false;
}

const std::string LibNcurse::handleEvent()
{
    if (_textMode)
        return getString();
    int a = getch();
    switch (a) {
        case KEY_UP:
            return "up";
        case KEY_DOWN:
            return "down";
        case KEY_LEFT:
            return "left";
        case KEY_RIGHT:
            return "right";
        case 'e':
            return "e";
        case 'l':
            return "next";
        case 'k':
            return "prev";
        default:
            return "";
    }
}

LibNcurse::~LibNcurse()
{
    endwin();
}

extern "C"
{
    __attribute__((constructor))
    void ctor()
    {
        lib = new LibNcurse;
    }

    __attribute__((destructor))
    void dtor ()
    {
        delete (lib);
    }

    LibNcurse *entryPoint()
    {
        return lib;
    }

    void draw_square(const Rectangle<int> &rect, std::string color)
    {
        lib->drawRectangle(rect, color);
    }

    void draw_text(const std::string &text,  const Vector2<int> &position, const std::string &color)
    {
        lib->drawText(text, position, color);
    }

    void draw()
    {
        lib->drawWindow();
    }

    void handle_event()
    {
        return;
    }
}