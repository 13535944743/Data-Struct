#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string.h>
#include<string>
#include<cmath>
#include<stack>
using namespace std;
int Next[10010];
void GetNext(string p) {
	int i = 0;
	Next[0] = -1;
	int j = -1;
	for (; i <= p.size(); ) {
		if (j == -1 || p[i] == p[j]) {
			++i;
			++j;
			Next[i] = j;
		}
		else j = Next[j];
	}
}
int KMPFind(string s, string p, int pos) {
	int i = pos;
	int j = 0;
	int len_s = s.size();
	int len_p = p.size();
	while (i < len_s && j < len_p) {
		if (j == -1 || s[i] == p[j]) {
			++i;
			++j;
		}
		else j = Next[j];
	}
	if (j == len_p) return i - j + 1;
	else return -1;
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		memset(Next, 0, sizeof(Next));
		string s;
		string p;
		cin >> s;
		cin >> p;
		GetNext(p);
		int temp = KMPFind(s, p, 0);

		for (int i = 0; i < p.size(); i++)
			cout << Next[i] << " ";
		cout << endl;
		if (temp == -1) cout << 0 << endl;
		else cout << temp << endl;
	}
	return 0;
}