#include<iostream>
using namespace std;

// Function to print array
void printArray(int arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

// SELECTION SORT - finds minimum element and places it at correct position
void selectionSort(int arr[], int n){
	
	// For each position in the array
	for(int i = 0; i < n-1; i++){
		
		// Assume current position has minimum
		int min_index = i;
		
		// Find actual minimum in remaining array
		for(int j = i+1; j < n; j++){
			
			// If found smaller element, update min_index
			if(arr[j] < arr[min_index]){
				min_index = j;
			}
		}
		
		// Swap minimum element with current position
		swap(arr[i], arr[min_index]);
	}
}

int main(){
	int arr[] = {5, 3, 8, 4, 2};
	int n = 5;
	
	cout << "Before Selection Sort: ";
	printArray(arr, n);
	
	selectionSort(arr, n);
	
	cout << "After Selection Sort: ";
	printArray(arr, n);
	
	return 0;
}
