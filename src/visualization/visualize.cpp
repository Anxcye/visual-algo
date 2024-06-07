#include "visualize.h"
#include <iostream>
#include <thread>
#include <chrono>

void visualize(const Array& array) {
    system("clear"); 
    for (int i = 0; i < array.getSize(); ++i) {
        for (int j = 0; j < array.get(i); ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
