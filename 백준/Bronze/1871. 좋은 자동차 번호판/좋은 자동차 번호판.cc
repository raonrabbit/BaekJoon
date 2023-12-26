#include<iostream>
#include<vector>
#include <sstream>
#include<math.h>

using namespace std;

int calculateAlphaScore(string carNumber);
int calculateNumberScore(string number);

int main() {
	int carCount;
	int alphabetScore;
	int numberScore;

	string carNumber;
	stringstream ss;
	string token;
	vector<string> tokens;
	vector<string> results;

	cin >> carCount;
	
	for (int i = 0; i < carCount; i++) {
		cin >> carNumber;
		ss.str(carNumber);

		while (getline(ss, token, '-')) {
			tokens.push_back(token);
		}

		alphabetScore = calculateAlphaScore(tokens[0]);
		numberScore = calculateNumberScore(tokens[1]);

		if (abs(alphabetScore - numberScore) <= 100) results.push_back("nice");
		else results.push_back("not nice");

		tokens.clear();
		ss.clear();
	}

	for (string result : results)
		cout << result << endl;
}

int calculateAlphaScore(string alphabet) {
	int value = 0;
	int square;
	int alphabetLength = alphabet.length();

	for (int i = 0; i < alphabetLength; i++) {
		square = alphabetLength - 1 - i;
		value += (int(alphabet[i]) - int('A')) * pow(26, square);
	}
	return value;
}

int calculateNumberScore(string number) {
	return(stoi(number));
}