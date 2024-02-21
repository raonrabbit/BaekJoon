#include<stdio.h>

int main() {
	int** paperRecord = new int*[101];
	for (int i = 0; i < 1001; i++) {
		paperRecord[i] = new int[101];
	}

	int paperCount;
	int result = 0;
    
	scanf("%d", &paperCount);

	int LBX, LBY, width = 10, height = 10;
	for (int i = 0; i < paperCount; i++) {
		scanf("%d %d", &LBX, &LBY);
		for (int h = LBY; h < LBY + height; h++) {
			for (int w = LBX; w < LBX + width; w++) {
				paperRecord[h][w] = i + 1;
			}
		}
	}

	for (int k = 0; k < paperCount; k++) {
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				if (paperRecord[i][j] == k + 1) {
					result++;
				}
			}
		}
	}
    printf("%d\n", result);
}