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

class SqQueue {
public:
    int* base;
    int front;
    int rear;
    SqQueue() {
        base = new int[MAXQSIZE];
        rear = 0;
        front = rear;
    }
    ~SqQueue() {
        delete[] base;
    }
    int EnQueue(int e) {
        if ( rear > MAXQSIZE) return error;
        base[rear] = e;
        rear++;
    }
    int DeQueue() {
        if (front == rear) return error;
        front++;
    }
    void display() {
        int temp = front;
        while (temp != rear) {
            cout << base[temp++] << " ";
        }
        cout << endl;
    }
};
int main()
{
    
    return 0;
}
 