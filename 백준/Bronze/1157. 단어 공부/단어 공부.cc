#include<iostream>

using namespace std;

void MostUsedAlphabet(string word) {
	int alphabetcount[26] = { 0, };
	int max = 0;
	bool isDup = false;
	for (int i = 0; i < word.length(); i++) {
		word[i] = toupper(word[i]);
		for (int j = 0; j < 26; j++) {
			if (word[i] == (char)(j + 65)) {
				alphabetcount[j]++;
				break;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		if (alphabetcount[max] < alphabetcount[i]) {
			max = i;
			isDup = false;
		}
		else if (max != i && alphabetcount[max] == alphabetcount[i]) {
			isDup = true;
		}
	}

	if (isDup) {
		cout << "?";
	}
	else {
		cout << (char)(max + 65);
	}
}

int main() {
	string word;
	cin >> word;
	MostUsedAlphabet(word);
	return 0;
}