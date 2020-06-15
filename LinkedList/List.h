
/**
 * class List<T>
 * 
 * General description:  class for storing and manipulating sequences of items 
 *    where item type is specified via template.
 * 
 * Underlying organization:  the implementation uses a singly-linked list data structure
 *    with pointers to both the front (first node) and back (last node) of the list.
 * 
 *    A private struct Node is used to represent individual nodes in a list.
 */


#ifndef LIST_H
#define LIST_H

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
class List {
    
    private:
        
        struct Node {
            
            T data;
            Node *next;
            Node *prev;
            
            Node(const T &d = T{}, Node *n = nullptr, Node *p = nullptr)
                : data{d}, next{n}, prev(p) {}
        };
        
        Node *front;
        Node *back;
        int size;
        
    public:
        
        // constructor for list
        List() {
            front = nullptr;
            back = nullptr;
            size = 0;
        }
        
        // copy constructor
        List(const List &source) {
            
            size = source.size;
            
            if(source.isEmpty()) front = back = nullptr;
            
            else {
                
                front = new Node(source.front->data);
                
                Node *newNode = front;
                Node *currNode = source.front->next;
                
                while(currNode != nullptr) {
                    
                    newNode->next = new Node(currNode->data, nullptr, newNode);
                    
                    newNode = newNode->next;
                    currNode = currNode->next;
                }
                
                back = newNode;
            }
        }
            
        // destructor
        ~List() {
            clear();
        }
        
        // clears the list but still exists
        void clear() {
            
            Node *currptr = front;
            Node *pnext;
            
            while(currptr != nullptr) {
                pnext = currptr->next;
                delete currptr;
                currptr = pnext;
            }
            front = back = nullptr;
        }
        
        // gets the size of the list
        int length() const {
            return size;
        }
        
        // checks if list is empty
        bool isEmpty() const {
            return front == nullptr;
        }
        
        // add to the front of the list
        void push_front(const T &val) {
            
            Node * newNode = new Node(val, front, nullptr);
            
            if(isEmpty()) front = back = newNode;
            
            // if it has one item
            else if(front == back) {
                back->prev = newNode;
                front = newNode;
            }
            else {
                front->prev = newNode;
                front = newNode;
            }
            
            size++;
        }
        
        // remove node from front of the list
        bool pop_front(T &val) {
            
            Node *tmp;
            
            // list was empty
            if(isEmpty()) return false;
            
            // value gets passed back to user
            val = front->data;
            
            tmp = front;
            front = front->next;
            delete tmp;
            
            if(isEmpty()) back = nullptr;
            
            size--;
            
            // success
            return true;
        }
        
        
        // add to the end of the list
        void push_back(const T &val) {
            
            Node *newNode = new Node(val, nullptr, back);
            
            if(isEmpty()) {
                front = back = newNode;
            }
            else if(front == back) {
                front->next = newNode;
                back = newNode;
            }
            else {
                back->next = newNode;
                back = newNode;
            }
            
            size++;
        }
        
        
        // remove item from back of list
        bool pop_back(T &val) {
            
            Node *currptr = front;
            Node *prevptr = back;

            //if empty return false
            if (isEmpty()) return false;

            val = back->data;
            
            // if only one item in list
            if(currptr->next == nullptr) {
                front = nullptr;
                back = nullptr;
                delete currptr;
            }
            else {
                currptr = back;
                prevptr = back->prev->next = nullptr;
                back = prevptr;
                delete currptr;
            }
            
            size--;
            
            return true;
        }
        
        
        // print the list
        void printList() const {
            
            Node *currptr = front;

            std::cout << "[ ";
            while (currptr != nullptr){
              std::cout << currptr->data << " ";
              currptr = currptr->next;
            }
            std::cout << "]\n";
        }
        
        // print list in reverse
        void printReverse() const {
            
            Node *currptr = back;
            
            std::cout << "[ ";
            while(currptr != nullptr) {
                std::cout << currptr->data << " ";
                currptr = currptr->prev;
            }
            std::cout << "]\n";
        }
        
        // search for an item by value
        bool searchList(const T &val) {
            
            Node *currptr = front;
            
            while(currptr != nullptr) {
                
                if(currptr->data == val) return true;
                
                currptr = currptr->next;
            }
            
            return false;
        }
        
        // insert item in order (list is assumed to be in order and only integers)
        void insertInOrder(const T &val) {
            
            if(isEmpty()) push_front(val);
            
            else {
                
                // if val is less than or equal to first node
                if(val <= front->data) push_front(val);
                
                // if val is the largest
                else if(val >= back->data) push_back(val);
                
                else {
                    
                    Node *newNode = new Node(val);
                    Node *currptr = front->next;
                    
                    while(currptr != nullptr) {
                        
                        if(val <= currptr->data) {
                            
                            newNode->next = currptr;
                            newNode->prev = currptr->prev;
                            currptr->prev->next = newNode;
                            currptr->prev = newNode;
                            size++;
                            break;
                        }
                        currptr = currptr->next;
                    }
                }
            }
        }
        
        // delete an item from list (deletes first encountered value)
        bool deleteNode(const T &val) {
            
            Node *prevNode = front;
            Node *currNode = front->next;
            T dummy;
            
            if(isEmpty()) return false;
            
            if(val == front->data) {
                pop_front(dummy);
                return true;
            }
            else {
                
                while(currNode != nullptr) {
                    
                    if(val == currNode->data) {
                        
                        if(currNode == back) {
                            pop_back(dummy);
                        }
                        else {
                            currNode->next->prev = prevNode;
                            prevNode->next = currNode->next;
                            delete currNode;
                            size--;
                        }
                        
                        return true;
                    }
                    
                    currNode = currNode->next;
                    prevNode = prevNode->next;
                }
            }
            
            return false;
        }
        
        /*
        // sort in ascending order
        void sortList() {
            
            Node *currNode = front;
            std::vector<int> v;
            
            while(currNode != nullptr) {
                v.push_back(currNode->data);
                currNode = currNode->next;
            }
            
            std::sort(v.begin(), v.end());
            
            currNode = front;
            
            for(auto val : v) {
                currNode->data = val;
                currNode = currNode->next;
            }
        }
        */
};

#endif /* LIST_H */

