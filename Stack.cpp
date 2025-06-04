#include<iostream>
using namespace std;

class Stackbase{
    public:
        int* arr;
        int top;
        int capacity;
    
    Stackbase(int capacity){
        this->capacity = capacity;
        this->arr = new int[this->capacity];
        this->top = -1;
    }

    ~Stackbase()
    {
        delete[] arr; 
    }

    void push(int element);
    int pop();
    void peek();
    bool isEmpty();
    bool isFull();
    int size();
    void display();

};

class Stack : public Stackbase{
    public:

    Stack(int capacity) : Stackbase(capacity) {}

    void push(int element){
        if(isFull()){
            cout<<"Stack is overflow"<<endl;
            return;
        }
        else
        {
            this->top++;
            this->arr[this->top] = element;
        }
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack is underflow/empty"<<endl;
            return -1;
        }
        else
        {
            cout<<"pop element : " <<arr[top--]<<endl;
        }
    }

    void peek(){
        if(isEmpty()){
            cout<<"Stack is underflow/empty."<<endl;
        }
        else
        {
            cout<<"top/peek element : "<<this->arr[top]<<endl;
        }
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == capacity-1;
    }

    int size(){
        return top+1;
    }

    void display(){
        if(isEmpty()){
            cout << "Stack is empty!" << endl;
            return;
        }

        cout<<"stack : ";
            for(int i = top; i >= 0; i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
    }
};

int main()
{
    int capacity;
    cout<<"Enter Stack Capacity : ";
    cin>>capacity;

    Stack s(capacity);                                         

    int choice,value;

    do{

        cout<<"\n-------------------------------"<<endl;
        cout<<"Enter 1 for push"<<endl;
        cout<<"Enter 2 for pop"<<endl;
        cout<<"Enter 3 for peek"<<endl;
        cout<<"Enter 4 for display"<<endl;
        cout<<"Enter 5 for size"<<endl;
        cout<<"Enter 6 for isEmpty"<<endl;
        cout<<"Enter 7 for isFull"<<endl;
        cout<<"Enter 0 for Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch (choice)
        {
            case 1 :
                cout<<"Enter value for push : ";
                cin>>value;
                s.push(value);
                break;
            case 2 :
                s.pop();
                break;
            case 3 :
                s.peek();
                break;
            case 4 :
                s.display();
                break;
            case 5 :
                cout<<"size : "<<s.size()<<endl;
                break;
            case 6 :
                cout<<s.isEmpty();
                break;
            case 7 :
                cout<<s.isFull();
                break;
            case 0 :
                cout<<"Exiting...!"<<endl;
                break;
            default:
                cout<<"Invalid choice!!"<<endl;
                break;
        }

    }while(choice != 0);
    
    return 0;
}