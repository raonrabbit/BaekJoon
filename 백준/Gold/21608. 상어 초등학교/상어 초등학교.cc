#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Student {
	int studentNum;
	int favoriteStudents[4];
};

struct SeatInfo {
	int studentNum = NULL;
	int nearBlankCount;
	vector<int> nearStudents;
	int favoriteStudents[4];
};

int main(void) {
	int N;
	scanf("%d", &N);
	
	struct Student** students = new Student*[N];
	for (int i = 0; i < N; i++)
		students[i] = new Student[N];

	struct SeatInfo** seatInfo = new SeatInfo*[N];
	for (int i = 0; i < N; i++)
		seatInfo[i] = new SeatInfo[N];

	int candidateSeatX;
	int candidateSeatY;
	int maxNearBlankCount;
	int maxNearStudentsCount;
	int currentNearStudentsCount;
	int currentNearBlankCount;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int blankCount = 0;
			if (i - 1 >= 0) blankCount++;
			if (i + 1 < N) blankCount++;
			if (j - 1 >= 0) blankCount++;
			if (j + 1 < N) blankCount++;
			
			seatInfo[i][j].nearBlankCount = blankCount;
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			maxNearBlankCount = -1;
			maxNearStudentsCount = -1;
			currentNearBlankCount = -1;
			currentNearStudentsCount = -1;
			candidateSeatX = -1;
			candidateSeatY = -1;


			//학생번호 입력받고 저장
			scanf("%d", &students[i][j].studentNum);

			//좋아하는 학생들 입력받고 저장
			for (int t = 0; t < 4; t++) {
				scanf("%d", &students[i][j].favoriteStudents[t]);
			}

			for (int ii = 0; ii < N; ii++) {
				for (int jj = 0; jj < N; jj++) {
					if (seatInfo[ii][jj].studentNum != NULL) continue;
					currentNearStudentsCount = 0;
					for (int favoriteStudent : students[i][j].favoriteStudents) {
						if (find(seatInfo[ii][jj].nearStudents.begin(), seatInfo[ii][jj].nearStudents.end(), favoriteStudent) != seatInfo[ii][jj].nearStudents.end()) currentNearStudentsCount++;
					}
					currentNearBlankCount = seatInfo[ii][jj].nearBlankCount;
					if (currentNearStudentsCount > maxNearStudentsCount) {
						maxNearStudentsCount = currentNearStudentsCount;
						maxNearBlankCount = currentNearBlankCount;
						candidateSeatX = ii;
						candidateSeatY = jj;
					}
					else if (currentNearStudentsCount == maxNearStudentsCount) {
						if (currentNearBlankCount > maxNearBlankCount) {
							maxNearBlankCount = currentNearBlankCount;
							candidateSeatX = ii;
							candidateSeatY = jj;
						}
					}
				}
			}

			seatInfo[candidateSeatX][candidateSeatY].studentNum = students[i][j].studentNum;
			for (int t = 0; t < 4; t++) {
				seatInfo[candidateSeatX][candidateSeatY].favoriteStudents[t] = students[i][j].favoriteStudents[t];
			}
			
			if (candidateSeatX - 1 >= 0) {
				seatInfo[candidateSeatX - 1][candidateSeatY].nearBlankCount--;
				seatInfo[candidateSeatX - 1][candidateSeatY].nearStudents.push_back(students[i][j].studentNum);
			}
			if (candidateSeatX + 1 < N) {
				seatInfo[candidateSeatX + 1][candidateSeatY].nearBlankCount--;
				seatInfo[candidateSeatX + 1][candidateSeatY].nearStudents.push_back(students[i][j].studentNum);
			}
			if (candidateSeatY - 1 >= 0) {
				seatInfo[candidateSeatX][candidateSeatY - 1].nearBlankCount--;
				seatInfo[candidateSeatX][candidateSeatY - 1].nearStudents.push_back(students[i][j].studentNum);
			}
			if (candidateSeatY + 1 < N) {
				seatInfo[candidateSeatX][candidateSeatY + 1].nearBlankCount--;
				seatInfo[candidateSeatX][candidateSeatY + 1].nearStudents.push_back(students[i][j].studentNum);
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int count = 0;
			for (int nearStudent : seatInfo[i][j].nearStudents) {
				for (int favoriteStudent : seatInfo[i][j].favoriteStudents) {
					if (nearStudent == favoriteStudent) count++;
				}
			}
			if (count == 1) result += 1;
			if (count == 2) result += 10;
			if (count == 3) result += 100;
			if (count == 4) result += 1000;
		}
	}

	printf("%d", result);
}