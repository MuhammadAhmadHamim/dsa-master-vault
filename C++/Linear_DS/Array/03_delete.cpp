#include<iostream>
#include<conio.h>
using namespace std;
void deleteFunction(int arr[] ,int n , int index){ //function to delete through index
    for(int i=index;i<n-1;i++){
    	int temp; //pushing the value to the very last
    	temp=arr[i];
    	arr[i]=arr[i+1];
    	arr[i+1]=temp;
	}
	
	for(int i=0;i<n-1;i++){
	    cout<<arr[i]<<" "<<endl;  //printing the result
	}
}
int main(){
	int n;
	
	//Enter the size
	cout<<"Enter the size of your Array:";
	cin>>n;
	
	int* arr=new int[n]; //initializing an array with dynamic memory 
	
	for(int i = 0; i < n; i++){ //filling up of the respective array
    	cout<<"Enter the element of your array:";
        cin>>arr[i];
    }
    
    int index;
    
    //Enter the index to be deleted
    cout<<"Enter the index of value you want to delete:";
    cin>>index;
    
    //Checking the bounderies of array
    if(index>=0 && index<n){ //if, in range
    	deleteFunction(arr,n,index);
	}
	else{  //if not
		cout<<"Invalid Input!"<<endl;
	}
	delete[] arr;
	getch();
	return 0;
}
