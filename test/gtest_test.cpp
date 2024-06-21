#include <gtest/gtest.h>
#include "data_structures/array.h"

TEST(GTest, Initialization) {
    Array arr(5);
    EXPECT_EQ(arr.getSize(), 5);
}

