/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 
Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
*/
#include<iostream>
using namespace std;
bool hasCycle(ListNode *head) {

    //By using Fast/Slow pointer method (Floyd's Cycle Detection)
    ListNode* fast=head; // One fast pointer
    ListNode* slow=head; // One slow pointer
    while(fast != NULL && fast->next != NULL){ // loop to check whether the fast pointer doesn't go outside the bounds
    //Two statements are joined by AND(&) operators since fast moves 2 steps and we need to make sure the path is clear

        fast=fast->next->next; // +2 steps
        slow=slow->next; // +1 step

        if(slow==fast){ //checking if they met on each iteration of the loop
            return true; // returns true if they met ever during the cycle
        }
    }
    return false; //returns false if the list has no cycle init
}