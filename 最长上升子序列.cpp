#include<iostream>
using namespace std;
int main() {
	int a;
	while (cin >> a) {
		int count = 0;
		int ch[10001] = { 0 };
		int cq[10001] = { 0 };
		for (int i = 0; i < a; ++i) {
			cin >> ch[i];
		}
		for (int i = 0; i < a; ++i) {
			for (int j = 0; j < i; ++j) {
				if (ch[j] < ch[i]) {
					cq[i] = cq[i] > cq[j] + 1 ? cq[i] : cq[j] + 1;
					count = count > cq[i] ? count : cq[i];
				}
			}
		}
		
		cout << count + 1 << endl;
	}
	return 0;
}