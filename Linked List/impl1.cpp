#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(){
            head = NULL;
        }
        void insertAtHead(int val=)
}