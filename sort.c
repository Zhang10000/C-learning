#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>

//  直接插入排序

void InsertSort(int* arr, int size) {
	for (int i = 1; i < size; ++i) {
		int k = arr[i];
		int end = i - 1;
		while (k < arr[end] && end >= 0) {
			arr[end + 1] = arr[end];     //	相比一下，大的向后移，继续向前比较
			end--;
		}
		arr[end + 1] = k;	//最后小于或者比较完了，保持原位不动
	}
}



//	希尔排序

void XierSort(int* arr, int size) {
	int gap = size / 3 + 1;
	while (gap >= 1) {
		for (int i = gap; i < size; ++i) {
			int k = arr[i];
			int end = i - gap;
			while (k < arr[end] && end >= 0) {
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = k;
		}
		if (gap != 1)
			gap = gap / 3 + 1;
		else
			gap--;
	}
}



//	选择排序
void Swap(int*a, int*b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void SelectSort(int *arr, int size) {
	while (size > 0) {
		int max = 0;
		for (int i = 1; i < size; ++i) {
			if (arr[i] > arr[max]) {
				max = i;
			}
		}
		Swap(&arr[max], &arr[size - 1]);
		size--;
	}
}


void SelectestSort(int *arr, int size) {
	int end = size - 1;
	int start = 0;
	while (end > start) {
		int max = start;
		int min = start;
		for (int i = start; i <= end; ++i) {
			if (arr[i] > arr[max]) {
				max = i;
			}
			if (arr[i] < arr[min]) {
				min = i;
			}
		}
		if (end == min && max == start) 
			Swap(&arr[max], &arr[min]);
		else if (min == end) {
			Swap(&arr[min], &arr[start]);
			Swap(&arr[max], &arr[end]);
		}
		else {
			Swap(&arr[max], &arr[end]);
			Swap(&arr[min], &arr[start]);
		}
		end--;
		start++;
	}
}



//	堆排序

void HeapAd(int*arr, int size, int parent) {    //给一个父节点，向下调整
	int child = parent * 2 + 1;
	while (child < size) {
		if (child + 1 < size&&arr[child + 1] > arr[child])
			child += 1;
		if (arr[child] > arr[parent]) {
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

void StackSort(int*arr, int size) {
	int end = size - 1;
	while (end != 0) {
		Swap(&arr[0], &arr[end]);
		HeapAd(arr, end, 0);
		end--;
	}
}



//	冒泡排序

void Bubble_Sort(int* arr, int size) {
	while (size > 0) {
		for (int i = 0; i < size - 1; ++i) {
			if (arr[i] > arr[i + 1])
				Swap(&arr[i], &arr[i + 1]);
		}
		size--;
	}
}



//	快排的三种基本方法

int Fast_row_1(int* arr, int left ,int right) {
	int key = arr[right - 1];
	int start = left;
	int end = right - 1;
	while (start < end) {
		while (arr[start] < key && start < end) {        //找到大于基准值的停止
			start++;
		}
		while (arr[end > key] && start < end) {       //找到小于基准值的停止
			end--;
		}
		if (start != end) {          //不是同一位置交换
			Swap(&arr[start], &arr[end]);  
		}
	}
	if (start != right - 1) {          //找到最后一个还没有大于的不换，否则交换基准值到正确的位置
		Swap(&arr[start], &arr[right - 1]);
	}
	return start;         //返回基准值下标，告诉主函数分割的位置
}

int Fast_row_2(int* arr, int left, int right) {
	int key = arr[right - 1];
	int start = left;
	int end = right - 1;
	while (start < end) {
		while (arr[start] < key && start < end) {        //找到大于基准值的元素
			start++;
		}
		if (start < end) {
			arr[end] = arr[start];     //把大于基准值的元素赋给end位置
			end--;
		}    
		while (arr[end > key] && start < end) {       //找到小于基准值的元素
			end--;
		}
		if (start < end) {
			arr[start] = arr[end];      //小于基准值的赋值给start位置
			start++;
		}
	}
	arr[start] = key;
	return start;
}

int Fast_row_3(int* arr, int left, int right) {
	int key = arr[right - 1];
	int pcur = left;
	int pre = pcur - 1;
	while (pcur < right) {
		if (arr[pcur] < key&&++pre != pcur) {
			Swap(&arr[pcur], &arr[pre]);
		}
		pcur++;
	}
	if (++pre != right + 1) {
		Swap(&arr[right - 1], &arr[pre]);
	}
	return pre;
}

int* KEY(int * arr,int left, int right) {
	int a = arr[left];
	int b = arr[left + (right - left) / 2];
	int c = arr[right - 1];
	if (a > b) {
		if (b > c) {
			Swap(&arr[left + (right - left) / 2], &arr[right - 1]);
		}
		else if (c > a) {
			Swap(&arr[left], &arr[right]);
		}
		else;
	}
	else if (a > c) {
		Swap(&arr[left], &arr[right]);
	}
	else if (c > b) {
		Swap(&arr[left + (right - left) / 2], &arr[right - 1]);
	}
	else;
	return arr;
}

void QuickSort(int* arr, int left, int right) {
	KEY(arr, left, right);
	if (right - left > 4)
	{
		//		int seg = Fast_row_1(arr, left, right);
		//		int seg = Fast_row_2(arr, left, right);
		int seg = Fast_row_3(arr, left, right);
		QuickSort(arr, left, seg);
		QuickSort(arr, seg + 1, right);
	}
	else {
		InsertSort(arr, right);
	}
}



//	快排的循环写法
//       栈



//  归并排序

void Merging(int* arr, int left, int right, int sec, int size) {
	int str_1 = left;
	int end_1 = sec;
	int str_2 = sec;
	int end_2 = right;
	int* tmp = (int*)malloc(sizeof(int)*size);
	if (tmp == NULL) {
		assert(0);
	}
	int insert = left;   //标记插入辅助空间的位置
	while (str_1 < end_1 && str_2 < end_2) {
		if (arr[str_1] < arr[str_2]) {
			tmp[insert] = arr[str_1];
			str_1++;
			insert++;
		}
		else {
			tmp[insert] = arr[str_2];
			str_2++;
			insert++;
		}
	}
	//   哪个剩余把哪个的元素依次搬移到辅助空间
	while (str_1 < end_1) {
		tmp[insert] = arr[str_1];
		str_1++;
		insert++;
	}
	while (str_2 < end_2) { 
		tmp[insert] = arr[str_2];
		str_2++;
		insert++;
	}
	//   把已经排好的元素拷贝到本来数组的位置
	memcpy(arr + left, tmp + left, sizeof(int)*(right - left));
	free(tmp);
}
void Merge_sort(int* arr, int left, int right, int size) {
	if (right - left > 1) {
		int sec = left + (right - left) / 2;
		Merge_sort(arr, left, sec ,size);
		Merge_sort(arr, sec, right, size);
		Merging(arr, left, right, sec, size);
	}
}
void Mergesort(int* arr, int size) {   //封装
	Merge_sort(arr, 0, size, size);
}


//    归并排序的循环写法
void MergeSortCyc(int* arr, int size) {
	int gap = 1;
	while (gap < size) {
		for (int i = 0; i < size; i += 2 * gap) {
			int left = i;
			int sec = left + gap;
			int right = sec + gap;
			if (right >= size) {
				right = size;
			}
			if (sec >= size) {
				sec = size;
			}
			Merging(arr, left, right, sec, size);
		}
		gap *= 2;
	}
}




void PrintArr(int* arr,int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[] = { 9,4,5,3,7,8,2,6,0,1 };
	//XierSort(arr, sizeof(arr) / sizeof(arr[0]));
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	//SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	//SelectestSort(arr, sizeof(arr) / sizeof(arr[0]));
	//StackSort(arr, sizeof(arr) / sizeof(arr[0]));
	//Bubble_Sort(arr, sizeof(arr) / sizeof(arr[0]));
	//QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]));
	//Mergesort(arr, sizeof(arr) / sizeof(arr[0]));
	MergeSortCyc(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
	system("pause");
}