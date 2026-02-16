#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int n=10;
	int value,index;
	
	//declaration of array
	int arr1[n]={11,12,13,14,15,16,17}; //1st way
	int arr2[n];    //2nd way
	
	//Enter value to insert
	cout<<"Enter the value to be inserted:";
	cin>>value;
	
	//Enter the index 
	cout<<"Enter the index upon which value to be added(0 to 9):";
	cin>>index;
	
	for(int i=n-1;i>index;i--){
		arr1[i]=arr1[i-1]; ///making space for the incoming value
	}
	
	arr1[index]=value; //inserting the value in freed space
	
	for(int i=0;i<n;i++){
	cout<<arr1[i]<<" "<<endl;  //printing the result
	}
	
	getch();
	return 0;
}
