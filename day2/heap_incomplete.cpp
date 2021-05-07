/*
Essential Operations in Heaps
The following are the essential operations you might use when implementing a heap data structure:

heapify: rearranges the elements in the heap to maintain the heap property.
insert: adds an item to a heap while maintaining its heap property.
delete: removes an item in a heap.
extract: returns the value of an item and then deletes it from the heap.
isEmpty: boolean, returns true if boolean is empty and false if it has a node.
size: returns the size of the heap.
getMax(): returns the maximum value in a heap

*/

#include <iostream>
#include <vector>
#include <climits>

class Heap {
public:
       virtual void insert(int val) = 0; // insert into the heap
       virtual int  size() const { return m_size; } // return size of the heap
       virtual bool isEmpty() const { return m_size == 0; }; // return true if heap is empty
       virtual void heapify() = 0; // heapify the distorted heap property
       virtual void remove(int val) = 0; // remove key from the heap
protected:
    int m_size {0};
    std::vector<int> heap;
};

class MaxHeap : public Heap {
public: 
       int getMax() const { m_size ? heap[0] : INT_MIN ; } // return the max value in heap ie root.
       
       
       void insert(int val) {
       }
        
       void remove(int val) {
       }

       void heapify() {
       
       }  

       int extractMax(); // remove the max node from the heap and return it's value.
private:
};


class MinHeap : public Heap {
public:
        int getMin() const { m_size ? heap[0] : INT_MIN ; } // return the min value in heap ie root.
        
        
        void insert(int val) {
        }

        void remove(int val) {
        }

        void heapify() {

        }
    
        int extractMin(); // remove the min node ffrom the heap and return it's value
private:
};


int main() {
    Heap *heap = new MaxHeap();
    heap.insert(2);
    heap.insert(3);
    heap.insert(13);
    heap.insert(23);
    heap.insert(0);
    heap.insert(20);
    heap.insert(40);
    heap.insert(5);
    


    
    return 0;
}
