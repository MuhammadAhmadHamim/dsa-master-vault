#include<iostream>
using namespace std;
void indexAdd(int arr[] , int value , int index){ //function for index-based addition/updation
	cout<<"Previous value on respective index:"<<arr[index]<<endl;
	arr[index]=value;
	cout<<"Added value on respective index:"<<arr[index]<<endl;
}
void valueAdd(int arr[] , int n , int value1, int value2){ //function for value-based addition/updation
	bool added=false;
	for(int i=0 ; i<n ; i++){
		if(arr[i]==value1){  //condition if found
		    arr[i]=value2;
			added=true;
		    break;
		}
		else{
			continue;
		}
	}
	if(added){  //printing the result message
		cout<<"Added/Updated!"<<endl;
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
	cout<<"Which Addition function you want to access?"<<endl;
	cout<<"1.Index-based"<<endl;
	cout<<"2.Value-based"<<endl;
	cin>>choice;
	switch(choice){
		case 1:    // if choice is 1
			int index;
			
			cout<<"Enter the index you want to add on-to:";  //Input the index
			cin>>index;
			
			int value;
			
			cout<<"Enter the value you want to add:"; // Input the value 
			cin>>value;
			 
			if(index>=0 && index<n){  //checking the bounderies 
			    indexAdd(arr , value , index); //calling the indexAdd function
			}
			else{
				cout<<"Index out of bound!"<<endl;
			}
			break;
		case 2:  // if choice is 2
			int value1;
			
			cout<<"Enter the value you want to replace:"; // Input the value1 
			cin>>value1;
			
			int value2;
			
			cout<<"Enter the value you want to add:"; // Input the value2 
			cin>>value2;
			
			valueAdd(arr , n , value1 , value2);  //calling the valueAdd function
			break;
		default:
			cout<<"Invalid input!"<<endl; //just in case input isn't 1 or 2
			break;
	}
	
	for(int i=0;i<n;i++){
	cout<<arr[i]<<" "<<endl;  //printing the result
	}
	
	delete[] arr; //freeing the memory
	return 0;
}
