/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

int LinkedListLength(Node *head) {
    int cnt = 0;
    Node *curr = head;
    while(curr != NULL) {
        cnt++;
        curr = curr -> next;
    }
    return cnt;
}

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    int length = LinkedListLength(head);
    if(K == length) {
        head = head -> next;
        return head;
    }

    length = length - K;
    Node *curr = head;
    while(length-- > 1) {
        curr = curr -> next;
    } 
    curr -> next = curr -> next -> next;
    return head;

}
