#include<stdio.h>
#include<map>
#include<math.h>

using namespace std;

int main() {
	int diceThrowCount;
	int result = 0;
	int score;
	int diceNumber[3];
	map<int, int> diceRecord;

	scanf("%d", &diceThrowCount);
	
	for (int i = 0; i < diceThrowCount; i++) {
		int selectedDice = 0, max = 0;
		scanf("%d%d%d", &diceNumber[0], &diceNumber[1], &diceNumber[2]);
		for (int j = 0; j < 3; j++) {
			if (diceRecord.find(diceNumber[j]) != diceRecord.end()) {
				selectedDice = diceNumber[j];
				diceRecord[diceNumber[j]]++;
			}
			else diceRecord.insert({ diceNumber[j], 1 });
			if (max < diceNumber[j]) max = diceNumber[j];
		}

		if (selectedDice != 0) 
			score = pow(10, diceRecord[selectedDice] + 1) + pow(10, diceRecord[selectedDice]) * selectedDice;
		else 
			score = 100 * max;

		if (score > result) result = score;
		diceRecord.clear();
	}

	printf("%d", result);
}