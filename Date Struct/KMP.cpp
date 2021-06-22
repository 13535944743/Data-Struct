#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string.h>
#include<string>
#include<cmath>
#include<stack>
#define maxn 1000010
using namespace std;
int Next[maxn];
int main()
{
	string s;
	string p;
	cin >> s;
	cin >> p;
	int len_s = s.size();
	int len_p = p.size();
	int now = 0;
	for (int i = 1; i < len_p;) {
		if (p[i] == p[now]) {
			now += 1;
			Next[i] = now;
			i++;
		}
		else if (now) {
			now = Next[now - 1];
		}
		else {
			Next[i] = 0;
			i ++;
		}
	}

	int pos = 0;
	for (int tar = 0; tar < len_s; ) {
		if (s[tar] == p[pos]) {
			tar++;
			pos++;
		}
		else if (pos) {
			pos = Next[pos - 1];
		}
		else tar++;

		if (pos == len_p) {
			cout << (tar - pos + 1) << endl;
			pos = Next[pos - 1];
		}
	}
	for (int i = 0; i < len_p; i++) {
		if (i == 0) cout << Next[i];
		else cout << " " << Next[i];
	}
	return 0;
}