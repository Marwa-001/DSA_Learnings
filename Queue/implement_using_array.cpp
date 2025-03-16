#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int f, r, size;

public:
    Queue(int size){
        this->size=size;
        f=-1;
        r=-1;
        arr = new int(size);
    }

    void traversal(){
        for(int i=f+1; i<=r; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    int isEmpty(){
        if(f==r){
            return true;
        }
        return false;
    }

    int isFull(){
        if(r==size-1){
            return true;
        }
        return false;
    }

    void enqueue(int val){
        r+=1;
        arr[r]=val;
    }

    int dequeue(){
        int a=-1;
        if(isEmpty()){
            return a;
        }
        f=f+1;
        a=arr[f];
        return a;
    }

    int firstVal(){
        if(isEmpty()){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        return arr[f+1];
    }

    int lastVal(){
        if(isEmpty()){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        return arr[r];
    }
};

int main()
{
    Queue q(5);
    cout<<q.isEmpty()<<" "<<q.isFull()<<endl;
    q.enqueue(5);
    q.enqueue(9);
    q.enqueue(2);
    q.enqueue(6);
    
    cout<<q.isEmpty()<<" "<<q.isFull()<<endl;
    q.enqueue(7);
    cout<<q.isEmpty()<<" "<<q.isFull()<<endl;
    q.traversal();

    q.dequeue();
    q.dequeue();
    cout<<q.isEmpty()<<" "<<q.isFull()<<endl;
    q.traversal();

    return 0;
}