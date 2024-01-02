#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stack>

using namespace std;

int main() {
	string firstBit;
	string secondBit;
	stack<int> bitbit;
	stack<int> bootboot;
	stack<int> result;

	cin >> firstBit;
	cin >> secondBit;

	size_t index1 = firstBit.find('1');
	size_t index2 = secondBit.find('1');

	if (index1 == string::npos) firstBit = "0";
	else firstBit = firstBit.substr(index1);

	if (index2 == string::npos) secondBit = "0";
	else secondBit = secondBit.substr(index2);

	for (int i = 0; i < firstBit.length(); i++) {
		bitbit.push(firstBit[i] - '0');
	}

	for (int i = 0; i < secondBit.length(); i++) {
		bootboot.push(secondBit[i] - '0');
	}

	int carry = 0;
	while (!bitbit.empty() || !bootboot.empty()) {
		int sum = carry;
		
		if (!bitbit.empty()) {
			sum += bitbit.top();
			bitbit.pop();
		}

		if (!bootboot.empty()) {
			sum += bootboot.top();
			bootboot.pop();
		}

		result.push(sum % 2);

		if (sum >= 2) carry = 1;
		else carry = 0;
	}

	if (carry == 1) result.push(1);

	int size = result.size();
	while (!result.empty()) {
		printf("%d", result.top());
		result.pop();
	}
}