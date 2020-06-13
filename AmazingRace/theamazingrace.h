
/* 
 * File:   AmazingRace.h
 * Author: john almazan
 *
 * Created on June 13, 2020, 9:32 AM
 */

#ifndef THEAMAZINGRACE_H
#define THEAMAZINGRACE_H

extern int oneRacer[1];
extern int manyEvenRacers[8];
extern int manyOddRacers[5];
extern int multipleWinners[5];

// get the winner of the race and return start position of the racer
int getWinner(int numOfRacers, int height[]);

#endif /* THEAMAZINGRACE_H */

