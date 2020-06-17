
#ifndef HASH_H
#define HASH_H

#include <forward_list>

class Hash {
    
private:
    static const int ARRAY_SIZE = 31;
    int hashInteger(int key) {
        return key%ARRAY_SIZE;
    }
    
public:
    std::forward_list<int> getUnion(const std::forward_list<int> &list1, const std::forward_list<int> &list2);
    std::forward_list<int> getIntersection(const std::forward_list<int> &list1, const std::forward_list<int> &list2);
    void getPairsThatSum(int array[], int size, int sum);
};


#endif /* HASH_H */

