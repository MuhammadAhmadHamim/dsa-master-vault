#include<iostream>
using namespace std;

// Function to print array
void printArray(int arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

// INSERTION SORT - builds sorted array by inserting elements one by one
void insertionSort(int arr[], int n){
	
	// Start from second element (first element is already "sorted")
	for(int i = 1; i < n; i++){
		
		// Element to be inserted into sorted portion
		int key = arr[i];
		
		// j points to last element of sorted portion
		int j = i - 1;
		
		// Shift elements greater than key to the right
		// while j >= 0: we haven't reached start of array
		// arr[j] > key: current element is greater than key
		while(j >= 0 && arr[j] > key){
			
			// Shift element one position right
			arr[j + 1] = arr[j];
			
			// Move j to previous element
			j = j - 1;
		}
		
		// Insert key in correct position
		arr[j + 1] = key;
	}
}

int main(){
	int arr[] = {5, 3, 8, 4, 2};
	int n = 5;
	
	cout << "Before Insertion Sort: ";
	printArray(arr, n);
	
	insertionSort(arr, n);
	
	cout << "After Insertion Sort: ";
	printArray(arr, n);
	
	return 0;
}
