#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	string number1;
	string number2;
	vector<int> result;
	vector<int> temp;

	cin >> number1;
	cin >> number2;

	for (int i = 0; i < number1.length(); i++) {
		result.push_back(number1[i] - '0');
		result.push_back(number2[i] - '0');
	}

	while (result.size() > 2) {
		temp.clear();
		for (int i = 0; i < result.size() - 1; i++) {
			temp.push_back((result[i] + result[i + 1]) % 10);
		}
		result = temp;
	}

	cout << result[0] << result[1];
}