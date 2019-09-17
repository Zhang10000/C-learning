#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	string sInput;
	cin >> sInput;
	int len = sInput.length();
	if ((len < 1) || (len > 50))
		return -1;
	vector<string>vRes;
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			string sSub = sInput.substr(i, (j - i + 1));
			bool flag = true;
			for (int k = 0, l = sSub.length() - 1; k < l; k++, l--) {
				if (sSub[k] != sSub[l]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				vRes.push_back(sSub);
			}
		}
	}
	cout << vRes.size() << endl;
	return 0;
}