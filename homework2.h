#ifndef GTEST_HOMEWORK1_H_
#define GTEST_HOMEWORK1_H_

#include <string>
#include <sstream>

using namespace std;

// Triangl
enum TriangleType {
	TRIANGLE_NOT_A_TRIANGLE,
	TRIANGLE_SCALENE,
	TRIANGLE_ISOSCELES,
	TRIANGLE_EQUILATERAL,
	TRIANGLE_IMPOSSIBLE
};

// Returns triangle type
TriangleType getTriangleType(int a, int b, int c);

// Next date
string getNextDate(int year, int month, int day);

#endif  // GTEST_HOMEWORK1_H_
