#include<iostream>
using namespace std;

// Function to print array
void printArray(int arr[], int n){
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

// BUBBLE SORT - repeatedly swaps adjacent elements if in wrong order
void bubbleSort(int arr[], int n){
	
	// Outer loop: number of passes (n-1 passes needed for n elements)
	for(int i = 0; i < (n-1); i++){
		
		// Inner loop: compare adjacent elements
		// n - i - 1 because last i elements are already sorted
		for(int j = 0; j < n - i - 1; j++){
			
			// If current element > next element, swap them
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);  // Bubble larger element right
			}
		}
	}
}

int main(){
	int arr[] = {5, 3, 8, 4, 2};
	int n = 5;
	
	cout << "Before Bubble Sort: ";
	printArray(arr, n);
	
	bubbleSort(arr, n);
	
	cout << "After Bubble Sort: ";
	printArray(arr, n);
	
	return 0;
}
