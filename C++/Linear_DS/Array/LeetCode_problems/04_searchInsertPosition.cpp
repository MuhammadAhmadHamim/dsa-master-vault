/*
Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/
#include<iostream>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    int size=nums.size();
    int index=0;
    for(int i=0;i<size;i++){
        if(nums[i]==target){
            index=i;
            break;
        }
        else{
            if(nums[i]<target) ++index;
        }
    }
    return index;
}