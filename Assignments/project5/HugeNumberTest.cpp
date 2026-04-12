#include <gtest/gtest.h>
#include "HugeNumber.h"
#include <iostream>
#include <string>
#include <vector>

TEST(DefaultConstructor, InitializesToZero)
{
    HugeNumber hn;
    ASSERT_EQ(hn.isZero(), true);
    std::cout << hn << "\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(StringConstructor, PositiveIntInput)
{
    HugeNumber hn(std::string("90"));
    std::cout << hn << "\n";
}

TEST(StringConstructor, NegativeIntInput)
{
    HugeNumber hn(std::string("-90"));
    std::cout << hn << "\n";
}

TEST(StringConstructor, NegativeZero)
{
    HugeNumber hn(std::string("-0"));
    std::cout << hn << "\n";
}

TEST(StringConstructor, ExampleInput1)
{
    HugeNumber hn(std::string("12345678901234567890"));
    std::cout << hn << "\n";
}

TEST(StringConstructor, ExampleInput2)
{
    HugeNumber hn(std::string("-45009"));
    std::cout << hn << "\n";
}

TEST(StringConstructor, EmptyStringThrows)
{
    EXPECT_THROW(HugeNumber hn(std::string("")), std::invalid_argument);
}

TEST(StringConstructor, NegativeSignOnlyThrows)
{
    EXPECT_THROW(HugeNumber hn(std::string("-")), std::invalid_argument);
}

TEST(StringConstructor, MalformedStringsThrows)
{
    EXPECT_THROW(HugeNumber hn(std::string("-A123")), std::invalid_argument);
    EXPECT_THROW(HugeNumber hn(std::string("A-123")), std::invalid_argument);
    EXPECT_THROW(HugeNumber hn(std::string("123A")), std::invalid_argument);
    EXPECT_THROW(HugeNumber hn(std::string("A")), std::invalid_argument);
    EXPECT_THROW(HugeNumber hn(std::string("123-A")), std::invalid_argument);
    EXPECT_THROW(HugeNumber hn(std::string("Ab123")), std::invalid_argument);
    EXPECT_THROW(HugeNumber hn(std::string("-123Ab")), std::invalid_argument);
    EXPECT_THROW(HugeNumber hn(std::string("--123")), std::invalid_argument);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(ArrayConstructor, PositiveIntInput)
{
    const int SIZE = 3;
    char arr[SIZE] = {"90"};
    HugeNumber hn(arr, SIZE);
    std::cout << hn << "\n";
}

TEST(ArrayConstructor, NegativeIntInput)
{
    const int SIZE = 4;
    char arr[SIZE] = {"-90"};
    HugeNumber hn(arr, SIZE);
    std::cout << hn << "\n";
}

TEST(ArrayConstructor, NegativeZero)
{
    const int SIZE = 3;
    char arr[SIZE] = {"-0"};
    HugeNumber hn(arr);
    std::cout << hn << "\n";
}

TEST(ArrayConstructor, ExampleInput1)
{
    const int SIZE = 21;
    char arr[SIZE] = {"12345678901234567890"};
    HugeNumber hn(arr);
    std::cout << hn << "\n";
}

TEST(ArrayConstructor, ExampleInput2)
{
    const int SIZE = 7;
    char arr[SIZE] = {"-45009"};
    HugeNumber hn(arr);
    std::cout << hn << "\n";
}

TEST(ArrayConstructor, EmptyStringThrows)
{
    const int SIZE = 1;
    char arr[SIZE] = {""};
    EXPECT_THROW(HugeNumber hn(arr), std::invalid_argument);
}

TEST(ArrayConstructor, NegativeSignOnlyThrows)
{
    const int SIZE = 2;
    char arr[SIZE] = {"-"};
    EXPECT_THROW(HugeNumber hn(arr), std::invalid_argument);
}

TEST(ArrayConstructor, MalformedStringsThrows)
{
    EXPECT_THROW(HugeNumber("-A123", 6), std::invalid_argument);
    EXPECT_THROW(HugeNumber("A-123", 6), std::invalid_argument);
    EXPECT_THROW(HugeNumber("123A", 5), std::invalid_argument);
    EXPECT_THROW(HugeNumber("A", 2), std::invalid_argument);
    EXPECT_THROW(HugeNumber("123-A", 6), std::invalid_argument);
    EXPECT_THROW(HugeNumber("Ab123", 6), std::invalid_argument);
    EXPECT_THROW(HugeNumber("-123Ab", 7), std::invalid_argument);
    EXPECT_THROW(HugeNumber("--123", 6), std::invalid_argument);
}
////////////////////////////////////////////////////////////////////////////////////
TEST(VectorConstructor, PositiveIntInput)
{
    std::vector<int> d = {9, 0};
    HugeNumber hn(d, true);
    std::cout << hn << "\n";
}

TEST(VectorConstructor, NegativeIntInput)
{
    std::vector<int> d = {9, 0};
    HugeNumber hn(d, false);
    std::cout << hn << "\n";
}

TEST(VectorConstructor, NegativeZero)
{
    std::vector<int> d = {0};
    HugeNumber hn(d, true);
    std::cout << hn << "\n";
}

TEST(VectorConstructor, ExampleInput1)
{
    std::vector<int> d = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    HugeNumber hn(d, false);
    std::cout << hn << "\n";
}

TEST(VectorConstructor, ExampleInput2)
{
    std::vector<int> d = {4, 5, 0, 0, 9};
    HugeNumber hn(d, true);
    std::cout << hn << "\n";
}

TEST(VectorConstructor, EmptyVectorThrows)
{
    std::vector<int> d = {};
    EXPECT_THROW(HugeNumber hn(d, false), std::invalid_argument);
}

TEST(VectorConstructor, MalformedVectorThrows)
{
    EXPECT_THROW(HugeNumber(std::vector<int>{1, 2, 11, 3}, false), std::invalid_argument);
    EXPECT_THROW(HugeNumber(std::vector<int>{1, -2, 3}, true), std::invalid_argument);
    EXPECT_THROW(HugeNumber(std::vector<int>{10, 2, 3}, false), std::invalid_argument);
}

////////////////////////////////////////////////////////////////////////////////////
TEST(Addition, BothPositive)
{
    HugeNumber hn1(std::string("90"));
    HugeNumber hn2(std::string("90"));

    std::cout << hn1 + hn2 << "\n";
}

TEST(Addition, BothPositiveOneLarger)
{
    HugeNumber hn1(std::string("189"));
    HugeNumber hn2(std::string("91"));

    HugeNumber hnr(std::string("280"));

    std::cout << hn1 + hn2 << "\n";
}

TEST(Addition, BothNegative)
{
    HugeNumber hn1(std::string("-90"));
    HugeNumber hn2(std::string("-90"));

    std::cout << hn1 + hn2 << "\n";
}

TEST(Addition, BothNegativeOneLarger)
{
    HugeNumber hn1(std::string("-189"));
    HugeNumber hn2(std::string("-91"));

    HugeNumber hnr(std::string("-280"));

    std::cout << hn1 + hn2 << "\n";
}

TEST(Addition, LargePlusSmall)
{
    HugeNumber hn1(std::string("999999999999"));
    HugeNumber hn2(std::string("1"));

    HugeNumber hnr(std::string("1"));

    std::cout << hn1 + hn2 << "\n";
}

TEST(EqualsComparison, SmallPositiveNumbersEqual)
{
    HugeNumber hn1(std::string("1"));
    HugeNumber hn2(std::string("1"));

    ASSERT_EQ(hn1 == hn2, true);
}

TEST(EqualsComparison, SmallPositiveNumbersNotEqual)
{
    HugeNumber hn1(std::string("-1"));
    HugeNumber hn2(std::string("1"));

    ASSERT_EQ(hn1 == hn2, false);
}

TEST(EqualsComparison, SmallNegativeNumberEquals)
{
    HugeNumber hn1(std::string("-11"));
    HugeNumber hn2(std::string("-11"));

    ASSERT_EQ(hn1 == hn2, true);
}

TEST(EqualsComparison, SmallNegativeNumberNotEquals)
{
    HugeNumber hn1(std::string("-11"));
    HugeNumber hn2(std::string("-10"));

    ASSERT_EQ(hn1 == hn2, false);
}

TEST(EqualsComparison, SmallDifferentSigns)
{
    HugeNumber hn1(std::string("10"));
    HugeNumber hn2(std::string("-10"));

    ASSERT_EQ(hn1 == hn2, false);
}

TEST(EqualsComparison, LargePositiveNumberEquals)
{
    HugeNumber hn1(std::string("99999999999999999999"));
    HugeNumber hn2(std::string("99999999999999999999"));

    ASSERT_EQ(hn1 == hn2, true);
}

TEST(EqualsComparison, LargePositiveNumberNotEquals)
{
    HugeNumber hn1(std::string("99999999999999999998"));
    HugeNumber hn2(std::string("99999999999999999999"));

    ASSERT_EQ(hn1 == hn2, false);
}

TEST(EqualsComparison, LargeNegativeNumberEquals)
{
    HugeNumber hn1(std::string("-99999999999999999999"));
    HugeNumber hn2(std::string("-99999999999999999999"));

    ASSERT_EQ(hn1 == hn2, true);
}

TEST(EqualsComparison, LargeNegativeNumberNotEquals)
{
    HugeNumber hn1(std::string("-99999999999999999998"));
    HugeNumber hn2(std::string("-99999999999999999999"));

    ASSERT_EQ(hn1 == hn2, false);
}

TEST(EqualsComparison, LargeDifferentSign)
{
    HugeNumber hn1(std::string("99999999999999999999"));
    HugeNumber hn2(std::string("-99999999999999999999"));

    ASSERT_EQ(hn1 == hn2, false);
}

TEST(Normalize, NormalizeCases)
{
    HugeNumber hn1(std::string("00123"));
    HugeNumber hn2(std::string("0"));
    HugeNumber hn3(std::string("01"));
    HugeNumber hn4(std::string("-0"));

    hn1.normalize();
    ASSERT_EQ(hn1 == HugeNumber(std::string("123")), true);

    hn2.normalize();
    ASSERT_EQ(hn2.isZero(), true);

    hn3.normalize();
    ASSERT_EQ(hn3 == HugeNumber(std::string("1")), true);

    hn4.normalize();
    ASSERT_EQ(hn4.isZero(), true);
}

TEST(LessThan, Test1)
{
    HugeNumber hn1(std::string("1"));
    HugeNumber hn2(std::string("2"));

    ASSERT_EQ(hn1 < hn2, true);
}

TEST(LessThan, Test2)
{
    HugeNumber hn1(std::string("2"));
    HugeNumber hn2(std::string("1"));

    ASSERT_EQ(hn1 < hn2, false);
}

TEST(LessThan, Test3)
{
    HugeNumber hn1(std::string("-2"));
    HugeNumber hn2(std::string("1"));

    ASSERT_EQ(hn1 < hn2, true);
}

TEST(LessThan, Test4)
{
    HugeNumber hn1(std::string("2"));
    HugeNumber hn2(std::string("-1"));

    ASSERT_EQ(hn1 < hn2, false);
}

TEST(LessThan, Test5)
{
    HugeNumber hn1(std::string("-2"));
    HugeNumber hn2(std::string("-1"));

    ASSERT_EQ(hn1 < hn2, true);
}

TEST(LessThan, Test6)
{
    HugeNumber hn1(std::string("-1"));
    HugeNumber hn2(std::string("-2"));

    ASSERT_EQ(hn1 < hn2, false);
}

TEST(LessThan, Test7)
{
    HugeNumber hn1(std::string("-123"));
    HugeNumber hn2(std::string("-2"));

    ASSERT_EQ(hn1 < hn2, true);
}

TEST(LessThan, Test8)
{
    HugeNumber hn1(std::string("-2"));
    HugeNumber hn2(std::string("-123"));

    ASSERT_EQ(hn1 < hn2, false);
}

TEST(LessThan, Test9)
{
    HugeNumber hn1(std::string("0"));
    HugeNumber hn2(std::string("0"));

    ASSERT_EQ(hn1 < hn2, false);
}

TEST(LessThan, Test10)
{
    HugeNumber hn1(std::string("1"));
    HugeNumber hn2(std::string("1"));

    ASSERT_EQ(hn1 < hn2, false);
}

TEST(LessThan, Test11)
{
    HugeNumber hn1(std::string("-1"));
    HugeNumber hn2(std::string("-1"));

    ASSERT_EQ(hn1 < hn2, false);
}



