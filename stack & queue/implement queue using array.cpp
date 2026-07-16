#include<iostream>
using namespace std;
class Queue{
    private:
        int front;
        int rear;
        int* arr;
        int capacity;
    public:
        Queue(int size){
            capacity = size;
            arr = new int[capacity];
            front=0;
            rear=-1;
        }
        void enqueue(int x){
            if(rear==capacity-1){
                cout<<"Queue Overflow";
                return;
            }
            arr[++rear]=x;
        }
        void dequeue(){
            if(isEmpty()){
                cout<<"Queue Underflow";
                return;
            }
            front++;
        }
        int peek(){
            if(isEmpty()){
                cout<<"Queue is Empty";
                return -1;
            }
            return arr[front];
        }
        bool isEmpty(){
            return front>rear;
        }
        int size(){
            return rear-front+1;
        }
        void display(){
            if(isEmpty()){
                cout << "Queue is Empty\n";
                return;
            }
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
        }

        ~Queue(){
            delete[] arr;
        }
};

int main(){
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << q.peek() << endl;
    q.dequeue();
    q.display();
    cout << q.size() << endl;

    return 0;
}