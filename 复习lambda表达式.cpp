//#include<iostream>
//using namespace std;
//int main()
//{
//	// 最简单的lambda表达式, 该lambda表达式没有任何意义
//	[] {};
//
//	// 省略参数列表和返回值类型，返回值类型由编译器推导为int
//	int a = 3, b = 4;
//	[=] {return a + 3; };
//
//	// 省略了返回值类型，无返回值类型
//	auto fun1 = [&](int c) {b = a + c; };
//	fun1(10);
//	cout << a << " " << b << endl;
//
//	// 各部分都很完善的lambda函数
//	auto fun2 = [=, &b](int c)->int {return b += a + c; };
//	cout << fun2(10) << endl;
//
//	// 复制捕捉x
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
		sum++; // 原子操作
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