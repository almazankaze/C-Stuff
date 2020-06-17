
#include <cstdlib>
#include <iostream>
#include "Hash.h"

using namespace std;

int main(int argc, char** argv) {
    
    Hash hash;
    
    // get the union
    forward_list<int> list1 = {10,15,4,20};
    forward_list<int> list2 = {8,4,2,10};
    
    forward_list<int> newList = hash.getUnion(list1, list2);
    
    for(auto num:newList) {
        cout << num << " ";
    }
    cout << endl;
    
    // get the intersection
    forward_list<int> otherList = hash.getIntersection(list1, list2);
    
    for(auto num:otherList) {
        cout << num << " ";
    }
    cout << endl;
    
    // find pairs of numbers that add up to the sum of a number
    int sum = -2;
    
    int sumArray[] = {0,-1,2,-3,1};
    hash.getPairsThatSum(sumArray, 5, sum);
    
    
    return 0;
}

