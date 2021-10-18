//2164 Ä«µå2
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX_QUEUE_SIZE 510000

int queue[MAX_QUEUE_SIZE];
int main() {
	int n,front=-1,rear=0,temp=1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		front++;
		queue[front] = temp;
		temp++;
	}
	while (front != rear) {
		rear = (rear + 1) % MAX_QUEUE_SIZE;
		front = (front + 1) % MAX_QUEUE_SIZE;
		queue[front] = queue[rear];
		rear = (rear + 1) % MAX_QUEUE_SIZE;
	}
	printf("%d", queue[front]);
	return 0;
}