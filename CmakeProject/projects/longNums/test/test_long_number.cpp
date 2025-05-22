#include <gtest/gtest.h>
#include "long_number.hpp"

using naa::LongNumber;

TEST(ArraysEqual, AnyElementsCount) {
	LongNumber a = "-15";
	LongNumber b = "7";
	std::cout << "BORIS: " << std::endl << a % b << std::endl;
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}