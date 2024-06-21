#include <gtest/gtest.h>
#include <ui.h>
#include"random_generator.h"

TEST(UiTest, test1) {
    initUi();
    char *choices[] = {
        "Bubble Sort",
        "Selection Sort",
        "Insertion Sort",
        "Quick Sort",
        "Merge Sort",
        "Merge Sort",
        "Merge Sort",
        "Exit"
    };
    showMenu(choices, sizeof(choices) / sizeof(char*));
    endUi();
}

TEST(UiTest, test2) {
    initUi();
    Array arr(5);
    generateRandomArray(arr, 0, 60);
    displayArray(arr, 100);
    endUi();
}