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

    int k=8;

    if(head==nullptr){
        cout<<"Null";
        return -1;
    }
    if(head->data==k){
        temp=head;
        head=head->next;
        delete temp;
    }
    else{
        temp=head;


        while(temp->next!=nullptr){
            if(temp->next->data==k){
                Node* delNode=temp->next;
                temp->next=delNode->next;
                delete delNode;
                break;
            }
            temp=temp->next;
        }
    }

    cout<<"\nAfter Deletion\n";
    temp=head;
    while(temp){
        cout<<temp->data;
        temp=temp->next;
    }

    

    return 0;
}