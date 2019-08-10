//#include<iostream>
//#include<stack>
//#include<string>
//using namespace std;
//
//bool chkParenthesis(string A, int n) {
//	stack<char>s;
//	for (size_t i = 0; i < n; i++) {
//		if (A[i] != '(' && A[i] != ')')
//			return false;
//		if (A[i] == '(')
//			s.push('(');
//		if (A[i] == ')') {
//			if (s.empty())
//				return false;
//			if (s.top() != '(') {
//				return false;
//			}
//			else {
//				s.pop();
//			}
//		}
//	}
//	if (!s.empty())
//		return false;
//	return true;
//}
//
//int main113() {
//	string s;
//	int n;
//	cin >> s >> n;
//	cout << chkParenthesis(s, n) << endl;
//	system("pause");
//	return 0;
//}