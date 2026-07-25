/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> heap; // Backing array for the min-heap (root = current smallest)
    
    // --- Index arithmetic: derive tree relationships without pointers ---
    int parent(int index){
        return (index - 1) / 2;
    }
    
    int leftChild(int index){
        return (2 * index) + 1;
    }
    
    int rightChild(int index){
        return (2 * index) + 2;
    }
    
    // Restore heap property downward — used after root is disturbed
    void shiftDown(int index){
        int smallest = index; // declared once; stays in sync since index gets reassigned to smallest below
        while(true){
            // Compare against left child, if it exists within bounds
            if(leftChild(index) < heap.size() && heap[index] > heap[leftChild(index)]){
                smallest = leftChild(index);
            }
    
            // Compare against right child, using the RUNNING smallest (not stale heap[index])
            if(rightChild(index) < heap.size() && heap[smallest] > heap[rightChild(index)]){
                smallest = rightChild(index);
            }
    
            if(smallest != index){
                swap(heap[index], heap[smallest]); // demote the out-of-place node
                index = smallest;                   // descend and keep checking
            }
            else{
                break; // heap property restored at this position
            }
        }
    }
    
    // Restore heap property upward — used after inserting a new leaf
    void shiftUp(int index){
        // Guard (index != 0) checked FIRST so parent(0) is never evaluated unsafely
        while(index != 0 && heap[index] < heap[parent(index)]){
            swap(heap[index], heap[parent(index)]); // bubble toward root while smaller than parent
            index = parent(index);
        }
    }
    
    // Remove and discard the current minimum, refilling the root from the tail
    void extractMin(){
        // Safety check in case of size = 0
        if(heap.size() == 0){
            cout << "Heap is empty!\n";
            return;
        }
    
        heap[0] = heap[heap.size() - 1]; // move last element into the root slot
            
        heap.pop_back(); // Removing the last element                 
    
        shiftDown(0); // re-settle the moved element into its correct position
    }
    
    // Maintain a min-heap of size k holding the k largest elements seen so far
    void heapify(vector<int>& nums, int k){
    
        for(int i = 0; i < nums.size(); i++){
            if(heap.size() < k){
                // Still filling up to k — no comparison needed yet
                heap.push_back(nums[i]);
                shiftUp(heap.size() - 1); 
            }
            else if(nums[i] > heap[0]){
                // New element beats the current weakest of the top-k — swap it in
                extractMin();                 // evict the current minimum (the weakest top-k member)
                heap.push_back(nums[i]);      // insert the new, stronger element at the tail
                shiftUp(heap.size() - 1);     // settle it into its correct position
            }
            // else: new element is weaker than the current weakest top-k member — discard, do nothing
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        heapify(nums, k);
        return heap[0]; // root of a min-heap of size k = the kth largest overall
    }
};
/*
20
ms
Beats
89.51%

72.58
MB
Beats
31.94%
*/