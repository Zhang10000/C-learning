#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;


vector<int> GetPowerFactor(int R, int N) {
	vector<int>con;
	if (R < N) {
		con.push_back(0);
		return con;
	}
	int count = 0;
	while (R / N != 0) {
		int su = R % N;
		if (su < N && su > 1) {
			con.clear();
			return con;
		}
		if (su == 1) {
			con.push_back(count);
		}
		R /= N;
		count++;
		if (R == 1)
			con.push_back(count);
	}
	return con;
}


int InLine(vector<int>&a, vector<int>&b, vector<int>wait) {
	int count = 0;
	int size = wait.size();
	for (int i = 0; i < size; i++) {
		count += a[wait[i] - 1] * (i - 1) + b[wait[i] - 1] * (size - i);
	}
	return count;
}

int wait(vector<int>wait, vector<int>&a, vector<int>&b, int line) {

}

vector<int> WaitInLine(vector<int>& a, vector<int>& b) {
	vector<int>arr(a.size(), 0);
	int line = 1;
	int min = INT_MIN;
	int le = 0;
	for (int i = 0; i < a.size(); i++) {
		arr[i] = line;
		int x = wait(arr, a, b, line++);
		if (x < min) {
			min = x;
			le = i;
		}
	}
}

int main() {
	int x, y;
	while (cin >> x >> y) {
		vector<int>arr;
		arr = GetPowerFactor(x, y);
		for (auto e : arr)
			cout << e << ' ';
		cout << endl;
	}
	return 0;
}

int main0() {
	string s;
	while (getline(cin,s)) {
		stack<char>left;
		stack<char>right;
		int count = 0;
		if (s.size() == 0) {
			cout << count << ' ' << 0 << ' ' << 0 << endl;
			continue;
		}
		for (auto c : s) {
			if (c == '(') {
				left.push(c);
			}
			else if (c == ')') {
				if (left.size() != 0) {
					count++;
					left.pop();
				}
				else
					right.push(')');
			}
		}
		cout << count << ' ' << left.size() << ' ' << right.size() << endl;
	}

	return 0;
}
