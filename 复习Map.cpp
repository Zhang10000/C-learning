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
	m.insert(make_pair("banana", "香蕉"));
	m["apple"] = "苹果";
	m["qiezi"] = "茄子";
	m["gggg"] = "垃圾";
	m["xixix"] = "哈哈哈";
	m["ouyou"] = "啊哈";
	m["gag"] = "额。。。";
	m["photo"] = "照片";
	m["dad"] = "扶贫";
	cout << m.size() << endl;
	for (auto e : m)
		cout << e.first << "---->" << e.second << endl;
	cout << endl;
	auto ret = m.insert(make_pair("apple", "甜"));
	if (ret.second)
		cout << "成功" << endl;
	else
		cout << "失败" << ret.first->first << "--" << ret.first->second << endl;
	m.erase("apple");
	if (1 == m.count("apple"))
		cout << "yes" << endl;
	else
		cout << "NO" << endl;
	// multimap 默认按小于的方式对key 进行比较
	// multimap 没有重载的operator[]操作
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