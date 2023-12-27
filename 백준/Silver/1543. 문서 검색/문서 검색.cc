#include<stdio.h>
#include<string.h>

int main() {
	char paper[2501];
	char word[51];
	int result = 0;
	int paperLength, wordLength;
	bool isSame;

	scanf("%[^\n]s", paper);
	getchar();
	scanf("%[^\n]s", word);

	paperLength = strlen(paper);
	wordLength = strlen(word);

	for (int i = 0; i <= paperLength - wordLength; i++) {
		isSame = true;
		for (int j = 0; j < wordLength; j++) {
			if (paper[i + j] != word[j]) isSame = false;
		}

		if (isSame) {
			result++;
			i += wordLength - 1;
		}
	}

	printf("%d", result);
}