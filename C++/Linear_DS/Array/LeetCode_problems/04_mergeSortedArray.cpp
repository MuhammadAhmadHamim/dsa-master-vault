/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n,
representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, 
but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n,
where the first m elements denote the elements that should be merged,
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/
#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int i=m-1; //pointer for accessing the last digit of nums1
    int j=n-1;  //pointer for accessing the last digit of nums2
    //write is the pointer to access the slot in which value to be inserted
	for(int write=m+n-1;write>=0;write--){   //write=m+n-1 means the first slot where digit to be placed in nums1 since it's size=m+n and -1 converts it from size to pointer 
        if(j < 0 || (i>=0 && nums1[i] > nums2[j])){ // j < 0 to check if nums2 is exhausted or not 
                                                    // i>=0 to check if i still has elements or not
													// nums1[i] > nums2[j] to check if num1's element is bigger or not
	    // This block exectues if either nums2 is exhausted or num1 is not exhausted and digit underconsideration of nums1 is greater than that of nums2  
			nums1[write]=nums1[i]; //overriding the digit of nums1 on write's position
            i-=1; //moving the pointer of nums1 backward since nums1 was used
        }
        else{  //This block exectues if nums2 is not exhausted and the digit underconsideration of num1 is less than or equal to that of nums2
            nums1[write]=nums2[j]; //overriding the digit of nums2 on write's position
            j-=1; //moving the pointer of nums2 backward since nums2 was used
        }  
    }	
	return 0;
}
