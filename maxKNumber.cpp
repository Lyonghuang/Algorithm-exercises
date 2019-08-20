#include <cstdio>

using namespace std;

int maxKNumberByHeap(int *a, int n, int k);
int maxKNumberByBinary(int *a, int n, int k);
int binary(int *a, int start, int end, int k);

int main() {
	int n, k;
	int a[100];
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	//printf("%d\n", maxKNumberByHeap(a, n, k));
	printf("%d\n", maxKNumberByBinary(a, n, k));
	return 0;
}

int maxKNumberByHeap(int *a, int n, int k) {
	int heap[100];
	int p;
	int temp;
	for (int i = 0; i < k; i++) {
		heap[i] = a[i];
		p = i;
		while (p && heap[(p - 1) / 2] > heap[p]) {
				temp = heap[p];
				heap[p] = heap[(p - 1) / 2];
				heap[(p - 1) / 2] = temp;
				p = (p - 1) / 2;
		}
	}

	for (int i = k; i < n; i++) {
		if (a[i] <= heap[0]) continue;
		heap[0] = a[i];
		int p = 0;
		int q;
		while (p < k) {
			q = p;
			if (p * 2 + 1 < k && heap[p * 2 + 1] < heap[q]) {
				q = p * 2 + 1;
			}
			if (p * 2 + 2 < k && heap[p * 2 + 2] < heap[q]) {
				q = p * 2 + 2;
			}
			if (p == q) break;
			int temp = heap[p];
			heap[p] = heap[q];
			heap[q] = temp;
			p = q;
		}
	}

	int minIndex = 0;
	for (int i = 0; i < k; i++) {
		if (heap[i] < heap[minIndex]) {
			minIndex = i;
		}
	}
	return heap[minIndex];
}

int maxKNumberByBinary(int *a, int n, int k) {
	return binary(a, 0, n-1, k);
}

int binary(int *a, int start, int end, int k) {
	int i = start;
	int j = end;
	int m = (i + j) / 2;
	
	if (i == j)
		return a[i];
	while (i <= j) {
		while (a[i] > a[m]) i++;
		while (a[j] < a[m]) j--;
		if (i <= j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i <= k - 1) return binary(a, i, end, k);
	else if (j >= k - 1) return binary(a, start, j, k);
	else return a[(i + j) / 2];
}
