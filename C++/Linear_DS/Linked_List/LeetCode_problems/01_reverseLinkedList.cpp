//Given the head of a singly linked list, reverse the list, and return the reversed list.
#include<iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
}
ListNode* reverseList(ListNode* head) {
    //Declaring the required pointers
    ListNode* current=head;
    ListNode* next=NULL;
    ListNode* prev=NULL;

    //Setting up the logic
    while(current != NULL){
        next=current->next; // First we break the chain with `next = current->next
        current->next = prev; // Then we update the pointer in the node current is holding to point towards prev
        prev = current; // Then we update prev by making it hold the current pointer which has the node plus the right side of chain
        current=next; // Then we update current by making it hold the next pointer which contains the remaining chain
    }
return prev; // Returning the node containing the head of the reversed chain
}