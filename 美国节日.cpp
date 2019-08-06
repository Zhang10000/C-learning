#include<iostream>
#include<vector>
using namespace std;

void fest(int &a, int m, int d, int n) {
	int start = 5 + (a - 2000);
	for (int i = 2000; i <= a; ++i)
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
			start++;
	start = start % 7;
	vector<int>Month = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
	if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
		Month[2]++;
	if (d == 0) {
		int i = Month[m] - start;
		while ((i + start) % 7 != n) i--;
		cout << a << '-' << m << '-' << i - Month[m - 1] + start << endl;
	} else {
		int i = Month[m - 1] + 1;
		for (; i <= Month[m]; ++i) {
			if ((i + start) % 7 == n)
				d--;
			if (d == 0)
				break;
		}
		cout << a << '-' << m << '-' << i - Month[m - 1] << endl;
	}
}
void Fest(int a) {
	cout << a << '-' << 1 << '-' << 1 << endl;//Ԫ��
	fest(a, 1, 3, 1);//1.3.1  ������
	fest(a, 2, 3, 1);//2.3.1 ��ͳ��
	fest(a, 5, 0, 1);//5.last.1 ������
	cout << a << '-' << 7 << '-' << 4 << endl;//7.4  ����
	fest(a, 9, 1, 1);//9.1.1 �Ͷ���
	fest(a, 11, 4, 4);//11.4.4 �ж���
	cout << a << '-' << 12 << '-' << 25 << endl;//12.25 ʥ����
}

int WeekToDay(int y, int m, int c, int w, bool B) {//�����������µڼ������ڼ����Լ��������ǵ������������
	int d, week, i;
	if (m == 1) { m = 13; y--; }//��ʽҪ��1�¡�2��ҪתΪ��һ��13��14��
	if (m == 2) { m = 14; y--; }
	i = 0;
	for (d = B ? 1 : 31; d <= B ? 31 : 1; B ? (d++) : (d--)) {//B������/����
		week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;//���չ�ʽ
		if (week + 1 == w) ++i;
		if (i == c) break;
	}
	return d;
}

int main(void) {
	int y;
	while (cin >> y) {
		cout << y << "-01-01" << endl;
		printf("%d-01-%02d\n", y, WeekToDay(y, 1, 3, 1, 1));
		printf("%d-02-%02d\n", y, WeekToDay(y, 2, 3, 1, 1));
		printf("%d-05-%02d\n", y, WeekToDay(y, 5, 1, 1, 0));//����
		cout << y << "-07-04" << endl;
		printf("%d-09-%02d\n", y, WeekToDay(y, 9, 1, 1, 1));
		printf("%d-11-%02d\n", y, WeekToDay(y, 11, 4, 4, 1));
		cout << y << "-12-25" << endl << endl;
	}
	return 0;
}