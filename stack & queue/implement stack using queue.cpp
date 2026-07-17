#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int n=q.size();
        for(int i=0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow\n";
            return;
        }

        q.pop();
    }
    int peek() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return -1;
        }

        return q.front();
    }
    bool isEmpty() {
        return q.empty();
    }

    int size() {
        return q.size();
    }
};