#include<iostream>
using namespace std;

class Stack{
    int size;
    int top;
    int * arr;
    public:
        Stack(int size){
            this->size=size;
            top=-1;
            arr = new int[size];
        }

        int isEmpty(){
            if(top==-1){
                return 1;
            }
            return 0;
        }

        int isFull(){
            if(top==arr[top]-1){
                return 1;
            }
            return 0;
        }

        void push(int val){
            top+=1;
            arr[top]=val;
        }

        int pop(){
            int val=arr[top];
            top-=1;
            return val;
        }

        int stackTop(){
            if(isEmpty()){
                cout<<"Empty stack"<<endl;
                return -1;
            }
            else{
                return arr[top];
            }
        }

        int stackBottom(){
            if(isEmpty()){
                cout<<"Empty stack"<<endl;
                return -1;
            }
            else{
                return arr[0];
            }
        }

        // Peek operation can behave in two ways:
        // 1. in most of the cases, it returns the topmost element and this behaviour is more common. To achieve this behaviour the implementation will be same as that of stackTop()
        // 2. but it can also return the elment present at a specific position. to understand this consider a stack with 3 values, the position of topmost value will be 1 while the value at the bottom will have position 3. you will have to pass the position as a parameter  in function call and it will return the value at that position

        // I'm implementing second approach here because first one has already been discussed in stackTop()
        int peek(int pos){
            if(isEmpty()){
                cout<<"Empty stack"<<endl;
                return -1;
            }
            else{
                if(top-pos+1<0){
                    cout<<"Invalid position"<<endl;
                    return -1;
                }
                return arr[top-pos+1];
            }
        }
};

int main(){
    Stack* s = new Stack(20);
    cout<<s->isEmpty()<<endl;
    cout<<s->isFull()<<endl;
    s->push(1);
    s->push(2);
    s->push(3);
    cout<<s->pop()<<endl;
    cout<<s->stackBottom()<<endl;
    cout<<s->stackTop()<<endl;
    cout<<s->peek(4)<<endl;

    delete s;
    return 0;
}