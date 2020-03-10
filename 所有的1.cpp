class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n){
		if (n < 1)return 0;
		int count = 0;
		for (int i = 1; i <= n; i++) {
			int tmp = i;
			while (tmp) {
				if (tmp % 10 == 1)
					++count;
				tmp /= 10;
			}
		}
		return count;
	}
};
