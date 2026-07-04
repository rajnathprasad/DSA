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
    vector<int> arr={};
    Node* head = convertArr2DLL(arr);

    cout<<"Before Deletion\n";
    print(head);

    // Logic
    
    if(head==nullptr){
        return 0;
    }
    if(head->next==nullptr){
        head=nullptr;
    }else{
        Node* temp = head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        Node* tail = temp->next;
        temp->next=nullptr;
        delete tail;
    }

    //Logic End

    cout<<"\nAfter Deletion\n";
    print(head);
    

    return 0;
}