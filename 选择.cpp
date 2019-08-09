//#include<iostream>
//class A {
//public:
//	A() :s(0) { test(); }
//	virtual void func() { std::cout << s << ' '; }
//	void test() { func(); }
//public:
//	int s;
//};
//class B :public A {
//public:
//	B() { test(); }
//	virtual void func() {
//		++s;
//		std::cout << s << ' ';
//	}
//};
//int main128(int argc, char*argv[]) {
//	A*p = new B;
//	p->test();
//	system("pause");
//	return 0;
//}