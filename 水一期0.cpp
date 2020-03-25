#include<iostream>
#include<vector>

using namespace std;

int main() {
	const char a[] = { "hello" };
	vector<char> b(a, a + 4);
	const char c[] = "hello";
	cout << sizeof(a) << ' ' << sizeof(b) << ' ' << sizeof(c) << ' '<< sizeof("hello") << endl;
	return 0;
}
