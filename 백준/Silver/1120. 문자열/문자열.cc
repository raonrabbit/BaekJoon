#include<iostream>
#include <string>

using namespace std;
int compareString(string a, string b);

int main() {
	string A;
	string B;
	int result;
	int wrongCharacterCount;

	cin >> A;
	cin >> B;

	result = A.length();
	for (int i = 0; i <= B.length() - A.length(); i++){
		string subB = B.substr(i, A.length());

		wrongCharacterCount = compareString(A, subB);
		if (wrongCharacterCount < result) result = wrongCharacterCount;
	}

	cout << result;
}

int compareString(string a, string b) {
	int wrongCharacterCount = 0;
	for (int i = 0; i < a.length(); i++) {
		if(a[i] != b[i]) wrongCharacterCount++;
	}
	return wrongCharacterCount;
}