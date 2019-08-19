#include <stdio.h>

void quickSort(int *a, int start, int end);
void bubbleSort(int *a, int n);
void selectionSort(int *a, int n);
void insertSort(int *a, int n);
void mergeSort(int *a, int start, int end);
void heapSort(int *a, int n);

int main() {
	int n;
	int a[100]; // = {3,2,9,4,1,8,10,5,7,6};
	//quickSort(a, 0, 9);
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	//bubbleSort(a, n);
	//selectionSort(a, n);
	//insertSort(a, n);
	//mergeSort(a, 0, n-1);
	heapSort(a, n);
	for (int i=0; i<n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

void quickSort(int *a, int start, int end){
	int i = start;
	int j = end;
	int m = (i + j) / 2;
	int temp;

	while (i <= j) {
		while (a[i] < a[m]) i++;
		while (a[j] > a[m]) j--;
		if (i <= j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}

	if (j > start) quickSort(a, start, j);
	if (i < end) quickSort(a, i, end);
}

void bubbleSort(int *a, int n) {
	int temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void selectionSort(int *a, int n) {
	int temp;
	for (int i = 0; i < n; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[minIndex]) {
				minIndex = j;
			}
		}
		temp = a[i];
		a[i] = a[minIndex];
		a[minIndex] = temp;
	}
}

void insertSort(int *a, int n) {
	int temp;
	int p;
	for (int i = 1; i < n; i++) {
		temp = a[i];
		p = i - 1;
		while (p >= 0 && a[p] > temp) {
			a[p + 1] = a[p];
			p--;
		}
		a[p + 1] = temp;
	}
}

void mergeSort(int *a, int start, int end) {
	int m = (start + end) / 2;
	if (end - start > 1) {
		mergeSort(a, start, m);
		mergeSort(a, m + 1, end);
	}

	int p = start;
	int q = m + 1;
	int cur = 0;
	int c[100];
	while (p <= m && q <= end) {
		if (a[p] < a[q]) {
			c[cur++] = a[p];
			p++;
		}
		else {
			c[cur++] = a[q];
			q++;
		}
	}

	while (p <= m) {
		c[cur++] = a[p++];
	}
	while (q <= end) {
		c[cur++] = a[q++];
	}

	for(int i = start; i <= end; i++) {
		a[i] = c[i-start];
	}
}

void heapSort(int *a, int n) {
	int t[100];
	int p, q, temp;
	for (int i = 0; i < n; i++) {
		t[i] = a[i];
		p = i;
		while (p && t[p] < t[(p - 1) / 2]) {
			temp = t[p];
			t[p] = t[(p - 1) / 2];
			t[(p - 1) / 2] = temp;
			p = (p - 1) / 2;
		}
	}

	for (int i = 0; i < n; i++) {
		a[i] = t[0];
		t[0] = t[n - 1 - i];
		p = 0;
		int last = n - 1 - i;
		while (p < last) {
			if (p * 2 + 2 < last) {//这里分三种情况，当前节点有0，1或2个子节点
				if (t[p * 2 + 2] < t[p * 2 + 1]) {
					q = p * 2 + 2;
				} 
				else {
					q = p * 2 + 1;
				}
				if (t[p] <= t[q]) {
					break;
				}
				temp = t[p];
				t[p] = t[q];
				t[q] = temp;
				p = q;
			} 
			else if (p * 2 + 1 < last) {
				q = p * 2 + 1;
				if (t[p] <= t[q]) {
					break;
				}
				temp = t[p];
				t[p] = t[q];
				t[q] = temp;
				p = q;
			}
			else {
				break;
			}
		}
	}
}
