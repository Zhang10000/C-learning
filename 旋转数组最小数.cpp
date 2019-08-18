#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int min = 2100000000;
		for (int i = 0; i < rotateArray.size(); ++i) {
			min = min < rotateArray[i] ? min : rotateArray[i];
		}
		return min;
	}
};