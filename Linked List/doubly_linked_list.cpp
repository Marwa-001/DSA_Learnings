#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

void traversal(Node *head)
{
    Node *p = head;
    do
    {
        cout << p->data << endl;
        p = p->next;
    } while (p != nullptr);
}

void reverse_traversal(Node *head)
{
    Node *p = head;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    while (p != nullptr)
    {
        cout << p->data << endl;
        p = p->prev;
    }
}

// Node *insert_at_beginning(Node *head, int data)
// {
//     return head;
// }

// Node *insert_at_end(Node *head, int data)
// {
//     return head;
// }

// Node* insert_at_index(Node* head, int index, int data){
//     return head;
// }

// Node* insert_after_node(Node* head, Node* prevNode, int data){
//     return head;
// }

// // Deletion operation in a circular linked list
// Node* delete_from_start(Node*head){
//     return head;
// }

// Node* delete_from_end(Node* head){
//     return head;
// }

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->data = 5;
    head->next = second;
    head->prev = nullptr;

    second->data = 3;
    second->next = third;
    second->prev = head;

    third->data = 7;
    third->next = nullptr;
    third->prev = second;

    traversal(head);
    reverse_traversal(head);
    return 0;
}