#include<iostream>

using namespace std;
int** field;
int** path;
int row;
int col;

void Init(int a, int b) {
	field = (int**)malloc(sizeof(int*) * a);

	for (int i = 0; i < a; i++) {

		field[i] = (int*)malloc(sizeof(int) * b);

	}
	path = (int**)malloc(sizeof(int*) * a);

	for (int i = 0; i < a; i++) {

		path[i] = (int*)malloc(sizeof(int) * b);

	}
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			path[i][j] = -1;
		}
	}
	return;
}

int cal_road(int x, int y) {
	int l = 0, r = 0, u = 0, d = 0;
	int i = 0;
	if (path[y][x] != -1) return path[y][x];
	if (x == (col - 1) && y == (row - 1)) return 1;
	path[y][x] = 0;
	if (x > 0 && field[y][x] > field[y][x - 1]) {
		i++;
		r = cal_road(x - 1, y);
	}
	if (x < (col - 1) && field[y][x] > field[y][x + 1]) {
		i++;
		l = cal_road(x + 1, y);
	}
	if (y > 0 && field[y][x] > field[y - 1][x]) {
		i++;
		u = cal_road(x, y - 1);
	}
	if (y < (row - 1) && field[y][x] > field[y + 1][x]) {
		i++;
		d = cal_road(x, y + 1);
	}
	if (i == 0) return 0;
	path[y][x] = (r + l + u + d);
	return(r + l + u + d);
}

int main(void) {

	int height;

	cin >> row;

	cin >> col;

	Init(row, col);

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {

			cin >> height;

			field[i][j] = height;

		}

	}
	cout << cal_road(0, 0) << endl;
}