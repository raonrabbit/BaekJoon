#include<stdio.h>
#include<queue>
using namespace std;

int main() {
	int teamNum;
	int samdae;
	int personalSamdae;
	int teamScore;
	int okTeamCount = 0;
	int score[3];
	queue<int> q;
	bool personalSamdaeOk;
	scanf("%d%d%d", &teamNum, &samdae, &personalSamdae);

	for (int i = 0; i < teamNum; i++) {
		personalSamdaeOk = true;
		teamScore = 0;
		scanf("%d%d%d", &score[0], &score[1], &score[2]);
		for (int j = 0; j < 3; j++) {
			teamScore += score[j];
			if (score[j] < personalSamdae) {
				personalSamdaeOk = false;
				break;
			}
		}

		if (personalSamdaeOk && samdae <= teamScore) {
			okTeamCount++;
			for (int k = 0; k < 3; k++) {
				q.push(score[k]);
			}
		}
	}

	printf("%d\n", okTeamCount);
	while (!q.empty()) {
		printf("%d ", q.front());
		q.pop();
	}
}