#include <ncurses.h>
#include <gtest/gtest.h>
TEST(NcursesTest, test1) {
    initscr();

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
    }

    printw("Hello, ncurses!");

    attron(COLOR_PAIR(1));
    mvprintw(4, 0, "This is red text.");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    mvprintw(5, 0, "This is green text.");
    attroff(COLOR_PAIR(2));
    mvprintw(7, 0, "Press any key to continue...");

    refresh();

    char ch = getch();

    mvprintw(9, 0, "Key pressed: %c\n", ch);
    refresh();

    WINDOW* win = newwin(10, 30, 5, 5);
    wbkgd(win, COLOR_PAIR(1));
    box(win, 0, 0);
    mvwprintw(win, 1, 1, "Window content");
    wrefresh(win);
    getch();
    delwin(win);
    refresh();
    getch();
    endwin();
}
TEST(NcursesTest, test2) {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_WHITE);
        init_pair(2, COLOR_BLACK, COLOR_BLACK);
        init_pair(3, COLOR_BLACK, COLOR_WHITE);
    }
    clear();
    bkgd(COLOR_PAIR(1));

    int height, width;
    getmaxyx(stdscr, height, width);

    int sub_height = 10;
    int sub_width = 30;
    int start_y = (height - sub_height) / 2;
    int start_x = (width - sub_width) / 2;

    WINDOW* subwin = newwin(sub_height, sub_width, start_y, start_x);
    wbkgd(subwin, COLOR_PAIR(1));
    wattron(subwin, COLOR_PAIR(3));
    box(subwin, 0, 0);
    mvwprintw(subwin, 1, 1, "This is a subwindow.");
    wattroff(subwin, COLOR_PAIR(3));

    wattron(stdscr, COLOR_PAIR(2));
    for (int i = 0; i < sub_height; ++i) {
        mvwaddch(stdscr, start_y + i, start_x + sub_width, ' ');
    }
    for (int i = 0; i < sub_width + 1; ++i) {
        mvwaddch(stdscr, start_y + sub_height, start_x + i, ' ');
    }
    wattroff(stdscr, COLOR_PAIR(2));

    refresh();
    wrefresh(subwin);

    getch();

    delwin(subwin);
    endwin();
}
TEST(NcursesTest, test3) {
    initscr();
    printw("Hello World !!!");
    refresh();
    getch();
    endwin();
}