#include "pch.h"
#include "../Maths/Vector3.h"

TEST(Vector3_Constructor, AssignsAllComponents) {
    Vector3 v(3, 4, 5);
    EXPECT_EQ(v.x, 3);
    EXPECT_EQ(v.y, 4);
    EXPECT_EQ(v.z, 5);
}

TEST(Vector3_EqualityComparison, Returns_True_For_Equal_Vectors) {
    EXPECT_TRUE(Vector3(3, 4, 5) == Vector3(3, 4, 5));
}

// test and implement inequality comparison

TEST(Vector3_EqualityComparison, Returns_False_For_Inequal_Vectors) {
    EXPECT_FALSE(Vector3(3, 4, 5) == Vector3(2, 4, 5));
    EXPECT_FALSE(Vector3(3, 4, 5) == Vector3(3, 2, 5));
    EXPECT_FALSE(Vector3(3, 4, 5) == Vector3(3, 4, 2));
    EXPECT_FALSE(Vector3(3, 4, 5) == Vector3(2, 2, 2));
}

// test and implement negate operator
TEST(Vector3_Negate, InvertsPositiveValues) {
  EXPECT_EQ(-Vector3(3,4,5), Vector3(-3,-4,-5));
  EXPECT_TRUE(true);
}

TEST(Vector3_AdditionComparison, Returns_Sum_Of_Floats) {
    EXPECT_EQ(Vector3(3, 4, 5) + Vector3(1, 2, 3), Vector3(4, 6, 8));
}

TEST(Vector3_MultiplicationComparison, Returns_Multiplication_Of_Floats) {
    EXPECT_EQ(Vector3(5, 4, 3) * Vector3(2, 1, 3), Vector3(10, 4, 9));
}

TEST(Vector3_ScalarMultiplication, ScalesAllValues) {
    EXPECT_EQ(Vector3(3, 4, 5)*2, Vector3(6, 8, 10));
}

TEST(Vector3_Division, DividesAllValues) {
    EXPECT_EQ(Vector3(4, 5, 6) / 2, Vector3(2, 2.5, 3));
}

TEST(Vector3_Magnitude, MagnitudesAllValues) {
    EXPECT_FLOAT_EQ(Vector3(3, 4, 0).Magnitude(), 5);
    EXPECT_FLOAT_EQ(Vector3(3, 0, 0).Magnitude(), 3);
    EXPECT_FLOAT_EQ(Vector3(5, -3, 2).Magnitude(), sqrt(38));
}

TEST(Vector3_DotProduct, DotsTheProductOfAllValues) {
    ASSERT_EQ(Vector3::DotProduct(Vector3(1, 2, 3), Vector3(4, 5, 6)), 32);
}

TEST(Vector3_SquareMagnitude, SquaresTheMagnitudesOfAllValuesIPreferCirclesThough) {
    EXPECT_FLOAT_EQ(Vector3(3, 4, 0).SquareMagnitude(), 25);
}

TEST(Vector3_Distance, DistancesTheTwoVectors) {
    ASSERT_EQ(Vector3::Distance(Vector3(1, 2, 3), Vector3(4, 5, 6)), sqrt(27));
}