//#include<iostream>
//using namespace std;
//int main()
//{
//	// ��򵥵�lambda���ʽ, ��lambda���ʽû���κ�����
//	[] {};
//
//	// ʡ�Բ����б�ͷ���ֵ���ͣ�����ֵ�����ɱ������Ƶ�Ϊint
//	int a = 3, b = 4;
//	[=] {return a + 3; };
//
//	// ʡ���˷���ֵ���ͣ��޷���ֵ����
//	auto fun1 = [&](int c) {b = a + c; };
//	fun1(10);
//	cout << a << " " << b << endl;
//
//	// �����ֶ������Ƶ�lambda����
//	auto fun2 = [=, &b](int c)->int {return b += a + c; };
//	cout << fun2(10) << endl;
//
//	// ���Ʋ�׽x
//	int x = 10;
//	auto add_x = [x](int a) mutable { x *= 2; return a + x; };
//	cout << add_x(10) << endl;
//	return 0;
//}#include <iostream>
#include <thread>
#include <atomic>
atomic_long sum{ 0 };
using namespace std;
void fun(size_t num) {
	for (size_t i = 0; i < num; ++i)
		sum++; // ԭ�Ӳ���
}
int main() {
	cout << "Before joining, sum = " << sum << endl;
	thread t1(fun, 1000000);
	thread t2(fun, 1000000);
	t1.join();
	t2.join();
	cout << "After joining, sum = " << sum << endl;
	return 0;
}