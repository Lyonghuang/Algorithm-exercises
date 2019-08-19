#include <stdio.h>

void quickSort(int *a, int start, int end);
void bubbleSort(int *a, int n);
void selectionSort(int *a, int n);

int main() {
	int n;
	int a[100]; // = {3,2,9,4,1,8,10,5,7,6};
	//quickSort(a, 0, 9);
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	//bubbleSort(a, n);
	selectionSort(a, n);
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
