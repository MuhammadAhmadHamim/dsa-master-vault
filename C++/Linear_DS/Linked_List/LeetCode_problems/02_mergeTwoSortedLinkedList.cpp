/*
ou are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list.
The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/
#include<iostream>
using namespace std;
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy=new ListNode(0); // A dummy head for the resultant list
    ListNode* current= dummy; // a pointer to iterate over it

    while(list1 != NULL && list2 != NULL){ //loop to check both lists
        
        if(list1->val <= list2->val){ // if list1 has smaller value node
            current->next=list1; //joining it to the dummy head through current pointer
            list1=list1->next; // moving list1 forward
        }
        
        else{ //if list2 has smaller value node
            current->next=list2; //joining it to the dummy head through current pointer
            list2=list2->next; // moving list2 forward
        }

        current=current->next; //moving the current pointer forward
    }

    // checking if either list has anything left and adding it too
    
    if(list1 != NULL){ 
    current->next =list1; 
    }
    
    if(list2 != NULL){ 
    current->next = list2;
    }    
    
    return dummy->next; // returning dummy->next so as to skip the dummy head node
} 