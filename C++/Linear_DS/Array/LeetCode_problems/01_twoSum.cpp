/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order. 
*/
#include<iostream>
using namespace std;
int* twoSum(int nums[], int numsSize, int target) {
    int* sol = new int[2];
    for(int i=0; i<numsSize-1; i++){
        bool found=false;
        if(found){break;}
        else{
            for(int j=i+1; j<numsSize; j++){
                if(nums[i]+nums[j]==target){
                    sol[0]=i;
                    sol[1]=j;
                    found=true;
                    break;
                }
                else{continue;}
            }
        }
    }
    return sol;
}