#include<stdio.h>
#include<vector>
#include<numeric>
using namespace std;
vector<int> cutpaper(vector<vector<int>> a, int xsi, int xei, int ysi, int yei) {
	int length = xei - xsi + 1;
	if (length == 1) {
		if (a[ysi][xsi] == 0)
			return { 0, 1 };
		else
			return { 1, 0 };
	}
	bool haveToCut = false;
	int n = a[ysi][xsi];
	vector<int> cutCount{ 0, 0 };
	vector<int> result{ 0, 0 };
	for (int i = ysi; i <= yei; i++) {
		for (int j = xsi; j <= xei; j++) {
			if (a[i][j] != n) {
				haveToCut = true;
				cutCount = cutpaper(a, xsi, xei - (length / 2), ysi, yei - (length / 2));
				result[0] += cutCount[0];
				result[1] += cutCount[1];
				cutCount = cutpaper(a, xei - (length / 2) + 1, xei, ysi, yei - (length / 2));
				result[0] += cutCount[0];
				result[1] += cutCount[1];
				cutCount = cutpaper(a, xsi, xei - (length / 2), yei - (length / 2) + 1, yei);
				result[0] += cutCount[0];
				result[1] += cutCount[1];
				cutCount = cutpaper(a, xei - (length / 2) + 1, xei, yei - (length / 2) + 1, yei);
				result[0] += cutCount[0];
				result[1] += cutCount[1];
				return result;
			}
		}
	}
	if (a[ysi][xsi] == 0) return { 0, 1 };
	else return { 1, 0 };
}

int main() {
	int n, d;
	vector<vector<int>> a(128, vector<int>());
	vector<int> result;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d%*c", &d);
			a[i].push_back(d);
		}
	}
	result = cutpaper(a, 0, n - 1, 0, n - 1);
	printf("%d\n%d", result[1], result[0]);
}