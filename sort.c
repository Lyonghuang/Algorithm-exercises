#include <stdio.h>

void quick_sort(int *a, int start, int end);

int main() {
	int a[10] = {3,2,9,4,1,8,10,5,7,6};
	quick_sort(a, 0, 9);
	for (int i=0; i<10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

void quick_sort(int *a, int start, int end){
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

	if (j > start) quick_sort(a, start, j);
	if (i < end) quick_sort(a, i, end);
}
