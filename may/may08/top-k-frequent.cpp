Problem Link: https://leetcode.com/problems/top-k-frequent-elements/submissions/


class Solution {
public:
    
    void minHeapify(std::vector<std::pair<int, int>> &heap, int i, int n) {
        int j = 0;
        while (2*i <= n) {
            j = 2*i;
            if (j < n && heap[j-1] > heap[j])
                ++j;
            if (heap[i-1].second > heap[j-1].second) {
                std::swap(heap[i-1].first, heap[j-1].first);
                std::swap(heap[i-1].second, heap[j-1].second);
            }
            else 
                break;
            i = j;
        }
    }
    
    void createMinHeap(std::vector<std::pair<int, int>> &heap) {
        int n = heap.size();
        for (int i = n/2; i > 0; --i) {
            minHeapify(heap, i, n);
        }
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) return {};
        std::map<int, int> freqMap;
        // step 1: calculate frequency of all unqiue data in nums
        // O(n) work
        for (int i = 0; i < n; ++i) {
            ++freqMap[nums[i]];
        }
        
        // take a pair of vector to create heap
        // O(k) work
        std::vector<std::pair<int, int>> heap(k, {0,0});
        
        for (int i = 0; i < k; ++i) {
            auto it = freqMap.begin();
            heap[i] = {it->first, it->second};
            freqMap.erase(it);
        }
         
        // create min heap of size k from vector <heap>
        // O(k) work
        createMinHeap(heap);
        for (auto pair: heap) {
            std::cout << pair.first << " " << pair.second << std::endl;
        }
        // check for other pair in map if they can be in top k frequent elements
        // O((n-k)logk) work
        for (auto it: freqMap) {
            
            if (heap[0].second < it.second) {
                heap[0] = std::make_pair(it.first, it.second);
                minHeapify(heap, 1, k);
            }
            // pending code failing
            /*
            [5,1,-1,-8,-7,8,-5,0,1,10,8,0,-4,3,-1,-1,4,-5,4,-3,0,2,2,2,4,-2,-4,8,-7,-7,2,-8,0,-8,10,8,-8,-2,-9,4,-7,6,6,-1,4,2,8,-3,5,-9,-3,6,-8,-5,5,10,2,-5,-1,-5,1,-3,7,0,8,-2,-3,-1,-5,4,7,-9,0,2,10,4,4,-4,-1,-1,6,-8,-9,-1,9,-9,3,5,1,6,-1,-2,4,2,4,-6,4,4,5,-5]
7
            */
        }
    
        
        std::vector<int> res;
        // heap will ultimately have top k frequents elements
        // O(k) work
        for (auto pair: heap) {
            res.push_back(pair.first);
        }
        return res;
    }
};
