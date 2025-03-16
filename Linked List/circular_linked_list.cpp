#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void traversal(Node *head)
{
    Node *p = head;
    do
    {
        cout << p->data << endl;
        p = p->next;
    } while (p != head);
}

Node *insert_at_beginning(Node *head, int data)
{
    Node *p = new Node();
    p->data = data;
    p->next = head;

    Node *q = head;
    while (q->next != head)
    {
        q = q->next;
    }
    q->next = p;
    return p;
}

Node *insert_at_end(Node *head, int data)
{
    Node *q = new Node();
    Node *p = head;
    q->data = data;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = q;
    q->next=head;
    return head;
}

Node* insert_at_index(Node* head, int index, int data){
    Node *ptr = new Node();
    ptr->data = data;

    Node *p = head;
    int i = 0;
    while (i != index - 1) // or while(i<index-1)
    { 
        p = p->next;
        i++;
    }

    ptr->next = p->next;
    p->next = ptr;
    return head;
}

Node* insert_after_node(Node* head, Node* prevNode, int data){
    Node *ptr = new Node();
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

// Deletion operation in a circular linked list 
Node* delete_from_start(Node*head){
    Node* q = head;
    Node * p =head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next = q->next;
    free(q);
    head= p->next;
    return head;
}

Node* delete_from_end(Node* head){
    Node*p=head;
    Node*q=head;
    while(p->next->next!=head){
        p=p->next;
    }
    q=p->next;
    p->next=head;
    free(q);

    //This will work too

    // while(p->next->next!=head){
    //     p=p->next;
    //     q=q->next;
    // }
    // p->next=head;
    // q=q->next;
    // free(q);

    return head;
}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->data = 5;
    head->next = second;
    second->data = 3;
    second->next = third;
    third->data = 7;
    third->next = head;

    traversal(head);
    head = insert_at_beginning(head, 8);
    head = insert_at_end(head, 10);

    // These two are same as that of a singly linked list
    // head = insert_at_index(head, 1, 8);
    // head = insert_after_node(head, second, 8);

    head=delete_from_start(head);
    head=delete_from_end(head);
    traversal(head);
    return 0;
}