#include<iostream>
#include<vector>
using namespace std;
class MinHeap{
public:
    vector<int> heap; // Using array as reference
    
    int parent(int i){
		return (i - 1) / 2;	
	}
	
	// Methods to return the indices of both children
    int leftChild(int i){ 
		return (i * 2) + 1;
	}
    
	int rightChild(int i){
		return (i * 2) + 2;
	}
	
	void shiftUp(int index){
		// A shift-up loop to maintain heap property
		while(index != 0 && heap[index] < heap[parent(index)]){
			
			swap(heap[index], heap[parent(index)]); // Swap as long as it's less than parent
			
			index = parent(index); // Update the index to it's parent value
		}
	}

	void insert(int value){
		
		heap.push_back(value); // Pushing the value into heap
		
		int index = heap.size() - 1; // Saving the pos of our insertion
		
		shiftUp(index);
	}
	
	int getMin(){
		return heap[0];
	}
	
	void shiftDown(int index){
		
		// A shift-down loop that'd iterate until leaf node
		while(true){
			int smallest = index; // Save the smallest index
			
			if(leftChild(index) < heap.size() && heap[index] > heap[leftChild(index)]){ // Compare with left(if exists)
				smallest = leftChild(index);
			}
			
			if(rightChild(index) < heap.size() && heap[smallest] > heap[rightChild(index)]){ // Compare with right(if exists)
				smallest = rightChild(index);
			}
			
			if(smallest != index){ // If they are different
				swap(heap[index], heap[smallest]);
				
				index = smallest;
			}
			else{ // No need for further shifting  
				break;
			}
		}
	}
	
	int extractMin(){
		
		// Safety check in case of size = 0 
		if(heap.size() == 0){
			cout<<"Heap is empty!\n";
			return -1;
		}
		
		int minimum = heap[0]; // Saving the min
		
		heap[0] = heap[heap.size() - 1]; // Moving the last element at root position
		
		heap.pop_back(); // Removing the last slot
		
		shiftDown(0); // Shifting down from root
		
		return minimum;
	}
	
	void buildHeap(vector<int> arr){
		
		// Copying the elements from given arr in heap
		for(int i = 0; i < arr.size(); i++){
			heap.push_back(arr[i]);
		}
		
		int index = parent(heap.size() - 1); // Getting the index of last non-leaf node
		
		// Shifting down from index until root
		for(int i = index; i >= 0; i--){
			shiftDown(i);
		}
	}
};
