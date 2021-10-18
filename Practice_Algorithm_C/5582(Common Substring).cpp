//공통 부분 문자열
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STRING_SIZE 4002


#include<stdio.h>
#include<string.h>
char first[MAX_STRING_SIZE], second[MAX_STRING_SIZE];
int str_map[MAX_STRING_SIZE][MAX_STRING_SIZE];
int main() {
	int res=0;
	scanf("%s", &first);
	scanf("%s", &second);
	int f_size = strlen(first), s_size = strlen(second);
	for (int i = 0; i < f_size; i++) {
		for (int j = 0; j < s_size; j++) {
			if (first[i] == second[j]) {
				if (i == 0 || j == 0) {
					str_map[i][j] = 1;
					if (res == 0)
						res = 1;
				}
				else {
					str_map[i][j] = str_map[i - 1][j - 1] + 1;
					if (res < str_map[i][j])
						res = str_map[i][j];
				}
			}
		}
	}
	printf("%d", res);
}