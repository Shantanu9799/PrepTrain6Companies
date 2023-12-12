/****************************************************************

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

*****************************************************************/

int LinkedListLength(Node *head) {
    int cnt = 0;
    Node *curr = head;
    while(curr != NULL) {
        cnt++;
        curr = curr -> next;
    }
    return cnt;
}

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    int firstLength = LinkedListLength(firstHead);
    int secondLength = LinkedListLength(secondHead);

    // cout << firstLength << " " << secondLength << endl;

    int diff = firstLength - secondLength;
    Node *firstStart = firstHead;
    Node *secondStart = secondHead;
    if(diff < 0) {
        while(diff != 0) {
            secondStart = secondStart -> next;
            diff++;
        }
    } else {
        while(diff != 0) {
            firstStart = firstStart -> next;
            diff--;
        }
    }

    // cout << firstStart -> data << endl;

    while(firstStart!=NULL && secondStart!=NULL) {
        firstStart = firstStart -> next;
        secondStart = secondStart -> next;
        if(firstStart == secondStart) return firstStart;
    }

    return NULL;

}
