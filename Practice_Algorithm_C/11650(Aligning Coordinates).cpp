//11650 좌표 정렬하기
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int x[100000], y[100000];
void print_array(int x[],int y[],int n);
void swap(int x[], int y[], int first, int second);
void quick_sort(int x[], int y[],int n,int left,int right);

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	quick_sort(x, y, n, 0, n - 1);

	print_array(x, y, n);
}

void print_array(int x[], int y[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", x[i], y[i]);
	}
}

void swap(int x[], int y[], int first, int second) {
	int temp;
	printf("%d,%d\n", first, second);
	temp = x[first];
	x[first] = x[second];
	x[second] = temp;
	temp = y[first];
	y[first] = y[second];
	y[second] = temp;
}

void quick_sort(int x[], int y[], int n, int left, int right) {
	if (left != right) {
		int L = left, R = right;
		int pivot = left;
		L++;
		while (L <= R) {
			if (x[pivot] >= x[L]) {
				L++;
			}
			else if (x[pivot] <= x[R]) {
				R--;
			}
			else {
				swap(x, y, L,R);
			}
		}
		if (L<n && x[L] < x[pivot]) {
			swap(x, y, L, pivot);
			return quick_sort(x, y, n, left, L - 1), quick_sort(x, y, n, L+1, right);
		}
		else {
			swap(x, y, L-1, pivot);
			return quick_sort(x, y, n, left, L - 2), quick_sort(x, y, n, L, right);
		}
	}
	else {
		return;
	}
}