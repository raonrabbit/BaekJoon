#include<stdio.h>
#include<string.h>

int calWrongCount(char* first, char* second, int startIdx) {
	int wrongCount = 0;
	for (int i = 0, j = startIdx; i < strlen(second); i++, j++) {
		if (first[j] != second[i]) wrongCount++;
	}
	return wrongCount;
}

int main() {
	char secret[8][7] = {
		"000000",
		"001111",
		"010011",
		"011100",
		"100110",
		"101001",
		"110101",
		"111010"
	};
	char inputString[601];
	char outputString[10];
	int charCount, wrongCount;
	int count = 0, min, idx;

	scanf("%d", &charCount);
	scanf("%s", inputString);
	
	for (int i = 0; i < charCount; i++) {
		min = 10;
		for (int j = 0; j < 8; j++) {
			wrongCount = calWrongCount(inputString, secret[j], i * 6);
			if (wrongCount < min) {
				min = wrongCount;
				idx = j;
			}
		}
		if (min <= 1) outputString[i] = (char)(idx + 65);
		else {
			printf("%d", i + 1);
			return 0;
		}
	}
	for (int i = 0; i < charCount; i++) {
		printf("%c", outputString[i]);
	}
}