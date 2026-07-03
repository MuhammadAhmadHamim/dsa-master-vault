#include<iostream>
using namespace std;

// Function to print array
void printArray(int arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

// PARTITION function - divides array into two parts using pivot
// All elements < pivot go left, all elements > pivot go right
int partition(int arr[], int low, int high){
	
	// Choose last element as pivot
	int pivot = arr[high];
	
	// i tracks boundary of smaller elements
	// Starts at low-1 (before first element)
	int i = low - 1;
	
	// Scan through array from low to high-1
	for(int j = low; j < high; j++){
		
		// If current element is smaller than pivot
		if(arr[j] < pivot){
			
			// Move boundary forward
			i++;
			
			// Swap current element to left side
			swap(arr[i], arr[j]);
		}
	}
	
	// Place pivot in correct position
	// Swap pivot with element at i+1
	swap(arr[i + 1], arr[high]);
	
	// Return pivot's final position
	return i + 1;
}

// QUICK SORT - recursively sorts using partition
void quickSort(int arr[], int low, int high){
	
	// Base case: if low >= high, array is sorted (1 or 0 elements)
	if(low < high){
		
		// Partition array and get pivot position
		int pivot_index = partition(arr, low, high);
		
		// Recursively sort left side (elements < pivot)
		quickSort(arr, low, pivot_index - 1);
		
		// Recursively sort right side (elements > pivot)
		quickSort(arr, pivot_index + 1, high);
	}
}

int main(){
	int arr[] = {5, 3, 8, 4, 2};
	int n = 5;
	
	cout << "Before Quick Sort: ";
	printArray(arr, n);
	
	// Call quickSort with low=0, high=n-1
	quickSort(arr, 0, n-1);
	
	cout << "After Quick Sort: ";
	printArray(arr, n);
	
	return 0;
}
