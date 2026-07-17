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
class Stack{
    private:   
        Node* top;

    
    public:
        Stack(){
            top=nullptr;
        }
        void push(int x){
            top=new Node(x, top);
        }
        void pop(){
            if(isEmpty()){
                cout<<"Stack Underflow";
                return;
            }
            Node* temp=top;
            top=top->next;
            delete temp;
        }
        int peek(){
            if(isEmpty()){
                cout<<"Stack is empty";
                return -1;
            }
            return top->val;
        }
        bool isEmpty(){
            return top==nullptr;
        }
        int size(){
            int count=0;
            Node* temp=top;
            while(temp){
                count++;
                temp=temp->next;
            }
            return count;
        }
        void display(){
            if(isEmpty()){
                cout<<"Stack is empty";
                return;
            }
            Node* temp=top;
            while(temp){
                cout<<temp->val<<" ";
                temp=temp->next;
            }
        }
        ~Stack(){
            while(!isEmpty()){
                pop();
            }
        }
};

int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    st.display();
    cout << st.peek() << endl;
    st.pop();
    st.display();
    cout << st.size() << endl;
    return 0;
}