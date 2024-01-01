#include<iostream>

using namespace std;

int main() {
	string firstWord;
	string secondWord;
	int result;

	cin >> firstWord;
	cin >> secondWord;

	result = firstWord.length() + secondWord.length();

	for (int i = 0; i < secondWord.length(); i++) {
		size_t index = firstWord.find(secondWord[i]);

		if (index != string::npos) {
			firstWord.replace(index, 1, "");
			result -= 2;
		}
	}

	cout << result;
}