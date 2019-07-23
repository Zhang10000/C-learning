#include<iostream>
#include<string>
using namespace std;
bool sss(const char* s1, const char* s2) {
	if (*s1 == '\0' && *s2 == '\0')
		return true;
	if (*s1 == '\0' || *s2 == '\0')
		return false;
	if (*s1 == '?')
		return sss(s1 + 1, s2 + 1);
	else if (*s1 == '*')
		return sss(s1 + 1, s2) || sss(s1 + 1, s2 + 1) || sss(s1, s2 + 1);
	else if (*s1 == *s2)
		return sss(s1 + 1, s2 + 1);
}
int main7() {
	string s, y;
	while (cin >> s >> y) {
		if (sss(s.c_str(), y.c_str()))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	system("pause");
	return 0;
}