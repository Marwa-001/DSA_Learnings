#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void traversal(Node *temp)
{
    while (temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

Node *insert_at_beginning(Node *head, int data)
{
    Node *ptr = new Node();
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

Node *insert_at_end(Node *head, int data)
{
    Node *ptr = new Node();
    ptr->data = data;

    Node *p = head;
    while (p->next != nullptr)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = nullptr;
    return head;
}

Node *insert_at_index(Node *head, int index, int data)
{
    Node *ptr = new Node();
    ptr->data = data;

    Node *p = head;
    int i = 0;
    while (i != index - 1)
    { // or while(i<index-1)
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
    return head;
}

Node *insert_after_node(Node *head, Node *prevNode, int data)
{
    Node *ptr = new Node();
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

Node* delete_from_start(Node* head){
    Node* ptr =head;
    head=head->next;
    free(ptr);
    return head;
}

Node* delete_from_end(Node*head){
    Node* ptr=head;
    Node* q = head->next;
    while (q->next!=nullptr){
        ptr=ptr->next;
        q=q->next;
    }
    ptr->next=nullptr;
    free(q);
    return head;
}

Node* delete_after_node(Node* head, Node* prevNode){
    Node*ptr=prevNode->next;
    prevNode->next=prevNode->next->next; // or prevNode->next=ptr->next
    free(ptr);
    return head;
}

Node* delete_at_index(Node* head, int index){
    Node* p=head;
    Node* q = head->next;
    for(int i=0; i<index-1; i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

Node* delete_node_with_specific_value(Node* head, int value){
    Node* p=head;
    Node* q = head->next;
    while(q->data!=value && q->next!=nullptr){
        q=q->next;
        p=p->next;
    }
    if(q->data==value){
        p->next=q->next;
        free(q);
    }
    return head;
}

int main()
{
    Node * head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    // Linking Nodes
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = nullptr;

    // Traversing a linked list
    traversal(head);

    // INSERTION 
    
    // head=insert_at_beginning(head,19);
    // head=insert_after_node(head, 20);
    // head = insert_at_index(head, 1, 100);
    // head=insert_at_end(head,22);

    // DELETION

    // head=delete_from_start(head);
    // head= delete_from_end(head);
    // head=delete_after_node(head, head);
    // head=delete_at_index(head, 1);
    // delete_node_with_specific_value(head,2);

    traversal(head);
    return 0;
}