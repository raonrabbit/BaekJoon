#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int wordCount;

	map<string, int> reverseWords;
	string currentWord;
	vector<string> words;

	cin >> wordCount;

	for (int i = 0; i < wordCount; i++) {
		cin >> currentWord;
		words.push_back(currentWord);
		reverse(currentWord.begin(), currentWord.end());
		reverseWords.insert(pair<string, int>(currentWord, 0));
	}

	for (string word : words) {
		if (reverseWords.find(word) != reverseWords.end()) {
			printf("%d %c", word.length(), word[word.length()/2]);
			break;
		}
	}
}