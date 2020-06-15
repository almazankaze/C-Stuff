#include "List.h"
#include <gtest/gtest.h>

// note this is done before every test that uses this
class EmptyList : public ::testing::Test {
    
    protected:
        virtual void SetUp() {

        }
        List<int> L;
        int val;
    
    public:
    EmptyList(){}
};

class OneItemList : public ::testing::Test {
    
    protected:
        virtual void SetUp() {
            L.insertInOrder(1);
        }
        List<int> L;
        int val;
    
    public:
    OneItemList(){}
};

class ManyItemsList : public ::testing::Test {
    
    protected:
        virtual void SetUp() {
            L.insertInOrder(1);
            L.insertInOrder(5);
        }
        List<int> L;
        int val;
    
    public:
    ManyItemsList(){}
};

// test isEmpty function
TEST_F(EmptyList, IsEmpty) {
    ASSERT_EQ(true, L.isEmpty());
}

// test push_front on an empty list
TEST_F(EmptyList, addToEmptyList) {
    
    L.push_front(4);
    L.pop_front(val);
    
    ASSERT_EQ(4, val);
}

// test push_front on a list with one item
TEST_F(OneItemList, addToListWithItem) {
    
    L.push_front(2);
    L.pop_front(val);
    
    ASSERT_EQ(2, val);
}

// test push_front on a list with more than one item
TEST_F(ManyItemsList, addToListWithItems) {
    
    L.push_front(8);
    L.pop_front(val);
    
    ASSERT_EQ(8, val);
}

// test length function
TEST_F(ManyItemsList, Length) {
    ASSERT_EQ(2, L.length());
}

// test adding item to the back
TEST_F(EmptyList, AddToEmptyList) {
    
    L.push_back(3);
    L.pop_back(val);
    
    ASSERT_EQ(3, val);
}

// test adding item to the back with one item in list
TEST_F(OneItemList, AddToBackListWithItem) {
    
    L.push_back(1);
    L.pop_back(val);
    
    ASSERT_EQ(1, val);
}

// test adding item to the back with more than one item in list
TEST_F(ManyItemsList, AddToListWithItems) {
   
    L.push_back(9);
    L.pop_back(val);
    
    ASSERT_EQ(9, val);
}

// test removing item from the back with no items in list
TEST_F(EmptyList, BackRemove) {    
    ASSERT_EQ(false, L.pop_back(val));
}

// search for an item that exists
TEST_F(ManyItemsList, Found) {
    ASSERT_EQ(true, L.searchList(1));
}

// search for an item that does not exist
TEST_F(ManyItemsList, NotFound) {
    ASSERT_EQ(false, L.searchList(7));
}

// insert an item in order when list was empty
TEST_F(EmptyList, InsertToEmptyList) {
    
    L.insertInOrder(1);
    L.pop_back(val);
    
    ASSERT_EQ(1, val);
}

// insert an item when item is the smallest
TEST_F(ManyItemsList, smallItem) {

    L.insertInOrder(0);
    L.pop_front(val);
    
    ASSERT_EQ(0, val);
}

// insert an item when item is the largest
TEST_F(ManyItemsList, LargeItem) {
    
    L.insertInOrder(7);
    L.pop_back(val);
    
    ASSERT_EQ(7, val);
}

// insert an item in the middle
TEST_F(ManyItemsList, MiddleItem) {
    
    L.insertInOrder(4);
    L.pop_front(val);
    L.pop_front(val);
    
    ASSERT_EQ(4, val);
}
