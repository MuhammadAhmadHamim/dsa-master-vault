#include<iostream>
#include<vector>
using namespace std;
class MaxHeap{
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

        // Using a shift-up loop so as to shift the positions until the element at index sits at its rightful place
        while(index != 0 && heap[index] > heap[parent(index)]){
            
            swap(heap[index], heap[parent(index)]); // Shifting if the parent is smaller than value at index

            index = parent(index); // Updating the index value to check
        }
    }

    void insert(int value){

        heap.push_back(value); // Pushing the value into heap

        int index = heap.size() - 1; // Getting the index of value we just pushed

        shiftUp(index); // Using shiftUp() to maintain heap order
    }

    int getMax(){
        return heap[0];
    }

    void shiftDown(int index){
        // Using a shift-down loop to correct the heap order
        while(true){
            int largest = index;

            if(leftChild(index) < heap.size() && heap[index] < heap[leftChild(index)]){ // Compare with leftChild(if exists)
                largest = leftChild(index);
            }

            if(rightChild(index) < heap.size() && heap[largest] < heap[rightChild(index)]){ // Compare with rightChild(if exists)
                largest = rightChild(index);
            }

            if(largest != index){ // If element at index is not the largest
                swap(heap[index], heap[largest]);

                index = largest; // Moving the index forward
            }
            else{ // If it is
                break;
            }
        }
    }

    int extractMax(){

        // Safety check in case of size = 0 
		if(heap.size() == 0){
			cout<<"Heap is empty!\n";
			return -1;
		}

        int maximum = heap[0]; // Saving the max value to be returned later

        heap[0] = heap[heap.size() - 1]; // Overwriting the max value 

        heap.pop_back(); // Removing the last value

        shiftDown(0); // Using shiftDown() to maintain heap order

        return maximum;
    }

    void buildHeap(vector<int> arr){
        // Fill the heap with the array elements
        for(int i = 0; i < arr.size(); i++){
            heap.push_back(arr[i]);
        }

        int index = parent(heap.size() - 1); // Getting the index of last non-leaf node

        // Shift the elements from index to root
        for(int i = index; i >= 0; i--){
            shiftDown(i);
        }
    }
};