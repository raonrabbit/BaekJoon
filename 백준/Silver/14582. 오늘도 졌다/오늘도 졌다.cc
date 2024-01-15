#include<stdio.h>

int main() {
	int jeminis[9];
	int gulibus[9];
	int score = 0;
	bool yukjunpae = false;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &jeminis[i]);
	}
	for (int i = 0; i < 9; i++) {
		scanf("%d", &gulibus[i]);
	}
	for (int i = 0; i < 9; i++) {
		score += jeminis[i];
		if (score > 0) yukjunpae = true;
		else if (score == 0) yukjunpae = false;
		score -= gulibus[i];
	}

	if (yukjunpae) printf("Yes");
	else printf("No");
}