/*
Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/
#include<iostream>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    int size=nums.size();//getting the size of DS
    int index=0; //index to be returned
    for(int i=0;i<size;i++){
        if(nums[i]==target){ // case if,found
            index=i;
            break;
        }
        else{      // if not
            if(nums[i]<target) ++index;
        }
    }
    return index;
}