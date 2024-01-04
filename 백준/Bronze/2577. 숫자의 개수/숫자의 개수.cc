#include<stdio.h>
#include<string>
#include<map>

using namespace std;

int main() {
	int a, b, c;
	string multiple;
	map<int, int> numCount;

	for (int i = 0; i < 10; i++) {
		numCount.insert({ i, 0 });
	}

	scanf("%d%d%d", &a, &b, &c);

	multiple = to_string(a * b * c);

	for (int i = 0; i < multiple.length(); i++) {
		numCount.find(multiple[i] - '0')->second++;
	}

	for (auto it = numCount.begin(); it != numCount.end(); it++) {
		printf("%d\n", it->second);
	}
}