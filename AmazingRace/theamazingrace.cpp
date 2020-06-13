#include "theamazingrace.h"

int oneRacer[1] = {2};
int manyEvenRacers[8] = {2,3,6,1,2,4,3,2};
int manyOddRacers[5] = {5,1,2,4,1};
int multipleWinners[5] = {2,2,1,1,0};

// get the winner of the race and return position of the racer
int getWinner(int numOfRacers, int height[]) {
    
    int winner = 0;             // keeps track of who is winning
    int frontIndex;             // index of racer in front of current racer
    int behindIndex;            // index of racer behind current racer
    int currentRacerPos;        // current racer's position
    int X = 0;                  // number of racers a racer can see
    int maxSight = 0;           // keep track of the max sight value
    int currSight = 0;          // sight of the current rider
    
    // only one racer, wins by default
    if(numOfRacers == 1) {
        return 1;
    }
    
    // go through array and find out who has the better sight
    for(int i = 0; i < numOfRacers; i++) {
        
        currentRacerPos = i + 1;
        frontIndex = i - 1;
        behindIndex = i + 1;
        
        // see if racer can see behind them or in front of them
        while(frontIndex >= 0 || behindIndex < numOfRacers) {
            
            // if haven't reached the front of the line
            if(frontIndex >= 0) {
                
                // if height of current rider is larger than height of the rider in front
                if(height[i] > height[frontIndex]) {
                    X += 1;
                }
                else {
                    
                    // cant see anymore riders
                    X += 1;
                    frontIndex = -1;
                }
            }
            
            // if haven't reached the back of the line
            if(behindIndex < numOfRacers) {
                
                // if height of current rider is larger than height of the rider in back
                if(height[i] > height[behindIndex]) {
                    X += 1;
                }
                else {
                    
                    // can't see anymore riders
                    X += 1;
                    behindIndex = numOfRacers;
                }
            }
            
            frontIndex--;;
            behindIndex++;
        }
        
        // calculate the sight of this rider
        currSight = X * currentRacerPos;
        X = 0;
        
        // check if sight is the largest
        if(currSight > maxSight) {
            maxSight = currSight;
            winner = currentRacerPos;
        }
    }
    
    // return winner
    return winner;
}

