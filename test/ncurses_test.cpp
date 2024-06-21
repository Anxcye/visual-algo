#include <ncurses.h>
#include <gtest/gtest.h>

TEST(NcursesTest, test1) {
    // Initialize the screen
    initscr();

    // Check if the terminal supports colors
    if (has_colors()) {
        // Enable color mode
        start_color();
        // Define a color pair (pair number, foreground color, background color)
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
    }

    // Print a message at the current cursor position
    printw("Hello, ncurses!");


    // Change text color using the defined color pair
    attron(COLOR_PAIR(1));
    mvprintw(4, 0, "This is red text.");
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvprintw(5, 0, "This is green text.");
    attroff(COLOR_PAIR(2));

    mvprintw(7, 0, "Press any key to continue...");

    // Refresh the screen to update changes
    refresh();

    // Wait for user input
    char ch = getch();

    // Move the cursor to a new position and print another message
    mvprintw(9, 0, "Key pressed: %c\n", ch);
    refresh();

    // window and subwindow
    WINDOW* win = newwin(10, 30, 5, 5); // Create a new window
    wbkgd(win, COLOR_PAIR(1)); // Set the background color of the window
    box(win, 0, 0); // Draw a box around the window
    mvwprintw(win, 1, 1, "Window content");
    wrefresh(win); // Refresh the window to show changes

    getch();
    // delete the window
    delwin(win);
    refresh();

    getch();
    // End ncurses mode and clean up
    endwin();
}

TEST(NcursesTest, test2) {
      // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);


    // Check if the terminal supports colors
    if (has_colors()) {
        // Start color mode
        start_color();
        // Define color pairs
        init_pair(1, COLOR_WHITE, COLOR_WHITE); // White on white for the subwindow
        init_pair(2, COLOR_BLACK, COLOR_BLACK); // Black on black for the shadow
        init_pair(3, COLOR_BLACK, COLOR_WHITE); // Black text on white background
    }
    clear();
    bkgd(COLOR_PAIR(1));


    // Get screen size
    int height, width;
    getmaxyx(stdscr, height, width);

    // Define the subwindow size and position
    int sub_height = 10;
    int sub_width = 30;
    int start_y = (height - sub_height) / 2;
    int start_x = (width - sub_width) / 2;

    // Create the subwindow
    WINDOW *subwin = newwin(sub_height, sub_width, start_y, start_x);
    wbkgd(subwin, COLOR_PAIR(1)); // Set white background for the subwindow
    wattron(subwin, COLOR_PAIR(3));
    box(subwin, 0, 0); // Draw a box around the subwindow
    mvwprintw(subwin, 1, 1, "This is a subwindow.");
    wattroff(subwin, COLOR_PAIR(3));

    // Create the shadow effect
    wattron(stdscr, COLOR_PAIR(2));
    for (int i = 0; i < sub_height; ++i) {
        mvwaddch(stdscr, start_y + i, start_x + sub_width, ' '); // Right shadow
    }
    for (int i = 0; i < sub_width + 1; ++i) {
        mvwaddch(stdscr, start_y + sub_height, start_x + i, ' '); // Bottom shadow
    }
    wattroff(stdscr, COLOR_PAIR(2));

    // Refresh both windows
    refresh();
    wrefresh(subwin);

    // Wait for user input
    getch();

    // Clean up
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