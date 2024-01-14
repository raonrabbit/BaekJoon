#include<stdio.h>

int main() {
	int** paperRecord = new int*[1001];
	for (int i = 0; i < 1001; i++) {
		paperRecord[i] = new int[1001];
	}

	int paperCount;
	int result;

	scanf("%d", &paperCount);

	int LBX, LBY, width, height;
	for (int i = 0; i < paperCount; i++) {
		scanf("%d%d%d%d", &LBX, &LBY, &width, &height);
		for (int h = LBY; h < LBY + height; h++) {
			for (int w = LBX; w < LBX + width; w++) {
				paperRecord[h][w] = i + 1;
			}
		}
	}

	for (int k = 0; k < paperCount; k++) {
		result = 0;
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 1001; j++) {
				if (paperRecord[i][j] == k + 1) {
					result++;
				}
			}
		}
		printf("%d\n", result);
	}
}