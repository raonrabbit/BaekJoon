#include<stdio.h>
#include<string.h>

int num[8] = { 3, 3, 3, 3, 3, 4, 3, 4 };


int* findGroup(char c) {
	static int result[2];
	int count = 0;
	for (int group = 0; group < 8; group++) {
		count += num[group];
		if (count > c - 'A') {
			result[0] = group;
			result[1] = ((c - 'A') - (count - num[group])) + 1;
			return result;
		}
	}
}

int main() {
	int pressTime, waitTime;
	char text[1001];
	int result = 0;
	int prevGroup = -1;
	int *currGroup;
	scanf("%d%d ", &pressTime, &waitTime);
	scanf("%[^\n]s", text);

	for (int i = 0; i < strlen(text); i++) {
		if (text[i] == ' ') {
			prevGroup = -1;
			result += pressTime;
			continue;
		}
		currGroup = findGroup(text[i]);
		if (prevGroup == currGroup[0]) result += waitTime;
		result += pressTime * currGroup[1];
		
		prevGroup = currGroup[0];
	}

	printf("%d", result);
}