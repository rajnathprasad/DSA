#include<iostream>
using namespace std;
class Node{
    public:
        int val;
        Node* next;

        Node(int x){
            val=x;
            next=nullptr;
        }
        Node(int x, Node* next1){
            val=x;
            next=next1;
        }
};
class Queue{
    private:
        Node* front;
        Node* rear;
    public:
        Queue(){
            front=rear=nullptr;
        }
        void enqueue(int x){
            Node* temp= new Node(x);
            if(isEmpty()){
                front=rear=temp;
                return;
            }
            rear->next=temp;
            rear=temp;
        }
        void dequeue(){
            if(isEmpty()){
                cout<<"Queue Underflow";
                return;
            }
            Node* temp=front;
            front=front->next;
            delete temp;

            if(front==nullptr){
                rear=nullptr;
            }
        }
        int peek(){
            if(isEmpty()){
                cout<<"Queue is empty";
                return -1;
            }
            return front->val;
        }
        bool isEmpty(){
            return front==nullptr;
        }
        int size(){
            int count=0;
            Node* temp= front;
            while(temp){
                count++;
                temp=temp->next;
            }
            return count;
        }
        void display(){
            if(isEmpty()){
                cout<<"Queue is empty";
                return;
            }
            Node* temp= front;
            while(temp){
                cout<<temp->val<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
        ~Queue(){
            while(!isEmpty()){
                dequeue();
            }
        }
};

int main(){
    Queue q;

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
