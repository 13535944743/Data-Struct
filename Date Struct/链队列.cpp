#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string.h>
#include<string>
#include<cmath>
#include<stack>
using namespace std;

#define error -1
#define MAXQSIZE 1000

class QNode {
public:
    int data;
    QNode* next;
};

class LinkQueue {
public:
    QNode* front;
    QNode* rear;
    LinkQueue() {
        QNode* p = new QNode();
        p->next = NULL;
        rear = p;
        front = p;
    }
    void EnQueue(int e) {
        QNode* p = new QNode();
        p->data = e;
        p->next = NULL;
        rear->next = p;
        rear = p;
    }
    int DeQueue() {
        if (front == rear) return error;
        QNode* p = front->next;
        front->next = p->next;
    }
    void display() {
        QNode* temp = front;
        while (temp != rear) {
            cout << temp->next->data << " ";
            temp = temp->next;
        }
    }
};
int main()
{
    
    return 0;
}
