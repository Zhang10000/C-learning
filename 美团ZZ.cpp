#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;



int main1() {
	int n;
	while (cin >> n) {
		vector<vector<char>> arr;
		if (n == 0)
			cout << -1 << endl;
		vector<char> s;
		char x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			s.push_back(x);
		}
		arr.push_back(s);
		s.clear();
		for (int i = 0; i < n; i++) {
			cin >> x;
			s.push_back(x);
		}
		arr.push_back(s);
		vector<vector<int>> count(2);
		count[0].push_back(0);
		if (arr[0][1] == '.')
			count[1].push_back(1);
		else
			count[1].push_back(0);
		for(int i=1;i<n;i++){
			if (arr[0][n] == 'X')
				count[0].push_back(0);
			else
				count[0].push_back(count[0][i - 1] + count[1][i - 1]);
			if (arr[1][n] == 'X')
				count[1].push_back(0);
			else
				count[1].push_back(count[0][i - 1] + count[1][i - 1]);
		}
		if (count[1][n - 1] != 0)
			cout << count[1][n - 1] << endl;
		else
			cout << -1 << endl;
		
	}
	return 0;
}


int find(vector<int>arr, int k) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == k)
			return 1;
	}
	return -1;
}
int ZScount(vector<int>arr,int k) {
	vector<int> zu;
	vector<int> sum;
	for (int i = 0; i < arr.size(); i++) {
		if (find(zu, arr[i]) == -1) {
			zu.push_back(arr[i]);
			sum.push_back(1);
		}
		else {
			sum[find(zu, arr[i])]++;
		}
	}
	int max = zu[0];
	int count = 0;
	for (int i = 0; i < sum.size(); i++) {
		max = count > sum[i] ? max : zu[i];
		count = count > sum[i] ? count : sum[i];
	}
	for (int i = 0; i < arr.size(); i++) {
		if (k | arr[i] == max)
			count++;
	}
	return count;
}

int main0() {
	int n, k;
	while (cin >> n >> k) {
		int x;
		vector<int> arr;
		for (int i = 0; i < n; i++) {
			cin >> x;
			arr.push_back(x);
		}
		cout << ZScount(arr, k) << endl;
	}

	return 0;
}



int main() {
	int n, k, L, R;
	while (cin >> n >> k >> L >> R) {
		cout << pow((R - L) / k, n) << endl;
	}
	return 0;
}
