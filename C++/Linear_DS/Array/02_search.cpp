#include<iostream>
#include<conio.h>
using namespace std;
void indexSearch(int arr[] , int index){ //function for index-based search
	cout<<"Searched value:"<<arr[index]<<endl;
}
void valueSearch(int arr[] , int n , int value){ //function for value-based search
	bool found=false;
	int i;
	for(i=0;i<n;i++){
		if(arr[i]==value){  //condition if found
		    found=true;
		    break;
		}
		else{
			continue;
		}
	}
	if(found){  //printing the result
		cout<<"Found!"<<endl;
		cout<<"The given value is on index "<<i<<" of the Array"<<endl;
	}
	else{
		cout<<"Not Found!"<<endl;
	}
}

int main(){
	int n;
	
	cout<<"Enter the size of your Array:";
	cin>>n;

	int* arr=new int[n]; //initializing an array with dynamic memory 
	
	for(int i = 0; i < n; i++) { //filling up of the respective array
    	cout<<"Enter the element of your array:";
        cin>>arr[i];
    }
    
	int choice;
	cout<<"Which Search function you want to access?"<<endl;
	cout<<"1.Index-based"<<endl;
	cout<<"2.Value-based"<<endl;
	cin>>choice;
	
	switch(choice){
		case 1:    // if choice is 1
			int index;
			
			cout<<"Enter the index you want to search:";  //Input the index
			cin>>index;
			
			if(index>=0 && index<n){  //checking the bounderies 
			    indexSearch(arr , index); //calling the indexSearch function
			}
			else{
				cout<<"Index out of bound!"<<endl;
			}
			break;
		case 2:  // if choice is 2
			int value;
			
			cout<<"Enter the value you want to search:"; // Input the value 
			cin>>value;
			
			valueSearch(arr , n , value);  //calling the valueSearch function
			break;
		default:
			cout<<"Invalid input!"<<endl; //just in case input isn't 1 or 2
			break;
	}
	delete[] arr; //freeing the memory
	getch();
	return 0;
}
