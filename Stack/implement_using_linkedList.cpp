#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    int isEmpty()
    {
        if (top == nullptr)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int isFull()
    {
        Node *n = new Node();
        if (n == nullptr)
        {
            return 1;
        }
        return 0;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            Node *n = new Node();
            n->data = val;
            n->next = top;
            top = n;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        Node *p = top;
        top = top->next;
        int val = p->data;
        free(p);
        return val;
    }

    int peek(int pos){
        if(isEmpty()){
            cout<<"stack underflow";
            return -1;
        }
        Node* p=top;
        for(int i=1; i<pos; i++){
            if (p->next == nullptr) { // Prevent out-of-bounds access
                cout << "Invalid position\n";
                return -1;
            }
            p=p->next;
        }
        return p->data;
    }

    int stackTop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return top->data;
    }

    int stackBottom()
    {
        Node *p = top;
        while (p->next != nullptr)
        {
            p = p->next;
        }
        return p->data;
    }

    void traversal()
    {
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Stack *s = new Stack();

    // cout << s->isEmpty() << endl;
    // cout << s->isFull() << endl;

    s->push(8);
    s->push(22);
    s->push(17);

    s->traversal();

    // cout<<s->stackTop()<<endl;
    // cout<<s->stackBottom()<<endl;
    
    // cout << "Popped element: " << s->pop() << endl;

    cout<<s->peek(3);

    delete s;
    return 0;
}