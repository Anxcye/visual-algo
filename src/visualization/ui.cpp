#include "ui.h"
#include <cstdlib>
#include <menu.h>
#include <iostream>
#include "array.h"
#include "bits/this_thread_sleep.h"

void initUi() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_BLUE, COLOR_WHITE);
        init_pair(2, COLOR_BLACK, COLOR_BLACK);
        init_pair(3, COLOR_WHITE, COLOR_BLUE);
    }

}

void endUi() {
    endwin();
}


int showMenu( char*choices[], int n_choices) {
    ITEM **items;
    MENU *menu;
    int i;
    WINDOW *menu_win;

    clear();
    bkgd(COLOR_PAIR(1));


    items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        items[i] = new_item(choices[i], "");

    menu = new_menu(items);

    // Create menu window
    menu_win = newwin(n_choices + 2, 40, 1, 4);
    box(menu_win, 0, 0);
    wbkgd(menu_win, COLOR_PAIR(1));
    keypad(menu_win, TRUE);

    set_menu_back(menu, COLOR_PAIR(1));
    set_menu_fore(menu, COLOR_PAIR(1) | A_REVERSE);

    set_menu_win(menu, menu_win);
    set_menu_sub(menu, derwin(menu_win, n_choices, 38, 1, 1));

    set_menu_mark(menu, "> ");

    mvprintw(LINES - 3, 3, "Select the sorting algorithm:");

    refresh();

    post_menu(menu);
    wrefresh(menu_win);

    int ch;
    while ((ch = wgetch(menu_win)) != '\n') {
        switch (ch) {
            case KEY_DOWN:
                menu_driver(menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                menu_driver(menu, REQ_UP_ITEM);
                break;
        }
        wrefresh(menu_win);
    }

    ITEM *cur_item = current_item(menu);
    int selected_index = item_index(cur_item);

    unpost_menu(menu);
    free_menu(menu);
    for (i = 0; i < n_choices; ++i)
        free_item(items[i]);
    delwin(menu_win);

    return selected_index;
}


void displayArray(Array& arr, int delay) {
    // clear();
    // bkgd(COLOR_PAIR(1));

    int height, width;
    getmaxyx(stdscr, height, width);

    int sub_height = arr.getSize() * 2 + 1;
    int sub_width = 70;
    int start_y = (height - sub_height) / 2;
    int start_x = (width - sub_width) / 2;

    WINDOW *subwin = newwin(sub_height, sub_width, start_y, start_x);
    wbkgd(subwin, COLOR_PAIR(3));
    box(subwin, 0, 0);

    wattr_on(subwin, COLOR_PAIR(3), NULL);

    for (int i = 0; i < arr.getSize(); ++i) {
        mvwprintw(subwin, i * 2  + 1, 1, "%d", arr.get(i));
        for (int j = 0; j < arr.get(i); ++j) {
            mvwaddch(subwin, i * 2 + 1, j + 5, '\u2598' );
            // mvwaddstr
        }
        
    }

    wattr_off(subwin, COLOR_PAIR(3), NULL);

    refresh();
    wrefresh(subwin);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
}

