
#include <gtest/gtest.h>
#include <iostream>


int main(int argc, char** argv) {
    std::cout << "Gtest!" << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    ::testing::GTEST_FLAG(filter) = "UiTest.test*";

    return RUN_ALL_TESTS();
}
