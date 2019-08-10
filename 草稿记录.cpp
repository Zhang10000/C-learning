//#if 0
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int>s(3 * n);
//	for (int i = 0; i < 3 * n; ++i)
//		cin >> s[i];
//	sort(s.begin(), s.end());
//	int sum = 0;
//	for (int i = s.size() / 3; n > 0; n--, i++)
//		sum += s[i];
//	cout << sum << endl;
//	return 0;
//}
//
//---------------------------------------------------------------
//
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//int main() {
//	string s1;
//	string s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	char s[256] = { 0 };
//	for (int i = 0; i < s2.size(); ++i)
//		s[s2[i]]++;
//	string ret;
//	for (int i = 0; i < s1.size(); ++i)
//		if (s[s1[i]] == 0)
//			ret += s1[i];
//	cout << ret << endl;
//	system("pause");
//	return 0;
//}
//
//-----------------------------------------------------------------
//
//
//#include<iostream>
//using namespace std;
//
//int main() {
//	int x = 10;
//	auto a = &x;
//	auto* b = &x;
//	auto& c = x;
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	*a = 20;
//	*b = 30;
//	c = 40;
//	system("pause");
//	return 0;
//}
//
//---------------------------------------------------------------
//
//#include<iostream>
//using namespace std;
//void f(int) {
//	cout << "f(int)" << endl;
//}
//void f(int*) {
//	cout << "f(int*)" << endl;
//}
//int main() {
//	f(0);
//	f(NULL);
//	f((int*)NULL);
//	system("pause");
//	return 0;
//}
//
//
//--------------------------------------------------------------------------
//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//	int n;
//	int count = 1;
//	cin >> n;
//	vector<int>s(n);
//
//	for (int i = 0; i < n; ++i) {
//		cin >> s[i];
//	}
//	for (int i = 1; i < n - 1; i++) {
//		if (s[i] > s[i - 1] && s[i] > s[i + 1] || s[i] < s[i - 1] && s[i] < s[i + 1]) {
//			count++;
//			if (n - 3 != i) i++;
//		}
//	}
//	cout << count << endl;
//	system("pause");
//	return 0;
//}
//
//
//
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s1, s2;
//	cin >> s2;
//	while (cin >> s1)
//		s2 = s1 + " " + s2;
//	cout << s2 << endl;
//	return 0;
//}
//
//
//
//
//
//
//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	Solution() {
//		a = 0;
//		c = 0;
//	}
//	void MoreThanHalfNum_Solution(vector<int> numbers) {
//		size_t sh[10] = { 0 };
//		while (cin >> a) {
//			if (getchar() == '\n') {
//				break;
//			}
//			numbers.push_back(a);
//		}
//		for (int i = 0; i < numbers.size(); ++i) {
//			sh[numbers[i]]++;
//		}
//		for (int i = 0; i < 10; i++) {
//			if (sh[i] >= numbers.size() / 2) {
//				c = i;
//			}
//		}
//		cout << c << endl;
//	}
//private:
//	int a;
//	int c;
//};
//
//int main() {
//	Solution ss;
//	vector<int>s;
//	ss.MoreThanHalfNum_Solution(s);
//	return 0;
//}
//
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//int find_max(int a[]) {
//	int max = 0;
//	for (int i = 0; i < 256; i++)
//		max = a[i] > a[max] ? i : max;
//	return max;
//}
//
//int main() {
//	string s;
//	int a[256] = { 0 };
//	int len = 0;
//	cin >> s;
//	for (int i = 0; i < s.size(); i++) {
//		len = 0;
//		while (s[i] >= '0'&&s[i] <= '9') {
//			len++;
//			i++;
//		}
//		a[i] = len;
//	}
//	int x = find_max(a);
//	for (int i = (x - a[x]); i < x; i++) {
//		cout << s[i];
//	}
//	return 0;
//}
//
//
//
//#include <iostream>
//using namespace std;
//
//int main() {
//	int a[4] = { 0 };
//	int b[3] = { 0 };
//	for (int i = 0; i < 4; i++) {
//		cin >> a[i];
//	}
//	b[0] = (a[0] + a[2]) / 2;
//	b[1] = (a[1] + a[3]) / 2;
//	b[2] = a[3] - b[1];
//	if ( b[1] - a[1] == b[2] ) {
//		
//		cout << b[0] << " " << b[1] << " " << b[2] << endl;
//	}
//	else {
//		cout << "no" << endl;
//	}
//	system("pause");
//	return 0;
//}
//
//
//
//#include <iostream>
//using namespace std;
//
//void Conversion(long&s, int&n) {
//	char b[16] = { '0','1','2','3','4','5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E' , 'F'};
//	while (s) {
//		if (s < 0) {
//			s = -s;
//			cout << "-";
//		}
//		int i = s % n;
//		cout << b[i]; 
//		s /= n;
//	}
//}
//
//int main() {
//	int n;
//	long s;
//	cin >> s;
//	cin >> n;
//	Conversion(s, n);
//	system("pause");
//	return 0;
//}
//
//
//
//#include <iostream>
//#include<string>
//using namespace std;
//
//void Is_Back_to_text(string s, string a) {
//	int count = 0;
//	for (size_t i = 0; i < s.size(); i++) {
//		for (size_t x = i, j = 0; x < s.size(); x++, j++) {
//			s[x + a.size()] = s[i];
//			s[x] = a[j];
//		}
//		string c = string(s);
//		int start = 0;
//		int end = s.size();
//		while (start <= end) {
//			char a = s[start];
//			s[start] = s[end];
//			s[end] = a;
//			start++;
//			end--;
//		}
//		if ( c == s )
//			count++;
//	}
//	cout << count << endl;
//}
//
//int main() {
//	string s, a;
//	cin >> s >> a;
//	Is_Back_to_text(s, a);
//	system("pause");
//	return 0;
//}
//
//
//
//
//#include<iostream>
//#include<string>
//using namespace std;
//bool Huiwen(string str1)
//{
//	int length = str1.length();
//	for (int i = 0; i < length; i++)
//	{
//		if (str1[i] != str1[length - 1])
//			return false;
//		length = length - 1;
//	}
//	return true;
//}
//int main()
//{
//	string str1, str2, temp;
//	int count, len;
//	while (cin >> str1 >> str2)
//	{
//		count = 0;
//		temp = str1;
//		len = str1.length() + 1;
//		for (int i = 0; i < len; i++)
//		{
//			str1 = temp;
//			str1.insert(i, str2);
//			if (Huiwen(str1))
//				count = count + 1;    
//		}
//		cout << count << endl;
//	}
//	return 0;
//}
//
//
//
////
////
////#include<iostream>
////#include<vector>
////using namespace std;
////
////int main() {
////	vector<int>s;
////	vector<int>a;
////	cin >> s;
////
////	system("pause");
////	return 0;
////}
//
//
//#include <iostream>
//using namespace std;
//int main() {
//	int n, curSum = 0, maxSum = -1e5;
//	cin >> n;
//	int arr[n];
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//		curSum += arr[i];
//		if (curSum > maxSum) {
//			maxSum = curSum;
//		}
//		if (curSum < 0) {
//			curSum = 0;
//		}
//	}
//	cout << maxSum << endl;
//	return 0;
//}
//
//
//
//
//#include <iostream>
//using namespace std;
//int main() {
//	int w, h;
//	cin >> w >> h;
//	if (w > 2)
//		w = w / 2 + w % 2;
//	if (h > 2)
//		h = h / 2 + h % 2;
//	cout << w * h << endl;
//	system("pause");
//	return 0;
//}
// 
//
//#include<iostream>
//using namespace std;
//int a[1000][1000] = { 0 };
//int main()
//{
//	int w, h, res = 0;
//	cin >> w >> h;
//
//	for (int i = 0; i < w; i++)
//	{
//		for (int j = 0; j < h; j++)
//		{
//			if (a[i][j] == 0)
//			{
//				res++;
//				if ((i + 2) < w) a[i + 2][j] = -1;
//				if ((j + 2) < h) a[i][j + 2] = -1;
//			}
//		}
//	}
//	cout << res;
//	return 0;
//}
//
//#endif
