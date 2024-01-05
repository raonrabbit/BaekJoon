#include<stdio.h>

int main() {
	int songCount;
	int songLength;
	int ringGap;
	int result;
	int albumEndTime;
	scanf("%d%d%d", &songCount, &songLength, &ringGap);

	albumEndTime = songCount * songLength + 5 * (songCount - 1);

	int current = 0;
	result = ringGap;
	while (result < albumEndTime) {
		while (result > current) {
			current += (songLength + 5);
		}
		if (result >= current - 5 && result < current) break;
		result += ringGap;
	}

	printf("%d", result);
}