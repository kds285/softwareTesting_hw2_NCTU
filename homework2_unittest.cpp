#include <limits.h>
#include "homework2.h"
#include "gtest/gtest.h"

// Test getTriangleType().
TEST(TriangleTest, EquivalenceClassWN) {
	EXPECT_EQ(TRIANGLE_EQUILATERAL,getTriangleType(5,5,5));
	EXPECT_EQ(TRIANGLE_ISOSCELES,getTriangleType(2,2,3));
	EXPECT_EQ(TRIANGLE_SCALENE,getTriangleType(3,4,5));
	EXPECT_EQ(TRIANGLE_NOT_A_TRIANGLE,getTriangleType(4,1,2));
}

TEST(TriangleTest, EquivalenceClassWR) {
	EXPECT_EQ(TRIANGLE_IMPOSSIBLE,getTriangleType(-1,5,5));
	EXPECT_EQ(TRIANGLE_IMPOSSIBLE,getTriangleType(5,-1,5));
	EXPECT_EQ(TRIANGLE_IMPOSSIBLE,getTriangleType(5,5,-1));
	EXPECT_EQ(TRIANGLE_IMPOSSIBLE,getTriangleType(201,5,5));
	EXPECT_EQ(TRIANGLE_IMPOSSIBLE,getTriangleType(5,201,5));
	EXPECT_EQ(TRIANGLE_IMPOSSIBLE,getTriangleType(5,5,201));
}

TEST(TriangleTest, EquivalenceClassSR) {
	EXPECT_EQ(TRIANGLE_IMPOSSIBLE,getTriangleType(-1,5,5));
	EXPECT_EQ(TRIANGLE_IMPOSSIBLE,getTriangleType(5,-1,5));
	EXPECT_EQ(TRIANGLE_IMPOSSIBLE,getTriangleType(5,5,-1));
	EXPECT_EQ(TRIANGLE_IMPOSSIBLE,getTriangleType(-1,-1,5));
	EXPECT_EQ(TRIANGLE_IMPOSSIBLE,getTriangleType(5,-1,-1));
	EXPECT_EQ(TRIANGLE_IMPOSSIBLE,getTriangleType(-1,-5,-1));
	EXPECT_EQ(TRIANGLE_IMPOSSIBLE,getTriangleType(-1,-1,-1));
}

TEST(TriangleTest, DecisionTableBased) {
	EXPECT_EQ(TRIANGLE_NOT_A_TRIANGLE,getTriangleType(3,1,2));
	EXPECT_EQ(TRIANGLE_NOT_A_TRIANGLE,getTriangleType(1,3,2));
	EXPECT_EQ(TRIANGLE_NOT_A_TRIANGLE,getTriangleType(1,2,3));
	EXPECT_EQ(TRIANGLE_SCALENE,getTriangleType(3,4,5));
	EXPECT_EQ(TRIANGLE_ISOSCELES,getTriangleType(3,3,4));
	EXPECT_EQ(TRIANGLE_ISOSCELES,getTriangleType(3,4,3));
	EXPECT_EQ(TRIANGLE_ISOSCELES,getTriangleType(4,3,3));
	EXPECT_EQ(TRIANGLE_EQUILATERAL,getTriangleType(1,1,1));
	EXPECT_EQ(TRIANGLE_IMPOSSIBLE,getTriangleType(0,201,-1));
}

// Test getNextDate().
TEST(NextDateTest, EquivalenceClassWN) {
	EXPECT_STREQ("6/16/1912",getNextDate(6,15,1912).c_str());
}

TEST(NextDateTest, EquivalenceClassWR) {
	EXPECT_STREQ("6/16/1912",getNextDate(6,15,1912).c_str());
	EXPECT_STREQ("Invalid input date",getNextDate(-1,15,1912).c_str());
	EXPECT_STREQ("Invalid input date",getNextDate(13,15,1912).c_str());
	EXPECT_STREQ("Invalid input date",getNextDate(6,-1,1912).c_str());
	EXPECT_STREQ("Invalid input date",getNextDate(6,32,1912).c_str());
	EXPECT_STREQ("Invalid input date",getNextDate(6,15,1811).c_str());
	EXPECT_STREQ("Invalid input date",getNextDate(6,15,5001).c_str());
}

TEST(NextDateTest, EquivalenceClassSN) {
	EXPECT_STREQ("6/16/1912",getNextDate(6,15,1912).c_str());
}

TEST(NextDateTest, EquivalenceClassSR) {
	EXPECT_STREQ("Invalid input date",getNextDate(-1,15,1912).c_str());
	EXPECT_STREQ("Invalid input date",getNextDate(6,-1,1912).c_str());
	EXPECT_STREQ("Invalid input date",getNextDate(6,15,1811).c_str());
	EXPECT_STREQ("Invalid input date",getNextDate(-1,-1,1912).c_str());
	EXPECT_STREQ("Invalid input date",getNextDate(6,-1,1811).c_str());
	EXPECT_STREQ("Invalid input date",getNextDate(-1,15,1811).c_str());
	EXPECT_STREQ("Invalid input date",getNextDate(-1,-1,1811).c_str());
}

TEST(NextDateTest, DecisionTableBased) {
	EXPECT_STREQ("4/16/2001",getNextDate(4,15,2001).c_str());
	EXPECT_STREQ("5/1/2001",getNextDate(4,30,2001).c_str());
	EXPECT_STREQ("Invalid input date",getNextDate(4,31,2001).c_str());
	EXPECT_STREQ("1/16/2001",getNextDate(1,15,2001).c_str());
	EXPECT_STREQ("2/1/2001",getNextDate(1,31,2001).c_str());
	EXPECT_STREQ("12/16/2001",getNextDate(12,15,2001).c_str());
	EXPECT_STREQ("1/1/2002",getNextDate(12,31,2001).c_str());
	EXPECT_STREQ("2/16/2001",getNextDate(2,15,2001).c_str());
	EXPECT_STREQ("2/29/2004",getNextDate(2,28,2004).c_str());
	EXPECT_STREQ("3/1/2001",getNextDate(2,28,2001).c_str());
	EXPECT_STREQ("3/1/2004",getNextDate(2,29,2004).c_str());
	EXPECT_STREQ("Invalid input date",getNextDate(2,29,2001).c_str());
	EXPECT_STREQ("Invalid input date",getNextDate(2,30,2001).c_str());
}