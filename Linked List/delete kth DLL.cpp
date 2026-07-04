#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1, Node* next1, Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr){
    if(arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* prev= head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

int countSize(Node* head){
    int count=0;
    while(head!=nullptr){
        count++;
        head=head->next;
    }
    return count;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    vector<int> arr={54,84,65,88,56,65};
    Node* head = convertArr2DLL(arr);

    cout<<"Before Deletion\n";
    print(head);

    // Logic
    int k=2;
    int count=1;
    Node* temp = head;
    while(temp!=nullptr  && count < k){
        temp=temp->next;
        count++;
    }
    if(temp!=nullptr){
        Node* prev = temp->back;
        Node* front = temp->next;
        if (prev != nullptr)
        prev->next = front;
        else
        head = front;
        if (front != nullptr)
        front->back = prev;
        delete temp;
    }

    //Logic End

    cout<<"\nAfter Deletion\n";
    print(head);
    

    return 0;
}