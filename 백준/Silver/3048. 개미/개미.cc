#include<stdio.h>
#include<string.h>

using namespace std;

void mirrorString(char* str, int strLength) {
	char temp;
	for (int i = 0; i < strLength / 2; i++) {
		temp = str[i];
		str[i] = str[strLength - i - 1];
		str[strLength - i - 1] = temp;
	}
}

int main() {
	int firstGroupLength;
	int secondGroupLength;
	int T;
	char firstGroup[10000];
	char secondGroup[10000];

	scanf("%d%d", &firstGroupLength, &secondGroupLength);
	scanf("%s%s", firstGroup, secondGroup);
	scanf("%d", &T);
	mirrorString(firstGroup, firstGroupLength);

	strcat(firstGroup, secondGroup);
	int left = firstGroupLength - 1;
	int right = firstGroupLength - 1;
	int temp;

	bool leftEnd = false, rightEnd = false;
	for (int i = 0; i < T; i++) {
		if (left == 0)leftEnd = true;
		if (right == strlen(firstGroup) - 2) rightEnd = true;
		for (int j = left; j <= right; j += 2) {
			temp = firstGroup[j];
			firstGroup[j] = firstGroup[j + 1];
			firstGroup[j + 1] = temp;
		}
		if (leftEnd && rightEnd && left == right) break;

		if (!leftEnd)left--;
		else left++;
		if (!rightEnd) right++;
		else right--;
	}

	for (int i = 0; i < strlen(firstGroup); i++) {
		printf("%c", firstGroup[i]);
	}
}