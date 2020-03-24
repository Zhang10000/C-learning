#include<iostream>
#include<vector>
using namespace std;

int main0() {
	int	N, X;
	int count = 0;
	while (cin >> N >> X) {
		int c, p;
		while (N--) {
			cin >> c >> p;
			count += p - 10 + c;
		}
		cout << count << endl;
	}
	return 0;
}
int main1() {
	int	N, X;
	int count = 0;
	while (cin >> N >> X) {
		int c, p;
		vector<int> tmp(N, 0);
		for (int i = 0; i < N; i++) {
			cin >> c >> p;
			tmp[i] = c;
			for (int j = i; j >= 0; j--) {
				if (tmp[j] < 10) {
					if ((p - 10 + tmp[j]) > 0) {
						p = p - 10 + tmp[j];
						tmp[j] = 10;
					}
					else {
						tmp[j] += p;
						p = 0;
					}
				}
			}
			count += p;
		}
		cout << count << endl;
	}
	return 0;
}

void pop(vector<int>&arr,size_t i) {
	for (; i < arr.size() - 1; i++)
		arr[i] = arr[i + 1];
	arr.pop_back();
}
int main() {
	int N, M;
	while (cin >> N >> M) {
		vector<int>arr(N + 1, 0);
		for (int i = 0; i < N + 1; i++) {
			arr[i] = i;
		}
		int count = 1;
		for (size_t i = 1; i <= arr.size() && arr.size() != 2; i++, count++) {
			if (i = arr.size())
				i = 1;
			if (count % M == 0) {
				pop(arr, i);
				i--;
			}
		}
		cout << arr[1] << endl;
	}
	return 0;
}
