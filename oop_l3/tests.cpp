#include <gtest/gtest.h>
#include <iostream>

#include "Array.h"
#include "Trapezoid.h"
#include "Pentagon.h"
#include "Rhombus.h"

TEST(pentagon, default_constructor)
{
	Pentagon pent;
	std::pair<double, double> pair;
	pair.first = 0;
	pair.second = 0;
	ASSERT_EQ(pent.get_area(), 0);
	ASSERT_EQ(pent.get_center(), pair);
	ASSERT_EQ(pent.get_points().size(), 5);
}

TEST(pentagon, area_with_zeros)
{
    std::vector<std::pair<double, double>> v(5);
    v[0].first = 0; v[0].second = 0;
	v[1].first = 0; v[1].second = 0;
	v[2].first = 0; v[2].second = 0;
	v[3].first = 0; v[3].second = 0;
	v[4].first = 0; v[4].second = 0;
    std::pair<double, double> p;
    p.first = 0;
    p.second = 0;
    Pentagon pent(v);
    ASSERT_EQ(pent.get_area(), 0);
    ASSERT_EQ(pent.get_center(), p);
}

TEST(pentagon, area_ok)
{
	std::vector<std::pair<double, double>> v(5);
	v[0].first = 2; v[0].second = 1;
	v[1].first = 1; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 4;
	v[4].first = 3; v[4].second = 3;

	Pentagon pent(v);
	ASSERT_EQ(3<pent.get_area()<4, 1);
	ASSERT_EQ(pent.get_points(), v);
}

TEST(rhombus, default_constructor)
{
Rhombus rhomb;
std::pair<double, double> pair;
pair.first = 0;
pair.second = 0;
ASSERT_EQ(rhomb.get_area(), 0);
ASSERT_EQ(rhomb.get_center(), pair);
ASSERT_EQ(rhomb.get_points().size(), 4);
}

TEST(rhombus, area_with_zeros)
{
std::vector<std::pair<double, double>> v(4);
v[0].first = 0; v[0].second = 0;
v[1].first = 0; v[1].second = 0;
v[2].first = 0; v[2].second = 0;
v[3].first = 0; v[3].second = 0;
std::pair<double, double> p;
p.first = 0;
p.second = 0;
Rhombus rhomb(v);
ASSERT_EQ(rhomb.get_area(), 0);
ASSERT_EQ(rhomb.get_center(), p);
}

TEST(rhombus, area_ok)
{
std::vector<std::pair<double, double>> v(4);
v[0].first = 3; v[0].second = 1;
v[1].first = 1; v[1].second = 4;
v[2].first = 3; v[2].second = 7;
v[3].first = 5; v[3].second = 4;

std::pair<double, double> p;
p.first = 3;
p.second = 4;
Rhombus rhomb(v);
ASSERT_EQ(rhomb.get_area(), 12);
ASSERT_EQ(rhomb.get_center(), p);
}

TEST(trapezoid, default_constructor)
{
Trapezoid trap;
std::pair<double, double> pair;
pair.first = 0;
pair.second = 0;
ASSERT_EQ(trap.get_area(), 0);
ASSERT_EQ(trap.get_center(), pair);
ASSERT_EQ(trap.get_points().size(), 4);
}


TEST(trapezoid, area_with_zeros)
{
std::vector<std::pair<double, double>> v(4);
v[0].first = 0; v[0].second = 0;
v[1].first = 0; v[1].second = 0;
v[2].first = 0; v[2].second = 0;
v[3].first = 0; v[3].second = 0;
std::pair<double, double> p;
p.first = 0;
p.second = 0;
Trapezoid trap(v);
ASSERT_EQ(trap.get_area(), 0);
ASSERT_EQ(trap.get_center(), p);
}

TEST(trapezoid, area_ok)
{
std::vector<std::pair<double, double>> v(4);
v[0].first = 1; v[0].second = 1;
v[1].first = 2; v[1].second = 4;
v[2].first = 5; v[2].second = 4;
v[3].first = 6; v[3].second = 1;
std::pair<double, double> p;
p.first = 3.5;
p.second = 2.5;
Trapezoid trap(v);
ASSERT_EQ(trap.get_area(), 12);
ASSERT_EQ(trap.get_center(), p);
}

TEST(array, default_constructor) {
	Array arr;

	for(int i = 0; i < 50; i++) 
		ASSERT_EQ(arr[i], nullptr);
}

TEST(array, total_area) {
	std::vector<std::pair<double, double>> v(4);
	v[0].first = 1; v[0].second = 1;
	v[1].first = 0; v[1].second = 2;
	v[2].first = 1; v[2].second = 3;
	v[3].first = 2; v[3].second = 2;

	std::vector<std::pair<double, double>> v1(4);
	v1[0].first = 0; v1[0].second = 0;
	v1[1].first = 0; v1[1].second = 0;
	v1[2].first = 0; v1[2].second = 0;
	v1[3].first = 0; v1[3].second = 0;

	Array arr;
	Rhombus rh(v);
	Rhombus rh1(v1);
	arr.add(0, &rh);
	arr.add(1, &rh1);

	ASSERT_EQ(arr.total_area(), 2);
}




