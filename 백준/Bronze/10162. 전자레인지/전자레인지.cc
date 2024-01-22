#include<stdio.h>

int main() {
	int goalTime;
	int times[3] = { 0, };

	scanf("%d", &goalTime);
	
	times[0] = goalTime / 300;
	times[1] = goalTime % 300 / 60;
	times[2] = goalTime % 60 / 10;

	if (goalTime % 10 == 0) {
		for (int i = 0; i < 3; i++) {
			printf("%d ", times[i]);
		}
	}
	else {
		printf("-1");
	}
}