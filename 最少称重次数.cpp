#include<iostream>
using namespace std;
int Min(int a) {
	int count = 0;
	while (a > 1) {
		count++;
		a = a / 3 + 1 - (a % 3 ^ 3) / 3;
	}
	return count;
}