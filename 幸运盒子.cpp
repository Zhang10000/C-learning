#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//int ccc(int * s) {
//	return 2;
//}
//
//bool is1(vector<int>s) {
//	for (size_t i = 0; i < s.size(); ++i) {
//		if (s[i] != 1)
//			return false;
//	}
//	return true;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int>s(n, 0);
//	int count[1001] = { 0 };
//	if (is1(s)) {
//		cout << s.size() - 1 << endl;
//		return 0;
//	}
//	ccc(count);
//
//
//	system("pause");
//	return 0;
//}

int cont = 0;
void ContOne(int OneNub, vector<int> list, int nowBit, int sum, int mult) {
	for (int i = nowBit; i < list.size(); i++) {

		sum += list[i], mult *= list[i];                        //����͡���

		if (sum <= mult)
			break;
		else
			cont++;

		ContOne(OneNub, list, i + 1, sum, mult);

		sum -= list[i], mult /= list[i];                        // ������һ��

		while (i < list.size() - 1 && list[i] == list[i + 1])   // ȥ��
			i++; 
	}
}
int main(void)
{
	int n, numb, OneCont(0);        //OneCont������¼1���ܸ���
	vector<int> list;
	cin >> n;
	while (n--)
	{
		cin >> numb;
		if (numb > 1)
			list.push_back(numb);
		else
			OneCont++;
	}
	cont = OneCont - 1; //����1�����ȼ������
	if (!list.empty())
	{
		sort(list.begin(), list.end()); //����������
		for (int i = 1; i <= OneCont; i++) ContOne(i, list, 0, i, 1);
	}
	cout << cont << endl;
	return 0;
}
