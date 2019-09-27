#include<iostream>
#include<string>
#include<map>
#include<set>
#include<bitset>
using namespace std;

template<class T1,class T2>
struct par{
	T1 first;
	T2 second;
	par():first(T1()),second(T2()){}
	par(const T1&a, const T2&b) :first(a), second(b){}
};

void Mapper() {
	map<string, string>m;
	m.insert(make_pair("banana", "�㽶"));
	m["apple"] = "ƻ��";
	m["qiezi"] = "����";
	m["gggg"] = "����";
	m["xixix"] = "������";
	m["ouyou"] = "����";
	m["gag"] = "�����";
	m["photo"] = "��Ƭ";
	m["dad"] = "��ƶ";
	cout << m.size() << endl;
	for (auto e : m)
		cout << e.first << "---->" << e.second << endl;
	cout << endl;
	auto ret = m.insert(make_pair("apple", "��"));
	if (ret.second)
		cout << "�ɹ�" << endl;
	else
		cout << "ʧ��" << ret.first->first << "--" << ret.first->second << endl;
	m.erase("apple");
	if (1 == m.count("apple"))
		cout << "yes" << endl;
	else
		cout << "NO" << endl;
	// multimap Ĭ�ϰ�С�ڵķ�ʽ��key ���бȽ�
	// multimap û�����ص�operator[]����
}

void SSet() {
	int array[] = { 1,7,8,5,9,6,3,2,4,5,90,87,4,56 };
	set<int>a(array, array + sizeof(array) / sizeof(array[0]));
	multiset<int>s(array, array + sizeof(array) / sizeof(array[0]));
	for (auto e : a)
		cout << e << endl;
	cout << endl;
	cout << s.size() << endl;
	for (auto e : s)
		cout << e << endl;
	cout << endl;
}

int main() {
	SSet();
	system("pause");
	return 0;
}