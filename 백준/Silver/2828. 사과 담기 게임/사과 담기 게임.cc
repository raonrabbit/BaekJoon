#include<stdio.h>

int main() {
	int N, M;
	int appleCount;
	int currentApplePosition;
	int basketLeft, basketRight;
	int movedLength = 0;
	
	scanf("%d%d", &N, &M);
	basketLeft = 1;
	basketRight = M;

	scanf("%d", &appleCount);
	
	int difference;
	for (int i = 0; i < appleCount; i++) {
		scanf("%d", &currentApplePosition);

		if (currentApplePosition < basketLeft) {
			difference = basketLeft - currentApplePosition;
			movedLength += difference;
			basketLeft -= difference;
			basketRight -= difference;
		}
		else if (basketRight < currentApplePosition) {
			difference = currentApplePosition - basketRight;
			movedLength += difference;
			basketLeft += difference;
			basketRight += difference;
		}
	}

	printf("%d", movedLength);
}