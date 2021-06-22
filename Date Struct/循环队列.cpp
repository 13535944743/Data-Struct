#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string.h>
#include<string>
#include<cmath>
#include<stack>
using namespace std;

#define error -1
#define MAXQSIZE 5

class SqQueue {
public:
    int* base;
    int front;
    int rear;
    int length;
    SqQueue() {
        base = new int[MAXQSIZE];
        front = 0;
        rear = front;
        length = 0;
    }
    ~SqQueue() {
        delete[] base;
    }
    int EnQueue(int e) {
        if ( ( rear + 1 ) % MAXQSIZE == front ) return error;
        base[rear] = e;
        rear = (rear + 1) % MAXQSIZE;
        length++;
    }
    int DeQueue() {
        if (front == rear) return error;
        front = (front + 1) % MAXQSIZE;
        length--;
    }
    void display() {
        int temp = front;
        int count = 0;
        while (1) {
            cout << base[(temp++) % MAXQSIZE] << " ";
            count++;
            if (count > length - 1) break;
        }
        cout << endl;
    }
};
int main()
{
    
    return 0;
}
