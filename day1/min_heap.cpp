// Implement the min and max heap of Binary Heap
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
What is Binary Heap ?
A Binary Heap is a Binary Tree with following properties.
1. It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.

2. A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Examples of Min Heap:

            10                      10
         /      \               /       \
       20        100          15         30
      /                      /  \        /  \
    30                     40    50    100   40

Max Heap is opposite of Min Heap

Applications of Heaps:
-----------------------
1) Heap Sort: Heap Sort uses Binary Heap to sort an array in O(nLogn) time.

2) Priority Queue: Priority queues can be efficiently implemented using Binary Heap because it supports insert(), delete() and extractmax(), decreaseKey() operations in O(logn) time. Binomoial Heap and Fibonacci Heap are variations of Binary Heap. These variations perform union also efficiently.

3) Graph Algorithms: The priority queues are especially used in Graph Algorithms like Dijkstra’s Shortest Path and Prim’s Minimum Spanning Tree.

4) Many problems can be efficiently solved using Heaps. See following for example.
    a) K’th Largest Element in an array.
    b) Sort an almost sorted array/
    c) Merge K Sorted Arrays.


Source -> https://www.geeksforgeeks.org/binary-heap/

Binary Heap supports the following function:
-------------------------------------------
1. Getting minimum/maximum : O(1) present at root.
2. Search in Heap: O(n) need to look in full tree
3. Insert in Heap: O(Logn) 
    a. insert at last of the array and call heapify on that node so it will reach at correct position if heap order is distorted. This will take O(logn) as visiting the half of the tree in worst case.
4. Delete in Heap: O(Logn)
    b. Delete the key and then heapify to correct the distorted order
5. Removing the min/max from minheap/maxheap - O(Logn) basically need to call heapify on root as we removing it.


----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Dummy Helper function
// with index - 1
/*
void minHeapify(std::vector<int> &v, int i, int n) {
    int j = 0; // index for children of current index i
    while (2*i <= n) {
        j = 2*i;
        if (j < n && v[j] > v[j+1]) { //checking if left child is greater than right child if that is the case we can increase j to point to right child the smaller one and then compare it with root node 
            ++j;
        }
        if (v[i] > v[j]) { // when right child is smaller than root node we need to swap the nodes.
            std::swap(v[i], v[j]);
        } else {
            break;
        }
        i = j;
    }
}
*/
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// The above helper function has a problem because index start with 0. Fixing it in below function
// As array starts with index 0, just replace j with j-1 and i with i-1 everywhere in above helper function
// when accessing vector indexes.
void minHeapify(std::vector<int> &v, int i, int n) {
    int j = 0; // index for children of current index i
    while (2*i <= n) { // left child must be less than n(number of elements)
        j = 2*i;
        if (j < n && v[j-1] > v[j]) { //checking if left child is greater than right child if that is the case we can increase j to point to right child the smaller one and then compare it with root node
            ++j;
        }
        if (v[i-1] > v[j-1]) { // when right child is smaller than root node we need to swap the nodes.
            std::swap(v[i-1], v[j-1]);
        } else {
            break;
        }
        i = j; // same processing for child node of i index
    }
}


// create the max-heap out of the passed array
// 1. Create the tree from the array with index 1.
// e.g [1,2,4,-5,16,0,5]
// Tree would look like:
//                           1(index - 1)
//                         /    \
//                        2(2)  4(3)
//                       / \     /   \
//                   -5(4) 16(5) 0(6) 5(7)
//
// Now start with index = N/2 and call heapify at each index until root node.

// TC: O(N)
// SC: O(1)
void minHeap(std::vector<int> &v) {
    int n = v.size();
    for (int i = n/2; i > 0;--i) {
        minHeapify(v, i, n);
    }
}


void traverse(const std::vector<int> &v) {
    for (const auto i: v) {
        std::cout << i << ' ';
    }

    std::cout << "\n";
}

int main() {
    std::vector<int> v1 = {3,4,1,45,32,6,9,22};
    minHeap(v1);
    traverse(v1);

}
