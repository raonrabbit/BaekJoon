#include<stdio.h>
#include<map>

using namespace std;

bool isAEIOU(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}


int main() {
	int wordLength;
	char word1[100001];
	char word2[100001];

	map<char, int> aeiouCount = {
		{'a', 0},
		{'e', 0},
		{'i', 0},
		{'o', 0},
		{'u', 0}
	};

	bool isDurumari = true;

	scanf("%d", &wordLength);

	scanf("%s", word1);
	scanf("%s", word2);

	if (word1[0] != word2[0] || word1[wordLength - 1] != word2[wordLength - 1]) {
		isDurumari = false;
	}
	else {
		int word1P = 1;
		int word2P = 1;
		
		while (word1P < wordLength - 1 || word2P < wordLength - 1) {
			char word1Character = word1[word1P];
			char word2Character = word2[word2P];

			if (isAEIOU(word1Character) && word1P < wordLength - 1) {
				aeiouCount.find(word1Character)->second++;
				word1P++;
			}

			if (isAEIOU(word2Character) && word2P < wordLength - 1) {
				aeiouCount.find(word2Character)->second--;
				word2P++;
			}

			if (!isAEIOU(word1Character) && !isAEIOU(word2Character)) {
				if (word1Character == word2Character) {
					word1P++;
					word2P++;
				}
				else {
					isDurumari = false;
					break;
				}
			}
		}
	}
	
	for (auto itr = aeiouCount.begin(); itr != aeiouCount.end(); itr++) {
		if (itr->second != 0) {
			isDurumari = false;
			break;
		}
	}

	if (isDurumari) printf("YES");
	else printf("NO");
}