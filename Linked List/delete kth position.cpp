#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next = temp;
        mover=temp;
    }
    return head;
}

int main(){
    vector<int> arr={2,5,8,7};
    int present=0;
    Node* head = convertArr2LL(arr);

    cout<<"Before Deletion\n";
    Node* temp=head;
    while(temp){
        cout<<temp->data;
        temp=temp->next;
    }

    int k=2;

    if(head==nullptr){
        cout<<"Null";
        return -1;
    }
    else if(k==1){
        temp=head;
        head=head->next;
        delete temp;
    }
    else{
        int count=1;
        temp=head;
        while(count<k-1){
            temp=temp->next;
            count++;
        }
        Node* prev=temp->next;
        temp->next=prev->next;
        delete prev;
    }

    cout<<"\nAfter Deletion\n";
    temp=head;
    while(temp){
        cout<<temp->data;
        temp=temp->next;
    }

    

    return 0;
}