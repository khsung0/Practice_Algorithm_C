//11650 좌표 정렬하기
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int x[100000], y[100000];
void print_array(int x[],int y[],int n);
void swap(int x[], int y[], int first, int second);
//void quick_sort(int x[], int y[],int n,int left,int right);

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	for (int i = n-1; i >0; i--) {
		for (int j = 0; j < i ; j++) {
			if (x[j] > x[j+1]) {
				swap(x, y, j, j+1);
			}
			else if (x[j] == x[j+1]) {
				if (y[j] > y[j+1]) {
					swap(x, y, j , j+1);
				}
			}
		}
	}

	print_array(x, y, n);
}

void print_array(int x[], int y[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", x[i], y[i]);
	}
}

void swap(int x[], int y[], int first, int second) {
	int temp;
	temp = x[first];
	x[first] = x[second];
	x[second] = temp;
	temp = y[first];
	y[first] = y[second];
	y[second] = temp;
}

//void quick_sort(int x[], int y[], int n, int left, int right) {
//	if (left != right) {
//		int L = left, R = right;
//
//	}
//}