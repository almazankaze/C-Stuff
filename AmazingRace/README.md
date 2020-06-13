# The Amazing Race

A program which determines who wins a race amongst race car drives. The winner is decided based on the height of each racer and their position in the race. These two values are used to calculate a racer's SIGHT. The larger value wins.

```
given some racers, where each integer is a racer's height:
5,1,2,4,1

SIGHT = P * X 
- X = number of riders a single rider can see in front of them or behind them. (note, a rider can only see past another rider if their height is smaller than theirs).
- P = the rider's position

in this case, rider in position 4 would win since their SIGHT = 4 * (1 person behind + 3 people in front),  which is 16
```

challenge can be found at [hackerearth.com](https://www.hackerearth.com/practice/)

## Method used
Looped through each racer where each racer checked how many people can be seen in front and behind at the same time.
