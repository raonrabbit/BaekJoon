#include<stdio.h>

int main() {
	bool** paperRecord = new bool*[100];
	for (int i = 0; i < 100; i++) {
		paperRecord[i] = new bool[100];
	}

	int paperCount;
	int result = 0;
    
	scanf("%d", &paperCount);

	int LBX, LBY, width = 10, height = 10;
	for (int i = 0; i < paperCount; i++) {
		scanf("%d %d", &LBX, &LBY);
		for (int h = LBY; h < LBY + height; h++) {
			for (int w = LBX; w < LBX + width; w++) {
				paperRecord[h][w] = true;
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (paperRecord[i][j]) result++;
		}
	}
    printf("%d\n", result);
}