#include "array.h"
#include "bubble_sort.h"
#include "random_generator.h"

int main() {
    int size = 20;
    Array array(size);

    generateRandomArray(array, 1, 20);
    bubbleSort(array);

    return 0;
}
