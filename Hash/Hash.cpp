#include "Hash.h"
#include <unordered_map>
#include <array>
#include <iostream>
#include <forward_list>

std::forward_list<int> Hash::getUnion(const std::forward_list<int> &l1, const std::forward_list<int> &l2) {
    
    if(l1.empty()) return l2;
    
    if(l2.empty()) return l1;
    
    std::unordered_map<int,int> buckets;
    std::forward_list<int> list;
    
    for(auto num:l1) {
        buckets[num] = num;
    }
    
    for(auto num:l2) {
        if(buckets.find(num) == buckets.end())
            buckets[num] = num;
    }
    
    for(auto num : buckets) {
        list.push_front(num.second);
    }
    
    return list;
} 

std::forward_list<int> Hash::getIntersection(const std::forward_list<int> &l1, const std::forward_list<int> &l2) {
    
    std::unordered_map<int,int> buckets;
    std::forward_list<int> list;
    
    if(l1.empty() || l2.empty()) return list;
    
    for(auto num:l1) {
        buckets[num] = num;
    }
    
    for(auto num:l2) {
        if(!(buckets.find(num) == buckets.end()))
            list.push_front(num);
    }
    
    return list;
}

void Hash::getPairsThatSum(int array[], int size, int sum) {
    
    std::unordered_map<int, int> buckets;
    
    for(int i = 0; i < size; i++) {
        
        if(buckets.find(sum - array[i]) == buckets.end())
            buckets[array[i]] = array[i];
        else
            std::cout << array[i] << ":" << sum - array[i];
    }
}