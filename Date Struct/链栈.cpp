#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string.h>
#include<string>
#include<cmath>
using namespace std;

#define error -1
#define ok 0

class ListNode {
public:
	int data;
	ListNode* next;
	ListNode() {
		next = NULL;
	}
};
class LinkStack {
public:
	ListNode* top;
	int len;

	LinkStack() {
		top = NULL;
		len = 0;
	}
	void push(int e) {
		ListNode* s = new ListNode();
		s->data = e;
		s->next = top;
		top = s;
		len++;
	}
	void pop() {
		ListNode* s = top;
		top = top->next;
		delete s;
		len--;
	}
	void print() {
		ListNode* p = top;
		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
};
int main()
{
	
	return 0;
}