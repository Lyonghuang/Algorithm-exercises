#include <cstdio>
#include <algorithm>
using namespace std;

int binarySearch(int *a, int target, int start, int end);

int main() {
	int n;
	int a[100];
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}

	int target = a[0];
	sort(a, a+n);
	for (int i=0; i<n; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	printf("\ntarget = %d\n", target);
	printf("%d\n", binarySearch(a, target, 0, n-1));
	return 0;
}

/*
参数说明：
int *a：被查找的数组，需保证有序
int target：查找的值
int start， int end为数组的查找范围，start表示起始下标，end为末尾下标
返回值：如果查找成功返回目标在数组的下标，查找失败返回-1
算法复杂度log(n)，n为数组长度
*/
int binarySearch(int *a, int target, int start, int end){
	while (start <= end) {
		int m = (start + end) / 2;
		if (a[m] == target) return m;
		else if (a[m] > target) {
			end = m-1;
		}
		else {
			start = m+1;
		}
	}
	return -1;
}
