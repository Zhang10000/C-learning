#include<string>
#include<iostream>
using namespace std;
void M_cat(string &a, string &b) {  //一个字符串可以分出多少个另一个
	int count = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == b[0]) {
			int j = 0;
			for (; j < b.size(); ++j, ++i)
				if (a[i] != b[j])
					break;
			if (j == b.size())
				count++;
			--i;
		}
	}
	cout << count << endl;
}