#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Implement Using Array........................................

class stack {

    private: 
        int top = -1;
        static const int Size = 100;
        int Stack_arr[Size];

    public:
        stack() : Stack_arr{0} {}

        void push(int item) {
            if (top<Size-1) {
                top++;
                Stack_arr[top]=item;
            }else {
                cout << "Error - Stack Overflow." << endl;
            }
        }

        int pop() {
            if (top>-1) {
                int num = Stack_arr[top];
                top--;
                return num;
            }else {
                cout << "Error - Stack Underflow." << endl;
                return 0;
            }
        }

        bool isEmpty() {
            if (top==-1) {
                return true;
            }else {
                return false;
            }
        }

        bool isFull() {
            if (top<Size) {
                return false;
            }else {
                return true;
            }
        }

        void StackTop() {
            if (top>-1) {
                int num = Stack_arr[top];
                cout << num << endl;
            }else {
                cout << "Stack is Empty." << endl;
            }
        }

        void Display() {
            if (top>-1) {
                for (int i=0;i<=top;i++) {
                    cout << Stack_arr[i]<<" ";
                }
                cout << endl;
            }else {
                cout << "Stack is Empty." << endl;
            }
        }
};

// Implement Using LinkedList...................................


class Node {
    public:
        int data;
        Node* next;
    };

class Stack {
    private:
        Node* top;

    public:
        Stack() : top(nullptr) {}

        void push(int item) {

            Node* newnode = new Node();
            newnode -> data = item;
            newnode -> next = top;
            top = newnode;
        }

        int pop() {
            if (top==nullptr) {
                cout << "Error - Stack Underflow." << endl;
                return 0;
            }else {
                int num = top -> data;
                top = top -> next;
                return num;
            }
        }

        bool isEmpty() {
            if (top==nullptr) {
                return true;
            }else {
                return false;
            }
        }

        int StackTop() {
            if (top==nullptr) {
                cout << "Stack is Empty." << endl;
                return 0;
            }else {
                int num = top -> data;
                return num;
            }
        }

        void Display() {
            if (top==nullptr) {
                cout << "Stack is Empty." << endl;
            }else {
                Node* current = top;
                while (current -> next!=nullptr) {
                    cout << current -> data << " ";
                    current = current -> next;
                }
                cout << current -> data << endl;
            }
        }
};

int main() {
    cout<<endl;
    int size = 100;
    cout<<"Size is "<<size<<endl;

    cout<<endl;
    // Array
    cout << "Using Array"<<endl;
    auto start1 = high_resolution_clock::now();

    stack S;
    for (int x=0;x<size+2;x++) {
        S.push(rand()%100);
    }
    S.Display();
    for (int x=0;x<size/2;x++) {
        S.pop();
    }
    S.Display();
    for (int x=0;x<size/2+3;x++) {
        S.push(rand()%100);
    }
    S.Display();

    auto end1 = high_resolution_clock::now();
    auto duration1= duration_cast<microseconds>(end1-start1);
    cout<<duration1.count()<<" microseconds"<<endl;
    cout<<endl;

    // LinkedList
    cout<<"Using LinkedList"<<endl;
    auto start2 = high_resolution_clock::now();

    Stack s;
    for (int x=0;x<size+2;x++) {
        s.push(rand()%100);
    }
    s.push(100);
    s.Display();
    for (int x=0;x<size/2;x++) {
        s.pop();
    }
    s.Display();
    for (int x=0;x<size/2+3;x++) {
        s.push(rand()%100);
    }
    s.Display();

    auto end2 = high_resolution_clock::now();
    auto duration2= duration_cast<microseconds>(end2-start2);
    cout<<duration2.count()<<" microseconds"<<endl;
    cout<<endl;
}