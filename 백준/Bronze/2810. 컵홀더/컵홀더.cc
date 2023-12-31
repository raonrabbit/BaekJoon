#include<stdio.h>
#include<string.h>

int main() {
	int seatCount;
	int cupHolderCount;
	char seatInfo[101];

	scanf("%d", &seatCount);
	scanf("%s", seatInfo);

	cupHolderCount = 1;
	for (int i = 0; i < strlen(seatInfo); i++) {
		cupHolderCount++;
		if (seatInfo[i] == 'L') i++;
	}

	if (cupHolderCount >= seatCount) printf("%d", seatCount);
	else printf("%d", cupHolderCount);
}