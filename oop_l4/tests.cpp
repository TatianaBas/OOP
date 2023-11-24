#include <gtest/gtest.h>

#include "Figure.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Array.h"
#include "Functions.h"

#define pii std::pair<int,int>
#define pdd std::pair<double,double>

// Trapezoid

TEST(trapezoid_test01, empty_constructor_int){
    Trapezoid<int> a;

    double sm = square<Trapezoid<int>,int>(a);

    EXPECT_EQ(sm,0);
}

TEST(trapezoid_test02, four_points_constructor_int){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));

    double sm = square<Trapezoid<int>,int>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}

TEST(trapezoid_test08, four_points_constructor_double){
    Trapezoid<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0));

    double sm = square<Trapezoid<double>,double>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}

// Rhombus

TEST(rhombus_test01, empty_constructor_int){
    Rhombus<int> a;

    double sm = square<Rhombus<int>,int>(a);

    EXPECT_EQ(sm,0);
}

TEST(Rhombus_test02, four_points_constructor_int){
    Rhombus<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));

    double sm = square<Rhombus<int>,int>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}


TEST(Rhombus_test08, four_points_constructor_double){
    Rhombus<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0));

    double sm = square<Rhombus<double>,double>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}

// Pentagon

TEST(Pentagon_test01, empty_constructor_int){
    Pentagon<int> a;

    double sm = square<Pentagon<int>,int>(a);

    EXPECT_EQ(sm,0);
}

TEST(Pentagon_test02, four_points_constructor_int){
    Pentagon<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0),pii(0,0));

    double sm = square<Pentagon<int>,int>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}


TEST(Pentagon_test07, empty_constructor_double){
    Pentagon<double> a;

    double sm = square<Pentagon<double>,double>(a);

    EXPECT_EQ(sm,0);
}

TEST(Pentagon_test08, four_points_constructor_double){
    Pentagon<double> a(pdd(0.0,0.0),pdd(0.0,10.0),pdd(10.0,10.0),pdd(10.0,0.0),pdd(0.0,0.0));

    double sm = square<Pentagon<double>,double>(a);
    std::cout << sm << std::endl;

    EXPECT_TRUE(sm == 100);
}

// Array

TEST(array_test01, empty_constructor){
    Array<std::shared_ptr<Figure>> arr;

    EXPECT_EQ(arr.size(), 0);
}

TEST(array_test02, size_constructor){
    Array<std::shared_ptr<Figure>> arr(2);

    EXPECT_EQ(arr.size(), 0);

    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);

    arr.push_back(a_ptr);

    EXPECT_EQ(arr.size(), 1);
}

TEST(array_test03, list_constructor){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(pii(10,10),pii(20,20),pii(30,30),pii(40,40));
    Pentagon<int> c(pii(100,100),pii(200,200),pii(300,300),pii(400,400),pii(500,500));

    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);
    std::shared_ptr<Rhombus<int>> b_ptr = std::make_shared<Rhombus<int>>(b);
    std::shared_ptr<Pentagon<int>> c_ptr = std::make_shared<Pentagon<int>>(c);

    Array<std::shared_ptr<Figure>> arr{a_ptr,b_ptr,c_ptr};

    EXPECT_EQ(arr.size(), 3);
}

TEST(array_test06, sum_array){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(pii(10,10),pii(20,20),pii(30,30),pii(40,40));
    Pentagon<int> c(pii(100,100),pii(200,200),pii(300,300),pii(400,400),pii(500,500));

    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);
    std::shared_ptr<Rhombus<int>> b_ptr = std::make_shared<Rhombus<int>>(b);
    std::shared_ptr<Pentagon<int>> c_ptr = std::make_shared<Pentagon<int>>(c);

    Array<std::shared_ptr<Figure>> arr{a_ptr,b_ptr,c_ptr};

    EXPECT_TRUE(arr.sum() <= 28668 and arr.sum() >= 28667);
}

TEST(array_test07, empty_constructor){
    Trapezoid<int> a(pii(0,0),pii(0,10),pii(10,10),pii(10,0));
    Rhombus<int> b(pii(10,10),pii(20,20),pii(30,30),pii(40,40));
    Pentagon<int> c(pii(100,100),pii(200,200),pii(300,300),pii(400,400),pii(500,500));

    std::shared_ptr<Trapezoid<int>> a_ptr = std::make_shared<Trapezoid<int>>(a);
    std::shared_ptr<Rhombus<int>> b_ptr = std::make_shared<Rhombus<int>>(b);
    std::shared_ptr<Pentagon<int>> c_ptr = std::make_shared<Pentagon<int>>(c);

    Array<std::shared_ptr<Figure>> arr{a_ptr,b_ptr,c_ptr};

    EXPECT_EQ(arr.size(), 3);

    arr.delete_elem(0);

    EXPECT_EQ(arr.size(), 2);

    arr.delete_elem(0);

    EXPECT_EQ(arr.size(), 1);
}
