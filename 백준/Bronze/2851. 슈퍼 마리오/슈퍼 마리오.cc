#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

int main() {
	int mushroomAmount = 10;
	int targetScore = 100;
	int currentScore = 0;
	int prevScore = 0;
	int result = 0;

	vector<int> mushroomScores(mushroomAmount);

	for (int i = 0; i < mushroomAmount; i++) {
		scanf("%d", &mushroomScores[i]);
	}

	for (int mushroomScore : mushroomScores) {
		currentScore += mushroomScore;
		
		if (targetScore < currentScore) {
			int prevScoreDifference = abs(targetScore - prevScore);
			int currentScoreDifference = abs(targetScore - currentScore);

			if (prevScoreDifference > currentScoreDifference || prevScoreDifference == currentScoreDifference) {
				result = currentScore;
			}

			break;
		}

		prevScore = currentScore;
		result = currentScore;
	}
	
	printf("%d", result);
}