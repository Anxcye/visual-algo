#include "random_generator.h"


void generateRandomArray(Array& array, int minValue, int maxValue) {
    std::srand(std::time(nullptr));
    for (int i = 0; i < array.getSize(); ++i) {
        array.set(i, minValue + std::rand() % (maxValue - minValue + 1));
    }
}
