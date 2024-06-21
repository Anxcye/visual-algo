#include "bubble_sort.h"
#include "visualize.h"
#include "ui.h"

void bubbleSort(Array array) {
    int size = array.getSize();
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array.get(j) > array.get(j + 1)) {
                int temp = array.get(j);
                array.set(j, array.get(j + 1));
                array.set(j + 1, temp);
                displayArray(array, 100);   
            }
        }
    }
}
