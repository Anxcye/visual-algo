#include "array.h"
#include "bubble_sort.h"
#include "random_generator.h"
#include "ui.h"

int main() {
    int size = 10;
    char* choices[] = {
        "Bubble Sort",
        "Selection Sort",
        "Insertion Sort",
        "Quick Sort",
        "Merge Sort",
        "Merge Sort",
        "Merge Sort",
        "Exit"
    };

    Array array(size);

    generateRandomArray(array, 1, 20);
    initUi();

    int selected = 0;
    while (1) {
        Array arr(array);
        selected = showMenu(choices, sizeof(choices) / sizeof(char*));

        switch (selected) {
        case 0:
            bubbleSort(arr);
            break;
        case 1:
            bubbleSort(arr);
            break;
        default:
            endUi();
            return 0;
            break;
        }


    }
}
