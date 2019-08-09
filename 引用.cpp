//#include<iostream>
//#include<time.h>
//
//using namespace std;
//
//int a;
//
//int aa1(){
//	return a;
//}
//int& aa2(){
//	return a;
//}
////定义时必须初始化
//void aa3() {
//	size_t s1 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		aa1();
//	size_t s2 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		aa2();
//	size_t s3 = clock();
//	cout << s2 - s1 << endl;
//	cout << s3 - s2 << endl;
//	cout << endl;
//}
//
//int main2() {
//	for (int i = 1; i < 8;++i) {
//		aa3();
//	}
//	system("pause");
//	return 0;
//}