#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void deleteNode(int val) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Value not found\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }


    bool search(int key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextPtr;

        while (curr != NULL) {
            nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }

        head = prev;
    }

    ~LinkedList() {
        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;


    list.insertAtHead(2);
    list.insertAtHead(1);
    list.insertAtTail(3);
    list.insertAtTail(4);

    cout << "Initial List:\n";
    list.display();


    list.deleteNode(3);
    cout << "After deleting 3:\n";
    list.display();


    cout << "Search 4: " << (list.search(4) ? "Found" : "Not Found") << endl;

    list.reverse();
    cout << "After reversing:\n";
    list.display();

    return 0;
}