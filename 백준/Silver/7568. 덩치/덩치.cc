#include<stdio.h>

int main() {
	int peopleCount;
	int weight, height;
	int weights[50];
	int heights[50];

	scanf("%d", &peopleCount);

	for (int i = 0; i < peopleCount; i++) {
		scanf("%d%d", &weight, &height);
		weights[i] = weight;
		heights[i] = height;
	}

	int result;
	for (int i = 0; i < peopleCount; i++) {
		result = 1;
		for (int j = 0; j < peopleCount; j++) {
			if (i == j) continue;
			if (weights[i] < weights[j] && heights[i] < heights[j])
				result += 1;
		}
		printf("%d ", result);
	}
}