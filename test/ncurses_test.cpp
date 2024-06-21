#include <ncurses.h>
#include <gtest/gtest.h>

TEST(NcursesTest, Initialization) {
    initscr();			
	printw("Hello World !!!");	
	refresh();		
	getch();		
	endwin();		

}


