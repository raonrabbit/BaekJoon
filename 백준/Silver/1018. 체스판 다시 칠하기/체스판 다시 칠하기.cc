#include<iostream>

using namespace std;

int main() {
	int row, col;
	int startwhite, startblack;
	int i, j, a, b;
	int min;
	int** countdata;
	char** chessboard;
	cin >> row;
	cin >> col;

	countdata = new int* [row - 8 + 1];
	for (i = 0; i <= row - 8; i++) {
		countdata[i] = new int[col - 8 + 1];
	}

	chessboard = new char* [row];
	for (i = 0; i < row; i++) {
		chessboard[i] = new char[col];
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			cin >> chessboard[i][j];
		}
	}

	for (i = 0; i <= row - 8; i++) {
		for (j = 0; j <= col - 8; j++) {
			startwhite = 0;
			startblack = 0;
			for (a = i; a < i + 8; a++) {
				for (b = j; b < j + 8; b++) {
					if ((j - b) % 2 == 0) {
						if ((i - a) % 2 == 0) {
							if (chessboard[a][b] == 'B')startwhite++;
							else startblack++;
						}
						else {
							if (chessboard[a][b] == 'W')startwhite++;
							else startblack++;
						}
					}
					else {
						if ((i - a) % 2 == 0) {
							if (chessboard[a][b] == 'W')startwhite++;
							else startblack++;
						}
						else {
							if (chessboard[a][b] == 'B')startwhite++;
							else startblack++;
						}
					}
				}
			}
			if (startwhite >= startblack) {
				countdata[i][j] = startblack;
			}
			else countdata[i][j] = startwhite;
		}
	}

	min = countdata[0][0];
	for (i = 0; i <= row - 8; i++) {
		for (j = 0; j <= col - 8; j++) {
			if (min >= countdata[i][j]) min = countdata[i][j];
		}
	}

	cout << min;
	//system("pause");
	return(0);
}