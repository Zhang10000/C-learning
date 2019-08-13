#include<string>
#include<vector>
#include<iostream>
using namespace std;
struct Yl {
	vector<long long> Js;
	string Xs;
};
int Max_Y(Yl&n) {
	if (n.Js[0] == 1)
		return 1;
	for (int i = n.Js[0]; i > 1; --i)
		if (n.Js[0] % i == 0 && n.Js[1] % i == 0)
			return i;
}
long long Min_B(Yl&n, Yl&s) {
	if (n.Js.size() == 1 && s.Js.size() == 1)
		return 1;
	if (n.Js.size() == 1 || s.Js.size() == 1)
		return (n.Js.size() > s.Js.size() ? n.Js : s.Js)[1];
	for (long long i = n.Js[1] > s.Js[1] ? n.Js[1] : s.Js[1];; ++i) {
		if (i%n.Js[1] == 0 && i%s.Js[1])
			return i;
	}
}
void Xsh(Yl&n) {
	if (n.Js[0] < 0)
		n.Xs.push_back('-');
	if (n.Js[0] == 0) {
		n.Js.clear();
		n.Js.push_back(0);
		n.Xs.push_back('0');
		return;
	}
	if (n.Js[0] == n.Js[1]) {
		n.Js.clear();
		n.Js.push_back(1);
		n.Xs.push_back('1');
		return;
	}
	if (n.Js[0] < n.Js[1]) {
		n.Js[0] /= Max_Y(n);
		n.Js[1] /= Max_Y(n);
		long long i = n.Js[1];
		while (i != 0) {
			n.Xs.push_back(i % 10 + '0');
			i /= 10;
		}
		n.Xs.push_back('/');
		i = n.Js[0];
		while (i != 0) {
			n.Xs.push_back(i % 10 + '0');
			i /= 10;
		}
		return;
	}
	if (n.Js[0] > n.Js[1]) {
		int a = n.Js[0] / n.Js[1];
		n.Js[0] = n.Js[0] % n.Js[1];
		n.Js[0] /= Max_Y(n);
		n.Js[1] /= Max_Y(n);
		long long i = n.Js[1];
		while (i != 0) {
			n.Xs.push_back(i % 10 + '0');
			i /= 10;
		}
		n.Xs.push_back('/');
		i = n.Js[0];
		while (i != 0) {
			n.Xs.push_back(i % 10 + '0');
			i /= 10;
		}
		n.Xs.push_back(' ');
		n.Xs.push_back(a + '0');
	}
}
void JJCC(Yl&a, Yl&b) {
	Xsh(a);
	Xsh(b);
	long long x = Min_B(a, b);
	Yl c;
	c.Js[0] = a.Js[0] * x / b.Js[1] + b.Js[0] * x / a.Js[1];
	c.Js[1] = x;
	Xsh(c);
	cout << a.Xs << " + " << b.Xs << " = " << c.Xs << endl;
	c.Js.clear();
	c.Xs.clear();
	c.Js[0] = a.Js[0] * x / b.Js[1] - b.Js[0] * x / a.Js[1];
	c.Js[1] = x;
	Xsh(c);
	cout << a.Xs << " + " << b.Xs << " = " << c.Xs << endl;
	c.Js.clear();
	c.Xs.clear();
	c.Js[0] = a.Js[0] * b.Js[0];
	c.Js[1] = b.Js[1] * a.Js[1];
	Xsh(c);
	cout << a.Xs << " * " << b.Xs << " = " << c.Xs << endl;
	c.Js.clear();
	c.Xs.clear();
	c.Js[0] = a.Js[0] * b.Js[1];
	c.Js[1] = b.Js[1] * a.Js[0];
	Xsh(c);
	cout << a.Xs << " / " << b.Xs << " = " << c.Xs << endl;
	c.Js.clear();
	c.Xs.clear();
}
Yl Init(string s) {
	Yl a;
	long long x = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-')
			x *= (-1);
		if (s[i] == '/') {
			a.Js.push_back(x);
			x = 0;
		}
		x += 10 * x + s[i] - '0';
	}
	return a;
}
int main() {
	Yl a, b;
	string s1, s2;
	while (cin >> s1 >> s2) {
		a = Init(s1);
		b = Init(s2);
		JJCC(a, b);
	}
	return 0;
}