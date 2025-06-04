#include<iostream>
using namespace std;

class Queue{
    public:
        int front,rear,capacity;
        int* arr;
    
    Queue(int capacity){
        this->capacity = capacity;
        this->arr = new int[this->capacity];
        this->front = this->rear = -1;
    }

    ~Queue(){
        delete[] arr;
    }

    void Enqueue(int data);
    int Dequeue();
    int Front();
    int Rear();
    bool isEmpty();
    bool isFull();
    int size();
    void Display();
};

void Queue::Enqueue(int data){
    if(this->isFull()){
        cout<<"Queue is overflow!"<<endl;
    }
    else if(this->front == -1 && this->rear == -1){
        this->front = this->rear = 0;
        this->arr[this->rear] = data;
    }
    else{
        this->arr[++this->rear] = data;
    }
}

int Queue::Dequeue(){
    if(this->isEmpty())
    {
        cout << "Queue is underflow!" << endl;
        return -1;
    }
    else if(this->front == this->rear){
        this->front = this->rear = -1;
        return -1;
    }
    else{
        cout<<"Dequeue element : "<<arr[this->front];
        return arr[this->front++];
    }
}

int Queue::Front(){
    if(this->isEmpty())
    {
        return -1;
    }
    else
    {   
        cout<<"front element : "<<arr[this->front]<<endl;
        return arr[this->front];
    }
}

int Queue::Rear(){
    if(this->isEmpty())
    {
        return -1;
    }
    else
    {
        cout<<"Rare element : "<<arr[this->rear]<<endl;
        return arr[this->rear];
    }
}

void Queue::Display(){
    if(this->isEmpty())
    {
        cout<<"Queue is underflow!"<<endl;
    }
    else
    {
        cout<<"Queue is : ";
        for(int i = this->front; i<=this->rear; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

bool Queue::isEmpty(){
    return this->rear == -1;
}

bool Queue::isFull(){
    return this->rear == capacity - 1;
}

int Queue::size(){
    if(this->isEmpty())
    {
        cout<<"Queue is underflow!"<<endl;
        return 0;
    }
    else
    {
        return rear - front + 1;
    }
}

int main(){

    int capacity;
    cout<<"Enter Queue Capacity : ";
    cin>>capacity;

    Queue que(capacity);                                         

    int choice,value;

    do{

        cout<<"\n-------------------------------"<<endl;
        cout<<"Enter 1 for Enqueue"<<endl;
        cout<<"Enter 2 for dequeue"<<endl;
        cout<<"Enter 3 for front"<<endl;
        cout<<"Enter 4 for rear"<<endl;
        cout<<"Enter 5 for display"<<endl;
        cout<<"Enter 6 for isEmpty"<<endl;
        cout<<"Enter 7 for isFull"<<endl;
        cout<<"Enter 8 for size"<<endl;
        cout<<"Enter 0 for Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch (choice)
        {
            case 1 :
                cout<<"Enter value for add/enqueue : ";
                cin>>value;
                que.Enqueue(value);
                break;
            case 2 :
                que.Dequeue();
                break;
            case 3 :
                que.Front();
                break;
            case 4 :
                que.Rear();
                break;
            case 5 :
                que.Display();
                break;
            case 6 :
                cout<<que.isEmpty();
                break;
            case 7 :
                cout<<que.isFull();
                break;
            case 8 :
                cout<<"size : "<<que.size()<<endl;
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