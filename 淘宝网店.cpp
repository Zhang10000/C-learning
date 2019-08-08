#include<vector>
#include<iostream>
using namespace std;
bool Run(int n) {
	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
		return true;
	return false;
}
void Mmm(int n1, int n2, int m1, int m2, int d1, int d2) {
	int sum = 0;
	vector<int>Day = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	vector<int>RunDay = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	vector<int>Money = { 0,2,1,1,2,1,2,1,2,2,2,1,2 };
	int Year = 0;
	for (int i = 1; i < 13; ++i)
		Year += Day[i] * Money[i];
	if (n1 == n2) {
		if (Run(n1)) {
			if (m1 == m2)
				sum += (d2 - d1 + 1)*Money[m1];
			else {
				for (int i = m1 + 1; i < m2; ++i)
					sum += RunDay[i] * Money[i];
				sum += (RunDay[m1] - d1 + 1)*Money[m1];
				sum += d2 * Money[m2];
			}
		}
		else {
			if (m1 == m2)
				sum += (d2 - d1 + 1)*Money[m1];
			else {
				for (int i = m1 + 1; i < m2; ++i)
					sum += Day[i] * Money[i];
				sum += (Day[m1] - d1 + 1)*Money[m1];
				sum += d2 * Money[m2];
			}
		}
	}
	else {
		if (Run(n1)) {
			for (int i = m1 + 1; i < 13; ++i)
				sum += RunDay[i] * Money[i];
			sum += (RunDay[m1] - d1 + 1)*Money[m1];
		}
		else {
			for (int i = m1 + 1; i < 13; ++i)
				sum += Day[i] * Money[i];
			sum += (Day[m1] - d1 + 1)*Money[m1];
		}
		if (Run(n2)) {
			for (int i = 0; i < m2; ++i)
				sum += RunDay[i] * Money[i];
			sum += d2 * Money[m1];
		}
		else {
			for (int i = 0; i < m2; ++i)
				sum += Day[i] * Money[i];
			sum += d2 * Money[m1];
		}
		for (int i = n1 + 1; i < n2; ++i) {
			if (Run(i))
				sum += Year + 1;
			else
				sum += Year;
		}
	}
	cout << sum << endl;
	return;
}