#include<stdio.h>

int main() {
	int dishCount;
	int start, prev, current;
	int wontakCount = 0;

	scanf("%d", &dishCount);
	scanf("%d", &start);
	prev = start;
	for(int i = 1; i < dishCount; i++){
		scanf("%d", &current);
		if (prev >= current) {
			wontakCount++;
		}
		prev = current;
	}
	if (current >= start) wontakCount++;

	printf("%d", wontakCount);
}