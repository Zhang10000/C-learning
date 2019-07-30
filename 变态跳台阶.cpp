#include<iostream>
int main() {
	int n, s;
	while (std::cin >> n) {
		s = 1;
		while (n-->1)
			s *= 2;
		std::cout << s << std::endl;
	}
	return 0;
}