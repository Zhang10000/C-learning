#include<iostream>
#include<string>
#include<malloc.h>
using namespace std;
//归并
void Merge(int* arr, int start, int end, int sec, int size) {
	int sta1 = start, end1 = sec, sta2 = sec, end2 = end, insert = start;
	int * tmp = (int*)malloc(sizeof(int)*size);
	while (sta1 < end1&&sta2 < end2) {
		if (arr[sta1] > arr[sta2]) {
			tmp[insert] = arr[sta2];
			sta2++, insert++;
		}
		else {
			tmp[insert] = arr[sta1];
			sta1++, insert++;
		}
	}
	while (sta1 < end1) {
		tmp[insert] = arr[sta1];
		sta1++, insert++;
	}
	while (sta2 < end2) {
		tmp[insert] = arr[sta2];
		sta1++, insert++;
	}
	memcpy(arr + start, tmp + start, size);
	free(tmp);
}
void Merge_sort(int* arr, int start, int end, int size) {
	int sec = start + (end - start) / 2;
	if (end - start >= 2) {
		Merge_sort(arr, start, sec, size);
		Merge_sort(arr, sec, end, size);
		Merge(arr, start, end, sec, size);
	}

}
void MergeSort(int * arr, int size) {
	Merge_sort(arr, 0, size, size);
}
int main1() {
	int N;
	while (cin >> N){
		int n;
		int * arr1 = (int*)malloc(sizeof(int)*N);
		int * arr2 = (int*)malloc(sizeof(int)*N);
		int * arr = (int*)malloc(sizeof(int)*2*N);
		for (int i = 0; i < N; i++) {
			cin >> n;
			arr1[i] = n;
		}
		for (int i = 0; i < N; i++) {
			cin >> n;
			arr2[i] = n;
		}
		MergeSort(arr1, N);//分别排
		MergeSort(arr2, N);
		memcpy(arr, arr1, N);
		free(arr1);
		memcpy(arr + N, arr2, N);
		free(arr2);
		Merge(arr, 0, 2 * N, N, 2 * N);//归并排最后一次
		cout << arr[N - 1] << endl;
		free(arr);
	}
	return 0;
}

int main() {
	string s;
	char arr[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	while (cin >> s) {
		int i = 0;
		for (int insert = 0; insert < 4; insert++) {
			int sum = 0;
			for (; i < s.size(); i++) {
				if (s[i] == '.') { i++; break;}
				sum = sum * 10 + (s[i] - '0');
			}
			if (sum / 16 == 0)
				cout << 0;
			else
				cout << arr[sum / 16];
			cout << arr[sum % 16];
		}
		cout << endl;
	}
}
