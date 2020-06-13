#include <gtest/gtest.h>
#include "theamazingrace.h"

// tests case where there is only one racer
TEST(GetWinner, OneRacer) {
    EXPECT_EQ(1, getWinner(1, oneRacer));
}

// tests case where there are an odd number of racers
TEST(GetWinner, OddRacers) {
    EXPECT_EQ(4, getWinner(5, manyOddRacers));
}

// tests case where there are an even number of racers
TEST(GetWinner, EvenRacers) {
    EXPECT_EQ(6, getWinner(8, manyEvenRacers));
}

// tests case where there could be multiple winners, returns rider with lowest position
TEST(GetWinner, MultipleWinners) {
    EXPECT_EQ(2, getWinner(5, multipleWinners));
}

