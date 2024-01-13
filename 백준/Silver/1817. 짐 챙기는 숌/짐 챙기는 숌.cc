#include<stdio.h>

int main() {
	int bookNum;
	int maxWeight;

	scanf("%d%d", &bookNum, &maxWeight);

	int bookWeight;
	int currentBoxWeight = 0;
	int result = 0;

	if (bookNum != 0) result = 1;
	for (int i = 0; i < bookNum; i++) {
		scanf("%d", &bookWeight);
		if (maxWeight < currentBoxWeight + bookWeight) {
			currentBoxWeight = bookWeight;
			result++;
		}
		else currentBoxWeight += bookWeight;
	}
	printf("%d", result);
}