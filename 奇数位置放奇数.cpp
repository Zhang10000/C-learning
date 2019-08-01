#include<iostream>
#include<vector>
using namespace std;
void oddInOddEvenInEven(vector<int>& arr, int len) {
	int i = 0, j = 1;
	while (i < len && j < len) {
		while (i < len && arr[i] % 2 == 0) i += 2;
		while (j < len && arr[j] % 2 == 1) j += 2;
		if(i < len && j < len) swap(arr[i], arr[j]);
	}
}