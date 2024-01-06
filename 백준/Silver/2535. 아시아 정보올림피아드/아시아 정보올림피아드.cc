#include<stdio.h>
#include<string>
#include<map>

using namespace std;

int main() {
	int studentCount;
	map<int, int, greater<int>> scoreCountry;
	map<int, int, greater<int>> scoreStudentNum;
	map<int, int> countryCount;
	scanf("%d", &studentCount);

	int country, studentNum;
	int score;
	for (int i = 0; i < studentCount; i++) {
		scanf("%d%d%d", &country, &studentNum, &score);
		scoreCountry.insert(pair<int, int>(score, country));
		scoreStudentNum.insert(pair<int, int>(score, studentNum));
	}

	int a, b, c;
	int count = 0;
	for (auto itr = scoreCountry.begin(); itr != scoreCountry.end(); itr++) {
		if (count == 3) break;

		if (countryCount.find(itr->second) == countryCount.end()) {
			countryCount.insert(pair<int, int>(itr->second, 1));
			printf("%d %d\n", itr->second, scoreStudentNum.find(itr->first)->second);
			count++;
			continue;
		}

		if (countryCount.find(itr->second)->second < 2) {
			countryCount.find(itr->second)->second++;
			printf("%d %d\n", itr->second, scoreStudentNum.find(itr->first)->second);
			count++;
			continue;
		}
	}
}