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
    Node* head = convertArr2LL(arr);

    cout<<"Before Insertion\n";
    Node* temp=head;
    while(temp){
        cout<<temp->data;
        temp=temp->next;
    }
    
    int k=2;
    int ele=70;
    if(head==nullptr){
        if(k==1){
            Node* newNode= new Node(70);
        }
    }
    else if(k==1){
        Node* temp=new Node(ele,head);
        head=temp;
    }
    else{
        int count=0 ;
        Node* temp=head;
        while(temp!=nullptr){
            count++;
            if(count==k-1){
                Node* newNode=new Node(ele,temp->next);
                temp->next=newNode;
            }
            temp=temp->next;
        }
        

    }



    cout<<"\nAfter Insertion\n";
    temp=head;
    while(temp){
        cout<<temp->data;
        temp=temp->next;
    }

    

    return 0;
}