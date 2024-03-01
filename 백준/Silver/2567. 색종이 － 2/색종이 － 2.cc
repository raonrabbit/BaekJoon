#include<stdio.h>

int main() {
	bool** paperRecord = new bool* [102];
	for (int i = 0; i < 102; i++) {
		paperRecord[i] = new bool[102];
	}

	int paperCount;
	int result = 0;

	scanf("%d", &paperCount);

	int LBX, LBY, width = 10, height = 10;
	for (int i = 0; i < paperCount; i++) {
		scanf("%d %d", &LBX, &LBY);
		LBX += 1;
		LBY += 1;
		for (int h = LBY; h < LBY + height; h++) {
			for (int w = LBX; w < LBX + width; w++) {
				paperRecord[h][w] = true;
			}
		}
	}

	for (int i = 0; i < 102; i++) {
		for (int j = 0; j < 101; j++) {
			if (paperRecord[i][j]^paperRecord[i][j+1]) result++;
			if (paperRecord[j][i] ^ paperRecord[j+1][i])result++;
		}
	}
	printf("%d\n", result);
}