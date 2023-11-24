#include <gtest/gtest.h>
#include "check.hpp"

TEST(test_1, correct_number)
{
    ASSERT_TRUE(check("aa") == 2);
}
TEST(test_2, correct_number)
{
    ASSERT_TRUE(check("aa a") == 3);
}
TEST(test_3, correct_number)
{
    ASSERT_TRUE(check("b") == 0);
}
TEST(test_4, correct_number)
{
    ASSERT_TRUE(check("i") == 1);
}
TEST(test_5, correct_number)
{
    ASSERT_TRUE(check("y") == 1);
}
TEST(test_6, correct_number)
{
    ASSERT_TRUE(check("bbbbbbbb a") == 1);
}
TEST(test_7, correct_number)
{
    ASSERT_TRUE(check("") == 0);
}
TEST(test_8, correct_number)
{
    ASSERT_TRUE(check("byby yu") == 4);
}
TEST(test_9, correct_number)
{
    ASSERT_TRUE(check("rrr skiski meow") == 4);
}
TEST(test_10, correct_number)
{
    ASSERT_TRUE(check("aya  ") == 3);
}
TEST(test_11, correct_number)
{
    ASSERT_TRUE(check("     a") == 1);
}
TEST(test_12, correct_number)
{
    ASSERT_TRUE(check("      b     a") == 1);
}
TEST(test_13, correct_number)
{
    ASSERT_TRUE(check("iou") == 3);
}