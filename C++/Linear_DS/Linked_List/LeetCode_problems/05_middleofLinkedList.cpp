/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

*/
#include<iostream>
using namespace std;
ListNode* middleNode(ListNode* head) {
    ListNode* fast=head; // One fast pointer
    ListNode* slow=head; // One slow pointer
    while(fast != NULL && fast->next != NULL){ // loop to check whether the fast pointer doesn't go outside the bounds
        //Two statements are joined by AND(&) operators since fast moves 2 steps and we need to make sure the path is clear
    
        fast=fast->next->next; // +2 steps
        slow=slow->next; // +1 step
    }   
    return slow; // After going through the list slow would always land on middle(in case of odd list) OR second middle(in case of even list)
}