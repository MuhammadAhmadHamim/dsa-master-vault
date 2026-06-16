#include<iostream>
using namespace std;

void linearSearch(int arr[], int n, int value){
	
	// Declaring the index variable
	int index = -1;
	
	// Loop to iterate over the whole array(Time complexity: O(n))
	for(int i = 0; i < n; i++){
		
		// check if, Found
		if(arr[i] == value){
			index = i;
			break;
		}
		else{
			continue;
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
	for(int i = 0; i < n; i++){
		cout<<"Enter the element:";
		cin>>arr[i];
	}
	
	// Display Menu
	while(true){
		
		// Declare the choice variable
		int choice;
		
		cout<<"----MENU----\n";
		cout<<"1.Search\n";
		cout<<"2.Exit\n";
		cin>>choice;
		
		// Exit condition
		if(choice == 2){
			break;
		}
		
		switch(choice){
			case 1:{
				
				int value;
				
				cout<<"Enter value to search:";
				cin>>value;
				
				linearSearch(arr, n, value);
				
				break;
			}
			default:
				cout<<"Invalid input!\n";
		}
	}
	
	return 0;
}
