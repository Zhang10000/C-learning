class Solution {
public:
	int cutRope(int number) {
		if (number <= 1)
			return 0;
		if (number == 2)
			return 1;
		if (number == 3)
			return 2;
		int tmp = number / 3;
		if (number % 3 == 1)
            return pow(3, tmp - 1)*pow(2, (number - 3 * (tmp - 1)) / 2);
		else
			return pow(3, tmp)*pow(2, (number - 3 * tmp) / 2);
	}
};
