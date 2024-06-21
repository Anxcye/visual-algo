#include "sort.h"
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

void selectionSort(Array array) {
    int size = array.getSize();
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (array.get(j) < array.get(minIndex)) {
                minIndex = j;
            }
        }
        int temp = array.get(i);
        array.set(i, array.get(minIndex));
        array.set(minIndex, temp);
        displayArray(array, 100);
    }
}

void insertionSort(Array array) {
    int size = array.getSize();
    for (int i = 1; i < size; ++i) {
        int key = array.get(i);
        int j = i - 1;
        while (j >= 0 && array.get(j) > key) {
            array.set(j + 1, array.get(j));
            --j;
        }
        array.set(j + 1, key);
        displayArray(array, 100);
    }
}

int partition(Array& array, int low, int high) {
    int pivot = array.get(high);
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (array.get(j) < pivot) {
            ++i;
            int temp = array.get(i);
            array.set(i, array.get(j));
            array.set(j, temp);
            displayArray(array, 100);
        }
    }
    int temp = array.get(i + 1);
    array.set(i + 1, array.get(high));
    array.set(high, temp);
    displayArray(array, 100);
    return i + 1;
}

void quickSortHelper(Array& array, int low, int high) {
    if (low < high) {
        int pivot = partition(array, low, high);
        quickSortHelper(array, low, pivot - 1);
        quickSortHelper(array, pivot + 1, high);
    }
}

void quickSort(Array array) {
    quickSortHelper(array, 0, array.getSize() - 1);
}

void merge(Array& array, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    Array left(n1), right(n2);
    for (int i = 0; i < n1; ++i) {
        left.set(i, array.get(low + i));
    }
    for (int i = 0; i < n2; ++i) {
        right.set(i, array.get(mid + 1 + i));
    }
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left.get(i) <= right.get(j)) {
            array.set(k, left.get(i));
            ++i;
        } else {
            array.set(k, right.get(j));
            ++j;
        }
        ++k;
        displayArray(array, 100);
    }
    while (i < n1) {
        array.set(k, left.get(i));
        ++i;
        ++k;
        displayArray(array, 100);
    }
    while (j < n2) {
        array.set(k, right.get(j));
        ++j;
        ++k;
        displayArray(array, 100);
    }
}

void mergeSortHelper(Array& array, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSortHelper(array, low, mid);
        mergeSortHelper(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

void mergeSort(Array array) {
    mergeSortHelper(array, 0, array.getSize() - 1);
}