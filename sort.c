#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>

//  ֱ�Ӳ�������

void InsertSort(int* arr, int size) {
	for (int i = 1; i < size; ++i) {
		int k = arr[i];
		int end = i - 1;
		while (k < arr[end] && end >= 0) {
			arr[end + 1] = arr[end];     //	���һ�£��������ƣ�������ǰ�Ƚ�
			end--;
		}
		arr[end + 1] = k;	//���С�ڻ��߱Ƚ����ˣ�����ԭλ����
	}
}



//	ϣ������

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



//	ѡ������
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



//	������

void HeapAd(int*arr, int size, int parent) {    //��һ�����ڵ㣬���µ���
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



//	ð������

void Bubble_Sort(int* arr, int size) {
	while (size > 0) {
		for (int i = 0; i < size - 1; ++i) {
			if (arr[i] > arr[i + 1])
				Swap(&arr[i], &arr[i + 1]);
		}
		size--;
	}
}



//	���ŵ����ֻ�������

int Fast_row_1(int* arr, int left ,int right) {
	int key = arr[right - 1];
	int start = left;
	int end = right - 1;
	while (start < end) {
		while (arr[start] < key && start < end) {        //�ҵ����ڻ�׼ֵ��ֹͣ
			start++;
		}
		while (arr[end > key] && start < end) {       //�ҵ�С�ڻ�׼ֵ��ֹͣ
			end--;
		}
		if (start != end) {          //����ͬһλ�ý���
			Swap(&arr[start], &arr[end]);  
		}
	}
	if (start != right - 1) {          //�ҵ����һ����û�д��ڵĲ��������򽻻���׼ֵ����ȷ��λ��
		Swap(&arr[start], &arr[right - 1]);
	}
	return start;         //���ػ�׼ֵ�±꣬�����������ָ��λ��
}

int Fast_row_2(int* arr, int left, int right) {
	int key = arr[right - 1];
	int start = left;
	int end = right - 1;
	while (start < end) {
		while (arr[start] < key && start < end) {        //�ҵ����ڻ�׼ֵ��Ԫ��
			start++;
		}
		if (start < end) {
			arr[end] = arr[start];     //�Ѵ��ڻ�׼ֵ��Ԫ�ظ���endλ��
			end--;
		}    
		while (arr[end > key] && start < end) {       //�ҵ�С�ڻ�׼ֵ��Ԫ��
			end--;
		}
		if (start < end) {
			arr[start] = arr[end];      //С�ڻ�׼ֵ�ĸ�ֵ��startλ��
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



//	���ŵ�ѭ��д��
//       ջ



//  �鲢����

void Merging(int* arr, int left, int right, int sec, int size) {
	int str_1 = left;
	int end_1 = sec;
	int str_2 = sec;
	int end_2 = right;
	int* tmp = (int*)malloc(sizeof(int)*size);
	if (tmp == NULL) {
		assert(0);
	}
	int insert = left;   //��ǲ��븨���ռ��λ��
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
	//   �ĸ�ʣ����ĸ���Ԫ�����ΰ��Ƶ������ռ�
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
	//   ���Ѿ��źõ�Ԫ�ؿ��������������λ��
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
void Mergesort(int* arr, int size) {   //��װ
	Merge_sort(arr, 0, size, size);
}


//    �鲢�����ѭ��д��
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