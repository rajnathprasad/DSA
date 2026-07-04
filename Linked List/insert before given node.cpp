#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr){
    if(arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void print(Node* head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
}

int main(){

    vector<int> arr = {1,2,3,4};
    Node* head = convertArr2DLL(arr);

    cout << "Before Insertion\n";
    print(head);

    // Logic

    int d = 20;

    Node* node = head->next->next;

    if(node == head){
        Node* newNode = new Node(d, head, nullptr);
        head->back = newNode;
        head = newNode;
    }
    else{
        Node* prev = node->back;
        Node* newNode = new Node(d, node, prev);

        prev->next = newNode;
        node->back = newNode;
    }

    // Logic End

    cout << "\nAfter Insertion\n";
    print(head);

    return 0;
}