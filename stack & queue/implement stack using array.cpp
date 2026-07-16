#include<iostream>
using namespace std;
class Stack{
    private:
        int top;
        int *arr;
        int capacity;
    public:
        Stack(int size){
            capacity=size;
            arr = new int[capacity];
            top=-1;
        }
        void push(int x){
            if(top==capacity-1){
                cout<<"Overflow";
                return;
            }
            top++;
            arr[top]=x;
        }
        void pop(){
            if(top==-1){
                cout<<"Underflow";
                return;
            }
            top--;
        }
        int peek(){
            if(top==-1){
                cout<<"Stack is empty";
                return -1;
            }
            return arr[top];
        }
        bool isEmpty(){
            if(top==-1){
                return true;
            }
            return false;
        }
        int size(){
            return top+1;
        }
        void display(){
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        ~Stack(){
            delete[] arr;
        }
};

int main(){
    Stack st(5);
    
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