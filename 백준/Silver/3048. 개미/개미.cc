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
	char firstGroup[100];
	char secondGroup[100];
	int check[100];

	scanf("%d%d", &firstGroupLength, &secondGroupLength);
	scanf("%s%s", firstGroup, secondGroup);
	scanf("%d", &T);
	mirrorString(firstGroup, firstGroupLength);

	strcat(firstGroup, secondGroup);
	char temp;
	for (int i = 0; i < firstGroupLength; i++) {
		check[i] = 1;
	}

	for (int i = firstGroupLength; i < strlen(firstGroup); i++) {
		check[i] = -1;
	}

	for (int i = 0; i < T; i++) {
		for (int j = 0; j < strlen(firstGroup) - 1; j++) {
			if (check[j] > check[j + 1]) {
				temp = firstGroup[j];
				firstGroup[j] = firstGroup[j + 1];
				firstGroup[j + 1] = temp;
				check[j] = -1;
				check[j + 1] = 1;
				j++;
			}
		}
	}

	for (int i = 0; i < strlen(firstGroup); i++) {
		printf("%c", firstGroup[i]);
	}
}