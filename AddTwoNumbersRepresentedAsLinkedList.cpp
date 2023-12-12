#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure:
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }
    };

************************************************************/

// Reverse Linked List
Node<int>* reverseLinkedList(Node<int> *head) {
    if(head==NULL || head -> next==NULL) return head;
    Node<int>* remainListHead = reverseLinkedList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return remainListHead;
}

Node<int>* addTwoLists(Node<int>* first, Node<int>* second) {
    // Write your code here.

    // Reverse both of them
    first = reverseLinkedList(first);
    second = reverseLinkedList(second);

    // create a new list using a dummy Node
    Node<int> *sum = new Node<int>(0);

    // traversal node for adding all other Node
    Node<int> *curr = sum;

    // carry
    int carry = 0;

    Node<int> *fHead = first;
    Node<int> *sHead = second;

    // while both have values in it
    while(fHead!=NULL && sHead!=NULL) {
        // sum calculate
        int s = fHead -> data + sHead -> data + carry;
        // carry always will be the sum / 10 value
        carry = s / 10;
        // creating a node with the value of Sum%10. like 12, 2 will be added in the sum and 1 will be added to carry
        Node<int> *temp = new Node<int>(s%10);
        // adding new node to sum list
        curr -> next = temp;
        curr = curr -> next;
        fHead = fHead -> next;
        sHead = sHead -> next;
    }

    // only one loop will execute

    // if first linked list have still remains with some values
    while(fHead != NULL) {
        int s = fHead -> data + carry;
        carry = s / 10;
        Node<int> *temp = new Node<int>(s%10);
        curr -> next = temp;
        curr = curr -> next;
        fHead = fHead -> next;
    }
    
    // if second linked list have still remains with some values
    while(sHead != NULL) {
        int s = sHead -> data + carry;
        carry = s / 10;
        Node<int> *temp = new Node<int>(s%10);
        curr -> next = temp;
        curr = curr -> next;
        sHead = sHead -> next;
    }

    // finally we have to consider our carry value
    if(carry != 0) {
        Node<int> *temp = new Node<int>(carry);
        curr -> next = temp;
        curr = curr -> next;
    }

    // ommiting the dummy node
    sum = sum -> next;

    // reversing the sum list
    sum = reverseLinkedList(sum);
    
    // return the sum lisy
    return sum;
}