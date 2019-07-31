#include<iostream>
using namespace std;
class Solution {
public:
	int Add(int a, int b) {
		while ((a & b) != 0) {
			int _a = a;
			int _b = b;
			a = _a ^ _b;
			b = (_a & _b) << 1;
		}
		return a | b;
	}
};

