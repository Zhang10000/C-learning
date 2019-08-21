#include<string>
#include<iostream>
using namespace std;
int main() {
	string a, b;
	while (cin >> a >> b) {
		int arr[26] = { 0 };
		int srr[26] = { 0 };
		for (int i = 0; i < a.size(); i++)
			arr[a[i] - 'A']++;
		for (int i = 0; i < b.size(); i++)
			srr[b[i] - 'A']++;
		int i = 0;
		for(;i<26;i++)
			if (arr[i] - srr[i] < 0) {
				cout << "No" << endl;
				break;
			}
		if (i==26)
			cout << "Yes" << endl;
	}
	return 0;
}