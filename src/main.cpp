#include "array.h"
#include "sort.h"
#include "random_generator.h"
#include "ui.h"
#include <unistd.h>

int main() {
    int size = 10;
    char* choices[] = {
        "Bubble Sort",
        "Selection Sort",
        "Insertion Sort",
        "Quick Sort",
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
            selectionSort(arr);
            break;
        case 2:
            insertionSort(arr);
            break;
        case 3:
            quickSort(arr);
            break;
        case 4:
            mergeSort(arr);
            break;
        default:
            endUi();
            return 0;
            break;
        }
        sleep(1);

    }
}
