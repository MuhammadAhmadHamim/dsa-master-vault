#include<iostream>
using namespace std;

void binarySearch(int arr[], int n, int value){
    
    // Check if array is sorted (CRITICAL!)
    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]){
            cout<<"Array must be sorted for binary search!\n";
            return;
        }
    }
    
    int left = 0;
    int right = n - 1;
    int index = -1;
    
    // Keep dividing search space in half (Time complexity: O(log n))
    while(left <= right){
        int mid = left + (right - left) / 2;  // Mid of current search space
        
        if(arr[mid] == value){
            index = mid;
            break;
        }
        else if(arr[mid] > value){
            right = mid - 1;  // Eliminate right half
        }
        else{
            left = mid + 1;   // Eliminate left half
        }
    }
    
    // Found condition 
    if(index != -1){
        cout<<"Value found at index: "<<index<<endl;
    }
    else{
        cout<<"Value not found!\n";
    }
    
    cout<<endl;
}

int main(){
    
    // Declare an array and its size
    int n = 10;
    int arr[n];
    
    // Ask user to fill it
    cout<<"Enter 10 SORTED elements (binary search requires sorted array!):\n";
    for(int i = 0; i < n; i++){
        cout<<"Enter the element:";
        cin>>arr[i];
    }
    
    // Display Menu
    while(true){
        
        int choice;
        
        cout<<"----MENU----\n";
        cout<<"1.Search\n";
        cout<<"2.Exit\n";
        cin>>choice;
        
        if(choice == 2){
            break;
        }
        
        switch(choice){
            case 1:{
                int value;
                cout<<"Enter value to search:";
                cin>>value;
                
                binarySearch(arr, n, value);
                break;
            }
            default:
                cout<<"Invalid input!\n";
        }
    }
    
    return 0;
}
